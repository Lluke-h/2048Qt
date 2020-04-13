import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.12



Window {
    id: window
    visible: true
    height: 500
    //    height: 800
    //    minimumHeight: background.height + header.height + 10
    minimumWidth: background.width + 2*column.spacing
    minimumHeight: 400
    title: qsTr("2048Qt")


    Column {
        id: column
        anchors.fill: parent
        spacing: 10

        Rectangle {
            id: header
            width: parent.width
            height: Math.min(0.15 * parent.height, 75)
            color: "#e2dddd"

            // Lin arrow keys to the move() function
            Keys.onPressed: {
                switch (event.key){
                case Qt.Key_Up:
                    vueObjetCpt.increment();
                    game.move(2);

                    break;
                case Qt.Key_Left:
                    game.move(3);

                    break;
                case Qt.Key_Right:
                    game.move(1);

                    break;
                case Qt.Key_Down:
                    vueObjetCpt.decrement();
                    game.move(0);

                    break;
                }
            }


            Row {
                id: scores
                width: parent.width * 0.4
                height: parent.height
                anchors.right: parent.right
                anchors.rightMargin: 6
                spacing: 6
                layoutDirection: Qt.RightToLeft







                Rectangle {
                    id: scoreBoxBest
                    width: 0.5 * parent.width
                    height: 0.8 * parent.height
                    color: "#bdbdbd"
                    radius: 10
                    anchors.verticalCenter: parent.verticalCenter



                    Text {
                        id: scoreBestValue
                        focus: true
                        color: "#444444"
                        text: game.scoreMaxQML
                        font.family: "Verdana"
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        minimumPointSize: 10
                        anchors.fill: parent
                        font.pointSize: 60
                        fontSizeMode: Text.Fit
                        anchors.margins: 4

                    }

                    Text {
                        id: best
                        color: "#868686"
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: qsTr("BEST")
                        font.pixelSize: 10
                    }
                }

                Rectangle {
                    id: scoreBox
                    width: 0.5 * parent.width
                    height: 0.8 * parent.height
                    color: "#bdbdbd"
                    radius: 10
                    anchors.verticalCenter: parent.verticalCenter

                    Text {
                        id: scoreValue
                        color: "#444444"
                        text: game.scoreQML
                        focus: true
                        verticalAlignment: Text.AlignVCenter
                        font.family: "Verdana"
                        anchors.margins: 4
                        fontSizeMode: Text.Fit
                        anchors.fill: parent
                        minimumPointSize: 10
                        font.pointSize: 50
                        horizontalAlignment: Text.AlignHCenter
                    }

                    Text {
                        id: score
                        color: "#868686"
                        text: qsTr("SCORE")
                        anchors.horizontalCenter: parent.horizontalCenter
                        font.pixelSize: 10
                    }
                }










            }

            Text {
                id: title
                x: 20
                y: 17
                color: "#868686"
                text: qsTr("2048")
                anchors.left: parent.left

                anchors.leftMargin: 20
                font.family: "Verdana"
                font.weight: Font.ExtraBold
                font.pixelSize: parent.height * 0.5
                anchors.verticalCenter: parent.verticalCenter
                anchors.rightMargin: 20
            }

            Rectangle {
                id: retry
                x: 297
                y: 22
                height: 0.5 * parent.height
                width: height
                color: "#ffffff"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }


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

                property var tileMargin: 1.5
                anchors.rightMargin: tileMargin
                anchors.leftMargin: tileMargin
                anchors.bottomMargin: tileMargin
                anchors.topMargin: tileMargin
                spacing: 0
                rows: 4
                columns: 4

                Repeater{
                    model: backgroundGrid.rows * backgroundGrid.columns
                    BackgroundTile{
                        width : backgroundGrid.width / backgroundGrid.columns
                        height: backgroundGrid.height / backgroundGrid.rows
                        bgTileAnchorsbottomMargin: 3
                        bgTileAnchorsleftMargin: 3
                        bgTileAnchorsrightMargin: 3
                        bgTileAnchorstopMargin: 3

                    }

                }


            }

            Grid {
                id: gameGrid
                width: 680
                height: 680
                anchors.fill: parent

                property var tileMargin: 1.5
                anchors.rightMargin: tileMargin
                anchors.leftMargin: tileMargin
                anchors.bottomMargin: tileMargin
                anchors.topMargin: tileMargin
                spacing: 0
                rows: 4
                columns: 4

                Repeater{
                    model: gameGrid.rows * gameGrid.columns
                    Tile{
                        width : backgroundGrid.width / backgroundGrid.columns
                        height: backgroundGrid.height / backgroundGrid.rows
                        opacity: 100
                    }

                }



            }
        }





    }

}





/*##^##
Designer {
    D{i:13;anchors_height:680;anchors_width:680}
}
##^##*/
