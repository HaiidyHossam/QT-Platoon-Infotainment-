#include "Headers/mqtt_connection.h"

Mqtt_connection::Mqtt_connection(QString host, int port) :
    m_client(new QMqttClient(this))
{

    m_client->setHostname(host);

    m_client->setPort(port);





    connect(m_client, &QMqttClient::connected, this, &Mqtt_connection::onConnected);
    connect(m_client, &QMqttClient::messageReceived, this, &Mqtt_connection::onMessageReceived);
    connect(m_client, &QMqttClient::disconnected, this, &Mqtt_connection::onDisconnected);
    connect(m_client, &QMqttClient::errorChanged, this, &Mqtt_connection::onError);


    m_client->connectToHost();

}





void Mqtt_connection::subscribe(QString topic){


    auto subscription = m_client->subscribe(topic,1);



    if (!subscription) {
        qDebug("Could not subscribe. Is there a valid connection?");
        return;
    }
    qDebug() << "subscribed to " <<topic;


}




void Mqtt_connection::onMessageReceived(const QByteArray &message, const QMqttTopicName &topic)
{

    int x = 0,y = 0,speed = 0,rpm = 0;

    QString topic_str = topic.name();


    QString msg = QString::fromUtf8(message);

    if(topic_str ==  "posx66"){



        // Split the message into substrings based on the '.' delimiter
        QStringList parts = msg.split('.');

        if (parts.size() != 2) {
            qDebug() << "Invalid message format";
            return;
        }

        // Convert the substrings to integers
        x = parts[0].toInt();
        y = parts[1].toInt();


        emit messageReceived_pos_signal(x,y);

        qDebug("message recived: ");
        qDebug() << QString::fromUtf8(message);
    }


    if(topic_str == "speedx66"){

        speed = msg.toInt();

        emit messageReceived_speed_signal(speed);

        qDebug() << "<recived:" << speed;

    }

    if(topic_str == "rpmx66"){

        rpm = msg.toInt();

        emit messageReceived_rpm_signal(rpm);

        qDebug() <<"rpm: "<< rpm;

    }


}

void Mqtt_connection::onConnected()
{


    qDebug("connected !");



    // I have to put sub in here because connecting is async and takes time, if this was in main the clinet will fail to sub due to unestaplished connection, waiting for solution
    subscribe("posx66");
    subscribe("speedx66");
    subscribe("rpmx66");

}

void Mqtt_connection::onDisconnected()
{
    // emit disconnected();
    qDebug("disconnected");

}


void Mqtt_connection::onError(QMqttClient::ClientError error){


    qDebug() << "MQTT client error:" << error;

}






