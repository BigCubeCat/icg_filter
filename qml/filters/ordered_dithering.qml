import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    anchors.fill: parent
    anchors.margins: 20
    spacing: 10

    Text {
        text: "black-white dithering"
    }

    SliderSpinBox {
        minValue: 2
        maxValue: 255
        title: "count colors"
        value: bw_odf.quants
        onValueChanged: bw_odf.quants = value
    }
}
