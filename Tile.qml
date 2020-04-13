import QtQuick 2.0


Item {
    id : tile
    width : gameGrid.width / gameGrid.columns
    height: gameGrid.height / gameGrid.rows

    Rectangle {
        id: tileRect


        color: Qt.rgba(1-Math.log(element.text)/5+Math.floor(Math.log(element.text)/(Math.log(2048))), 0.9-(Math.log(element.text)/(Math.log(2)*23))-Math.floor(Math.log(element.text)/(Math.log(2048))), 0.1+(Math.log(element.text)/(Math.log(4)*13)), element.opacity)

        radius: 7


        anchors.rightMargin: 3
        anchors.leftMargin: 3
        anchors.bottomMargin: 3
        anchors.topMargin: 3
        anchors.fill: parent

        Text {
            id: element
            opacity: game.tileQML[2*index+1]
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
