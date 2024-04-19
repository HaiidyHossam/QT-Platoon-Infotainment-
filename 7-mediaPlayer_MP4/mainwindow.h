#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QtCore>
#include <QWidget>
#include <QtMultimedia>
#include <QMediaPlayer>
#include <QVideoWidget>

#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>


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
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
