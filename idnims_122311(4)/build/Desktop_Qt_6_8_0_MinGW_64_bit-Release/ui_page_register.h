/********************************************************************************
** Form generated from reading UI file 'page_register.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGE_REGISTER_H
#define UI_PAGE_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_page_register
{
public:
    QPushButton *btn_register;
    QPushButton *btn_exit;
    QWidget *widget_2;
    QGridLayout *gridLayout_3;
    QLineEdit *le_Password;
    QLabel *label_8;
    QLabel *label_2;
    QLineEdit *le_Id_2;
    QLineEdit *le_Username;
    QLabel *label;

    void setupUi(QDialog *page_register)
    {
        if (page_register->objectName().isEmpty())
            page_register->setObjectName("page_register");
        page_register->resize(613, 433);
        page_register->setStyleSheet(QString::fromUtf8("#page_register{background-image: url(:/new/prefix1/1735392184998.jpg);}"));
        btn_register = new QPushButton(page_register);
        btn_register->setObjectName("btn_register");
        btn_register->setGeometry(QRect(10, 320, 287, 35));
        btn_register->setMinimumSize(QSize(82, 35));
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(11);
        font.setBold(true);
        btn_register->setFont(font);
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
        btn_exit = new QPushButton(page_register);
        btn_exit->setObjectName("btn_exit");
        btn_exit->setGeometry(QRect(310, 320, 286, 35));
        btn_exit->setMinimumSize(QSize(82, 35));
        btn_exit->setFont(font);
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
        widget_2 = new QWidget(page_register);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(10, 0, 584, 304));
        gridLayout_3 = new QGridLayout(widget_2);
        gridLayout_3->setObjectName("gridLayout_3");
        le_Password = new QLineEdit(widget_2);
        le_Password->setObjectName("le_Password");
        le_Password->setMinimumSize(QSize(0, 28));
        QFont font1;
        font1.setPointSize(12);
        le_Password->setFont(font1);
        le_Password->setMaxLength(20);

        gridLayout_3->addWidget(le_Password, 1, 1, 1, 1);

        label_8 = new QLabel(widget_2);
        label_8->setObjectName("label_8");
        QFont font2;
        font2.setPointSize(14);
        label_8->setFont(font2);

        gridLayout_3->addWidget(label_8, 2, 0, 1, 1);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName("label_2");
        label_2->setFont(font2);

        gridLayout_3->addWidget(label_2, 1, 0, 1, 1);

        le_Id_2 = new QLineEdit(widget_2);
        le_Id_2->setObjectName("le_Id_2");
        le_Id_2->setFont(font1);

        gridLayout_3->addWidget(le_Id_2, 2, 1, 1, 1);

        le_Username = new QLineEdit(widget_2);
        le_Username->setObjectName("le_Username");
        le_Username->setMinimumSize(QSize(0, 28));
        le_Username->setFont(font1);
        le_Username->setMaxLength(20);

        gridLayout_3->addWidget(le_Username, 0, 1, 1, 1);

        label = new QLabel(widget_2);
        label->setObjectName("label");
        label->setFont(font2);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);


        retranslateUi(page_register);

        QMetaObject::connectSlotsByName(page_register);
    } // setupUi

    void retranslateUi(QDialog *page_register)
    {
        page_register->setWindowTitle(QCoreApplication::translate("page_register", "Dialog", nullptr));
        btn_register->setText(QCoreApplication::translate("page_register", "\344\277\235\345\255\230", nullptr));
        btn_exit->setText(QCoreApplication::translate("page_register", "\345\217\226\346\266\210", nullptr));
        le_Password->setPlaceholderText(QCoreApplication::translate("page_register", "\350\257\267\350\276\223\345\205\245\357\274\210\344\270\215\350\266\205\350\277\20720\344\275\215\357\274\211", nullptr));
        label_8->setText(QCoreApplication::translate("page_register", "\346\211\213\346\234\272\345\217\267", nullptr));
        label_2->setText(QCoreApplication::translate("page_register", "\345\257\206   \347\240\201", nullptr));
        le_Id_2->setPlaceholderText(QString());
        le_Username->setPlaceholderText(QCoreApplication::translate("page_register", "\350\257\267\350\276\223\345\205\245\357\274\210\344\270\215\350\266\205\350\277\20720\344\275\215\357\274\211", nullptr));
        label->setText(QCoreApplication::translate("page_register", "\347\224\250\346\210\267\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class page_register: public Ui_page_register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGE_REGISTER_H
