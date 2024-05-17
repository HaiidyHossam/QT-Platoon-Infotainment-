#ifndef MQTT_CONNECTION_H
#define MQTT_CONNECTION_H


#include <QtMqtt/QtMqtt>
#include <QtMqtt/QMqttClient>
#include <QQmlContext>
#include <QList>

struct Position {
    int x;
    int y;
};


class Mqtt_connection : public QObject
{


    Q_OBJECT
public:
    Mqtt_connection(QString host, int port);

    virtual ~Mqtt_connection(){};

    void subscribe(QString topic);


private:

    QMqttClient  *m_client;

    int QOS;


signals:
    void messageReceived_pos_signal(QVariantList positions);
    void messageReceived_speed_signal(int speed);
    void messageReceived_rpm_signal(int rpm);

    void connected_signal();
    void disconnected_signal();

private slots:
    void onMessageReceived(const QByteArray &message, const QMqttTopicName &topic);
    void onConnected();
    void onDisconnected();
    void onError(QMqttClient::ClientError error);





};

#endif // MQTT_CONNECTION_H
