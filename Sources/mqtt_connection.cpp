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




QString Mqtt_connection::formatCoordinates(const QByteArray &jsonData){

    // Parse the QByteArray as a JSON array of arrays
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "Error parsing JSON:" << parseError.errorString();
        return QString();
    }

    QJsonArray outerArray = doc.array();
    QString formattedCoordinates;

    // Iterate through each inner array
    for (int i = 0; i < outerArray.size(); ++i) {
        QJsonArray innerArray = outerArray[i].toArray();

        // Extract x, y coordinates (assuming they are the first two elements)
        if (innerArray.size() >= 2) {
            int x = innerArray.at(0).toInt();
            int y = innerArray.at(1).toInt();

            // Format and append to the result string
            formattedCoordinates.append(QString::number(x) + "." + QString::number(y));

            // Add comma separator if not the last element
            if (i < outerArray.size() - 1)
                formattedCoordinates.append(",");
        }
     }

    qDebug() << formattedCoordinates;

    return formattedCoordinates;


}


int Mqtt_connection::extractSpeed(const QByteArray &jsonData){

    // Parse the QByteArray as a JSON array of arrays
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);

    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "Error parsing JSON:" << parseError.errorString();
        return -1; // Error condition
    }

    QJsonArray outerArray = doc.array();

    // Extract speed from the first inner array (assuming speed is the fourth element)
    if (outerArray.size() > 0) {
        QJsonArray firstArray = outerArray[0].toArray();
        if (firstArray.size() >= 4) {
            int speed = firstArray.at(3).toInt();
            return speed;
        }
    }

    return -1; // Error condition or no speed found


}



double Mqtt_connection::extractThrottle(const QByteArray &jsonData){

    QJsonDocument doc = QJsonDocument::fromJson(jsonData);

    if (doc.isNull() || !doc.isArray()) {
        qWarning() << "Invalid JSON data or not an array";
        return -1.0; // Handle the error as appropriate
    }

    QJsonArray array = doc.array();
    if (array.isEmpty() || !array.at(0).isDouble()) {
        qWarning() << "Array is empty or first element is not a numeric value";
        return -1.0; // Handle the error as appropriate
    }

    return array.at(0).toDouble();


}

void Mqtt_connection::onMessageReceived(const QByteArray &message, const QMqttTopicName &topic)
{

    int x = 0,y = 0,speed = 0,rpm = 0;

    QString topic_str = topic.name();





    if(topic_str == "sim/sensors"){


        QString coords = formatCoordinates(message);
        speed = extractSpeed(message);




        QStringList positionStrings = coords.split(',');

        QVariantList positions;
        for (const QString& posStr : positionStrings) {
            QStringList coords = posStr.split('.');
            if (coords.size() != 2) {
                qDebug() << "Invalid position format: " << posStr;
                continue;
            }

            QVariantMap pos;
            pos["x"] = coords[0].toDouble();
            pos["y"] = coords[1].toDouble();
            positions.append(pos);
        }


        emit messageReceived_pos_signal(positions);

        qDebug("message recived: ");
        qDebug() << QString::fromUtf8(message);



        emit messageReceived_speed_signal(speed);

        qDebug() << "<recived:" << speed	;

    }else if(topic_str == "trgt/01/actions"){



        double throttle = extractThrottle(message);



        qDebug("message recived: ");
        qDebug() << QString::fromUtf8(message);


        qDebug()<< throttle;

        rpm = throttle * 5000;

        emit messageReceived_rpm_signal(rpm);

        qDebug() <<"rpm: "<< rpm;
        }else{qDebug()<< "format error";}











}

void Mqtt_connection::onConnected()
{


    qDebug("connected !");



    // I have to put sub in here because connecting is async and takes time, if this was in main the clinet will fail to sub due to unestaplished connection, waiting for solution

    subscribe("sim/sensors");
    subscribe("trgt/01/actions");

}

void Mqtt_connection::onDisconnected()
{
    // emit disconnected();
    qDebug("disconnected");

}


void Mqtt_connection::onError(QMqttClient::ClientError error){


    qDebug() << "MQTT client error:" << error;

}






