import QtQuick 2.0
import Qt.labs.presentation 1.0

Presentation {
    width: 1280
    height: 720

    Rectangle {
        anchors.fill: parent
        gradient: Gradient {
            GradientStop { position: 0.16; color: "green" }
            GradientStop { position: 0.17; color: "white" }
            GradientStop { position: 0.92; color: "white" }
            GradientStop { position: 0.93; color: "green" }
        }
    }

    Clock { textColor: "white" }
    SlideCounter { textColor: "white" }

    titleColor: "white"

    showNotes: false

    Slide {
        id: firstSlide;
        centeredText: "Introduction to Artificial Neural Networks"
        fontScale: 2
    }

    Slide {
        id: slideRobot
        title: "Why Artificial Neural Networks"
        contentWidth: width - imageRobot.width - 20
//        delayPoints: true

        footerText: "Robby The Robot (1956 Forbidden Planet)"

        content: [
            "people always dreamed of sentient machines",
            "we often mimic nature to solve problems",
            "humans have a neural network",
            "intelligent machines could use one as well",
            "so how do we create an artificial brain?"
        ]

        // TODO: add an animation on position and scale form center big -> right small on first "advance"
        Image {
            id: imageRobot
            anchors.right: slideRobot.right
            source: "qrc:/images/RobbieRobot.jpg"
        }
    }

    Slide {
        id: slideHistory
        title: "A bit of history"
        bulletSpacing: 0.80

        content: [
            "1943 - Warren McCulloch and Walter Pitts model a simple neural network using electrical circuits",
            "1949 - Donald Hebb wrote \"The Organization of Behavior\", in which he pointed out the fact that neural pathways are strengthened each time they are used",
            "1959 - Bernard Widrow and Marcian Hoff of Stanford University created \"ADALINE\" and \"MADALINE\".",
            "1986 - Three independent groups of researchers, come up with similar ideas which are now called back propagation networks",
            "now  - Advancement in computer hardware allows us to revisit Artificial Neural Networks"
        ]

        footerText: "https://cs.stanford.edu"

        notes: "
            https://cs.stanford.edu/people/eroberts/courses/soco/projects/neural-networks/History/history1.html
            ad 1943 - neurophysiologist Warren McCulloch and mathematician Walter Pitts wrote a paper on how neurons might work,
            ad 1949 - If two nerves fire at the same time, he argued, the connection between them is enhanced.
            ad 1959 - Models that could recognize patterns on the phone line transmission
            ad 1986 - back propagation learning method often requires thousands of iterations"
    }

    Slide {
        id: slideBiologicalNeuron
        title: "Biological Neuron"
        contentWidth: width * imageContentRatio
        property real imageContentRatio: 0.50

        //footerText: "Robby The Robot (1956 Forbidden Planet)"

        content: [
            "a neuron consist of a nucleus, axon and dendrites (plus a lot more)",
            "human brain contains about 86 billion (86×10⁹) neuron cells",
            "each neuron cell is connected to more than 10k other neurons",
            "nerve signal travels through an axon to dendrites of another neuron"
        ]

        Image {
            id: imageNeuron
            width: slideBiologicalNeuron.width * (1 - slideBiologicalNeuron.imageContentRatio)
            height: slideBiologicalNeuron.height
            fillMode: Image.PreserveAspectFit
            anchors.right: slideBiologicalNeuron.right
            source: "qrc:/images/Neuron_Hand-tuned.svg"
            property int yOffset: (imageNeuron.height - imageNeuron.paintedHeight) / 2

            Text { x:  77; y: imageNeuron.yOffset +  9; text: "<b>Dendrite</b>" }
            Text { x: 195; y: imageNeuron.yOffset + 100; text: "Soma" }
            Text { x:  25; y: imageNeuron.yOffset + 290; text: "<b>Nucleus</b>" }
            Text { x: 275; y: imageNeuron.yOffset + 178; text: "<b>Axon</b>" }
            Text { x: 292; y: imageNeuron.yOffset + 268; text: "Myelin sheath" }
            Text { x: 323; y: imageNeuron.yOffset +  90; text: "Node of Ranvier" }
            Text { x: 410; y: imageNeuron.yOffset + 231; text: "Schwann cell" }
            Text { x: 460; y: imageNeuron.yOffset +  33; text: "Axon terminal" }
        }

        footerText: "https://en.wikipedia.org/wiki/Neuron"

        notes: "Axons can extend tens, hundreds, or even tens of thousands of times the diameter of the soma in length.
                Sensory neurons can have axons that run from the toes to the spinal cord, over 1.5 meters in adults"
    }

    Slide {
        id: slidePerceptron
        title: "Artificial Neuron (Perceptron)"
        bulletSpacing: 1.2

        Perceptron {
            id: perceptron
            anchors.horizontalCenter: slidePerceptron.horizontalCenter

            radius: 75

            Input {
                start: Qt.point(200, perceptron.bodyOrigin.y - 100)
                lineWidth: perceptron.border * 2
            }

            Input {
                start: Qt.point(200, perceptron.bodyOrigin.y - 40)
                lineWidth: perceptron.border * 2
            }

            Input {
                start: Qt.point(200, perceptron.bodyOrigin.y + 40)
                lineWidth: perceptron.border * 2
            }

            Input {
                start: Qt.point(200, perceptron.bodyOrigin.y + 100)
                lineWidth: perceptron.border * 2
            }

            Text {
                x:390; y: 280
                text: "Weighted sum"
                font.pixelSize: 22
            }

            Text {
                x:590; y: 120
                text: "Step function"
                font.pixelSize: 22
            }

            Rectangle {
                id: stepFunction
                x: 590; y: 240

                Text {
                    y: 0
                    text: "     ⎧ 1, x ≥ p\nf(x)=⎨\n     ⎩ 0, x < p"
                    lineHeightMode: Text.FixedHeight
                    lineHeight: font.pixelSize
                    font.pixelSize: 22
                    font.family: " Courier"
                }
            }
        }

        Text {
            width: slidePerceptron.contentWidth
            anchors.top: perceptron.bottom
            text: "The perceptron calculates the weighted sum of all inputs, then calculates the output using the transfer function as shown above. In multilayer networks this output is fed to other perceptrons."
            font.pixelSize: slidePerceptron.baseFontSize
            font.family: slidePerceptron.fontFamily
            color: slidePerceptron.textColor
            wrapMode: Text.WordWrap
            lineHeightMode: Text.FixedHeight
            lineHeight: slidePerceptron.baseFontSize * slidePerceptron.bulletSpacing
        }

        notes: "The perceptron is a mathematical model of a biological neuron.
                While in actual neurons the dendrite receives electrical signals from the axons of other neurons,
                in the perceptron these electrical signals are represented as numerical values.
                At the synapses between the dendrite and axons, electrical signals are modulated in various amounts.
                This is also modeled in the perceptron by multiplying each input value by a value called the weight.
                An actual neuron fires an output signal only when the total strength of the input signals exceed a certain threshold.
                We model this phenomenon in a perceptron by calculating the weighted sum of the inputs to represent the total strength of the input signals,
                and applying a step function on the sum to determine its output.
                As in biological neural networks, this output is fed to other perceptrons."
    }

    Slide {
        id: slidePerceptronLinearSeparation
        title: "How the perceptron works"
        textFormat: Text.RichText
        contentWidth: 650
        bulletSpacing: 0.65

        content: [
            "let us assume that there are two input values, <i>x</i> and <i>y</i>",
            "and the weights for <i>x</i> and <i>y</i> be <i>A</i> and <i>B</i> respectively",
            "the weighted sum could be represented as: <i>Ax + By</i>",
            "if we recall the transfer function",
            "",
            "we can imagine that it separates <i>xy</i> plane by a straight line"
        ]

        Text {
            x: 45
            y: 330
            text: "     ⎧ 1, Ax + By ≥ C\nf(x)=⎨\n     ⎩ 0, Ax + By < C"
            lineHeightMode: Text.FixedHeight
            lineHeight: font.pixelSize
            font.pixelSize: 22
            font.family: " Courier"
        }


        Item {
            x: slidePerceptronLinearSeparation.contentWidth + 100
            y: 100
            Text {
                x: 50; y: 180
                text: "Ax + By + C = 0"
                font.pixelSize: 20
                font.family: " Courier"
                rotation: -30
            }
            Rectangle {
                x: 30; y: 146; height: 4; width: 400
                rotation: -30
                color: "dark grey"
            }
            Text {
                x: 166; y: 25
                text: "(x,y)"
                font.pixelSize: 20
                font.family: " Courier"
            }
            Rectangle { width: 5; height: width; radius: width; color: "red"; x: 156; y: 35 }
            Rectangle { width: 5; height: width; radius: width; color: "red"; x: 165; y: 65 }
            Rectangle { width: 5; height: width; radius: width; color: "red"; x: 120; y: 76 }
            Rectangle { width: 5; height: width; radius: width; color: "red"; x: 145; y: 68 }
            Rectangle { width: 5; height: width; radius: width; color: "red"; x:  80; y: 100 }
            Rectangle { width: 5; height: width; radius: width; color: "red"; x:  60; y: 135 }
            Rectangle { width: 5; height: width; radius: width; color: "red"; x: 115; y: 145 }
            Rectangle { width: 5; height: width; radius: width; color: "red"; x: 145; y: 165 }
            Rectangle { width: 5; height: width; radius: width; color: "red"; x: 138; y: 115 }
            Rectangle { width: 5; height: width; radius: width; color: "red"; x:  90; y: 86 }
            Rectangle { width: 5; height: width; radius: width; color: "red"; x: 115; y: 78 }
            Rectangle { width: 5; height: width; radius: width; color: "red"; x: 130; y: 98 }
            Rectangle { width: 5; height: width; radius: width; color: "red"; x:  80; y: 135 }
            Rectangle { width: 5; height: width; radius: width; color: "red"; x: 345; y: 075 }
            Rectangle { width: 5; height: width; radius: width; color: "red"; x: 238; y: 115 }
            Rectangle { width: 5; height: width; radius: width; color: "red"; x: 190; y:  86 }
            Rectangle { width: 5; height: width; radius: width; color: "red"; x: 215; y:  78 }
            Rectangle { width: 5; height: width; radius: width; color: "red"; x: 230; y:  98 }
            Rectangle { width: 5; height: width; radius: width; color: "red"; x: 180; y: 135 }

            Rectangle { width: 5; height: width; radius: width; color: "blue"; x: 315; y: 145 }
            Rectangle { width: 5; height: width; radius: width; color: "blue"; x: 115; y: 245 }
            Rectangle { width: 5; height: width; radius: width; color: "blue"; x: 205; y: 184 }
            Rectangle { width: 5; height: width; radius: width; color: "blue"; x: 218; y: 165 }
            Rectangle { width: 5; height: width; radius: width; color: "blue"; x: 365; y: 145 }
            Rectangle { width: 5; height: width; radius: width; color: "blue"; x: 145; y: 245 }
            Rectangle { width: 5; height: width; radius: width; color: "blue"; x: 225; y: 184 }
            Rectangle { width: 5; height: width; radius: width; color: "blue"; x: 211; y: 175 }
            Rectangle { width: 5; height: width; radius: width; color: "blue"; x: 335; y: 145 }
            Rectangle { width: 5; height: width; radius: width; color: "blue"; x: 125; y: 225 }
            Rectangle { width: 5; height: width; radius: width; color: "blue"; x: 215; y: 202 }
            Rectangle { width: 5; height: width; radius: width; color: "blue"; x: 220; y: 225 }
        }
    }

    Slide {
        id: slideLogicGate
        title: "Perceptron as a logic gate"
        bulletSpacing: 1.2

        Perceptron {
            id: logicPerceptron

//            anchors.horizontalCenter: slideLogicGate.horizontalCenter
            x: 50
            radius: 50
            param: 1 // TODO: allow modification on the slide
            _net: 0

            Input {
                start: Qt.point(100, logicPerceptron.bodyOrigin.y - 75)
                lineWidth: logicPerceptron.border * 2
                weight: 0.5
            }

            Input {
                start: Qt.point(100, logicPerceptron.bodyOrigin.y + 75)
                lineWidth: logicPerceptron.border * 2
                weight: 0.5
            }
        }

        Table {
            id: tableAnd
            x: 100; y: 300
            width: 150; height: 150
            name: "AND"
            input_vector: [0, 1]
//            weights_vector: [0.5,0.5]
//            param: 1
            net: logicPerceptron

            Line {
                start: Qt.point(tableAnd.width / 3, -20)
                end: Qt.point(tableAnd.width + 20, tableAnd.height / 3 * 2)
                lineColour: "red"
                lineWidth: 3
                visible: tableAnd.isReady
                opacity: visible ? 1.0 : 0.0

                Behavior on opacity {
                    NumberAnimation {
                        duration: 1500
                    }
                }
            }
        }

        Table {
            id: tableOr
            x: 400; y: 300
            width: 150; height: 150
            name: "OR"
            input_vector: [0, 1]
//            weights_vector: [0.5,0.5]
//            param: 0.5
            net: logicPerceptron

            Line {
                start: Qt.point(tableOr.width / 5, -5)
                end: Qt.point(tableOr.width + 5, tableOr.height * 0.8)
                lineColour: "red"
                lineWidth: 3
                visible: tableOr.isReady
                opacity: visible ? 1.0 : 0.0

                Behavior on opacity {
                    NumberAnimation {
                        duration: 1500
                    }
                }
            }
        }

        Perceptron {
            id: notPerceptron

//            anchors.horizontalCenter: slideLogicGate.horizontalCenter
            x: 550
            radius: 50
            param: 1 // TODO: allow modification on the slide
            _net: 0
            _bias: 1

            Input {
                start: Qt.point(100, logicPerceptron.bodyOrigin.y)
                lineWidth: logicPerceptron.border * 2
                weight: -0.5
            }
        }

        SmallTable {
            id: tableNot
            x: 650; y: 300
            width: 150; height: 150
            name: "NOT"
            input_vector: [0, 1]
//            param: 0
            net: notPerceptron

            Line {
                start: Qt.point(tableNot.width / 3 * 2 + 3, -20)
                end: Qt.point(tableNot.width / 3 * 2 + 3, tableNot.height + 20)
                lineColour: "red"
                lineWidth: 3
                visible: tableNot.isReady
                opacity: visible ? 1.0 : 0.0

                Behavior on opacity {
                    NumberAnimation {
                        duration: 1500
                    }
                }
            }
        }

        Table {
            id: tableXor
            x: 950; y: 300
            width: 150; height: 150
            name: "XOR"
            input_vector: [0, 1]
//            weights_vector: [0.5,0.5]
//            param: 0.5
            net: logicPerceptron
            enabled_output: false

            Line {
                id: line1
                start: Qt.point(tableXor.width / 5, -5)
                end: Qt.point(tableXor.width + 5, tableXor.height * 0.8)
                lineColour: "red"
                lineWidth: 3
                visible: false
                opacity: visible ? 1.0 : 0.0

                Behavior on opacity {
                    NumberAnimation {
                        duration: 1500
                    }
                }
            }

            Line {
                id: line2
                start: Qt.point(tableXor.width / 3, -20)
                end: Qt.point(tableXor.width + 20, tableXor.height / 3 * 2)
                lineColour: "red"
                lineWidth: 3
                visible: false
                opacity: visible ? 1.0 : 0.0

                Behavior on opacity {
                    NumberAnimation {
                        duration: 1500
                    }
                }
            }

            Text {
                id: doesntWork
                x: tableXor.width - width + 30
                y: tableXor.height + 5
                visible: false
                opacity: visible ? 1.0 : 0.0
                font.family: " Courier"
                font.pixelSize: 24
                color: "red"
                text: "<b>no solution!</b>"

                Behavior on opacity {
                    SequentialAnimation {
                        PauseAnimation { duration: 1500 }
                        NumberAnimation {
                            easing: Easing.InQuint
                            duration: 2000
                        }
                    }
                }
            }

            onClicked: {
                line1.visible = true
                line2.visible = true
                doesntWork.visible = true
                tableXor.output_vector = [1, 0, 0, 1]
            }
        }

        notes: "not all logic operators are linearly separable.
                For instance, the XOR operator is not linearly separable
                and cannot be achieved by a single perceptron.

                Yet this problem could be overcome by using more
                than one perceptron arranged in feed-forward networks"
    }

    Slide {
        id: slideTypesOfProblems
        title: "General functions of neural networks"
        footerText: "https://cs.stanford.edu"
        bulletSpacing: 1.5
        delayPoints: true
        textFormat: Text.RichText
        content: [
            "<b>Classification</b>: separation of input data into specified classes<br>
                like handrwritten character recognition",
            "<b>Clustering</b>: grouping together objects that are similar to each other<br>
                e.g. data conceptualization, traveling salesman problem",
            "<b>Prediction</b>: given a sequence of data, predict the upcoming ones<br>
                e.g. Stock market forecasting",
            "<b>Associative memory</b>: restore deformed input samples to its original content,
                filter noisy samples, compress and decompress images"
        ]
    }

    Slide {
        id: slideTypesOfNetworks
        title: "Types of artificial neural networks"
        footerText: "https://cs.stanford.edu\nhttps://en.wikipedia.org/wiki/Artificial_neural_network"
        Text {
            id: feedForwardText
            x: 50
            font.pixelSize: slideTypesOfNetworks.baseFontSize
            font.family: slideTypesOfNetworks.fontFamily
            color: slideTypesOfNetworks.textColor
            text: "Feed-forward networks"
        }

        Image {
            id: imageFF
            anchors.horizontalCenter: feedForwardText.horizontalCenter
            anchors.top: feedForwardText.bottom
            source: "qrc:/images/feed_forward.png"
            width: 300
            fillMode: Image.PreserveAspectFit
        }

        Text {
            anchors.horizontalCenter: feedForwardText.horizontalCenter
            anchors.top: imageFF.bottom
            font.pixelSize: slideTypesOfNetworks.baseFontSize * 0.8
            font.family: slideTypesOfNetworks.fontFamily
            color: slideTypesOfNetworks.textColor
            text: "Good at classification and prediction"
        }

        Text {
            id: recursiveText
            x: 710
            font.pixelSize: slideTypesOfNetworks.baseFontSize
            font.family: slideTypesOfNetworks.fontFamily
            color: slideTypesOfNetworks.textColor
            text: "Recursive networks"
        }

        Image {
            id: imageRecursive
            anchors.horizontalCenter: recursiveText.horizontalCenter
            anchors.top: recursiveText.bottom
            source: "qrc:/images/Hopfield-net.png"
            width: 300
            height: imageFF.height
            fillMode: Image.PreserveAspectFit
        }

        Text {
            anchors.horizontalCenter: recursiveText.horizontalCenter
            anchors.top: imageRecursive.bottom
            font.pixelSize: slideTypesOfNetworks.baseFontSize * 0.8
            font.family: slideTypesOfNetworks.fontFamily
            color: slideTypesOfNetworks.textColor
            text: "Associative memory, good at recognizing samples"
        }
    }

    Slide {
        id: slideFeedForward
        title: "Multi layer feed-forward networks"
        footerText: "https://cs.stanford.edu"

        Text {
            id: feedForwardDescr
            width: parent.contentWidth
            font.pixelSize: slideFeedForward.baseFontSize
            font.family: slideFeedForward.fontFamily
            color: slideFeedForward.textColor
            wrapMode: Text.WordWrap
            text: "Lets consider the two linearly inseparable regions.<br>
                Using more than one line, we can consider the center region
                as the <i>intersection</i> of linearly separable regions specified by the lines."
        }

        Image {
            id: imageRegionMarked
            anchors.top: feedForwardDescr.bottom
            source: "qrc:/images/regions_marked.png"
            x: 50
            width: 300
            height: imageFF.height
            fillMode: Image.PreserveAspectFit
        }

        Image {
            id: imageFeedForwardXY
            anchors.top: feedForwardDescr.bottom
            source: "qrc:/images/feedForwardXY.png"
            x: 400
            width: 300
            height: imageFF.height
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: feedForwardXYDescr
            anchors.left: imageFeedForwardXY.right
            anchors.right: slideFeedForward.right
            y: 150
            font.pixelSize: slideFeedForward.baseFontSize
            font.family: slideFeedForward.fontFamily
            color: slideFeedForward.textColor
            wrapMode: Text.WordWrap
            text: "Each perceptron in the hidden layer identifies a linear-separable region.<br><br>While the output perceptron perform AND oeration on the outputs of the hidden layer to find the union of these regions"
        }
    }

    Slide {
        id: slideHamming
        title: "Hamming Recursive Network"
        footerText: "Zastosowanie metod sztucznej inteligencji w algorytmach detekcji krawedzi (Konrad Ciekot 2007)"

        Text {
            id: hammingDescr
            width: parent.contentWidth
            font.pixelSize: slideFeedForward.baseFontSize
            font.family: slideFeedForward.fontFamily
            color: slideFeedForward.textColor
            wrapMode: Text.WordWrap
            text: "It's heteroassociative memory haracteristics mean it can associate any two given patterns. That includes classification problem as well. It will return the correct output even when the input pattern is damaged or incomplete."
        }

        Image {
            id: imageHamming
            anchors.top: hammingDescr.bottom
            source: "qrc:/images/hamming.png"
            x: 50
            width: 400
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: hammingDescr2
            anchors.left: imageHamming.right
            anchors.right: slideHamming.right
            y: 130
            font.pixelSize: slideHamming.baseFontSize * 0.9
            font.family: slideHamming.fontFamily
            color: slideHamming.textColor
            wrapMode: Text.WordWrap
            text: "
                The first layer is responsible for calculation of Hamming Distance from the input vector to each of the learning patters.<br>
                Such distance vector is then fed to the neurons in the Maxnet layer.<br>
                Maxnet determines a \"winner\" node, the one that is representing the closest training pattern for the given input.<br>
                The output pattern is then reconstructed by the weights in the output layer for that node."
        }

        notes: "Hamming network is built using an input layer, the hidden Maxnet layer and the output layer. Only the Maxnet layer has recursive connections."
    }
}
