import QtQuick 2.15
import QtQuick.Controls
Column {
    anchors.fill: parent

    spacing: 10
    Text {
        text: "Aquarel"
        font.family: "Helvetica"
        font.pointSize: 16
        font.bold: true
        width: parent.width
        wrapMode: Text.WordWrap
    }
    Text {
        width: parent.width
        text: "Данный фильтр преобразовывает изображения в вид, похожий на рисунок акварелью."
        font.family: "Helvetica"
        font.pointSize: 10
        wrapMode: Text.WordWrap
    }
    Text {
        MouseArea {
            id: _mouseArea
            hoverEnabled: true
            anchors.fill: parent
        }
        width: parent.width
        topPadding: 20
        text: "Размер окна для выбора медианы:"
        font.family: "Helvetica"
        font.pointSize: 10
        font.bold: true
        wrapMode: Text.WordWrap
        ToolTip.visible: _mouseArea.containsMouse
        ToolTip.text: "Цвет в каждом пикселе выбирается как медиана из квадрата с заданной стороной вокруг данного пикселя."
    }
    ComboBox {
        width: parent.width
        id: list
        model: ["5x5","7x7", "9x9", "11x11"]
        onActivated: {
            aquarel.size = (2 * (list.currentIndex + 1) + 3);
        }
    }
}
