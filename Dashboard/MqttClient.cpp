#include "MqttClient.h"
#include <QDebug>
MqttClient::MqttClient(QObject *parent) : QObject(parent), mqttClient(new QMqttClient(this))
{
    mqttClient->setHostname("broker.emqx.io");
    mqttClient->setPort(1883);
    mqttClient->connectToHost();
    connect(mqttClient, &QMqttClient::stateChanged, this, &MqttClient::mqttStateChanged);
    connect(mqttClient, &QMqttClient::messageReceived, this, &MqttClient::messageReceived);
}
void MqttClient::mqttStateChanged(QMqttClient::ClientState state)
{
    switch (state) {
    case QMqttClient::Connected:
        qDebug() << "Connected to MQTT broker";
        mqttClient->subscribe(QMqttTopicFilter("speed_topic"), 0);
        mqttClient->subscribe(QMqttTopicFilter("rpm_topic"), 0);        // Subscribe to sensor data topic
        break;
    case QMqttClient::Disconnected:
        qDebug() << "Disconnected from MQTT broker";
        break;
    default:
        break;
    }
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
