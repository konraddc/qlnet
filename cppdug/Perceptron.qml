import QtQuick 2.0

Item {
    id: root
    width: radius * 12
    height: radius * 5

    property int radius: 75
    property int border: 2
    property point bodyOrigin: Qt.point(body.x + body.width / 2, body.y + body.height / 2);
    property point output: Qt.point(axon.x + axon.width, axon.y)

    property real param: 0
    property var _inputs: []
    property int _numInputs: 0
    property real _net: -1
    property real _bias: 0

    function inputPos(input) {
        if (input >= _numInputs)
            return undefined

        var center = 270, max_rotation = 45;
        var distance = (max_rotation * 2) / (_numInputs - 1)
        var pos = _numInputs > 1 ? input * distance : max_rotation
        var input_rotation = center - max_rotation + pos
        function toRadians(degrees) {
            return degrees * Math.PI / 180
        }

        var x = root.radius * Math.sin(toRadians(input_rotation))
        var y = root.radius * Math.cos(toRadians(input_rotation))
        return Qt.point(bodyOrigin.x + x, bodyOrigin.y + y)
    }

    function resolve(input_vector, param) {
        // TODO: here we can change states and do animation
        root._net = 0
        root.param = paramEdit.text
        for (var i = 0; i < root._inputs.length; ++i) {
            root._inputs[i].value = input_vector[i]
            _net += root._inputs[i].value * root._inputs[i].weight
        }

        _net += _bias;

        if (_net >= root.param) {
            return 1
        }

        return 0
    }

//    Rectangle {
//        id: todoRemoveMe
//        border.width: 1
//        border.color: "light gray"
//        anchors.fill: parent
//    }

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

    Item {
        id: paramText
        anchors.horizontalCenter: axon.horizontalCenter
        y: 70
        visible: root.param

        width: paramLabel.width + paramEdit.width
        height: paramLabel.height

        Text {
            id: paramLabel
            font.family: " Courier"
            font.pixelSize: 18
            text: "p = "
        }

        TextEdit {
            id: paramEdit
            anchors.left: paramLabel.right
            width: 35
            font.family: " Courier"
            font.pixelSize: 18
            horizontalAlignment: TextEdit.AlignHCenter
            text: root.param

            Rectangle {
                height: 2
                width: paramEdit.width
                anchors.top: paramEdit.bottom
                border.color: "light gray"
            }
        }
    }

    Text {
        id: netLabel
        x: root.bodyOrigin.x + root.radius
        y: root.bodyOrigin.y + root.radius
        font.family: " Courier"
        font.pixelSize: 18
        visible: _net >= 0
        text: "net = " + _net
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

    Rectangle {
        id: biasInput
        width: root.border * 2
        height: root.radius
        x: root.bodyOrigin.x
        y: root.bodyOrigin.y - root.radius * 2
        color: "black"
        visible: root._bias

        Text {
            id: biasLabel
            x: 10
            y: -10
            font.family: " Courier"
            font.pixelSize: 14
            text: "bias = 1"
        }

        Text {
            id: bias_weight_text
            x: 10
            y: biasInput.height / 2 - height / 2
            font.family: " Courier"
            font.pixelSize: 18
            text: "w<sub>0</sub> = " + root._bias
            textFormat: Text.RichText
        }
    }

    Component.onCompleted: {
        for (var i = 0; i < root.children.length; ++i) {
            var input = root.children[i];
            if (input._isInput && !input.bias) {
                root._inputs.push(input);
                console.log(input.start)
            }
        }

        root._numInputs = root._inputs.length
        var bias_n = root._bias != 0 ? 1 : 0

        for (var i = 0; i < root._inputs.length; ++i) {
            root._inputs[i]._end = root.inputPos(i)
            root._inputs[i]._index = i + bias_n;
            console.log(root._inputs[i].start, root._inputs[i]._end)
        }
    }
}

