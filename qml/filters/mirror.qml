// mirror.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    anchors.fill: parent
    spacing: 10

    Text {
        text: "Mirror"
        font.family: "Helvetica"
        font.pointSize: 16
        font.bold: true
        width: parent.width
        wrapMode: Text.WordWrap
    }

    Text {
        width: parent.width
        text: "Данный фильтр отражает изображение относительно заданной оси.\n"
        font.family: "Helvetica"
        font.pointSize: 10
        wrapMode: Text.WordWrap
    }
    ComboBox {
        id: comboBox
        width: 120
        currentIndex: mirror.value
        model: ["Вертикальная ось", "Горизонтальная ось"]
        onActivated: (index) => {
            console.log("Selected:", model[index])
            mirror.value = index
        }
    }
}
