import QtQuick 2.0

Item {
    id: root

    property point start: Qt.point(0, 0)
    property point end: Qt.point(0, 0)
    property int lineWidth: 2
    property color lineColour: "black"

    property real _lineRotation: _line.rotation

    Rectangle {
        id: _line
        x: start.x
        y: start.y
        width: Math.sqrt(Math.pow(end.x - start.x, 2) + Math.pow(end.y - start.y, 2)) + 1
        height: root.lineWidth
        color: lineColour

        transformOrigin: Item.TopLeft
        rotation: Math.atan((end.y - start.y) / (end.x - start.x)) / Math.PI * 180
    }
}

