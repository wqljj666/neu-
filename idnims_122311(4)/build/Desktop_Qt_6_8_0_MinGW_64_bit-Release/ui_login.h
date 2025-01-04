/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *widget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *le_password;
    QLabel *lb2;
    QLineEdit *le_username;
    QLabel *lb1;
    QPushButton *btn_login;
    QPushButton *btn_register;
    QPushButton *pushButton;
    QPushButton *btn_exit;
    QLabel *label_3;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName("login");
        login->resize(629, 427);
        login->setStyleSheet(QString::fromUtf8("#login{background-image: url(:/new/prefix1/1735392184998.jpg);}"));
        widget_2 = new QWidget(login);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(10, 90, 582, 184));
        gridLayout_2 = new QGridLayout(widget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        le_password = new QLineEdit(widget_2);
        le_password->setObjectName("le_password");
        le_password->setMinimumSize(QSize(0, 28));
        QFont font;
        font.setPointSize(12);
        le_password->setFont(font);
        le_password->setMaxLength(20);
        le_password->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(le_password, 1, 1, 1, 1);

        lb2 = new QLabel(widget_2);
        lb2->setObjectName("lb2");
        QFont font1;
        font1.setPointSize(14);
        lb2->setFont(font1);
        lb2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lb2, 1, 0, 1, 1);

        le_username = new QLineEdit(widget_2);
        le_username->setObjectName("le_username");
        le_username->setMinimumSize(QSize(0, 28));
        le_username->setFont(font);
        le_username->setMaxLength(20);

        gridLayout_2->addWidget(le_username, 0, 1, 1, 1);

        lb1 = new QLabel(widget_2);
        lb1->setObjectName("lb1");
        lb1->setFont(font1);
        lb1->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(lb1, 0, 0, 1, 1);

        btn_login = new QPushButton(login);
        btn_login->setObjectName("btn_login");
        btn_login->setGeometry(QRect(10, 280, 288, 35));
        btn_login->setMinimumSize(QSize(82, 35));
        btn_login->setMaximumSize(QSize(16777215, 35));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(11);
        font2.setBold(true);
        btn_login->setFont(font2);
        btn_login->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 0.5px solid white;\n"
"	border-radius: 6px;\n"
"	background-color: rgb(90, 194, 198);\n"
"	min-width: 80px;\n"
"	font-family: \"Times New Roman\";\n"
"	font-size: 11pt;\n"
"	font-weight: bold;\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	border: 0.5px solid white;\n"
"	border-radius: 6px;\n"
"	background-color: #1fab89;\n"
"	min-width: 80px;\n"
"	font-family: \"Times New Roman\";\n"
"	font-size: 10pt;\n"
"	font-weight: bold;\n"
"	color: white;\n"
"}"));
        btn_register = new QPushButton(login);
        btn_register->setObjectName("btn_register");
        btn_register->setGeometry(QRect(300, 280, 288, 35));
        btn_register->setMinimumSize(QSize(82, 35));
        btn_register->setMaximumSize(QSize(16777215, 35));
        btn_register->setFont(font2);
        btn_register->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 0.5px solid white;\n"
"	border-radius: 6px;\n"
"	background-color: rgb(90, 194, 198);\n"
"	min-width: 80px;\n"
"	font-family: \"Times New Roman\";\n"
"	font-size: 11pt;\n"
"	font-weight: bold;\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	border: 0.5px solid white;\n"
"	border-radius: 6px;\n"
"	background-color: #1fab89;\n"
"	min-width: 80px;\n"
"	font-family: \"Times New Roman\";\n"
"	font-size: 10pt;\n"
"	font-weight: bold;\n"
"	color: white;\n"
"}"));
        pushButton = new QPushButton(login);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 330, 288, 35));
        pushButton->setMinimumSize(QSize(82, 35));
        pushButton->setMaximumSize(QSize(16777215, 35));
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 0.5px solid white;\n"
"	border-radius: 6px;\n"
"	background-color: rgb(90, 194, 198);\n"
"	min-width: 80px;\n"
"	font-family: \"Times New Roman\";\n"
"	font-size: 11pt;\n"
"	font-weight: bold;\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	border: 0.5px solid white;\n"
"	border-radius: 6px;\n"
"	background-color: #1fab89;\n"
"	min-width: 80px;\n"
"	font-family: \"Times New Roman\";\n"
"	font-size: 10pt;\n"
"	font-weight: bold;\n"
"	color: white;\n"
"}"));
        btn_exit = new QPushButton(login);
        btn_exit->setObjectName("btn_exit");
        btn_exit->setGeometry(QRect(300, 330, 288, 35));
        btn_exit->setMinimumSize(QSize(82, 35));
        btn_exit->setMaximumSize(QSize(16777215, 35));
        btn_exit->setFont(font2);
        btn_exit->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	border: 0.5px solid white;\n"
"	border-radius: 6px;\n"
"	background-color: rgb(90, 194, 198);\n"
"	min-width: 80px;\n"
"	font-family: \"Times New Roman\";\n"
"	font-size: 11pt;\n"
"	font-weight: bold;\n"
"	color: white;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	border: 0.5px solid white;\n"
"	border-radius: 6px;\n"
"	background-color: #1fab89;\n"
"	min-width: 80px;\n"
"	font-family: \"Times New Roman\";\n"
"	font-size: 10pt;\n"
"	font-weight: bold;\n"
"	color: white;\n"
"}"));
        label_3 = new QLabel(login);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 20, 582, 60));
        label_3->setMinimumSize(QSize(0, 60));
        label_3->setMaximumSize(QSize(16777215, 60));
        QFont font3;
        font3.setPointSize(18);
        label_3->setFont(font3);
        label_3->setAlignment(Qt::AlignCenter);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Form", nullptr));
        le_password->setPlaceholderText(QCoreApplication::translate("login", "\350\257\267\350\276\223\345\205\245\357\274\210\344\270\215\350\266\205\350\277\20720\344\275\215\357\274\211", nullptr));
        lb2->setText(QCoreApplication::translate("login", "\345\257\206   \347\240\201", nullptr));
        le_username->setPlaceholderText(QCoreApplication::translate("login", "\350\257\267\350\276\223\345\205\245\357\274\210\344\270\215\350\266\205\350\277\20720\344\275\215\357\274\211", nullptr));
        lb1->setText(QCoreApplication::translate("login", "\347\224\250\346\210\267\345\220\215", nullptr));
        btn_login->setText(QCoreApplication::translate("login", "\347\231\273\345\275\225", nullptr));
        btn_register->setText(QCoreApplication::translate("login", "\346\263\250\345\206\214", nullptr));
        pushButton->setText(QCoreApplication::translate("login", "\345\277\230\350\256\260\345\257\206\347\240\201", nullptr));
        btn_exit->setText(QCoreApplication::translate("login", "\351\200\200\345\207\272", nullptr));
        label_3->setText(QCoreApplication::translate("login", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
