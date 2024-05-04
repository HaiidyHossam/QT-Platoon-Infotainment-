import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 2.15
import CustomTypes 1.0
Window {
    width: 1000
    height: 500
    visible: true
    title: qsTr("Dashboard")

    ValueSource{
        id:valueSource
    }
    MqttClient {
        id: mqttClient
    }

    Rectangle {
        id: dashboard
        anchors.centerIn: parent
        height:500
        width:1000
        color:"black";
        Row{
            id:indicatorRow
            spacing:dashboard.width*0.02
            anchors.top: parent.top
            anchors.topMargin: dashboard.width*0.02
            anchors.horizontalCenter:parent.horizontalCenter

            ArrowIndicator{
                id:leftIndicator
                height: dashboard.height *0.07
                width: height*1.5
                direction: Qt.LeftArrow
            }

            ArrowIndicator{
                id:rightIndicator
                height: dashboard.height *0.07
                width: height*1.5
                direction: Qt.RightArrow
            }
        }

        Row{
            id:dashboardRow
            spacing:dashboard.width *0.4
            anchors.centerIn: parent

            CircularGauge{
                id: rpmMeter
                width:height
                height:dashboard.height*0.5
                maximumValue: 5000
                style: RPMMeterStyle{}

                Connections {
                    target: mqttClient
                    onRpmChanged: {
                        rpmMeter.value = rpm;
                    }
                }
            }
            CircularGauge{
                id: speedometer
                value:acceleration? maximumValue : 0
                width:height
                height:dashboard.height*0.5
                maximumValue: 180
                property bool acceleration: false
                style: SpeedometerStyle{}
                Behavior on value {
                    NumberAnimation{
                        duration:5000
                    }
                }
                Component.onCompleted: forceActiveFocus();
                Connections {
                    target: mqttClient
                    onSpeedChanged: {
                        speedometer.value = speed;
                    }
                }
            }
        }
        /*Keys.onLeftPressed: {
            leftIndicator.on=true;
            rightIndicator.on=false;
        }
        Keys.onRightPressed: {
            rightIndicator.on=true;
            leftIndicator.on=false;
        }
        Keys.onUpPressed: {
            speedometer.acceleration = true
        }
        Keys.onReleased: {
            if(event.key === Qt.Key_Up)
            {
                speedometer.acceleration=false;
                event.accepted=true;
            }
        }*/
    }
    /*MqttClient {
        id: mqttClient
        onSpeedChanged: speedometer.value = speed
        onRpmChanged: rpmMeter.value = rpm
    }*/
}
