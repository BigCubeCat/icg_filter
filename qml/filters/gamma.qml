import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    anchors.fill: parent
    spacing: 10

    Text {
        text: "Gamma"
        font.family: "Helvetica"
        font.pointSize: 16
        font.bold: true
        width: parent.width
        wrapMode: Text.WordWrap
    }
    Text {
        width: parent.width
        text: "Данный фильтр изменяет гамму изображения.\n\nПоказатель определяет степень в которую возводится значение каждого цвета в каждом пикселе."
        font.family: "Helvetica"
        font.pointSize: 10
        wrapMode: Text.WordWrap
    }

    SliderSpinBoxF {
        title: "Показатель"
        onRealValueChanged: gamma.gamma = realValue
    }
}