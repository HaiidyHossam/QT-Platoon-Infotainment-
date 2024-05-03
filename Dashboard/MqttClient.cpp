#include "MqttClient.h"

MqttClient::MqttClient(QObject *parent) : QObject(parent), mqttClient(new QMqttClient(this))
{
    connect(mqttClient, &QMqttClient::messageReceived, this, &MqttClient::messageReceived);
}

void MqttClient::startClient()
{
    mqttClient->setHostname("broker.emqx.io");
    mqttClient->setPort(1883);
    mqttClient->connectToHost();
    mqttClient->subscribe("speed_topic", 0);
    mqttClient->subscribe("rpm_topic", 0);
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
