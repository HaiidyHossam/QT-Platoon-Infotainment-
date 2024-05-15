

import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Shapes 1.15

Rectangle {
    id: item
    width: 1024
    height: 600
    visible: true
    color : "black"

    property int animationIndex: 0
    // Define the scaling factor
    property real scaleFactor: 0.5 // Adjust this value based on your measurements

    Rectangle {
        id: imageContainer
        width: 679
        height: 670

        anchors.centerIn: parent

        Image {
            id: image
            source: "assets/images/carla_map.jpg"

            anchors.centerIn: parent
            smooth: true
            //scale: zoomFactor
        }

        PathView {
            id: pathView
            anchors.centerIn: parent
            preferredHighlightBegin: 0.5
            preferredHighlightEnd: 0.5
            snapMode: PathView.NoSnap
            highlightRangeMode: PathView.StrictlyEnforceRange
            pathItemCount: pathModel.count



            delegate: Rectangle {
                width: 20
                height: 20
                color: "blue"
                border.color: "white"
                radius: width / 2
                x: pathView.model.get(index).x - width / 2
                y: pathView.model.get(index).y - height / 2
            }

            focus: true
            Keys.onRightPressed: pathView.incrementCurrentIndex()
        }

        Rectangle {
            id: movingPoint
            width: 10
            height: 10
            color: "red"
            border.color: "white"
            radius: width / 2
            x:65
            y:42

            Behavior on x { NumberAnimation { duration: 1000 } }
            Behavior on y { NumberAnimation { duration: 1000 } }

            Timer {
                interval: 1000
                repeat: true
                running: true
                onTriggered: {
                    if (animationIndex < pathModel.count - 1)
                        animationIndex++
                    else
                        animationIndex = 0
                }
            }
        }
    }


    Button {

        objectName: "ExitButton"
        text: "Return to Main Window"
        anchors.left : parent.left

        onClicked:  returnToMainWindowAction()

        // Define a signal to indicate returning to the main window
        signal returnToMainWindow()

        function returnToMainWindowAction() {
            // Emit the signal to indicate returning to the main window
            console.log("emmiting signal");
            returnToMainWindow()
        }

    }


    Connections {
        target: possignal
        onMessageReceived_pos_signal: {

            console.log("postion has changed! ");
            movingPoint.x = x * scaleFactor;
            movingPoint.y = y * scaleFactor;
        }
    }

}











