#ifndef DIALOG_H
#define DIALOG_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QDebug>


#include <QMediaDevices>
#include <QtCore>
#include <QWidget>
#include <QtMultimedia>
#include <QVideoWidget>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>



QT_BEGIN_NAMESPACE
namespace Ui {
class dialog;
}
QT_END_NAMESPACE

class dialog : public QMainWindow
{
    Q_OBJECT

public:
    dialog(QWidget *parent = nullptr);
    ~dialog();


private slots:
    void on_sliderProgrss_sliderMoved(int position);

    void on_sliderVolum_sliderMoved(int position);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_durationChanged(qint64 position);

    void on_positionChanged(qint64 position);
private:
    Ui::dialog *ui;
    QMediaPlayer *player ;
    QAudioOutput *audioOutput; // Add a member for QAudioOutput
};
#endif // DIALOG_H
