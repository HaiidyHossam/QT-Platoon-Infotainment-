import QtQuick 2.15
import QtMultimedia 5.15
//import com.company.PlayerController
Item {
    id:root

    required property int songIndex
    property alias title:titleText.text
    property alias authorName: authorText.text
    property alias imageSource: albumImage.source

    visible: playercontrollerCPP.currentSongIndex === root.songIndex
    Image{
        id:albumImage

        anchors{
            verticalCenter: parent.verticalCenter
            left:parent.left
        }
        width:150
        height:150
    }
    Video{
        id:albumVideo

        anchors{
            verticalCenter: parent.verticalCenter
            left:parent.left
        }
        width:150
        height:150
        loops: MediaPlayer.Infinite
        volume:0
    }

    Audio{

    }

    Text{
        id:titleText
        anchors{
            bottom:parent.verticalCenter
            left:albumImage.right
            margins: 20
            right:parent.right
        }
        color:"white"
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        font{
            pixelSize: 20
            bold:true

        }
    }

    Text{
        id:authorText
        anchors{
            top:parent.verticalCenter
            left:titleText.left
            topMargin: 5
            right:parent.right
        }
        color:"gray"
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        font{
            pixelSize: 16

        }
    }
}
