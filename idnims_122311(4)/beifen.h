#ifndef BEIFEN_H
#define BEIFEN_H

#include <QWidget>
#include<QFileDialog>
#include <QMessageBox>
#include<QSqlDatabase>
namespace Ui {
class beifen;
}

class beifen : public QWidget
{
    Q_OBJECT

public:
    explicit beifen(QWidget *parent = nullptr);
    ~beifen();
    QString address;
    QString filename;
    QSqlDatabase db_1;    // Qt数据库连接
    void db(QSqlDatabase db){
        db_1=db;
    }
    void on_restore_clicked(QString filename_1);
private slots:
    void on_sure_2_clicked();

    void on_sure_3_clicked();

private:
    Ui::beifen *ui;
};

#endif // BEIFEN_H
