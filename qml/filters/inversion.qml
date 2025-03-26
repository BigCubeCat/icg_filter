import QtQuick 2.15
Column {
    spacing: 10
    Text {
        text: "Inversion"
        font.family: "Helvetica"
        font.pointSize: 16
        font.bold: true
        width: parent.width
        wrapMode: Text.WordWrap
    }
    Text {
        width: parent.width
        text: "Данный фильтр преобразовывает изображение в его инверсию"
        font.family: "Helvetica"
        font.pointSize: 10
        wrapMode: Text.WordWrap
    }
}
