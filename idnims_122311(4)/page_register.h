#ifndef PAGE_REGISTER_H
#define PAGE_REGISTER_H

#include <QDialog>

namespace Ui {
class page_register;
}

class page_register : public QDialog
{
    Q_OBJECT

public:
    explicit page_register(QWidget *parent = nullptr);
    ~page_register();

private slots:
    void on_btn_exit_clicked();

    void on_btn_register_clicked();

private:
    Ui::page_register *ui;
    void createTable();
};

#endif // PAGE_REGISTER_H
