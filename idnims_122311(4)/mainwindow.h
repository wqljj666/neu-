#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"domainmanagementsystem.h"
#include "login.h"
#include"beifen.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    domainmanagementsystem  dns;
    beifen* beifen;
    void setupDomainTree(); // 新增一个方法来设置域名树
    void deletenode();
    void insertnod();
    void hide_verticalLayout_6();
    void show_verticalLayout_6();
    std::string domainPath;
    ~MainWindow();

    int pagenum=0;
    int maxpage=6;

private slots:

    void on_searchBox_activated(int index=0);

    void on_pushButton_2_clicked();

    // void on_pushButton_3_clicked();

    void on_PB_lastPage_clicked();

    void on_PB_nextPage_clicked();

    void on_PB_delete_clicked();


    void on_PB_search_clicked();

    void on_s_level_1_clicked();

    void on_s_level_2_clicked();

    void on_searchBox_2_activated(int index);

    void on_select1_clicked();

    void on_PB_modifyConfirm_clicked();
    void on_s_level_3_clicked();

    void on_s_level_4_clicked();

    void on_sure_1_clicked();

    void on_sure_2_clicked();

    void on_sure_6_clicked();


    void on_sure_4_clicked();

    void on_sure_7_clicked();

private:
    Ui::MainWindow *ui;
    login loginPage; //登录
};
#endif // MAINWINDOW_H
