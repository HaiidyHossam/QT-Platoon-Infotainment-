import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Shapes 1.15

Window {
    width: 679
    height: 670
    visible: true
    title: qsTr("Carla Map")
    Image {
        id: mapImage
        source: "assets/images/carla_map.jpg"
        anchors.fill:parent
        property variant points: [
            {x:100,y:100},
            {x:300,y:200},
            {x:500,y:300},
            {x:700,y:400}
        ]
        Rectangle {
            id: arrowIcon
            width: 10
            height: 10
            color: "red"
            radius: 5
            visible: true
            x: mapImage.points[0].x - width / 2
            y: mapImage.points[0].y - height / 2

            SequentialAnimation {
                id: navigationAnimation
                loops: Animation.Infinite

                PropertyAnimation {
                    target: arrowIcon
                    property: "x"
                    to: mapImage.points[1].x - arrowIcon.width / 2
                    duration: 1000
                }
                PropertyAnimation {
                    target: arrowIcon
                    property: "y"
                    to: mapImage.points[1].y - arrowIcon.height / 2
                    duration: 1000
                }
                PropertyAnimation {
                    target: arrowIcon
                    property: "x"
                    to: mapImage.points[2].x - arrowIcon.width / 2
                    duration: 1000
                }
                PropertyAnimation {
                    target: arrowIcon
                    property: "y"
                    to: mapImage.points[2].y - arrowIcon.height / 2
                    duration: 1000
                }
                PropertyAnimation {
                    target: arrowIcon
                    property: "x"
                    to: mapImage.points[3].x - arrowIcon.width / 2
                    duration: 1000
                }
                PropertyAnimation {
                    target: arrowIcon
                    property: "y"
                    to: mapImage.points[3].y - arrowIcon.height / 2
                    duration: 1000
                }
            }
        }

        Path {
            id: navigationPath
            startX: mapImage.points[0].x
            startY: mapImage.points[0].y
        }
    }
}



/*Rectangle{
        id:root
        width: 679
        height: 670
        Image{
            source:"assets/images/carla_map.jpg"
            width: sourceSize.width
            height:sourceSize.height
            Component.onCompleted: console.log(width,height,sourceSize)
        }
        Image {
            id: background
            source: "assets/images/carla_map.jpg"
            //width: sourceSize.width
            //height:sourceSize.height
            anchors.fill: parent
        }
        Image {
            id: arrowNavigation
            source: "assets/icons/arrow.png"
            scale:0.03
            //anchors.centerIn: parent
            x:background.width/2
            y:background.height/2
            rotation: 90
        }
    }*/
/*background:Image{
        id:map
        source: "assets/images/carla_map.jpg"
        width: sourceSize.width
        height:sourceSize.height
    }

    forground:Image{
        id:arrowIcon
        source: "assets/icons/arrow.png"
        width: sourceSize.width
        height:sourceSize.height
        scale:0.06
    }*/
