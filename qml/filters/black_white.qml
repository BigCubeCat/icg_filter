import QtQuick 2.15


Column {
    anchors.fill: parent
    spacing: 10
    Text {
        text: "Black & White"
        font.family: "Helvetica"
        font.pointSize: 16
        font.bold: true
        width: parent.width
        wrapMode: Text.WordWrap
    }
    Text {
        width: parent.width
        text: "Данный фильтр преобразовывает изображение в чёрно-белое"
        font.family: "Helvetica"
        font.pointSize: 10
        wrapMode: Text.WordWrap
    }
}
