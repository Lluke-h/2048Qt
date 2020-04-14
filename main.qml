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

    Rectangle {                      //for the Game Over window: it appears when you lose the game, setting the opacity to 1
        id: gameOver
        opacity: game.gameOverQML
        //opacity: 1
        z: 1;
        width: 0.8 * parent.width
        height: 0.4 * parent.height
        color: "#eeeeee"
        radius: 10
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter


        Text {
            id: gameOverText
            color: "#222222"
            font.family: "Verdana"
            text: qsTr("GAME OVER")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            font.pixelSize: 30
        }

        Rectangle {  //mouse area to quit the game
            id: quit
            width: 0.4 * parent.width
            height: 0.2 * parent.height
            color: "#bdbdbd"
            radius: 10
            //opacity: parent.opacity
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.margins: 8


            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if (parent.parent.opacity == 1){   //if the GameOver window is not visible, we cannot click on these options
                        Qt.quit();
                    }
                }
            }



            Text {
                id: quitText
                color: "#868686"
                text: qsTr("QUIT")
                font.pixelSize: 20
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Rectangle {   //mouse area to retry and/or set a new size for the grid
            id: retryBox
            width: 0.4 * parent.width
            height: 0.2 * parent.height
            color: "#bdbdbd"
            radius: 10
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.margins: 8

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if (parent.parent.opacity == 1){
                        setSize.opacity= 1;
                    }
                }
            }



            Text {
                id: retryBoxText
                color: "#868686"
                text: qsTr("RETRY - SET SIZE")
                font.pixelSize: 20
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }
        }

    }

    Rectangle { //a window to set the size of the grid. It has 5 children (3 to 7) that represents a new size of the grid. You can choose the same that you just used if you dont want to try a new size of grid
        id: setSize
        opacity: 0
        z: 1
        width: 0.5 * parent.width
        height: 0.8 * parent.height
        color: "#eeeeee"
        radius: 10
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter


        Text {
            id: setSizeText
            color: "#222222"
            font.family: "Verdana"
            text: qsTr("Choose your grid size")
            anchors.top: parent.top
            anchors.margins: 8
            font.pixelSize: 20
        }

        Repeater{

            model: 5
            Rectangle {
                id: setSizeOption
                width: 0.9 * parent.width
                height: 0.1 * parent.height
                color: "#bdbdbd"
                radius: 10
                //opacity: parent.opacity
                anchors.horizontalCenter: parent.horizontalCenter
                y: 80 +50*index
                anchors.margins: 8


                MouseArea{  //it triggers resizing of the interface
                    anchors.fill: parent
                    onClicked: {
                        if (parent.parent.opacity == 1){
                            game.setSize(index+3); //it send the new size of the grid to the game
                            gameGrid.rows = game.sizeQML;
                            gameGrid.columns = game.sizeQML;
                            backgroundGrid.rows = game.sizeQML;
                            backgroundGrid.columns = game.sizeQML;
                            parent.parent.opacity = 0;
                        }
                    }
                }



                Text {
                    id: setSizeOptionText
                    color: "#868686"
                    text: qsTr(String(index+3))
                    font.pixelSize: 20
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }


        }








    }





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


            Row {                        //a row for scores and retry button
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

            Text {  //Title of the game
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
                width: 0.1 * parent.width
                height: 0.8 * parent.height
                color: "#888888"
                radius: 10
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter

                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        setSize.opacity = 1;
                    }


                }

                Text {
                    id: retryText
                    color: "#333333"
                    text: qsTr("RETRY\nSET SIZE")
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 10
                }

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
