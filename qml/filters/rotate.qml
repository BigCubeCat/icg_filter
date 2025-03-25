// rotate.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    anchors.fill: parent
    anchors.margins: 20
    spacing: 10
    Text {
        text: "Rotate"
    }

    SliderSpinBox {
        minValue: -180
        maxValue: 180
        title: "angle"
        value: rotate.angle
        onValueChanged: rotate.angle = value
    }
}
