import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.12



Window {
    id: window
    visible: true
    height: 600
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


            Row {
                id: scores
                width: parent.width * 0.4
                height: parent.height
                anchors.right: parent.right
                anchors.rightMargin: 4
                spacing: 4
                layoutDirection: Qt.RightToLeft







                Rectangle {
                    id: scoreBoxBest
                    width: 0.5 * parent.width
                    height: 0.9 * parent.height
                    color: "#bdbdbd"
                    radius: 10
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 4


                    Text {
                        id: scoreBestValue
                        focus: true
                        color: "#444444"
                        text: vueObjetCpt.cptQML
                        font.family: "Verdana"
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        minimumPointSize: 10
                        anchors.fill: parent
                        font.pointSize: 60
                        fontSizeMode: Text.Fit
                        anchors.margins: 4
                        Keys.onPressed: {
                            switch (event.key){
                            case Qt.Key_Up:
                                vueObjetCpt.increment();
                                break;
                            case Qt.Key_Down:
                                vueObjetCpt.decrement();

                                break;
                            }
                        }
                    }

                    Text {
                        id: best
                        color: "#868686"
                        anchors.horizontalCenter: parent.horizontalCenter
                        text: qsTr("BEST")
                        font.pixelSize: 12
                    }
                }

                Rectangle {
                    id: scoreBox
                    width: 0.5 * parent.width
                    height: 0.9 * parent.height
                    color: "#bdbdbd"
                    radius: 10
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 4

                    Text {
                        id: scoreValue
                        color: "#444444"
                        text: vueObjetCpt.cptQML
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
                        font.pixelSize: 12
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
                rows: 5
                columns: 5

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
        }





    }

}





/*##^##
Designer {
    D{i:13;anchors_height:680;anchors_width:680}
}
##^##*/
