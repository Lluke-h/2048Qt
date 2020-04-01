import QtQuick 2.12
import QtQuick.Window 2.12


Window {
    id: window
    visible: true
    width: 600
    height: 800
    //    height: 800
    //    minimumHeight: background.height + header.height + 10
    minimumWidth: background.width + 2*column.spacing
    minimumHeight: 600

    title: qsTr("Hello World")

    Column {
        id: column
        anchors.fill: parent
        spacing: 10

        Rectangle {
            id: header
            width: parent.width
            height: 100
            color: "#e2dddd"
        }

        Rectangle {
            id: background
            height: window.height - header.height - 2*column.spacing
            width: window.height - header.height - 2*column.spacing
            color: "#aaa2a2"
            radius: 7
            anchors.horizontalCenter: parent.horizontalCenter
            //            anchors.horizontalCenter: parent.horizontalCenter

            Grid {
                id: backgroundGrid
                width: 680
                height: 680
                anchors.fill: parent

                property var tileMargin: 3
                anchors.rightMargin: tileMargin
                anchors.leftMargin: tileMargin
                anchors.bottomMargin: tileMargin
                anchors.topMargin: tileMargin
                spacing: 0
                rows: 4
                columns: 4

                Repeater{
                    model: 16
                    BackgroundTile{
                        bgTileAnchorsbottomMargin: 6
                        bgTileAnchorsleftMargin: 6
                        bgTileAnchorsrightMargin: 6
                        bgTileAnchorstopMargin: 6


                    }

                }


            }
        }





    }

}





/*##^##
Designer {
    D{i:4;anchors_height:680;anchors_width:680}
}
##^##*/
