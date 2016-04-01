import QtQuick 2.0

Item {
    id: root
    property point start: Qt.point(0, 0)
    property int lineWidth: 2

    property real value: 0
    property real weight: 0

    property bool _isInput: true
    property point _end: Qt.point(0, 0)
    property int _index: 0

    Line {
        id: line
        start: root.start
        end: root._end
        lineWidth: root.lineWidth

        Text {
            id: input_value_text
            x: start.x + 5
            y: start.y + (line._lineRotation > 0 ? -height - line.lineWidth : height - line.lineWidth)
            font.family: " Courier"
            font.pixelSize: 18
            text: "x" + _index + (root.value == 0 ? "" : " = " + value)
        }

        Text {
            id: input_weight_text
            x: line.end.x - 10 - width
            y: line.end.y + (line._lineRotation > 0 ? -height - line.lineWidth - 10 : height - line.lineWidth + 10)
            font.family: " Courier"
            font.pixelSize: 18
            text: "w" + _index + (root.value == 0 ? "" : " = " + weight)

            Component.onCompleted: {
                console.log("line.width = ", line.width)
            }
        }
    }
}
