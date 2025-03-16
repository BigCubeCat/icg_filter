// sepia.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    anchors.fill: parent
    anchors.margins: 20

    spacing: 10
    SliderSpinBox {
        minValue: 0
        maxValue: 100
        title: "sepia percent"
        value: sepia.percent
        onValueChanged: sepia.percent = value
    }
}
