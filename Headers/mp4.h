#ifndef MP4_H
#define MP4_H

#include "QDialog"
#include "mainwindow.h"
#include "QMainWindow"
#include "QListWidget"
#include "QTimer"
#include "flash.h"
#include <QtMultimedia>
#include <QtMultimediaWidgets>


namespace Ui {
class Mp4;
}

class Mp4 : public QDialog
{
    Q_OBJECT

public:
    explicit Mp4(MainWindow *parent = nullptr);

    ~Mp4();

private slots:
    void on_home_button_clicked();
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void updateList(void);
    void on_back_button_clicked();
    void back(void);
    void play(void);
    void on_repeat_button_clicked();
    void on_start_pause_button_clicked();
    void on_seek_forward_button_clicked();
    void on_seek_backward_button_clicked();
    void on_verticalSlider_sound_valueChanged(int value);
    void on_horizontalSlider_duration_sliderMoved(int position);
    void on_horizontalSlider_duration_sliderReleased();
    void updateProgressBar();

    void handleMediaStatusChanged(QMediaPlayer::MediaStatus status);


    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::Mp4 *ui;
    Flash flashObj;
    MainWindow *mainWindowPtr;
    QMediaPlayer *player;
    QVideoWidget *video;
    QTimer *timer;
};

#endif // MP4_H
