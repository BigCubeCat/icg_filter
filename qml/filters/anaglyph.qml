// anaglyph.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    anchors.fill: parent
    spacing: 10
    Text {
        text: "Anaglyph"
        font.family: "Helvetica"
        font.pointSize: 16
        font.bold: true
        width: parent.width
        wrapMode: Text.WordWrap
    }
    Text {
        width: parent.width
        text: "Данный фильтр преобразовывает изображения в анаглиф. Если посмотреть на получившееся изображение через 3D очки, то будет виден стерео эффект."
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
        text: "Второе изображение"
        font.family: "Helvetica"
        font.pointSize: 14
        font.bold: true
        wrapMode: Text.WordWrap
        ToolTip.visible: _mouseAreaTh.containsMouse
        ToolTip.text: "Выбор второго изображения из стерео пары, которое будет наложено на первое."
    }

    ImagePicker {
        id: imagePicker
        imageSource: anaglyph.imagePath
        onImageSourceChanged: anaglyph.imagePath = imageSource
        visible: false
    }

    Text {
        MouseArea {
            id: _mouseAreaSec
            hoverEnabled: true
            anchors.fill: parent
        }
        width: parent.width
        topPadding: 40
        text: "Смещение"
        font.family: "Helvetica"
        font.pointSize: 14
        font.bold: true
        wrapMode: Text.WordWrap
        ToolTip.visible: _mouseAreaSec.containsMouse
        ToolTip.text: "Выбор смещения по оси X с которым второе изображение будет наложено на первое"
    }
    SliderSpinBox {
        minValue: 0
        maxValue: 20
        value: anaglyph.offset
        onValueChanged: anaglyph.offset = value
    }


    Text {
        MouseArea {
            id: _mouseArea
            hoverEnabled: true
            anchors.fill: parent
        }
        width: parent.width
        topPadding: 20
        text: "Режим работы"
        font.family: "Helvetica"
        font.pointSize: 14
        font.bold: true
        wrapMode: Text.WordWrap
        ToolTip.visible: _mouseArea.containsMouse
        ToolTip.text: "Выбор режима работы:\nОдна картинка - текущее изображение будет наложено само на себя с заданным смещением.\nПара картинок - выбранная картинка будет наложена на текущую с заданным смещением"
    }
    ComboBox {

        id: list
        model: ["Одна картинка", "Пара картинок"]
        onActivated: {
            imagePicker.visible = list.currentIndex !== 0;
        }
    }
}
