#ifndef MQTTCLIENT_H
#define MQTTCLIENT_H

#include <QObject>
#include <QtMqtt/QMqttClient>

class MqttClient : public QObject
{
    Q_OBJECT
public:
    explicit MqttClient(QObject *parent = nullptr);
    ~MqttClient();

signals:
    void positionUpdated(int x, int y);

private slots:
    void messageReceived(const QByteArray &message, const QMqttTopicName &topic);

private:
    QMqttClient m_client;
};


#endif // MQTTCLIENT_H
