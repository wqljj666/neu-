#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include<QFileDialog>
#include<qlistwidget.h>
#include <sstream>
#include"beifen.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loginPage.show();
    auto f=[&](){
        this->show();
    };
    connect(&loginPage,&login::loginSuccessful,this,f);
    setupDomainTree(); // 初始化域名树
    ui->urlInput->setPlaceholderText("Enter a URL (e.g., https://www.example.com)");

    // 展开所有项（全量展示）
    ui->treeWidget->expandAll();
    ui->treeWidget->resizeColumnToContents(0); // 自动调整第一列宽度
    ui->treeWidget->resizeColumnToContents(1); // 自动调整第二列宽度
    ui->treeWidget->resizeColumnToContents(2); // 自动调整第三列宽度
    ui->treeWidget->resizeColumnToContents(3);//自动调整第四列宽度
    //treewidget_2
    ui->treeWidget_2->expandAll();
    ui->treeWidget_2->resizeColumnToContents(0); // 自动调整第一列宽度
    ui->treeWidget_2->resizeColumnToContents(1); // 自动调整第二列宽度
    ui->treeWidget_2->resizeColumnToContents(2); // 自动调整第三列宽度
    //treewidget_3
    ui->treeWidget_3->expandAll();
    ui->treeWidget_3->resizeColumnToContents(0); // 自动调整第一列宽度
    ui->treeWidget_3->resizeColumnToContents(1); // 自动调整第二列宽度
    ui->treeWidget_3->resizeColumnToContents(2); // 自动调整第三列宽度
    //treewidget_4
    ui->treeWidget_4->expandAll();
    ui->treeWidget_4->resizeColumnToContents(0); // 自动调整第一列宽度
    ui->treeWidget_4->resizeColumnToContents(1); // 自动调整第二列宽度
    ui->treeWidget_4->resizeColumnToContents(2); // 自动调整第三列宽度
    ui->comboBox->setMaxVisibleItems(ui->comboBox->count()+100);
    ui->lineEdit_3->show();
    ui->searchcomboBox_2->hide();
    ui->keyword->hide();
    ui->keyword_1->hide();
    ui->tuijian->hide();
    ui->robot->hide();
    ui->sure_6->hide();
    hide_verticalLayout_6();
    ui->dateTimeEdit->setDisplayFormat("yyyy-MM-dd H:mm");
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
    ui->searchcomboBox_3->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setupDomainTree() {
    // 假设ui->treeWidget是你的QTreeWidget
    ui->treeWidget->clear();
    ui->treeWidget_2->clear();
    ui->treeWidget_3->clear();
    ui->treeWidget_4->clear();
    dns.populateTreeWidget(ui->treeWidget,dns.root); // 调用populateTreeWidget填充树形控件
    dns.populateTreeWidget(ui->treeWidget_2,dns.root);
    dns.populateTreeWidget(ui->treeWidget_3,dns.root);
    dns.populateTreeWidget(ui->treeWidget_4,dns.root);
}
void MainWindow::deletenode(){
    domainPath=ui->lineEdit_4->text().toStdString();
    domainPath=dns.reverseTransformDomain(domainPath);
    qDebug()<<domainPath;
    dns.deleteDomain(domainPath);
    ui->treeWidget->clear();
    ui->treeWidget_2->clear();
    ui->treeWidget_3->clear();
    ui->treeWidget_4->clear();
    setupDomainTree();
}
//判断域名等级
std::string how_level(std::string fill_path){
    int index=0;
    for(int i=0;i<fill_path.size();i++){
        if(fill_path[i]=='/'){
            index++;
        }
    }
    switch(index){
    case 1:
        return "一级域";
    case 2:
        return "二级域";
    case 3:
        return "三级域";
    case 4:
        return "四级域";
    case 5:
        return "五级域";
    default:
        return "不合法";
    }
}
//工具函数
void MainWindow::hide_verticalLayout_6(){
    ui->father->hide();
    ui->father_name->hide();
    ui->my_name_name->hide();
    ui->myname->hide();
    ui->descritpion_name->hide();
    ui->descritpion->hide();
    ui->combpBox_name->hide();
    ui->comboBox->hide();
    ui->sure_2->hide();
    ui->keyword->hide();
    ui->keyword_1->hide();
    ui->tuijian->hide();
    ui->sure_6->hide();
    ui->searchcomboBox_3->hide();
}
void MainWindow::show_verticalLayout_6(){
    ui->father->show();
    ui->father_name->show();
    ui->my_name_name->show();
    ui->myname->show();
    ui->descritpion_name->show();
    ui->descritpion->show();
    ui->combpBox_name->show();
    ui->comboBox->show();
    ui->sure_2->show();
}
//插入
void MainWindow::insertnod(){
    std::string father=ui->father->text().toStdString();
    father=dns.reverseTransformDomain(father);
    qDebug()<<father;
    std::string myname=ui->myname->text().toStdString();
    if(myname==""){
        // 构造消息字符串
        QString message = QString("插入失败，域名不能为空！！！");
        // 使用 QMessageBox 显示信息弹窗
        QMessageBox::information(nullptr, "错误", message);
        return;
    }
    std::string check_path=father+'/'+myname;
    std::string mylevel=how_level(check_path);
    std::string descritpion=ui->descritpion->text().toStdString();
    std::string filed=ui->comboBox->currentText().toStdString();
    if(mylevel!="不合法"){
    dns.insertDomain(father,myname,mylevel,descritpion,filed);
    setupDomainTree();
    }else{
        // 构造消息字符串
        QString message = QString("插入失败，域名等级不合法！！！");
        // 使用 QMessageBox 显示信息弹窗
        QMessageBox::information(nullptr, "错误", message);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    insertnod();
}





void MainWindow::on_PB_lastPage_clicked()
{
    pagenum--;
    if(pagenum<0)
        pagenum=maxpage;
    ui->stackedWidget->setCurrentIndex(pagenum);
}


void MainWindow::on_PB_nextPage_clicked()
{
    pagenum++;
    if(pagenum>maxpage)
        pagenum=0;
    ui->stackedWidget->setCurrentIndex(pagenum);
}

//删除
void MainWindow::on_PB_delete_clicked()
{
    if(ui->lineEdit_4->text()==""||ui->lineEdit_4->text()=="root"){
        // 构造消息字符串
        QString message = QString("删除失败，你没有权限删除根目录！！！");
        // 使用 QMessageBox 显示信息弹窗
        QMessageBox::information(nullptr, "错误", message);
        return;
    }
     deletenode();
    setupDomainTree();
}

void MainWindow::on_searchBox_activated(int index)
{
    // 使用 switch-case 结构处理不同索引值
    switch (index) {
    case 0: {
        // 当选择第一个选项时执行的操作
        ui->lineEdit_3->show();
        ui->searchcomboBox_2->hide();
        break;
    }
    case 1: {
        // 当选择第二个选项时执行的操作
        ui->lineEdit_3->hide();
        ui->searchcomboBox_2->show();
        break;
    }
     case 2: {
         ui->lineEdit_3->show();
         ui->searchcomboBox_2->hide();
         break;
     }
     case 3:{
         ui->lineEdit_3->show();
         ui->searchcomboBox_2->hide();
         break;
     }
     default: {
         // 处理超出范围的索引（如果需要）
         QMessageBox::warning(this, "Warning", "选择了未知选项");
         qDebug() << "Selected an unknown option.";
         break;
     }
    }
}


void MainWindow::on_PB_search_clicked()
{
    QString Qusertext=ui->lineEdit_3->text();

    // 将 QString 转换为 std::string
    std::string usertext=Qusertext.toStdString();

    int index=ui->searchBox->currentIndex();
    // 使用 switch-case 结构处理不同索引值

    switch (index) {



    case 0: {
        // 当选择第一个选项时执行的操作
        //全网址查询
        usertext=dns.reverseTransformDomain(usertext);
        std::vector<DomainNode*> subdomains = dns.viewSubdomainsAtPath(usertext);
         // 清空表格内容
        ui-> tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);
        // 遍历返回的 vector 并将信息添加到 QTableWidget
        for (const auto& domain : subdomains) {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);

            // 创建 QTableWidgetItem 并设置每个字段的内容
            QTableWidgetItem* itemName = new QTableWidgetItem(QString::fromStdString(dns.getFullPath(domain)));
            QTableWidgetItem* itemType = new QTableWidgetItem(QString::fromStdString(domain->type));
            QTableWidgetItem* itemDesc = new QTableWidgetItem(QString::fromStdString(domain->description));
            QTableWidgetItem* itemField = new QTableWidgetItem(QString::fromStdString(domain->filed));

            // 将 QTableWidgetItem 添加到对应的列
            ui->tableWidget->setItem(row, 0, itemName);
            ui->tableWidget->setItem(row, 1, itemType);
            ui->tableWidget->setItem(row, 2, itemDesc);
            ui->tableWidget->setItem(row, 3, itemField);

    }
     break;}

    case 1: {

        // 当选择第一个选项时执行的操作

        std::string usertext_2=ui->searchcomboBox_2->currentText().toStdString();
        std::vector<DomainNode*> subdomains = dns.searchDomainKeyword(usertext_2);

        // 清空表格内容
        ui-> tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);

        // 遍历返回的 vector 并将信息添加到 QTableWidget
        for (const auto& domain : subdomains) {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);

            // 创建 QTableWidgetItem 并设置每个字段的内容
            QTableWidgetItem* itemName = new QTableWidgetItem(QString::fromStdString(dns.getFullPath(domain)));
            QTableWidgetItem* itemType = new QTableWidgetItem(QString::fromStdString(domain->type));
            QTableWidgetItem* itemDesc = new QTableWidgetItem(QString::fromStdString(domain->description));
            QTableWidgetItem* itemField = new QTableWidgetItem(QString::fromStdString(domain->filed));

            // 将 QTableWidgetItem 添加到对应的列
            ui->tableWidget->setItem(row, 0, itemName);
            ui->tableWidget->setItem(row, 1, itemType);
            ui->tableWidget->setItem(row, 2, itemDesc);
            ui->tableWidget->setItem(row, 3, itemField);

        }
        break;
    }

     case 2: {
         // 当选择第三个选项时执行的操作
         std::vector<DomainNode*> subdomains =dns.searchDomainKeyword_descritpion(usertext);
         // 清空表格内容
         ui-> tableWidget->clearContents();
         ui->tableWidget->setRowCount(0);

         // 遍历返回的 vector 并将信息添加到 QTableWidget
         for (const auto& domain : subdomains) {
             int row = ui->tableWidget->rowCount();
             ui->tableWidget->insertRow(row);

             // 创建 QTableWidgetItem 并设置每个字段的内容
             QTableWidgetItem* itemName = new QTableWidgetItem(QString::fromStdString(dns.getFullPath(domain)));
             QTableWidgetItem* itemType = new QTableWidgetItem(QString::fromStdString(domain->type));
             QTableWidgetItem* itemDesc = new QTableWidgetItem(QString::fromStdString(domain->description));
             QTableWidgetItem* itemField = new QTableWidgetItem(QString::fromStdString(domain->filed));
             // 将 QTableWidgetItem 添加到对应的列
             ui->tableWidget->setItem(row, 0, itemName);
             ui->tableWidget->setItem(row, 1, itemType);
             ui->tableWidget->setItem(row, 2, itemDesc);
             ui->tableWidget->setItem(row, 3, itemField);

         }
         break;
     }
    case 3:{
        // 当选择第一个选项时执行的操作

        std::vector<DomainNode*> subdomains =dns.searchDomainKeyword_name(usertext);
        // 清空表格内容
        ui-> tableWidget->clearContents();
        ui->tableWidget->setRowCount(0);

        // 遍历返回的 vector 并将信息添加到 QTableWidget
        for (const auto& domain : subdomains) {
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);

            // 创建 QTableWidgetItem 并设置每个字段的内容
            QTableWidgetItem* itemName = new QTableWidgetItem(QString::fromStdString(dns.getFullPath(domain)));
            QTableWidgetItem* itemType = new QTableWidgetItem(QString::fromStdString(domain->type));
            QTableWidgetItem* itemDesc = new QTableWidgetItem(QString::fromStdString(domain->description));
            QTableWidgetItem* itemField = new QTableWidgetItem(QString::fromStdString(domain->filed));
            // 将 QTableWidgetItem 添加到对应的列
            ui->tableWidget->setItem(row, 0, itemName);
            ui->tableWidget->setItem(row, 1, itemType);
            ui->tableWidget->setItem(row, 2, itemDesc);
            ui->tableWidget->setItem(row, 3, itemField);

        }
        break;
    }
    // default: {
    //     // 处理超出范围的索引（如果需要）
    //     QMessageBox::warning(this, "Warning", "选择了未知选项");
    //     qDebug() << "Selected an unknown option.";
    //     break;
    // }

    }
}


