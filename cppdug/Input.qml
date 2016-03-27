import QtQuick 2.0

Item {
    id: root
    property point start: Qt.point(0, 0)
    property int lineWidth: 2

    property point _end: Qt.point(0, 0)
    property bool _isInput: true

    Rectangle {
        id: line
        x: start.x
        y: start.y
        width: Math.sqrt(Math.pow(_end.x - start.x, 2) + Math.pow(_end.y - start.y, 2)) + 1
        height: root.lineWidth
        color: "black"

        transformOrigin: Item.TopLeft
        rotation: Math.atan((_end.y - start.y) / (_end.x - start.x)) / Math.PI * 180
    }
}
