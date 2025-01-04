#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // w.show();
    //w.dns.printDomainTree();
    //std::string str="baidu.com";
    //()<<w.dns.reverseTransformDomain(str);
   // w.dns.insertDomain("root","com","顶级域","网络域名","网络");
    //w.dns.insertDomain("root","org","顶级域","公益组织域名","网络");
    //w.dns.loadDomainDataFromFile("D:\\domain_data.txt");
    return a.exec();
}
