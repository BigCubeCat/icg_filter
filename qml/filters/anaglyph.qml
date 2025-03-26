// anaglyph.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    anchors.fill: parent
    anchors.margins: 20
    spacing: 10
    Text {
        text: "anaglyph"
    }

    ImagePicker {
        id: imagePicker
        imageSource: anaglyph.imagePath
        onImageSourceChanged: anaglyph.imagePath = imageSource
    }

    SliderSpinBox {
        minValue: 0
        maxValue: 20
        title: "Смещение"
        value: anaglyph.offset
        onValueChanged: anaglyph.offset = value
    }

    ComboBox {
        id: list
        model: ["Одна картинка", "Пара картинок"]
        onActivated: {
            imagePicker.visible = list.currentIndex !== 0;
        }
    }
}
