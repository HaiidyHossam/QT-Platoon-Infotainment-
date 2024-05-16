#define Prayer_page 1
#define Camera_page 2
#define Weather_page 3
#define Bluetooth_page 5
#define Settings_page 4
#define Info_page 6
#define Music_page 7
#define Video_page 8
#define Map_page 9
#define Gauge_page 10

#include "Headers/mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QDebug>
#include <QQuickWidget>
#include <QQuickItem>
#include "Headers/Camera.h"
#include "Headers/Weather.h"
#include "Headers/Settings.h"
#include "Headers/Info.h"
#include "Headers/Prayer.h"
#include "Headers/mp3.h"
#include "Headers/mp4.h"
#include "Headers/mqtt_connection.h"
//.............
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);

    this->setFixedSize(1024,600);
    //set as default page
    ui->FirstStack->setCurrentIndex(0);

    //connect mqtt broker
    Mqtt_connection *MqttCon = new Mqtt_connection("broker.hivemq.com",1883);


    /* set widget as stacked widget*/
    Camera *cameraWidget = new Camera(this);
    ui->FirstStack->insertWidget(Camera_page, cameraWidget);
    Weather *WeatherWidget = new Weather(this);
    ui->FirstStack->insertWidget(Weather_page, WeatherWidget);
    Settings *SettingsWidget = new Settings(this);
    ui->FirstStack->insertWidget(Settings_page, SettingsWidget);
    Bluetooth *BluetoothWidget=new Bluetooth(this);
    ui->FirstStack->insertWidget(Bluetooth_page, BluetoothWidget);
    Info *InfoWidget=new Info(this);
    ui->FirstStack->insertWidget(Info_page, InfoWidget);
    Prayer *prayerWidget = new Prayer(this);
    ui->FirstStack->insertWidget(Prayer_page, prayerWidget);
    Mp3 *MusicWidget = new Mp3(this);
    ui->FirstStack->insertWidget(Music_page, MusicWidget);
    Mp4 *VideoWidget = new Mp4(this);
    ui->FirstStack->insertWidget(Video_page, VideoWidget);



    /* set qml map widgets*/
    QQuickWidget *MapWidget = new QQuickWidget(this);
    ui->FirstStack->insertWidget(Map_page,MapWidget);
    //link map matt signal to qml
    MapWidget->rootContext()->setContextProperty("possignal",MqttCon);

    MapWidget->setSource(QUrl("qrc:/qml/qml/map.qml"));


    //exit map to home
    QQuickItem *rootObjectMap = MapWidget->rootObject();
    auto return_button_map = rootObjectMap->findChild< QObject * > ("ExitButton");


    connect(return_button_map, SIGNAL(returnToMainWindow()), this, SLOT(Back_Home_Slot()));

    //gauge cluster qml
    QQuickWidget *GaugeClusterWidget = new QQuickWidget(this);
    ui->FirstStack->insertWidget(Gauge_page,GaugeClusterWidget);
    GaugeClusterWidget->rootContext()->setContextProperty("mqttClient",MqttCon);

    GaugeClusterWidget->setSource(QUrl("qrc:/qml/qml/main.qml"));

    QQuickItem *rootObjectGauge = GaugeClusterWidget->rootObject();
    auto return_button_gauge = rootObjectGauge->findChild<QObject *>("ExitButton");

    connect(return_button_gauge,SIGNAL(returnToMainWindow2()),this,SLOT(Back_Home_Slot()));




    qDebug()<<"number is"<< ui->FirstStack->count();

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start(1000);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showTime()
{
    QDateTime currentTime = QDateTime::currentDateTime();
    QString timeText = currentTime.toString("h:mm AP"); // Customize the time format and color
    ui->Digital_Clock->setText(timeText);

    QDateTime dateTime = QDateTime::currentDateTime();
    QString datetimetext = dateTime.toString("dddd, MMMM d, yyyy"); // Customize the date format and color
    ui->DateTime->setText(datetimetext);
}



void MainWindow::on_Prayer_Button_clicked()
{ ui->FirstStack->setCurrentIndex(Prayer_page);

}


void MainWindow::Back_Home()
{
    ui->FirstStack->setCurrentIndex(0);
}


void MainWindow::on_Camera_Button_clicked()
{  //camera
    ui->FirstStack->setCurrentIndex(Camera_page);
}


void MainWindow::on_Weather_Button_clicked()
{
    //weather
    ui->FirstStack->setCurrentIndex(Weather_page);
}

void MainWindow::on_Settings_Button_clicked()
{
    //settings widget
    ui->FirstStack->setCurrentIndex(Settings_page);
}


void MainWindow::on_Bluetooth_Button_clicked()
{
    //bluetooth icon
    ui->FirstStack->setCurrentIndex(Bluetooth_page);

}


void MainWindow::on_Info_Button_clicked()
{
    ui->FirstStack->setCurrentIndex(Info_page);
}




void MainWindow::on_Music_Button_clicked()
{
    ui->FirstStack->setCurrentIndex(Music_page);
}


void MainWindow::on_Video_Button_clicked()
{
    ui->FirstStack->setCurrentIndex(Video_page);
}


void MainWindow::Back_Home_Slot(){


    Back_Home();

}


void MainWindow::on_Map_Button_clicked()
{
    ui->FirstStack->setCurrentIndex(Map_page);
}


void MainWindow::on_Gauge_Cluster_Button_clicked()
{
    ui->FirstStack->setCurrentIndex(Gauge_page);
}

