#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_btn_register_clicked()
{
    m_register.exec();
}

void login::on_btn_login_clicked()
{
    QString username = ui->le_username->text();
        QString password = ui->le_password->text();
        if (validateLogin(username, password)) {
            // 登录成功，进行相应的操作，比如显示主窗口
            // 显示主窗口或其他操作
            loginSuccess();
            this->hide();
        } else {
            // 登录失败，显示错误消息
            QMessageBox::information(nullptr,"信息","输入的用户名或密码有误");
            ui->le_username->clear();
            ui->le_password->clear();
        }
}

bool login::validateLogin(const QString& username, const QString& password) {
    // 获取数据库连接
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","usertest1224"); // 假设使用的是SQLite
        db.setDatabaseName("usertest1224.db"); // 设置数据库文件名

        if (!db.open()) {
            qWarning() << "Database connection failed:" << db.lastError();
            return false;
        }

        QSqlQuery query(db);
        query.prepare("SELECT * FROM user WHERE user_name = :username AND password = :password");
        query.bindValue(":username", username);
        query.bindValue(":password", password);

        if (query.exec()) {
            if (query.next()) {
                return true; // 用户名和密码匹配
            }
        } else {
            qWarning() << "Query failed:" << query.lastError();
        }

        return false; // 用户名或密码不匹配
}

void login::on_btn_exit_clicked()
{
    exit(0);
}

void login::loginSuccess()
{
    emit loginSuccessful(); // 发出登录成功的信号
}

void login::on_pushButton_clicked()
{
    m_forget.exec();
}
