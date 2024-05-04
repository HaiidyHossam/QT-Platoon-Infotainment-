#include "MqttClient.h"
#include <QDebug>
#include <QDataStream>
MqttClient::MqttClient(QObject *parent) : QObject(parent)
{
    m_client.setHostname("broker.emqx.io");
    m_client.setPort(1883);
    m_client.connectToHost();

    connect(&m_client, &QMqttClient::messageReceived, this, &MqttClient::messageReceived);
}

MqttClient::~MqttClient()
{
    m_client.disconnectFromHost();
}

void MqttClient::messageReceived(const QByteArray &message, const QMqttTopicName &topic)
{
    Q_UNUSED(topic);
    QDataStream stream(message);
    int x, y;
    stream >> x >> y; // Assuming the position message is in the format "x y"
    emit positionUpdated(x, y);
}
