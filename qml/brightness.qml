// brightness.qml
import QtQuick 2.15
import QtQuick.Controls 2.15

Column {
    spacing: 10
    
    Slider {
        id: brightnessSlider
        from: 0.0
        to: 2.0
        value: settings.brightness
        onValueChanged: settings.brightness = value
    }
    
    Label {
        text: "Яркость: " + brightnessSlider.value.toFixed(1)
    }
}
