import QtQuick 2.0

Item {
    id: root

    property int fontSize: 22
    property string name: ""
    property var input_vector: []
//    property var weights_vector: []
    property real param: 0
    property Perceptron net: undefined
    property bool isReady: o0_1.value && o0_0.value && o1_0.value && o1_1.value
    property bool singleInput: false
    property var output_vector: []
    property bool enabled_output: true

    signal clicked()

    Rectangle {
        y: root.height / 3
        width: root.width
        height: 2
        color: "black"
    }

    Rectangle {
        y: root.height / 3 * 2
        width: root.width
        height: 2
        color: "black"
    }

    Rectangle {
        x: root.width / 3
        height: root.height
        width: 2
        color: "black"
    }

    Rectangle {
        x: root.width / 3 * 2
        height: root.height
        width: 2
        color: "black"
    }

    Text {
        id: name

        x: root.width / 6 - width / 2
        y: root.height / 6 * 5 - height / 2
        font.pixelSize: root.fontSize
        font.family: " Courier"

        text: root.name

        MouseArea {
            anchors.fill: parent
            onClicked: root.clicked()
        }
    }

    Text {
        id: x0_1

        x: root.width / 6 - width / 2
        y: root.height / 6 - height / 2
        font.pixelSize: root.fontSize
        font.family: " Courier"

        text: root.input_vector[1]
    }

    Text {
        id: x0_0

        x: root.width / 6 - width / 2
        y: root.height / 6 * 3 - height / 2
        font.pixelSize: root.fontSize
        font.family: " Courier"

        text: root.input_vector[0]
    }

    Text {
        id: x1_0

        x: root.width / 6 * 5 - width / 2
        y: root.height / 6 * 5 - height / 2
        font.pixelSize: root.fontSize
        font.family: "Courier"

        text: root.input_vector[1]
    }

    Text {
        id: x1_1

        x: root.width / 6 * 3 - width / 2
        y: root.height / 6 * 5 - height / 2
        font.pixelSize: root.fontSize
        font.family: "Courier"

        text: input_vector[0]
    }

    Item {
        id: o1_0
        x: root.width / 3; width: root.width / 3
        y: 0; height: root.height / 3
        property string value: root.output_vector[0]

        Text {
            anchors.centerIn: parent
            font.pixelSize: root.fontSize
            font.family: "Courier"
            text: parent.value
        }

        MouseArea {
            enabled: enabled_output
            anchors.fill: parent
            onClicked: parent.value = net.resolve([root.input_vector[1], root.input_vector[0]], root.param)
        }
    }

    Item {
        id: o1_1
        x: root.width / 3 * 2; width: root.width / 3
        y: 0; height: root.height / 3
        property string value: root.output_vector[1]

        Text {
            anchors.centerIn: parent
            font.pixelSize: root.fontSize
            font.family: "Courier"
            text: parent.value
        }

        MouseArea {
            enabled: enabled_output
            anchors.fill: parent
            onClicked: parent.value = net.resolve([root.input_vector[1], root.input_vector[1]], root.param)
        }
    }

    Item {
        id: o0_0
        x: root.width / 3; width: root.width / 3
        y: root.height / 3; height: root.height / 3
        property string value: root.output_vector[2]

        Text {
            anchors.centerIn: parent
            font.pixelSize: root.fontSize
            font.family: "Courier"
            text: parent.value
        }

        MouseArea {
            enabled: enabled_output
            anchors.fill: parent
            onClicked: parent.value = net.resolve([root.input_vector[0], root.input_vector[0]], root.param)
        }
    }

    Item {
        id: o0_1
        x: root.width / 3 * 2; width: root.width / 3
        y: root.height / 3; height: root.height / 3
        property string value: root.output_vector[3]

        Text {
            anchors.centerIn: parent
            font.pixelSize: root.fontSize
            font.family: "Courier"
            text: parent.value
        }

        MouseArea {
            enabled: enabled_output
            anchors.fill: parent
            onClicked: parent.value = net.resolve([root.input_vector[0], root.input_vector[1]], root.param)
        }
    }
}

