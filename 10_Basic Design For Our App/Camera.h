// Camera.h
#ifndef CAMERA_H
#define CAMERA_H

#include <QDialog>
#include <QCamera>
#include <QCameraViewfinder>
#include <QVBoxLayout>

class MainWindow; // Forward declaration

namespace Ui {
class Camera;
}

class Camera : public QDialog
{
    Q_OBJECT

public:
    explicit Camera(MainWindow *parent = nullptr); // Pass a pointer to MainWindow
    ~Camera();

    void startCamera();
    void stopCamera();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Camera *ui;
    QCamera *camera;
    QCameraViewfinder *viewfinder;
    MainWindow *mainWindowPtr; // Pointer to the MainWindow instance
};

#endif // CAMERA_H
