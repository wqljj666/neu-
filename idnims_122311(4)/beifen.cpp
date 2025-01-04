#include "beifen.h"
#include "ui_beifen.h"
#include<QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QSqlRecord>
beifen::beifen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::beifen)
{
    ui->setupUi(this);
}

beifen::~beifen()
{
    delete ui;
}

void beifen::on_sure_2_clicked()
{
    // 调用 getExistingDirectory 函数，传入适当的参数
    QString dirPath = QFileDialog::getExistingDirectory(this, "选择文件夹", QDir::homePath());

    // 检查用户是否选择了文件夹（即返回值不是空字符串）
    if (!dirPath.isEmpty()) {
        // 用户选择了文件夹，你可以在这里处理 dirPath
        qDebug() << "Selected folder:" << dirPath;
    } else {
        // 用户取消了选择，或者没有选择任何文件夹
        qDebug() << "No folder selected.";
    }
    filename = dirPath; // 将选择的文件夹路径赋值给 filename
}

void beifen::on_restore_clicked(QString filename_1)
{
    // 获取备份文件路径
    QString backupPath = filename_1; // 备份文件路径
    qDebug() << "Backup file path:" << backupPath;

    // 检查备份文件是否存在
    QFileInfo backupFileInfo(backupPath);
    if (!backupFileInfo.exists()) {
        qDebug() << "Error: Backup file does not exist.";
        return;
    }

    // 获取原数据库路径
    QString originalPath = db_1.databaseName(); // 原数据库路径
    qDebug() << "Original database path:" << originalPath;

    // 关闭原数据库连接
    if (db_1.isOpen()) {
        db_1.close();
        qDebug() << "Original database closed.";
    }

    // 删除原数据库文件
    QFile originalFile(originalPath);
    if (originalFile.exists()) {
        if (!originalFile.remove()) {
            qDebug() << "Error: Could not delete original database file.";
            return;
        }
        qDebug() << "Original database file deleted.";
    }

    // 将备份文件复制到原数据库文件的位置
    if (!QFile::copy(backupPath, originalPath)) {
        qDebug() << "Error: Could not copy backup file to original database location.";
        return;
    }
    qDebug() << "Backup file copied to original database location.";

    // 重新打开原数据库连接
    if (!db_1.open()) {
        qDebug() << "Error: Could not reopen original database." << db_1.lastError().text();
        return;
    }
    qDebug() << "Original database reopened successfully.";
}
void beifen::on_sure_3_clicked()
{
    address=ui->lineEdit->text();
    // 检查是否选择了文件夹
    if (filename.isEmpty()) {
        qDebug() << "Error: No folder selected.";
        return;
    }

    // 指定备份文件路径
    QString backupPath = filename +"/"+address+".db"; // 在选择的文件夹下创建备份文件
    // 确保目录存在
    QDir().mkpath(QFileInfo(backupPath).absolutePath());
    qDebug() << "Database path:" <<backupPath;
    // 确保文件夹存在
    QDir dir(QFileInfo(backupPath).absolutePath());
    if (!dir.exists()) {
        if (!dir.mkpath(".")) {
            qDebug() << "Error: Could not create database directory.";
        }
    }
    // 检查源数据库是否已连接
    if (!db_1.isOpen()) {
        qDebug() << "Error: Source database is not open.";
        return;
    }
    if (!QSqlDatabase::isDriverAvailable("QSQLITE")) {
        qDebug() << "Error: SQLite driver is not available.";
        return;
    }
    // 连接目标数据库（备份数据库）
    QSqlDatabase backupDb = QSqlDatabase::addDatabase("QSQLITE", "backup_connection");
    backupDb.setDatabaseName(backupPath);

    if (!backupDb.open()) {
        qDebug() << "Error: Could not open backup database."<< backupDb.lastError().text();
        return;
    }

    // 备份表结构和数据
    QSqlQuery srcQuery(db_1); // 使用已连接的源数据库 db
    if (srcQuery.exec("SELECT sql FROM sqlite_master WHERE type='table' AND name='jkomains'")) {
        if (srcQuery.next()) {
            QString createTableSql = srcQuery.value(0).toString();
            qDebug() << "Create table SQL:" << createTableSql;

            // 在备份数据库中创建表
            QSqlQuery backupQuery(backupDb);
            if (!backupQuery.exec(createTableSql)) {
                qDebug() << "Error: Could not create table in backup database." << backupQuery.lastError();
                backupDb.close();
                return;
            }

            // 导出数据
            if (srcQuery.exec("SELECT * FROM jkomains")) {
                backupDb.transaction(); // 开始事务
                while (srcQuery.next()) {
                    QString insertSql = "INSERT INTO jkomains VALUES (";
                    for (int i = 0; i < srcQuery.record().count(); ++i) {
                        if (i > 0) insertSql += ", ";
                        insertSql += "'" + srcQuery.value(i).toString().replace("'", "''") + "'"; // 防止 SQL 注入
                    }
                    insertSql += ");";

                    if (!backupQuery.exec(insertSql)) {
                        qDebug() << "Error: Could not insert data into backup table." << backupQuery.lastError();
                        backupDb.rollback(); // 回滚事务
                        backupDb.close();
                        return;
                    }
                }
                backupDb.commit(); // 提交事务
                qDebug() << "Table backup successful!";
            } else {
                qDebug() << "Error: Could not export table data." << srcQuery.lastError();
            }
        } else {
            qDebug() << "Error: Table 'jkomains' not found.";
        }
    } else {
        qDebug() << "Error: Could not export table structure." << srcQuery.lastError();
    }

    // 关闭备份数据库
    backupDb.close();
}

