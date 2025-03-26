import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    anchors.fill: parent
    anchors.margins: 20
    spacing: 10
    Text {
        text: "floyd dithering"
    }

    SliderSpinBox {
        minValue: 2
        maxValue: 128
        title: "red"
        value: fsf.red_quants
        onValueChanged: fsf.red_quants = value
    }
    SliderSpinBox {
        minValue: 2
        maxValue: 128
        title: "green"
        value: fsf.green_quants
        onValueChanged: fsf.green_quants = value
    }
    SliderSpinBox {
        minValue: 2
        maxValue: 128
        title: "blue"
        value: fsf.blue_quants
        onValueChanged: fsf.blue_quants = value
    }
}
