#ifndef MP3_H
#define MP3_H

#include <QDialog>
#include "qlistwidget.h"
#include <QMainWindow>
#include <QtMultimedia>
#include "mainwindow.h"
#include "flash.h"
#include <QTimer>

namespace Ui {
class Mp3;
}

class Mp3 : public QDialog
{
    Q_OBJECT

public:
    explicit Mp3(MainWindow *parent = nullptr);
    ~Mp3();

private:
    Ui::Mp3 *ui;
    Flash flashObj;
    QMediaPlayer *player;
    MainWindow *mainWindowPtr;
    QTimer *timer;
    int indx=0;

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void updateProgressBar(void);
    void on_horizontalSlider_sliderMoved(int position);
    void on_horizontalSlider_sliderReleased();
    void on_verticalSlider_valueChanged(int value);
    void updateList(void);
    void on_start_stop_button_clicked();
    void on_next_button_clicked();
    void on_previous_button_clicked();
    void on_repeat_button_clicked();
    void on_home_button_clicked();
};

#endif // MP3_H
