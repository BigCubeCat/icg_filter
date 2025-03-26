// sepia.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    anchors.fill: parent
    spacing: 10

    Text {
        text: "Sepia"
        font.family: "Helvetica"
        font.pointSize: 16
        font.bold: true
        width: parent.width
        wrapMode: Text.WordWrap
    }

    Text {
        width: parent.width
        text: "Данный фильтр преобразует изображение к виду старой фотографии."
        font.family: "Helvetica"
        font.pointSize: 10
        wrapMode: Text.WordWrap
    }

    SliderSpinBox {
        minValue: 0
        maxValue: 100
        title: "Процент сепии"
        value: sepia.percent
        onValueChanged: sepia.percent = value
    }
}
