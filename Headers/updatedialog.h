#ifndef UPDATEDIALOG_H
#define UPDATEDIALOG_H

#include <QDialog>

namespace Ui {
class updateDialog;
}

class updateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit updateDialog(QWidget *parent = nullptr);
    ~updateDialog();

private slots:
    void on_accept_button_clicked();

    void on_reject_button_clicked();

private:
    Ui::updateDialog *ui;
};

#endif // UPDATEDIALOG_H
