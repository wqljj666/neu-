/********************************************************************************
** Form generated from reading UI file 'page_forget.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE_FORGET_H
#define UI_PAGE_FORGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_page_forget
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *le_uesrname;
    QLabel *label_2;
    QLineEdit *le_Id;
    QLabel *label_3;
    QLineEdit *le_newPassword;
    QPushButton *btn_save;
    QPushButton *btn_exit;

    void setupUi(QDialog *page_forget)
    {
        if (page_forget->objectName().isEmpty())
            page_forget->setObjectName("page_forget");
        page_forget->resize(647, 437);
        page_forget->setStyleSheet(QString::fromUtf8("#page_forget{background-image: url(:/new/prefix1/1735392184998.jpg);}"));
        widget = new QWidget(page_forget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(10, 20, 582, 301));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(widget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(14);
        label->setFont(font);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        le_uesrname = new QLineEdit(widget);
        le_uesrname->setObjectName("le_uesrname");
        QFont font1;
        font1.setPointSize(12);
        le_uesrname->setFont(font1);

        gridLayout->addWidget(le_uesrname, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        le_Id = new QLineEdit(widget);
        le_Id->setObjectName("le_Id");
        le_Id->setFont(font1);

        gridLayout->addWidget(le_Id, 1, 1, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        le_newPassword = new QLineEdit(widget);
        le_newPassword->setObjectName("le_newPassword");
        le_newPassword->setFont(font1);

        gridLayout->addWidget(le_newPassword, 2, 1, 1, 1);

        btn_save = new QPushButton(page_forget);
        btn_save->setObjectName("btn_save");
        btn_save->setGeometry(QRect(10, 350, 288, 35));
        btn_save->setMinimumSize(QSize(82, 35));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Times New Roman")});
        font2.setPointSize(11);
        font2.setBold(true);
        btn_save->setFont(font2);
        btn_save->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        btn_exit = new QPushButton(page_forget);
        btn_exit->setObjectName("btn_exit");
        btn_exit->setGeometry(QRect(310, 350, 288, 35));
        btn_exit->setMinimumSize(QSize(82, 35));
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

        retranslateUi(page_forget);

        QMetaObject::connectSlotsByName(page_forget);
    } // setupUi

    void retranslateUi(QDialog *page_forget)
    {
        page_forget->setWindowTitle(QCoreApplication::translate("page_forget", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("page_forget", "\347\224\250\346\210\267\345\220\215", nullptr));
        le_uesrname->setPlaceholderText(QCoreApplication::translate("page_forget", "\350\257\267\350\276\223\345\205\245\357\274\210\344\270\215\350\266\205\350\277\20720\344\275\215\357\274\211", nullptr));
        label_2->setText(QCoreApplication::translate("page_forget", "\346\211\213\346\234\272\345\217\267", nullptr));
        label_3->setText(QCoreApplication::translate("page_forget", "\346\226\260\345\257\206\347\240\201", nullptr));
        le_newPassword->setPlaceholderText(QCoreApplication::translate("page_forget", "\350\257\267\350\276\223\345\205\245\357\274\210\344\270\215\350\266\205\350\277\20720\344\275\215\357\274\211", nullptr));
        btn_save->setText(QCoreApplication::translate("page_forget", "\344\277\235\345\255\230", nullptr));
        btn_exit->setText(QCoreApplication::translate("page_forget", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class page_forget: public Ui_page_forget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE_FORGET_H
