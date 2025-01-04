#include "page_forget.h"
#include "ui_page_forget.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>


page_forget::page_forget(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::page_forget)
{
    ui->setupUi(this);
}

page_forget::~page_forget()
{
    delete ui;
}

void page_forget::on_btn_save_clicked()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","usertest1224"); // 假设使用的是SQLite
    db.setDatabaseName("usertest1224.db"); // 设置数据库文件名

    if (!db.open()) {
        qWarning() << "Database connection failed:" << db.lastError();
        QMessageBox::critical(this, "Database Error", "Failed to connect to the database: " + db.lastError().text());
        return;
    }

    // 从界面获取用户名、手机号和新密码
    QString username = ui->le_uesrname->text(); // 假设您有一个名为 le_Username 的 QLineEdit 控件用于输入用户名
    QString phoneNumber = ui->le_Id->text(); // 假设您有一个名为 le_PhoneNumber 的 QLineEdit 控件用于输入手机号
    QString newPassword = ui->le_newPassword->text(); // 假设您有一个名为 le_NewPassword 的 QLineEdit 控件用于输入新密码

    // 检查用户名、手机号和新密码是否为空
    if (username.isEmpty() || phoneNumber.isEmpty() || newPassword.isEmpty()) {
        QMessageBox::information(this, "信息", "用户名、手机号和密码不能为空！");
        db.close();
        return;
    }

    QSqlQuery query(db);
    query.prepare("SELECT * FROM user WHERE user_name = :username AND phone_number = :phone_number");
    query.bindValue(":username", username);
    query.bindValue(":phone_number", phoneNumber);

    if (!query.exec()) {
        qWarning() << "Query failed:" << query.lastError();
        QMessageBox::critical(this, "Query Error", "Failed to execute query: " + query.lastError().text());
        db.close();
        return;
    }

    // 如果查询结果为空，说明用户名和手机号不匹配或不存在
    if (!query.next()) {
        QMessageBox::information(this, "信息", "用户名和手机号不匹配或不存在！");
        db.close();
        return;
    }

    // 如果用户名和手机号匹配且存在，更新密码
    query.prepare("UPDATE user SET password = :password WHERE user_name = :username AND phone_number = :phone_number");
    query.bindValue(":password", newPassword);
    query.bindValue(":username", username);
    query.bindValue(":phone_number", phoneNumber);

    if (!query.exec()) {
        qWarning() << "Update failed:" << query.lastError();
        QMessageBox::critical(this, "Update Error", "Failed to update password: " + query.lastError().text());
    } else {
        QMessageBox::information(this, "信息", "密码修改成功！");
        ui->le_uesrname->clear();
        ui->le_Id->clear();
        ui->le_newPassword->clear();
    }

    db.close(); // 关闭数据库连接
}

void page_forget::on_btn_exit_clicked()
{
    this->hide();
}
