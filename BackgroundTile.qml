import QtQuick 2.0

Item {
    id : bgTile
    width: parent.width/4
    height: parent.height/4
    property alias bgTileAnchorsrightMargin: bgTileRect.anchors.rightMargin
    property alias bgTileAnchorsleftMargin: bgTileRect.anchors.leftMargin
    property alias bgTileAnchorsbottomMargin: bgTileRect.anchors.bottomMargin
    property alias bgTileAnchorstopMargin: bgTileRect.anchors.topMargin


    Rectangle {
        id: bgTileRect
        color: "#9f9797"
        radius: 7
        anchors.fill: parent

    }



}

