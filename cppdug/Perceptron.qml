import QtQuick 2.0

Item {
    id: root
    width: radius * 12
    height: radius * 5

    property int radius: 75
    property int border: 2
    property point bodyOrigin: Qt.point(body.x + body.width / 2, body.y + body.height / 2);
    property point output: axon.TopRight // TODO: why it doesn't work?

    property int _numInputs

    function inputPos(input) {
        if (input >= _numInputs)
            return undefined

        var center = 270, max_rotation = 45;
        var distance = _numInputs > 1 ? (max_rotation * 2) / (_numInputs - 1): 0;
        var pos = input * distance
        var input_rotation = center - max_rotation + pos
        function toRadians(degrees) {
            return degrees * Math.PI / 180
        }

        var x = root.radius * Math.sin(toRadians(input_rotation))
        var y = root.radius * Math.cos(toRadians(input_rotation))
        return Qt.point(bodyOrigin.x + x, bodyOrigin.y + y)
    }

    Rectangle {
        id: todoRemoveMe
        border.width: 1
        border.color: "light gray"
        anchors.fill: parent
    }

    Rectangle {
        id: body
        anchors.centerIn: root
        radius: root.radius
        height: root.radius * 2; width: height
        border.width: root.border

        Text {
            anchors.horizontalCenter: body.horizontalCenter
            y: 4
            font.pixelSize: root.radius * 1.4
            text: "∑"
        }
    }

    Rectangle {
        id: axon
        anchors.verticalCenter: body.verticalCenter
        anchors.left: body.right
        border.width: root.border
        height: root.border * 2
        width: root.radius * 3.5

        Rectangle {
            id: transferFunc
            border.width: root.border
            anchors.centerIn: axon
            width: root.radius
            height: root.radius / 1.5

            Text {
                anchors.centerIn: transferFunc
                font.pixelSize: body.radius * 0.45
                text: "┌┘"
            }
        }
    }

    Component.onCompleted: {
        var inputs = []
        for (var i = 0; i < root.children.length; ++i) {
            var input = root.children[i];
            if (input._isInput) {
                inputs.push(input);
                console.log(input.start)
            }
        }

        root._numInputs = inputs.length

        for (var i = 0; i < inputs.length; ++i) {
            inputs[i]._end = root.inputPos(i)
            console.log(inputs[i].start, inputs[i]._end)
        }
    }
}

