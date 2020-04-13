import QtQuick 2.0

Item {
    id : tile
    width : gameGrid.width / gameGrid.columns
    height: gameGrid.height / gameGrid.rows

    Rectangle {
        id: tileRect
        //color: game.tileColorQML[index]
        color: Qt.rgba(game.tileColorQML[2*index], 1, 1, game.tileColorQML[2*index+1])
        radius: 7


        anchors.rightMargin: 3
        anchors.leftMargin: 3
        anchors.bottomMargin: 3
        anchors.topMargin: 3
        anchors.fill: parent

        Text {
            id: element
            opacity: game.tileColorQML[2*index+1]
            text: game.tileQML[index]
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
