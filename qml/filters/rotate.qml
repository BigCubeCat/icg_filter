// rotate.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    anchors.fill: parent
    spacing: 10
    Text {
        text: "Rotate"
        font.family: "Helvetica"
        font.pointSize: 16
        font.bold: true
        width: parent.width
        wrapMode: Text.WordWrap
    }

    Text {
        width: parent.width
        text: "Данный фильтр поворачивает изображение на заданный угол по часовой стрелке."
        font.family: "Helvetica"
        font.pointSize: 10
        wrapMode: Text.WordWrap
    }
    SliderSpinBox {
        minValue: -180
        maxValue: 180
        title: "Угол"
        value: rotate.angle
        onValueChanged: rotate.angle = value
    }
}
