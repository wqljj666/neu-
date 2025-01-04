/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_6;
    QLabel *label_20;
    QPushButton *sure_4;
    QPushButton *sure_5;
    QListWidget *listWidget_2;
    QWidget *page_3;
    QLabel *label_2;
    QTreeWidget *treeWidget_2;
    QPushButton *sure_7;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *keyword_2;
    QLineEdit *urlInput;
    QWidget *page;
    QTreeWidget *treeWidget;
    QLabel *label_3;
    QLabel *robot;
    QComboBox *comboBox;
    QPushButton *sure_2;
    QLineEdit *descritpion;
    QLabel *descritpion_name;
    QLabel *my_name_name;
    QLineEdit *myname;
    QLineEdit *father;
    QLabel *father_name;
    QLabel *combpBox_name;
    QComboBox *searchBox_2;
    QListWidget *tuijian;
    QLabel *keyword_1;
    QLineEdit *keyword;
    QPushButton *sure_6;
    QComboBox *searchcomboBox_3;
    QWidget *page_2;
    QTreeWidget *treeWidget_3;
    QLabel *label_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_4;
    QPushButton *PB_delete;
    QWidget *page_4;
    QLabel *label_5;
    QTreeWidget *treeWidget_4;
    QPushButton *PB_modifyConfirm;
    QLineEdit *lineEdit_2;
    QLabel *label_8;
    QLabel *label_des;
    QLineEdit *des1;
    QComboBox *comboBox_modify;
    QLabel *label_9;
    QWidget *page_5;
    QLabel *label_6;
    QTableWidget *tableWidget;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QComboBox *searchBox;
    QLineEdit *lineEdit_3;
    QComboBox *searchcomboBox_2;
    QPushButton *PB_search;
    QWidget *page_7;
    QLabel *label_7;
    QWidget *show_table;
    QListWidget *listWidget;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QPushButton *s_level_1;
    QPushButton *s_level_2;
    QPushButton *s_level_3;
    QPushButton *s_level_4;
    QLabel *label;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QPushButton *PB_lastPage;
    QPushButton *PB_nextPage;
    QDateTimeEdit *dateTimeEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1058, 608);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("#centralwidget{background-image: url(:/new/prefix1/loginbackground.jpeg);}"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(30, 70, 931, 521));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        page_6->setStyleSheet(QString::fromUtf8(""));
        label_20 = new QLabel(page_6);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(160, 10, 577, 61));
        label_20->setStyleSheet(QString::fromUtf8("font: 700 24pt \"Microsoft YaHei UI\";"));
        sure_4 = new QPushButton(page_6);
        sure_4->setObjectName("sure_4");
        sure_4->setGeometry(QRect(730, 420, 191, 20));
        sure_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        sure_5 = new QPushButton(page_6);
        sure_5->setObjectName("sure_5");
        sure_5->setGeometry(QRect(730, 390, 191, 20));
        sure_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        listWidget_2 = new QListWidget(page_6);
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget_2);
        __qlistwidgetitem->setTextAlignment(Qt::AlignCenter);
        __qlistwidgetitem->setFont(font);
        __qlistwidgetitem->setBackground(brush);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setGeometry(QRect(60, 90, 581, 341));
        stackedWidget->addWidget(page_6);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        page_3->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(page_3);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(-10, 10, 641, 21));
        QFont font1;
        font1.setPointSize(17);
        font1.setBold(true);
        label_2->setFont(font1);
        treeWidget_2 = new QTreeWidget(page_3);
        treeWidget_2->setObjectName("treeWidget_2");
        treeWidget_2->setGeometry(QRect(20, 70, 891, 361));
        sure_7 = new QPushButton(page_3);
        sure_7->setObjectName("sure_7");
        sure_7->setGeometry(QRect(740, 40, 82, 21));
        sure_7->setMinimumSize(QSize(82, 0));
        sure_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        widget = new QWidget(page_3);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(241, 41, 491, 21));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        keyword_2 = new QLabel(widget);
        keyword_2->setObjectName("keyword_2");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft New Tai Lue")});
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        keyword_2->setFont(font2);
        keyword_2->setAutoFillBackground(false);
        keyword_2->setStyleSheet(QString::fromUtf8("color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgba(0, 255, 255, 250);\n"
"background-color: rgb(251, 212, 231);\n"
"font: 14qt \"Microsoft New Tai Lue\";"));

        horizontalLayout_2->addWidget(keyword_2);

        urlInput = new QLineEdit(widget);
        urlInput->setObjectName("urlInput");

        horizontalLayout_2->addWidget(urlInput);

        stackedWidget->addWidget(page_3);
        page = new QWidget();
        page->setObjectName("page");
        page->setStyleSheet(QString::fromUtf8(""));
        treeWidget = new QTreeWidget(page);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(10, 50, 531, 471));
        label_3 = new QLabel(page);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 10, 531, 31));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Microsoft New Tai Lue")});
        font3.setPointSize(20);
        font3.setBold(false);
        font3.setItalic(false);
        label_3->setFont(font3);
        label_3->setStyleSheet(QString::fromUtf8("color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgba(0, 255, 255, 250);\n"
"background-color: rgb(251, 212, 231);\n"
"font: 20pt \"Microsoft New Tai Lue\";"));
        robot = new QLabel(page);
        robot->setObjectName("robot");
        robot->setGeometry(QRect(830, 50, 81, 111));
        robot->setStyleSheet(QString::fromUtf8(" \n"
"background-color: rgb(251, 212, 231);\n"
"border-color: rgb(0, 255, 255);"));
        robot->setOpenExternalLinks(true);
        comboBox = new QComboBox(page);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(619, 190, 201, 22));
        sure_2 = new QPushButton(page);
        sure_2->setObjectName("sure_2");
        sure_2->setGeometry(QRect(570, 230, 251, 20));
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
        descritpion = new QLineEdit(page);
        descritpion->setObjectName("descritpion");
        descritpion->setGeometry(QRect(620, 160, 201, 22));
        descritpion_name = new QLabel(page);
        descritpion_name->setObjectName("descritpion_name");
        descritpion_name->setGeometry(QRect(573, 160, 41, 21));
        descritpion_name->setFont(font2);
        descritpion_name->setStyleSheet(QString::fromUtf8("color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgba(0, 255, 255, 250);\n"
"background-color: rgb(251, 212, 231);\n"
"font: 14qt \"Microsoft New Tai Lue\";"));
        my_name_name = new QLabel(page);
        my_name_name->setObjectName("my_name_name");
        my_name_name->setGeometry(QRect(573, 132, 41, 21));
        my_name_name->setFont(font2);
        my_name_name->setStyleSheet(QString::fromUtf8("color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgba(0, 255, 255, 250);\n"
"background-color: rgb(251, 212, 231);\n"
"font: 14qt \"Microsoft New Tai Lue\";"));
        myname = new QLineEdit(page);
        myname->setObjectName("myname");
        myname->setGeometry(QRect(620, 132, 201, 22));
        father = new QLineEdit(page);
        father->setObjectName("father");
        father->setGeometry(QRect(620, 104, 201, 22));
        father_name = new QLabel(page);
        father_name->setObjectName("father_name");
        father_name->setGeometry(QRect(573, 104, 41, 21));
        father_name->setFont(font2);
        father_name->setAutoFillBackground(false);
        father_name->setStyleSheet(QString::fromUtf8("color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgba(0, 255, 255, 250);\n"
"background-color: rgb(251, 212, 231);\n"
"font: 14qt \"Microsoft New Tai Lue\";"));
        combpBox_name = new QLabel(page);
        combpBox_name->setObjectName("combpBox_name");
        combpBox_name->setGeometry(QRect(572, 190, 41, 21));
        combpBox_name->setFont(font2);
        combpBox_name->setStyleSheet(QString::fromUtf8("color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgba(0, 255, 255, 250);\n"
"background-color: rgb(251, 212, 231);\n"
"font: 14qt \"Microsoft New Tai Lue\";"));
        searchBox_2 = new QComboBox(page);
        searchBox_2->addItem(QString());
        searchBox_2->addItem(QString());
        searchBox_2->addItem(QString());
        searchBox_2->addItem(QString());
        searchBox_2->setObjectName("searchBox_2");
        searchBox_2->setGeometry(QRect(580, 50, 241, 21));
        tuijian = new QListWidget(page);
        tuijian->setObjectName("tuijian");
        tuijian->setGeometry(QRect(560, 280, 341, 221));
        keyword_1 = new QLabel(page);
        keyword_1->setObjectName("keyword_1");
        keyword_1->setGeometry(QRect(570, 80, 41, 20));
        keyword_1->setFont(font2);
        keyword_1->setAutoFillBackground(false);
        keyword_1->setStyleSheet(QString::fromUtf8("color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgba(0, 255, 255, 250);\n"
"background-color: rgb(251, 212, 231);\n"
"font: 14qt \"Microsoft New Tai Lue\";"));
        keyword = new QLineEdit(page);
        keyword->setObjectName("keyword");
        keyword->setGeometry(QRect(620, 80, 151, 20));
        sure_6 = new QPushButton(page);
        sure_6->setObjectName("sure_6");
        sure_6->setGeometry(QRect(770, 80, 82, 21));
        sure_6->setMinimumSize(QSize(82, 0));
        sure_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        searchcomboBox_3 = new QComboBox(page);
        searchcomboBox_3->addItem(QString());
        searchcomboBox_3->addItem(QString());
        searchcomboBox_3->addItem(QString());
        searchcomboBox_3->addItem(QString());
        searchcomboBox_3->addItem(QString());
        searchcomboBox_3->setObjectName("searchcomboBox_3");
        searchcomboBox_3->setGeometry(QRect(560, 250, 341, 20));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        treeWidget_3 = new QTreeWidget(page_2);
        treeWidget_3->setObjectName("treeWidget_3");
        treeWidget_3->setGeometry(QRect(0, 0, 471, 511));
        label_4 = new QLabel(page_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(480, 0, 281, 31));
        label_4->setFont(font3);
        label_4->setStyleSheet(QString::fromUtf8("color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgba(0, 255, 255, 250);\n"
"background-color: rgb(251, 212, 231);\n"
"font: 20pt \"Microsoft New Tai Lue\";"));
        layoutWidget = new QWidget(page_2);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(480, 40, 281, 50));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_4 = new QLineEdit(layoutWidget);
        lineEdit_4->setObjectName("lineEdit_4");

        verticalLayout->addWidget(lineEdit_4);

        PB_delete = new QPushButton(layoutWidget);
        PB_delete->setObjectName("PB_delete");
        PB_delete->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayout->addWidget(PB_delete);

        stackedWidget->addWidget(page_2);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        page_4->setStyleSheet(QString::fromUtf8(""));
        label_5 = new QLabel(page_4);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 0, 481, 31));
        label_5->setFont(font3);
        label_5->setStyleSheet(QString::fromUtf8("color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgba(0, 255, 255, 250);\n"
"background-color: rgb(251, 212, 231);\n"
"font: 20pt \"Microsoft New Tai Lue\";"));
        treeWidget_4 = new QTreeWidget(page_4);
        treeWidget_4->setObjectName("treeWidget_4");
        treeWidget_4->setGeometry(QRect(1, 41, 491, 471));
        PB_modifyConfirm = new QPushButton(page_4);
        PB_modifyConfirm->setObjectName("PB_modifyConfirm");
        PB_modifyConfirm->setGeometry(QRect(531, 170, 281, 20));
        PB_modifyConfirm->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        lineEdit_2 = new QLineEdit(page_4);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(614, 52, 191, 22));
        label_8 = new QLabel(page_4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(532, 52, 81, 21));
        label_8->setStyleSheet(QString::fromUtf8("color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgba(0, 255, 255, 250);\n"
"background-color: rgb(251, 212, 231);\n"
"font: 15pt \"Microsoft New Tai Lue\";"));
        label_des = new QLabel(page_4);
        label_des->setObjectName("label_des");
        label_des->setGeometry(QRect(532, 93, 81, 21));
        label_des->setStyleSheet(QString::fromUtf8("color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgba(0, 255, 255, 250);\n"
"background-color: rgb(251, 212, 231);\n"
"font: 15pt \"Microsoft New Tai Lue\";"));
        des1 = new QLineEdit(page_4);
        des1->setObjectName("des1");
        des1->setGeometry(QRect(616, 93, 191, 22));
        comboBox_modify = new QComboBox(page_4);
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->addItem(QString());
        comboBox_modify->setObjectName("comboBox_modify");
        comboBox_modify->setGeometry(QRect(616, 134, 191, 21));
        label_9 = new QLabel(page_4);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(532, 134, 81, 21));
        label_9->setStyleSheet(QString::fromUtf8("color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgba(0, 255, 255, 250);\n"
"background-color: rgb(251, 212, 231);\n"
"font: 15pt \"Microsoft New Tai Lue\";"));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        page_5->setStyleSheet(QString::fromUtf8(""));
        label_6 = new QLabel(page_5);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(1, -3, 441, 31));
        label_6->setFont(font3);
        label_6->setStyleSheet(QString::fromUtf8("color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgba(0, 255, 255, 250);\n"
"background-color: rgb(251, 212, 231);\n"
"font: 20pt \"Microsoft New Tai Lue\";"));
        tableWidget = new QTableWidget(page_5);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 30, 451, 481));
        tableWidget->setLineWidth(0);
        layoutWidget1 = new QWidget(page_5);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(460, 40, 461, 251));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        searchBox = new QComboBox(layoutWidget1);
        searchBox->addItem(QString());
        searchBox->addItem(QString());
        searchBox->addItem(QString());
        searchBox->addItem(QString());
        searchBox->setObjectName("searchBox");

        verticalLayout_3->addWidget(searchBox);

        lineEdit_3 = new QLineEdit(layoutWidget1);
        lineEdit_3->setObjectName("lineEdit_3");

        verticalLayout_3->addWidget(lineEdit_3);

        searchcomboBox_2 = new QComboBox(layoutWidget1);
        searchcomboBox_2->addItem(QString());
        searchcomboBox_2->addItem(QString());
        searchcomboBox_2->addItem(QString());
        searchcomboBox_2->addItem(QString());
        searchcomboBox_2->addItem(QString());
        searchcomboBox_2->setObjectName("searchcomboBox_2");

        verticalLayout_3->addWidget(searchcomboBox_2);

        PB_search = new QPushButton(layoutWidget1);
        PB_search->setObjectName("PB_search");
        PB_search->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayout_3->addWidget(PB_search);

        stackedWidget->addWidget(page_5);
        page_7 = new QWidget();
        page_7->setObjectName("page_7");
        page_7->setStyleSheet(QString::fromUtf8(""));
        label_7 = new QLabel(page_7);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 0, 931, 31));
        label_7->setFont(font3);
        label_7->setStyleSheet(QString::fromUtf8("color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgba(0, 255, 255, 250);\n"
"background-color: rgb(251, 212, 231);\n"
"font: 20pt \"Microsoft New Tai Lue\";"));
        show_table = new QWidget(page_7);
        show_table->setObjectName("show_table");
        show_table->setGeometry(QRect(180, 70, 631, 401));
        listWidget = new QListWidget(show_table);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(0, 0, 601, 371));
        layoutWidget2 = new QWidget(page_7);
        layoutWidget2->setObjectName("layoutWidget2");
        layoutWidget2->setGeometry(QRect(20, 40, 141, 441));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        s_level_1 = new QPushButton(layoutWidget2);
        s_level_1->setObjectName("s_level_1");
        s_level_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayout_2->addWidget(s_level_1);

        s_level_2 = new QPushButton(layoutWidget2);
        s_level_2->setObjectName("s_level_2");
        s_level_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayout_2->addWidget(s_level_2);

        s_level_3 = new QPushButton(layoutWidget2);
        s_level_3->setObjectName("s_level_3");
        s_level_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayout_2->addWidget(s_level_3);

        s_level_4 = new QPushButton(layoutWidget2);
        s_level_4->setObjectName("s_level_4");
        s_level_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        verticalLayout_2->addWidget(s_level_4);

        stackedWidget->addWidget(page_7);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(36, 20, 581, 41));
        label->setStyleSheet(QString::fromUtf8("color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgba(0, 255, 255, 250);\n"
"background-color: rgb(251, 212, 231);\n"
"font: 25pt \"Microsoft New Tai Lue\";"));
        layoutWidget3 = new QWidget(centralwidget);
        layoutWidget3->setObjectName("layoutWidget3");
        layoutWidget3->setGeometry(QRect(790, 40, 172, 22));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        PB_lastPage = new QPushButton(layoutWidget3);
        PB_lastPage->setObjectName("PB_lastPage");
        PB_lastPage->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(PB_lastPage);

        PB_nextPage = new QPushButton(layoutWidget3);
        PB_nextPage->setObjectName("PB_nextPage");
        PB_nextPage->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(PB_nextPage);

        dateTimeEdit = new QDateTimeEdit(centralwidget);
        dateTimeEdit->setObjectName("dateTimeEdit");
        dateTimeEdit->setGeometry(QRect(790, 20, 171, 21));
        dateTimeEdit->setReadOnly(true);
        dateTimeEdit->setButtonSymbols(QAbstractSpinBox::ButtonSymbols::NoButtons);
        dateTimeEdit->setAccelerated(false);
        dateTimeEdit->setProperty("showGroupSeparator", QVariant(true));
        dateTimeEdit->setDate(QDate(2000, 1, 2));
        dateTimeEdit->setCalendarPopup(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1058, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\346\254\242\350\277\216\346\235\245\345\210\260\344\272\222\350\201\224\347\275\221\345\237\237\345\220\215\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237\357\274\201", nullptr));
        sure_4->setText(QCoreApplication::translate("MainWindow", " \346\225\260\346\215\256\345\244\207\344\273\275", nullptr));
        sure_5->setText(QCoreApplication::translate("MainWindow", " \344\275\277\347\224\250\350\257\264\346\230\216", nullptr));

        const bool __sortingEnabled = listWidget_2->isSortingEnabled();
        listWidget_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_2->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", " \345\267\245\344\275\234\346\227\245\345\277\227", nullptr));
        listWidget_2->setSortingEnabled(__sortingEnabled);

        label_2->setText(QCoreApplication::translate("MainWindow", "                                                                      1\343\200\201\345\205\250\351\207\217\345\261\225\347\244\272", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget_2->headerItem();
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("MainWindow", "\351\242\206\345\237\237", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("MainWindow", "\346\217\217\350\277\260", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "\347\261\273\345\236\213", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "\345\237\237\345\220\215", nullptr));
        sure_7->setText(QCoreApplication::translate("MainWindow", " \346\220\234\347\264\242", nullptr));
        keyword_2->setText(QCoreApplication::translate("MainWindow", " \347\275\221\345\235\200\346\220\234\347\264\242\346\241\206\357\274\232", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->headerItem();
        ___qtreewidgetitem1->setText(3, QCoreApplication::translate("MainWindow", "\351\242\206\345\237\237", nullptr));
        ___qtreewidgetitem1->setText(2, QCoreApplication::translate("MainWindow", "\346\217\217\350\277\260", nullptr));
        ___qtreewidgetitem1->setText(1, QCoreApplication::translate("MainWindow", "\347\261\273\345\236\213", nullptr));
        ___qtreewidgetitem1->setText(0, QCoreApplication::translate("MainWindow", "\345\237\237\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "                                    2\343\200\201\345\210\233\345\273\272\345\237\237\345\220\215", nullptr));
        robot->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><img src=\":/new/prefix1/QQ20241226-201917.png\"/></p><p align=\"center\"><a href=\"https://webnames-2024.streamlit.app/\"><span style=\" text-decoration: underline; color:#007af4;\">\347\275\221\347\273\234\345\237\237\345\220\215\345\212\251\346\211\213</span></a></p></body></html>", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\347\275\221\347\273\234", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\346\225\231\350\202\262", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\347\247\221\346\212\200", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\347\244\276\344\272\244", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "\345\225\206\345\212\241", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "\345\271\277\345\221\212", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("MainWindow", "\345\250\261\344\271\220", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("MainWindow", "\347\224\265\345\225\206", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("MainWindow", "\344\272\221\350\256\241\347\256\227", nullptr));
        comboBox->setItemText(10, QCoreApplication::translate("MainWindow", "\345\212\236\345\205\254", nullptr));
        comboBox->setItemText(11, QCoreApplication::translate("MainWindow", "\345\274\200\345\217\221", nullptr));
        comboBox->setItemText(12, QCoreApplication::translate("MainWindow", "\345\215\232\345\256\242", nullptr));
        comboBox->setItemText(13, QCoreApplication::translate("MainWindow", "\350\256\276\350\256\241", nullptr));
        comboBox->setItemText(14, QCoreApplication::translate("MainWindow", "\351\200\232\344\277\241", nullptr));
        comboBox->setItemText(15, QCoreApplication::translate("MainWindow", "\344\272\221\345\202\250\345\255\230", nullptr));
        comboBox->setItemText(16, QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\347\256\241\347\220\206", nullptr));
        comboBox->setItemText(17, QCoreApplication::translate("MainWindow", "\345\256\211\345\205\250", nullptr));
        comboBox->setItemText(18, QCoreApplication::translate("MainWindow", "\347\275\221\347\273\234\345\256\211\345\205\250", nullptr));
        comboBox->setItemText(19, QCoreApplication::translate("MainWindow", "\351\237\263\344\271\220", nullptr));
        comboBox->setItemText(20, QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221", nullptr));
        comboBox->setItemText(21, QCoreApplication::translate("MainWindow", "\346\224\257\344\273\230", nullptr));
        comboBox->setItemText(22, QCoreApplication::translate("MainWindow", "\345\215\217\344\275\234", nullptr));
        comboBox->setItemText(23, QCoreApplication::translate("MainWindow", "\344\274\232\350\256\256", nullptr));
        comboBox->setItemText(24, QCoreApplication::translate("MainWindow", "\346\227\205\350\241\214", nullptr));
        comboBox->setItemText(25, QCoreApplication::translate("MainWindow", "\347\245\250\345\212\241", nullptr));
        comboBox->setItemText(26, QCoreApplication::translate("MainWindow", "\345\233\242\350\264\255", nullptr));
        comboBox->setItemText(27, QCoreApplication::translate("MainWindow", "\346\221\204\345\275\261", nullptr));
        comboBox->setItemText(28, QCoreApplication::translate("MainWindow", "\347\224\237\346\264\273", nullptr));
        comboBox->setItemText(29, QCoreApplication::translate("MainWindow", "\351\227\256\347\255\224", nullptr));
        comboBox->setItemText(30, QCoreApplication::translate("MainWindow", "\346\226\260\351\227\273", nullptr));
        comboBox->setItemText(31, QCoreApplication::translate("MainWindow", "\345\274\200\346\272\220\350\275\257\344\273\266", nullptr));
        comboBox->setItemText(32, QCoreApplication::translate("MainWindow", "\347\275\221\347\273\234\345\237\272\347\241\200\350\256\276\346\226\275", nullptr));
        comboBox->setItemText(33, QCoreApplication::translate("MainWindow", "\345\214\273\345\255\246\347\240\224\347\251\266", nullptr));
        comboBox->setItemText(34, QCoreApplication::translate("MainWindow", "\347\211\210\346\235\203\350\256\270\345\217\257", nullptr));
        comboBox->setItemText(35, QCoreApplication::translate("MainWindow", "\345\207\272\347\211\210", nullptr));
        comboBox->setItemText(36, QCoreApplication::translate("MainWindow", "\345\200\241\345\257\274", nullptr));
        comboBox->setItemText(37, QCoreApplication::translate("MainWindow", "\351\232\220\347\247\201\344\277\235\346\212\244", nullptr));
        comboBox->setItemText(38, QCoreApplication::translate("MainWindow", "\347\233\264\346\222\255", nullptr));

        sure_2->setText(QCoreApplication::translate("MainWindow", " \347\241\256\345\256\232", nullptr));
        descritpion_name->setText(QCoreApplication::translate("MainWindow", " \346\217\217\350\277\260\357\274\232", nullptr));
        my_name_name->setText(QCoreApplication::translate("MainWindow", " \345\237\237\345\220\215\357\274\232", nullptr));
        father_name->setText(QCoreApplication::translate("MainWindow", " \347\210\266\345\237\237\345\220\215\357\274\232", nullptr));
        combpBox_name->setText(QCoreApplication::translate("MainWindow", " \347\261\273\345\236\213\357\274\232", nullptr));
        searchBox_2->setItemText(0, QCoreApplication::translate("MainWindow", " \346\211\213\345\212\250\350\276\223\345\205\245", nullptr));
        searchBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266\350\257\273\345\217\226", nullptr));
        searchBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "\351\232\217\346\234\272\347\224\237\346\210\220\357\274\210\351\227\256\351\227\256AI\357\274\211", nullptr));
        searchBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "\351\232\217\346\234\272\347\224\237\346\210\220", nullptr));

        keyword_1->setText(QCoreApplication::translate("MainWindow", " \345\205\263\351\224\256\345\255\227\357\274\232", nullptr));
        sure_6->setText(QCoreApplication::translate("MainWindow", " \346\220\234\347\264\242", nullptr));
        searchcomboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "\344\270\200\347\272\247\345\237\237", nullptr));
        searchcomboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "\344\272\214\347\272\247\345\237\237", nullptr));
        searchcomboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "\344\270\211\347\272\247\345\237\237", nullptr));
        searchcomboBox_3->setItemText(3, QCoreApplication::translate("MainWindow", "\345\233\233\347\272\247\345\237\237", nullptr));
        searchcomboBox_3->setItemText(4, QCoreApplication::translate("MainWindow", "\344\272\224\347\272\247\345\237\237", nullptr));

