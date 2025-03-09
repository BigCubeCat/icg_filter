// contrast.qml
import QtQuick 2.15
import QtQuick.Controls 2.15

Column {
    spacing: 10
    
    Slider {
        id: contrastSlider
        from: 0.0
        to: 3.0
        value: filterSettings.contrast
        onValueChanged: filterSettings.contrast = value
    }
    
    Label {
        text: "Контраст: " + contrastSlider.value.toFixed(1)
    }
}
