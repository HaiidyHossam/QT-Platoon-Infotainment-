#include "MqttClient.h"
#include <QDebug>

MqttClient::MqttClient(QObject *parent) : QObject(parent)
{
    m_client.setHostname("broker.emqx.io");
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
    Q_UNUSED(message);
    Q_UNUSED(topic);
    int x, y;
    emit positionUpdated(x, y);
}
