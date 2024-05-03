#ifndef POPNOTIFY_H
#define POPNOTIFY_H

#include <QDialog>
#include <QMediaPlayer>
namespace Ui {
class popNotify;
}

class popNotify : public QDialog
{
    Q_OBJECT

public:
    explicit popNotify(QWidget *parent = nullptr);
    ~popNotify();

private slots:
    void on_Stop_Sound_clicked();

private:
    Ui::popNotify *ui;
      QMediaPlayer *player;

};

#endif // POPNOTIFY_H
