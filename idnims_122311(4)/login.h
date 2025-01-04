#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "page_register.h"
#include "page_forget.h"
#include "domainmanagementsystem.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    void loginSuccess();

private slots:
    void on_btn_login_clicked();

    void on_btn_register_clicked();

    void on_btn_exit_clicked();

    void on_pushButton_clicked();

signals:
    void loginSuccessful();

private:
    Ui::login *ui;
    page_register m_register;
    page_forget m_forget;
    bool validateLogin(const QString& username, const QString& password);
};

#endif // LOGIN_H