#if QT_CONFIG(tooltip)
        searchcomboBox_3->setToolTip(QCoreApplication::translate("MainWindow", "\350\257\245\346\250\241\345\274\217\344\270\213\351\200\211\346\213\251\345\237\237\345\220\215\347\255\211\347\272\247\346\237\245\346\211\276", nullptr));
#endif // QT_CONFIG(tooltip)
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget_3->headerItem();
        ___qtreewidgetitem2->setText(3, QCoreApplication::translate("MainWindow", "\351\242\206\345\237\237", nullptr));
        ___qtreewidgetitem2->setText(2, QCoreApplication::translate("MainWindow", "\346\217\217\350\277\260", nullptr));
        ___qtreewidgetitem2->setText(1, QCoreApplication::translate("MainWindow", "\347\261\273\345\236\213", nullptr));
        ___qtreewidgetitem2->setText(0, QCoreApplication::translate("MainWindow", "\345\237\237\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "     3\343\200\201\345\210\240\351\231\244\345\237\237\345\220\215", nullptr));
        lineEdit_4->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\276\223\345\205\245\346\203\263\345\210\240\351\231\244\347\232\204\347\275\221\345\235\200", nullptr));
        PB_delete->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\345\237\237\345\220\215", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "                               4\343\200\201\344\277\256\346\224\271\345\237\237\345\220\215", nullptr));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget_4->headerItem();
        ___qtreewidgetitem3->setText(3, QCoreApplication::translate("MainWindow", "\351\242\206\345\237\237", nullptr));
        ___qtreewidgetitem3->setText(2, QCoreApplication::translate("MainWindow", "\346\217\217\350\277\260", nullptr));
        ___qtreewidgetitem3->setText(1, QCoreApplication::translate("MainWindow", "\347\261\273\345\236\213", nullptr));
        ___qtreewidgetitem3->setText(0, QCoreApplication::translate("MainWindow", "\345\237\237\345\220\215", nullptr));
        PB_modifyConfirm->setText(QCoreApplication::translate("MainWindow", "\347\241\256\350\256\244\344\277\256\346\224\271", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", " \345\205\250\350\267\257\345\276\204\345\220\215\357\274\232", nullptr));
        label_des->setText(QCoreApplication::translate("MainWindow", " \346\217\217\350\277\260\357\274\232", nullptr));
        comboBox_modify->setItemText(0, QString());
        comboBox_modify->setItemText(1, QCoreApplication::translate("MainWindow", "\347\275\221\347\273\234", nullptr));
        comboBox_modify->setItemText(2, QCoreApplication::translate("MainWindow", "\346\225\231\350\202\262", nullptr));
        comboBox_modify->setItemText(3, QCoreApplication::translate("MainWindow", "\347\247\221\346\212\200", nullptr));
        comboBox_modify->setItemText(4, QCoreApplication::translate("MainWindow", "\347\244\276\344\272\244", nullptr));
        comboBox_modify->setItemText(5, QCoreApplication::translate("MainWindow", "\345\225\206\345\212\241", nullptr));
        comboBox_modify->setItemText(6, QCoreApplication::translate("MainWindow", "\345\271\277\345\221\212", nullptr));
        comboBox_modify->setItemText(7, QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        comboBox_modify->setItemText(8, QCoreApplication::translate("MainWindow", "\345\250\261\344\271\220", nullptr));
        comboBox_modify->setItemText(9, QCoreApplication::translate("MainWindow", "\347\224\265\345\225\206", nullptr));
        comboBox_modify->setItemText(10, QCoreApplication::translate("MainWindow", "\344\272\221\350\256\241\347\256\227", nullptr));
        comboBox_modify->setItemText(11, QCoreApplication::translate("MainWindow", "\345\212\236\345\205\254", nullptr));
        comboBox_modify->setItemText(12, QCoreApplication::translate("MainWindow", "\345\274\200\345\217\221", nullptr));
        comboBox_modify->setItemText(13, QCoreApplication::translate("MainWindow", "\345\215\232\345\256\242", nullptr));
        comboBox_modify->setItemText(14, QCoreApplication::translate("MainWindow", "\350\256\276\350\256\241", nullptr));
        comboBox_modify->setItemText(15, QCoreApplication::translate("MainWindow", "\351\200\232\344\277\241", nullptr));
        comboBox_modify->setItemText(16, QCoreApplication::translate("MainWindow", "\344\272\221\345\202\250\345\255\230", nullptr));
        comboBox_modify->setItemText(17, QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\347\256\241\347\220\206", nullptr));
        comboBox_modify->setItemText(18, QCoreApplication::translate("MainWindow", "\345\256\211\345\205\250", nullptr));
        comboBox_modify->setItemText(19, QCoreApplication::translate("MainWindow", "\347\275\221\347\273\234\345\256\211\345\205\250", nullptr));
        comboBox_modify->setItemText(20, QCoreApplication::translate("MainWindow", "\351\237\263\344\271\220", nullptr));
        comboBox_modify->setItemText(21, QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221", nullptr));
        comboBox_modify->setItemText(22, QCoreApplication::translate("MainWindow", "\346\224\257\344\273\230", nullptr));
        comboBox_modify->setItemText(23, QCoreApplication::translate("MainWindow", "\345\215\217\344\275\234", nullptr));
        comboBox_modify->setItemText(24, QCoreApplication::translate("MainWindow", "\344\274\232\350\256\256", nullptr));
        comboBox_modify->setItemText(25, QCoreApplication::translate("MainWindow", "\346\227\205\350\241\214", nullptr));
        comboBox_modify->setItemText(26, QCoreApplication::translate("MainWindow", "\347\245\250\345\212\241", nullptr));
        comboBox_modify->setItemText(27, QCoreApplication::translate("MainWindow", "\345\233\242\350\264\255", nullptr));
        comboBox_modify->setItemText(28, QCoreApplication::translate("MainWindow", "\346\221\204\345\275\261", nullptr));
        comboBox_modify->setItemText(29, QCoreApplication::translate("MainWindow", "\347\224\237\346\264\273", nullptr));
        comboBox_modify->setItemText(30, QCoreApplication::translate("MainWindow", "\351\227\256\347\255\224", nullptr));
        comboBox_modify->setItemText(31, QCoreApplication::translate("MainWindow", "\346\226\260\351\227\273", nullptr));
        comboBox_modify->setItemText(32, QCoreApplication::translate("MainWindow", "\345\274\200\346\272\220\350\275\257\344\273\266", nullptr));
        comboBox_modify->setItemText(33, QCoreApplication::translate("MainWindow", "\347\275\221\347\273\234\345\237\272\347\241\200\350\256\276\346\226\275", nullptr));
        comboBox_modify->setItemText(34, QCoreApplication::translate("MainWindow", "\345\214\273\345\255\246\347\240\224\347\251\266", nullptr));
        comboBox_modify->setItemText(35, QCoreApplication::translate("MainWindow", "\347\211\210\346\235\203\350\256\270\345\217\257", nullptr));
        comboBox_modify->setItemText(36, QCoreApplication::translate("MainWindow", "\345\207\272\347\211\210", nullptr));
        comboBox_modify->setItemText(37, QCoreApplication::translate("MainWindow", "\345\200\241\345\257\274", nullptr));
        comboBox_modify->setItemText(38, QCoreApplication::translate("MainWindow", "\351\232\220\347\247\201\344\277\235\346\212\244", nullptr));
        comboBox_modify->setItemText(39, QCoreApplication::translate("MainWindow", "\347\233\264\346\222\255", nullptr));

        label_9->setText(QCoreApplication::translate("MainWindow", " \347\261\273\345\236\213\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "                       5\343\200\201\346\220\234\347\264\242\345\237\237\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\345\205\250\345\237\237\345\220\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", " \346\217\217\350\277\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", " \347\261\273\345\236\213", nullptr));
        searchBox->setItemText(0, QCoreApplication::translate("MainWindow", "\347\275\221\345\235\200\346\220\234\347\264\242", nullptr));
        searchBox->setItemText(1, QCoreApplication::translate("MainWindow", "\347\255\211\347\272\247\346\220\234\347\264\242", nullptr));
        searchBox->setItemText(2, QCoreApplication::translate("MainWindow", "\346\217\217\350\277\260\346\220\234\347\264\242", nullptr));
        searchBox->setItemText(3, QCoreApplication::translate("MainWindow", "\345\205\263\351\224\256\345\255\227\346\220\234\347\264\242", nullptr));

        lineEdit_3->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\276\223\345\205\245\346\220\234\347\264\242\345\206\205\345\256\271", nullptr));
        searchcomboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "\344\270\200\347\272\247\345\237\237", nullptr));
        searchcomboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "\344\272\214\347\272\247\345\237\237", nullptr));
        searchcomboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "\344\270\211\347\272\247\345\237\237", nullptr));
        searchcomboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "\345\233\233\347\272\247\345\237\237", nullptr));
        searchcomboBox_2->setItemText(4, QCoreApplication::translate("MainWindow", "\344\272\224\347\272\247\345\237\237", nullptr));

#if QT_CONFIG(tooltip)
        searchcomboBox_2->setToolTip(QCoreApplication::translate("MainWindow", "\350\257\245\346\250\241\345\274\217\344\270\213\351\200\211\346\213\251\345\237\237\345\220\215\347\255\211\347\272\247\346\237\245\346\211\276", nullptr));
#endif // QT_CONFIG(tooltip)
        PB_search->setText(QCoreApplication::translate("MainWindow", "\346\220\234\347\264\242", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "                                                             6\343\200\201\345\237\237\345\220\215\347\233\270\345\205\263\347\273\237\350\256\241", nullptr));
        s_level_1->setText(QCoreApplication::translate("MainWindow", " \345\237\237\345\220\215\347\255\211\347\272\247", nullptr));
        s_level_2->setText(QCoreApplication::translate("MainWindow", " \351\242\206\345\237\237\347\273\237\350\256\241", nullptr));
        s_level_3->setText(QCoreApplication::translate("MainWindow", " \346\235\241\345\275\242\345\217\240\347\212\266\345\233\2761", nullptr));
        s_level_4->setText(QCoreApplication::translate("MainWindow", " \346\235\241\345\275\242\345\217\240\347\212\266\345\233\2762", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">     \344\272\222\350\201\224\347\275\221\345\237\237\345\220\215\344\277\241\346\201\257\347\256\241\347\220\206\347\263\273\347\273\237</span></p></body></html>", nullptr));
        PB_lastPage->setText(QCoreApplication::translate("MainWindow", "\344\270\212\344\270\200\351\241\265", nullptr));
        PB_nextPage->setText(QCoreApplication::translate("MainWindow", "\344\270\213\344\270\200\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
