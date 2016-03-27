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
        id: slideArtificialNeuron
        title: "Artificial Neuron (Perceptron)"

        Perceptron {
            id: perceptron
            anchors.horizontalCenter: slideArtificialNeuron.horizontalCenter

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

            Rectangle {
            }
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
}