void MainWindow::on_s_level_1_clicked()
{
    ui->listWidget->clear();
    std::vector<std::string>res;
    dns.statistics(res);
    for(int i=0;i<res.size();i++){
        QListWidgetItem *pItem = new QListWidgetItem(ui->listWidget);
        QString qstr2 = QString::fromStdString(res[i]);
        pItem->setText(qstr2);
        ui->listWidget->addItem(pItem);
    }
    res.clear();
}


void MainWindow::on_s_level_2_clicked()
{
    ui->listWidget->clear();
    std::vector<std::string>res;
    dns.statistics_2(res);
    for(int i=0;i<res.size();i++){
        QListWidgetItem *pItem = new QListWidgetItem(ui->listWidget);
        QString qstr2 = QString::fromStdString(res[i]);
        pItem->setText(qstr2);
        ui->listWidget->addItem(pItem);
    }
    res.clear();
}

// 函数定义
QString openFileDialog(QWidget *parent, const QString &caption, const QString &dir, const QString &filter)
{
    // 使用 QFileDialog::getOpenFileName 显示文件对话框并获取用户选择的文件路径
    return QFileDialog::getOpenFileName(parent, caption, dir, filter);
}
void MainWindow::on_searchBox_2_activated(int index)
{
    // 使用 switch-case 结构处理不同索引值
    switch (index) {
    case 0: {
        //手动输入
        show_verticalLayout_6();
        ui->robot->hide();
        ui->keyword->hide();
        ui->keyword_1->hide();
        ui->tuijian->hide();
        ui->searchcomboBox_3->hide();
        ui->sure_6->hide();
        setupDomainTree();
        break;
    }
    case 1: {
        // 文件操作
        hide_verticalLayout_6();
        ui->robot->hide();
        // 调用 openFileDialog 函数，传入适当的参数
        QString filePath = openFileDialog(this, "选择文件", QDir::homePath(), "文本文件 (*.txt);;所有文件 (*)");

        // 检查用户是否选择了文件（即返回值不是空字符串）
        if (!filePath.isEmpty()) {
            // 用户选择了文件，你可以在这里处理 filePath
            qDebug() << "Selected file:" << filePath;
        } else {
            // 用户取消了选择，或者没有选择任何文件
            qDebug() << "No file selected.";
        }
        std::string file=filePath.toStdString();
        dns.loadDomainDataFromFile(file);
        setupDomainTree();
        break;
    }
    case 2: {
        //ai链接
        show_verticalLayout_6();
        ui->keyword->hide();
        ui->keyword_1->hide();
        ui->tuijian->hide();
        ui->searchcomboBox_3->hide();
        ui->sure_6->hide();
        ui->robot->show();
        break;
    }
    case 3:{
        show_verticalLayout_6();
        ui->keyword->show();
        ui->keyword_1->show();
        ui->tuijian->show();
        ui->robot->hide();
        ui->sure_6->show();
        ui->searchcomboBox_3->show();
        break;
    }
    default: {
        // 处理超出范围的索引（如果需要）
        QMessageBox::warning(this, "Warning", "选择了未知选项");
        qDebug() << "Selected an unknown option.";
        break;
    }
    }
}


