#ifndef MQTTCLIENT_H
#define MQTTCLIENT_H

#include <QObject>
#include <QtMqtt/QtMqtt>
#include <QDebug>
#include <QtCore/QMap>
#include <QtMqtt/QMqttClient>
#include <QtMqtt/QMqttSubscription>

class MqttClient : public QObject
{
    Q_OBJECT
public:
    explicit MqttClient(QObject *parent = nullptr);

signals:
    void speedChanged(int speed);
    void rpmChanged(int rpm);

public slots:
    void mqttStateChanged(QMqttClient::ClientState state);
    void messageReceived(const QByteArray &message, const QMqttTopicName &topic);

private:
    QMqttClient *mqttClient;
};

#endif // MQTTCLIENT_H
