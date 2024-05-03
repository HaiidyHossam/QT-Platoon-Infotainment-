#include "MqttClient.h"

MqttClient::MqttClient(QObject *parent) : QObject(parent)
{
    m_client.setHostname("your_mqtt_broker_address");
    m_client.setPort(1883);
    m_client.connectToHost();

    QObject::connect(&m_client, &QMqttClient::messageReceived, this, &MqttClient::messageReceived);
}

MqttClient::~MqttClient()
{
    m_client.disconnectFromHost();
}

void MqttClient::messageReceived(const QByteArray &message, const QMqttTopicName &topic)
{
    int x, y;
    emit positionUpdated(x, y);
}
