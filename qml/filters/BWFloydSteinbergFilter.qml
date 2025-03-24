import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    anchors.fill: parent
    anchors.margins: 20
    spacing: 10
    Text {
        text: "b-w floyd dithering"
    }

    SliderSpinBox {
        minValue: 2
        maxValue: 255
        title: "count colors"
        value: bwfsf.quants
        onValueChanged: bwfsf.quants = value
    }
}
