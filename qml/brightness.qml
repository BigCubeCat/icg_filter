// brightness.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    spacing: 10
    SliderSpinBox {
        minValue: -50
        maxValue: 150
        title: "brightness"
        value: settings.brightness
        onValueChanged: settings.brightness = value
    }
}
