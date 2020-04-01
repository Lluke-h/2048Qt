import QtQuick 2.0

Item {
    width: parent.width/4
    height: parent.height/4
    property alias bgTileAnchorsrightMargin: bgTile.anchors.rightMargin
    property alias bgTileAnchorsleftMargin: bgTile.anchors.leftMargin
    property alias bgTileAnchorsbottomMargin: bgTile.anchors.bottomMargin
    property alias bgTileAnchorstopMargin: bgTile.anchors.topMargin


    Rectangle {
        id: bgTile
        color: "#9f9797"
        radius: 7
        anchors.fill: parent

    }



}


