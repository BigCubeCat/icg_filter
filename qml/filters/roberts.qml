import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    anchors.fill: parent
    anchors.margins: 20
    spacing: 10

    SliderSpinBox {
        minValue: 0
        maxValue: 610
        title: "threshold"
        value: roberts.threshold
        onValueChanged: roberts.threshold = value
    }
}