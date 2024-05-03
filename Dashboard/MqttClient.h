#ifndef MQTTCLIENT_H
#define MQTTCLIENT_H

#include <QObject>
#include <QtMqtt/QtMqtt>

class MqttClient : public QObject
{
    Q_OBJECT
public:
    explicit MqttClient(QObject *parent = nullptr);
    Q_INVOKABLE void startClient();

signals:
    void speedChanged(int speed);
    void rpmChanged(int rpm);

private slots:
    void messageReceived(const QByteArray &message, const QMqttTopicName &topic);

private:
    QMqttClient *mqttClient;
};

#endif // MQTTCLIENT_H
