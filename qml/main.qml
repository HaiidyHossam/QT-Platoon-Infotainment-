



import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 2.15
Item {
    width: 1024
    height: 600
    visible: true



    Rectangle {
        id: dashboard
        anchors.centerIn: parent
        width:1024
        height:600
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
            spacing:dashboard.width *0.2
            anchors.centerIn: parent

            CircularGauge{
                id: rpmMeter
                width:height
                height:dashboard.height*0.5
                maximumValue: 5000
                style: RPMMeterStyle{}

                Connections {
                    target: mqttClient
                    onMessageReceived_rpm_signal: {
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
                    onMessageReceived_speed_signal: {
                        speedometer.value = speed;
                    }
                }
            }
        }
        Keys.onLeftPressed: {
            leftIndicator.on=true;
            rightIndicator.on=false;
        }
        Keys.onRightPressed: {
            rightIndicator.on=true;
            leftIndicator.on=false;
        }

    }





    Button {
        Image {
            id: image_home2
            source: "assets/images/home2.png"
            //anchors.centerIn: parent
            smooth: true
        }

        objectName: "ExitButton"
        //text: "Return to Main Window"
        anchors.right : parent.right
        width: 80
        height: 600
        palette {
               button: "black"
           }

        onClicked:  returnToMainWindowAction2()

        // Define a signal to indicate returning to the main window
        signal returnToMainWindow2()

        function returnToMainWindowAction2() {
            // Emit the signal to indicate returning to the main window
            returnToMainWindow2()
        }

    }

}