void MainWindow::on_select1_clicked()
{

}


void MainWindow::on_PB_modifyConfirm_clicked()
{
    std::string fill_path=ui->lineEdit_2->text().toStdString();
    fill_path=dns.reverseTransformDomain(fill_path);
    std::string descritpion=ui->des1->text().toStdString();
    std::string type=ui->comboBox_modify->currentText().toStdString();
    qDebug()<<fill_path<<"||"<<descritpion.c_str()<<"||"<<type.c_str();
    dns.modifyDomain(fill_path,"",descritpion,type);
    setupDomainTree();
}



void MainWindow::on_s_level_3_clicked()
{
    ui->listWidget->clear();
    std::vector<std::string>res;
    dns.statisticsAndVisualization(res);
    for(int i=0;i<res.size();i++){
        QListWidgetItem *pItem = new QListWidgetItem(ui->listWidget);
        QString qstr2 = QString::fromStdString(res[i]);
        pItem->setText(qstr2);
        ui->listWidget->addItem(pItem);
    }
    res.clear();
}


void MainWindow::on_s_level_4_clicked()
{
    ui->listWidget->clear();
    std::vector<std::string>res;
    dns.statisticsAndVisualization_2(res);
    for(int i=0;i<res.size();i++){
        QListWidgetItem *pItem = new QListWidgetItem(ui->listWidget);
        QString qstr2 = QString::fromStdString(res[i]);
        pItem->setText(qstr2);
        ui->listWidget->addItem(pItem);
    }
    res.clear();
}


