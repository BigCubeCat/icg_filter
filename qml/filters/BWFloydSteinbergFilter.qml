import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    anchors.fill: parent
    spacing: 10
    Text {
        text: "Black White Floyd-Steinberg dithering"
        font.family: "Helvetica"
        font.pointSize: 16
        font.bold: true
        width: parent.width
        wrapMode: Text.WordWrap
    }

    Text {
        width: parent.width
        text: "Данный фильтр переводит изображение в чёрно белое и уменьшает количество цветов в палитре для каждого цвета, сохраняя общую композицию изображения."
        font.family: "Helvetica"
        font.pointSize: 10
        wrapMode: Text.WordWrap
    }
    SliderSpinBox {
        minValue: 2
        maxValue: 128
        value: bwfsf.red_quants
        onValueChanged: bwfsf.red_quants = value
    }
    SliderSpinBox {
        minValue: 2
        maxValue: 128
        value: bwfsf.green_quants
        onValueChanged: bwfsf.green_quants = value
    }
    SliderSpinBox {
        minValue: 2
        maxValue: 128
        value: bwfsf.blue_quants
        onValueChanged: bwfsf.blue_quants = value
    }

}
