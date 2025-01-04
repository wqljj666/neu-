/********************************************************************************
** Form generated from reading UI file 'beifen.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BEIFEN_H
#define UI_BEIFEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_beifen
{
public:
    QLabel *keyword_1;
    QLabel *keyword_2;
    QLineEdit *lineEdit;
    QPushButton *sure_2;
    QLabel *keyword_3;
    QPushButton *sure_3;

    void setupUi(QWidget *beifen)
    {
        if (beifen->objectName().isEmpty())
            beifen->setObjectName("beifen");
        beifen->resize(415, 178);
        keyword_1 = new QLabel(beifen);
        keyword_1->setObjectName("keyword_1");
        keyword_1->setGeometry(QRect(60, 70, 81, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft New Tai Lue")});
        font.setPointSize(15);
        font.setBold(false);
        font.setItalic(false);
        keyword_1->setFont(font);
        keyword_1->setAutoFillBackground(false);
        keyword_1->setStyleSheet(QString::fromUtf8("color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgba(0, 255, 255, 250);\n"
"background-color: rgb(251, 212, 231);\n"
"font: 14qt \"Microsoft New Tai Lue\";"));
        keyword_2 = new QLabel(beifen);
        keyword_2->setObjectName("keyword_2");
        keyword_2->setGeometry(QRect(130, 30, 171, 20));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft New Tai Lue")});
        font1.setPointSize(20);
        font1.setBold(false);
        font1.setItalic(false);
        keyword_2->setFont(font1);
        keyword_2->setAutoFillBackground(false);
        keyword_2->setStyleSheet(QString::fromUtf8("color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgba(0, 255, 255, 250);\n"
"background-color: rgb(251, 212, 231);\n"
"font: 14qt \"Microsoft New Tai Lue\";"));
        lineEdit = new QLineEdit(beifen);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(170, 70, 211, 20));
        sure_2 = new QPushButton(beifen);
        sure_2->setObjectName("sure_2");
        sure_2->setGeometry(QRect(170, 110, 211, 20));
        sure_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        keyword_3 = new QLabel(beifen);
        keyword_3->setObjectName("keyword_3");
        keyword_3->setGeometry(QRect(60, 110, 81, 21));
        keyword_3->setFont(font);
        keyword_3->setAutoFillBackground(false);
        keyword_3->setStyleSheet(QString::fromUtf8("color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgba(0, 255, 255, 250);\n"
"background-color: rgb(251, 212, 231);\n"
"font: 14qt \"Microsoft New Tai Lue\";"));
        sure_3 = new QPushButton(beifen);
        sure_3->setObjectName("sure_3");
        sure_3->setGeometry(QRect(60, 150, 321, 20));
        sure_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        retranslateUi(beifen);

        QMetaObject::connectSlotsByName(beifen);
    } // setupUi

    void retranslateUi(QWidget *beifen)
    {
        beifen->setWindowTitle(QCoreApplication::translate("beifen", "Form", nullptr));
        keyword_1->setText(QCoreApplication::translate("beifen", "\346\226\207\344\273\266\345\220\215\357\274\232", nullptr));
        keyword_2->setText(QCoreApplication::translate("beifen", "        \346\225\260\346\215\256\345\244\207\344\273\275", nullptr));
        sure_2->setText(QCoreApplication::translate("beifen", " \351\200\211\346\213\251", nullptr));
        keyword_3->setText(QCoreApplication::translate("beifen", " \345\255\230\345\202\250\345\234\260\345\235\200\357\274\232", nullptr));
        sure_3->setText(QCoreApplication::translate("beifen", " \347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class beifen: public Ui_beifen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BEIFEN_H