void MainWindow::on_sure_1_clicked()
{
     insertnod();
}


void MainWindow::on_sure_2_clicked()
{
     insertnod();
}
//工具函数，看看能否注册
std::vector<std::string> splitString(const std::string& input, char delimiter) {
    std::vector<std::string> tokens; // 用于存储分割后的子字符串
    std::string token;               // 临时存储每个子字符串
    std::istringstream tokenStream(input); // 使用字符串流处理输入字符串

    // 按分隔符分割字符串
    while (std::getline(tokenStream, token, delimiter)) {
        if (!token.empty()) { // 忽略空字符串
            tokens.push_back(token);
        }
    }
    return tokens;
}
bool can_zhuce(std::string res,std::string st){
    std::vector<std::string>check=splitString(res,'/');
    for(int i=0;i<check.size();i++){
        if(check[i]==st){
            return false;
        }
    }
    return true;
}
void MainWindow::on_sure_6_clicked()
{

    std::string st=ui->keyword->text().toStdString();
    if(st==""){
        // 构造消息字符串
        QString message = QString("插入失败，关键字不能为空！！！");
        // 使用 QMessageBox 显示信息弹窗
        QMessageBox::information(nullptr, "错误", message);
        return;
    }
    std::vector<std::string>res;
    int level=ui->searchcomboBox_3->currentIndex()+1;
    qDebug()<<level;
    dns.keyword_shengchen(st,res,level);
    //再将结果输出到板子上面
    ui->tuijian->clear();
    for(int i=0;i<res.size();i++){
        QListWidgetItem *pItem = new QListWidgetItem(ui->tuijian);
        QString qstr2;
        //在这里进行一步筛选，看看是否可以注册(不能与祖先域名冲突，更不能已经注册)
        if(can_zhuce(res[i],st)&&dns.queryDomain(res[i]+'/'+st)==NULL){
           qstr2 = QString::fromStdString(res[i]+"/"+st+":可以注册");
            QFont font =pItem->font(); // 获取当前字体
            font.setBold(true);        // 设置字体加粗
            pItem->setFont(font);       // 应用新字体
        }else{
           qstr2 = QString::fromStdString(res[i]+"/"+st+":不可注册");
            QFont font =pItem->font(); // 获取当前字体
            font.setBold(false);        // 设置字体加粗
            pItem->setFont(font);       // 应用新字体
            pItem->setBackground(QColor(Qt::red));
        }
        pItem->setText(qstr2);
        ui->tuijian->addItem(pItem);
    }
    res.clear();
}





void MainWindow::on_sure_4_clicked()
{
    beifen=new class beifen;
    beifen->db(dns.db);
    beifen->show();
}


void MainWindow::on_sure_7_clicked()
{
    // 获取用户输入的网址
    QString url = ui->urlInput->text();

    // 检查网址是否为空
    if (url.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter a URL.");
        return;
    }

    // 如果用户没有输入协议（如 http:// 或 https://），默认添加 http://
    if (!url.startsWith("http://") && !url.startsWith("https://")) {
        url = "http://" + url;
    }

    // 使用 QDesktopServices 打开网址
    if (!QDesktopServices::openUrl(QUrl(url))) {
        QMessageBox::warning(this, "Error", "Failed to open the URL.");
    }
}

