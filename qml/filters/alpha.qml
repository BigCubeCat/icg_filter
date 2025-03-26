// alpha.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    anchors.fill: parent
    spacing: 10
    Text {
        text: "Alpha filter"
        font.family: "Helvetica"
        font.pointSize: 16
        font.bold: true
        width: parent.width
        wrapMode: Text.WordWrap
    }
    Text {
        width: parent.width
        text: "Данный фильтр накладывает выбранное изображение на текущее с заданной прозрачностью."
        font.family: "Helvetica"
        font.pointSize: 10
        wrapMode: Text.WordWrap
    }

    Text {

        MouseArea {
            id: _mouseAreaTh
            hoverEnabled: true
            anchors.fill: parent
        }
        width: parent.width
        topPadding: 40
        text: "Процент прозрачности"
        font.family: "Helvetica"
        font.pointSize: 14
        font.bold: true
        wrapMode: Text.WordWrap
        ToolTip.visible: _mouseAreaTh.containsMouse
        ToolTip.text: "Определяет процент прозрачности с которым второе изображение накладывается на первое."
    }
    SliderSpinBox {
        minValue: 1
        maxValue: 99
        value: alpha.percent
        onValueChanged: alpha.percent = value
    }


    Text {
        MouseArea {
            id: _mouseAreaSec
            hoverEnabled: true
            anchors.fill: parent
        }
        width: parent.width
        topPadding: 40
        text: "Режим работы"
        font.family: "Helvetica"
        font.pointSize: 14
        font.bold: true
        wrapMode: Text.WordWrap
        ToolTip.visible: _mouseAreaSec.containsMouse
        ToolTip.text: "Масштаб - масштабирует второе изображение под первое\nЗамощение - укладывает плиткой второе изображение.\nИгнор - второе изображение не изменяется"
    }
    ComboBox {
        id: comboBox
        width: 120
        currentIndex: alpha.variant
        model: ["Масштаб", "Замощение", "Игнор"]

        onActivated: (index) => {
            console.log("выбрано:", model[index])
            alpha.variant = index
        }
    }

    Text {
        MouseArea {
            id: _mouseArea
            hoverEnabled: true
            anchors.fill: parent
        }
        width: parent.width
        topPadding: 40
        text: "Второе изображение"
        font.family: "Helvetica"
        font.pointSize: 14
        font.bold: true
        wrapMode: Text.WordWrap
        ToolTip.visible: _mouseArea.containsMouse
        ToolTip.text: "Путь до изображения, которое будет наложено на первое."
    }
    ImagePicker {
        id: imagePicker
        imageSource: alpha.imagePath
        onImageSourceChanged: alpha.imagePath = imageSource
    }
}
