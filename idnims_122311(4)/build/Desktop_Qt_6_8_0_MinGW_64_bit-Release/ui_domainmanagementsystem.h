/********************************************************************************
** Form generated from reading UI file 'domainmanagementsystem.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOMAINMANAGEMENTSYSTEM_H
#define UI_DOMAINMANAGEMENTSYSTEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_domainmanagementsystem
{
public:
    QTreeWidget *treeWidget;
    QPushButton *pushButton;
    QLineEdit *lineEdit;

    void setupUi(QWidget *domainmanagementsystem)
    {
        if (domainmanagementsystem->objectName().isEmpty())
            domainmanagementsystem->setObjectName("domainmanagementsystem");
        domainmanagementsystem->resize(899, 480);
        treeWidget = new QTreeWidget(domainmanagementsystem);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(20, 70, 601, 361));
        pushButton = new QPushButton(domainmanagementsystem);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(810, 160, 80, 18));
        lineEdit = new QLineEdit(domainmanagementsystem);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(650, 70, 211, 31));

        retranslateUi(domainmanagementsystem);

        QMetaObject::connectSlotsByName(domainmanagementsystem);
    } // setupUi

    void retranslateUi(QWidget *domainmanagementsystem)
    {
        domainmanagementsystem->setWindowTitle(QCoreApplication::translate("domainmanagementsystem", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("domainmanagementsystem", " ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class domainmanagementsystem: public Ui_domainmanagementsystem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOMAINMANAGEMENTSYSTEM_H
