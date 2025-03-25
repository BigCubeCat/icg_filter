import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    anchors.fill: parent
    anchors.margins: 20
    spacing: 10
    Text {
        text: "ordered-dithering"
    }
    SliderSpinBox {
        minValue: 2
        maxValue: 128
        title: "red"
        value: odf.red_quants
        onValueChanged: odf.red_quants = value
    }
    SliderSpinBox {
        minValue: 2
        maxValue: 128
        title: "green"
        value: odf.green_quants
        onValueChanged: odf.green_quants = value
    }
    SliderSpinBox {
        minValue: 2
        maxValue: 128
        title: "blue"
        value: odf.blue_quants
        onValueChanged: odf.blue_quants = value
    }
}
