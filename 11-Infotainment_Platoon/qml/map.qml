

import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Shapes 1.15

Item {
    width: 679
    height: 670
    visible: true

    property int animationIndex: 0
    // Define the scaling factor
    property real scaleFactor: 0.5 // Adjust this value based on your measurements

    Rectangle {
        id: imageContainer
        width: 679
        height: 670
        Image {
            id: image
            source: "assets/images/carla_map.jpg"
            anchors.fill: parent
            smooth: true
            //scale: zoomFactor
        }

        PathView {
            id: pathView
            anchors.fill: parent
            preferredHighlightBegin: 0.5
            preferredHighlightEnd: 0.5
            snapMode: PathView.NoSnap
            highlightRangeMode: PathView.StrictlyEnforceRange
            pathItemCount: pathModel.count

            model: ListModel {
                id: pathModel
                ListElement { x: 65; y: 42 }
                ListElement { x: 100; y: 42 }
                ListElement { x: 190; y: 42 }
                ListElement { x: 250; y: 42 }
                ListElement { x: 300; y: 42 }
                ListElement { x: 350; y: 42 }
                ListElement { x: 400; y: 42 }
                ListElement { x: 480; y: 42 }
                ListElement { x: 550; y: 42 }
                ListElement { x: 600; y: 42 }
                ListElement { x: 620; y: 42 }
                ListElement { x: 620; y: 50 }
                ListElement { x: 620; y: 100 }
                ListElement { x: 620; y: 150 }
                ListElement { x: 620; y: 200 }
                ListElement { x: 620; y: 250 }
                ListElement { x: 620; y: 300 }
                ListElement { x: 620; y: 350 }
                ListElement { x: 620; y: 400 }
                ListElement { x: 620; y: 450 }
                ListElement { x: 620; y: 500 }
                ListElement { x: 620; y: 550 }
                ListElement { x: 620; y: 600}
                ListElement { x: 600; y: 600}
                ListElement { x: 550; y: 600}
                ListElement { x: 500; y: 600}
                ListElement { x: 450; y: 600}
                ListElement { x: 400; y: 600}
                ListElement { x: 350; y: 600}
                ListElement { x: 300; y: 600}
                ListElement { x: 250; y: 600}
                ListElement { x: 200; y: 600}
                ListElement { x: 150; y: 600}
                ListElement { x: 100; y: 600}
                ListElement { x: 65; y: 600}
                ListElement { x: 65; y: 550}
                ListElement { x: 65; y: 500}
                ListElement { x: 65; y: 450}
                ListElement { x: 65; y: 400}
                ListElement { x: 65; y: 350}
                ListElement { x: 65; y: 300}
                ListElement { x: 65; y: 250}
                ListElement { x: 65; y: 200}
                ListElement { x: 65; y: 150}
                ListElement { x: 65; y: 100}
                ListElement { x: 65; y: 42 }
            }

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











