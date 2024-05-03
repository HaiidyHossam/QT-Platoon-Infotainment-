#include "MqttClient.h"

MqttClient::MqttClient(QObject *parent) : QObject(parent), MqttClient(new QMqttClient(this))
{
    connect(MqttClient, &QMqttClient::messageReceived, this, &MqttClient::messageReceived);
}

void MqttClient::startClient()
{
    MqttClient->setHostname("broker.emqx.io");
    MqttClient->setPort(1883);
    MqttClient->connectToHost();
    MqttClient->subscribe("speed_topic", 0);
    MqttClient->subscribe("rpm_topic", 0);
}

void MqttClient::messageReceived(const QByteArray &message, const QMqttTopicName &topic)
{
    if (topic.name() == "speed_topic")
    {
        int speed = QString(message).toInt();
        emit speedChanged(speed);
    }
    else if (topic.name() == "rpm_topic")
    {
        int rpm = QString(message).toInt();
        emit rpmChanged(rpm);
    }
}
