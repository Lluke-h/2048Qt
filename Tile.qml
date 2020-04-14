import QtQuick 2.0
//To lighten the code in main.qml: repeater of tiles

Item {
    id : tile
    width : gameGrid.width / gameGrid.columns
    height: gameGrid.height / gameGrid.rows

    Rectangle {
        id: tileRect


        color: Qt.rgba(1-Math.log(element.text)/5+Math.floor(Math.log(element.text)/(Math.log(2048))), 0.9-(Math.log(element.text)/(Math.log(2)*23))-Math.floor(Math.log(element.text)/(Math.log(2048))), 0.1+(Math.log(element.text)/(Math.log(4)*13)), element.opacity)
        //log/log(2) to make a different color for each tile
        //other parameters are to increase shades between colors of different tiles

        radius: 7


        anchors.rightMargin: 3
        anchors.leftMargin: 3
        anchors.bottomMargin: 3
        anchors.topMargin: 3
        anchors.fill: parent

        Text {
            id: element
            opacity: game.tileQML[2*index+1] //have a look on the readTiles function in game.cpp : we send the opacity of the space in the grid (0 for empty spaces, 1 for full spaces)
            text: game.tileQML[2*index]
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.fill: parent
            anchors.margins: 2
            fontSizeMode: Text.Fit
            font.pointSize: 20
        }

    }



}

/*##^##
Designer {
    D{i:2;anchors_x:314;anchors_y:260}
}
##^##*/
