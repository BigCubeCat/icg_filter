import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    anchors.fill: parent
    spacing: 10
    Text {
        text: "Ordered dithering"
        font.family: "Helvetica"
        font.pointSize: 16
        font.bold: true
        width: parent.width
        wrapMode: Text.WordWrap
    }
    Text {
        width: parent.width
        text: "Данный фильтр уменьшает количество цветов в палитре для каждого цвета, сохраняя общую композицию изображения."
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
        text: "Красный канал"
        font.family: "Helvetica"
        font.pointSize: 14
        font.bold: true
        wrapMode: Text.WordWrap
        ToolTip.visible: _mouseArea.containsMouse
        ToolTip.text: "Количество квантов цвета в красном канале."
    }
    SliderSpinBox {
        minValue: 2
        maxValue: 128
        value: bw_odf.red_quants
        onValueChanged: bw_odf.red_quants = value
    }
    Text {
        MouseArea {
            id: _mouseAreaSec
            hoverEnabled: true
            anchors.fill: parent
        }
        width: parent.width
        topPadding: 40
        text: "Зелёный канал"
        font.family: "Helvetica"
        font.pointSize: 14
        font.bold: true
        wrapMode: Text.WordWrap
        ToolTip.visible: _mouseAreaSec.containsMouse
        ToolTip.text: "Количество квантов цвета в зелёном канале."
    }
    SliderSpinBox {
        minValue: 2
        maxValue: 128
        value: bw_odf.green_quants
        onValueChanged: bw_odf.green_quants = value
    }
    Text {

        MouseArea {
            id: _mouseAreaTh
            hoverEnabled: true
            anchors.fill: parent
        }
        width: parent.width
        topPadding: 40
        text: "Синий канал"
        font.family: "Helvetica"
        font.pointSize: 14
        font.bold: true
        wrapMode: Text.WordWrap
        ToolTip.visible: _mouseAreaTh.containsMouse
        ToolTip.text: "Количество квантов цвета в синем канале."
    }
    SliderSpinBox {
        minValue: 2
        maxValue: 128
        value: bw_odf.blue_quants
        onValueChanged: bw_odf.blue_quants = value
    }
}

