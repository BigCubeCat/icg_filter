// emboss.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    anchors.fill: parent
    spacing: 10

    Text {
        text: "Emboss"
        font.family: "Helvetica"
        font.pointSize: 16
        font.bold: true
        width: parent.width
        wrapMode: Text.WordWrap
    }
    Text {
        width: parent.width
        text: "Данный фильтр преображает изображение к виду тиснения."
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
        text: "Смещение по X"
        font.family: "Helvetica"
        font.pointSize: 14
        font.bold: true
        wrapMode: Text.WordWrap
        ToolTip.visible: _mouseArea.containsMouse
        ToolTip.text: "Разность по X между сравниваемыми пикселями."
    }
    SliderSpinBox {
        minValue: -2
        maxValue: 2
        value: emboss.offsetX
        onValueChanged: emboss.offsetX = value
    }

    Text {
        MouseArea {
            id: _mouseAreaSec
            hoverEnabled: true
            anchors.fill: parent
        }
        width: parent.width
        topPadding: 20
        text: "Смещение по Y"
        font.family: "Helvetica"
        font.pointSize: 14
        font.bold: true
        wrapMode: Text.WordWrap
        ToolTip.visible: _mouseAreaSec.containsMouse
        ToolTip.text: "Разность по Y между сравниваемыми пикселями."
    }
    SliderSpinBox {
        minValue: -2
        maxValue: 2
        title: "offset Y"
        value: emboss.offsetY
        onValueChanged: emboss.offsetY = value
    }


    Text {
        MouseArea {
            id: _mouseAreaTh
            hoverEnabled: true
            anchors.fill: parent
        }
        width: parent.width
        topPadding: 20
        text: "Цвет поверхности"
        font.family: "Helvetica"
        font.pointSize: 14
        font.bold: true
        wrapMode: Text.WordWrap
        ToolTip.visible: _mouseAreaTh.containsMouse
        ToolTip.text: "Выбор цвета поверхности на которой происходит тиснение."
    }
    ColorSelect {
        selectedColor: "#888888"  // Начальный цвет
        previewSize: 120
        onColorChanged: {
            console.log("New color selected:", colorHex)
            emboss.color = colorHex
        }
    }
}
