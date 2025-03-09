// brightness.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    spacing: 10
    Label {
        text: "brightness: " + brightnessSlider.value.toFixed(1)
    }
    SliderSpinBox {
        minValue: -50
        maxValue: 150
        value: settings.brightness
        onValueChanged: settings.brightness = value
    }
}
