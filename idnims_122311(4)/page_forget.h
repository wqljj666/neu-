#ifndef PAGE_FORGET_H
#define PAGE_FORGET_H

#include <QDialog>

namespace Ui {
class page_forget;
}

class page_forget : public QDialog
{
    Q_OBJECT

public:
    explicit page_forget(QWidget *parent = nullptr);
    ~page_forget();

private slots:
    void on_btn_save_clicked();

    void on_btn_exit_clicked();

private:
    Ui::page_forget *ui;
};

#endif // PAGE_FORGET_H
