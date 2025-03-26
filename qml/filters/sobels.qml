import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    anchors.fill: parent
    spacing: 10

    Text {
        text: "Sobel filter"
        font.family: "Helvetica"
        font.pointSize: 16
        font.bold: true
        width: parent.width
        wrapMode: Text.WordWrap
    }
    Text {
        width: parent.width
        text: "Данный фильтр оставляет только границы объектов на изображении. Для этого он считает вектор производных в точке и если градиент по модулю превосходит пороговое значение, то данный пиксель появится на итоговой картинке."
        font.family: "Helvetica"
        font.pointSize: 10
        wrapMode: Text.WordWrap
    }
    SliderSpinBox {
        minValue: 0
        maxValue: 610
        title: "Пороговое значение"
        value: sobels.threshold
        onValueChanged: sobels.threshold = value
    }
}
