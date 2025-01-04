#include "page_register.h"
#include "ui_page_register.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

page_register::page_register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::page_register)
{
    ui->setupUi(this);
    createTable();
}

page_register::~page_register()
{
    delete ui;
}

void page_register::on_btn_exit_clicked()
{
    this->hide();
}

void page_register::on_btn_register_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","usertest1224"); // 假设使用的是SQLite
    db.setDatabaseName("usertest1224.db"); // 设置数据库文件名

    if (!db.open()) {
        qWarning() << "Database connection failed:" << db.lastError();
        QMessageBox::critical(this, "Database Error", "Failed to connect to the database: " + db.lastError().text());
        return;
    }

    // 从界面获取用户名、密码和手机号
    QString username = ui->le_Username->text();
    QString password = ui->le_Password->text();
    QString phoneNumber = ui->le_Id_2->text(); // 假设您有一个名为 le_PhoneNumber 的 QLineEdit 控件用于输入手机号

    // 检查用户名、密码和手机号是否为空
    if (username.isEmpty() || password.isEmpty() || phoneNumber.isEmpty()) {
        QMessageBox::information(this, "信息", "用户名、密码和手机号不能为空！");
        db.close();
        return;
    }

    QSqlQuery query(db);
    query.prepare("SELECT * FROM user WHERE user_name = :username");
    query.bindValue(":username", username);

    if (!query.exec()) {
        qWarning() << "Query failed:" << query.lastError();
        QMessageBox::critical(this, "Query Error", "Failed to execute query: " + query.lastError().text());
        db.close();
        return;
    }

    // 如果查询结果不为空，说明用户名已存在
    if (query.next()) {
        QMessageBox::information(this, "信息", "用户名已存在！");
        db.close();
        return;
    }

    // 如果用户名不存在，添加新用户
    query.prepare("INSERT INTO user (user_name, password, phone_number) VALUES (:username, :password, :phone_number)");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.bindValue(":phone_number", phoneNumber); // 绑定手机号到 SQL 语句

    if (!query.exec()) {
        qWarning() << "Insert failed:" << query.lastError();
        QMessageBox::critical(this, "Insert Error", "Failed to insert data: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "信息", "注册成功！");
        // 清空输入框
        ui->le_Username->clear();
        ui->le_Password->clear();
        ui->le_Id_2->clear(); // 清空手机号输入框
    }

    db.close(); // 关闭数据库连接
}

void page_register::createTable() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","usertest1224"); // 假设使用的是SQLite
    db.setDatabaseName("usertest1224.db"); // 设置数据库文件名

    if (!db.open()) {
        qWarning() << "Database connection failed:" << db.lastError();
        return;
    }

    QSqlQuery query(db);
    QString createTableQuery = "CREATE TABLE IF NOT EXISTS user ("
                                  "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                  "user_name TEXT, "
                                  "password TEXT, "
                                  "phone_number TEXT)"; // 添加手机号字段

    if (!query.exec(createTableQuery)) {
        qWarning() << "Failed to create table:" << query.lastError();
    }

    db.close(); // 创建表后关闭数据库连接
}
