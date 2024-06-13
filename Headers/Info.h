#ifndef INFO_H
#define INFO_H

#include <QDialog>
#include "Headers/updatedialog.h"

class MainWindow; // Forward declaration
namespace Ui {
class Info;
}

class Info : public QDialog
{
    Q_OBJECT

public:
    explicit Info(MainWindow *parent = nullptr);
    ~Info();

private slots:
    void on_Home_clicked();

    void on_update_clicked();

private:
    Ui::Info *ui;
    MainWindow *mainWindowPtr;
    updateDialog *dialog;
};

#endif // INFO_H





