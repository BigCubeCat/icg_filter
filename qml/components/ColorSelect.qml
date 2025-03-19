import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 


Item {
    id: cs
    property color selectedColor: "white"
    property string colorHex: selectedColor.toString().toUpperCase()
    property alias buttonText: colorButton.text
    property alias previewSize: colorPreview.width
    
    // Сигнал при изменении цвета
    signal colorChanged(color newColor)
    
    implicitWidth: 140
    implicitHeight: 150
    
    // Логика выбора цвета
    function openColorDialog() {
        colorDialog.open()
    }

    ColorDialog {
        id: colorDialog
        title: "Выберите цвет"
        selectedColor: cs.selectedColor
        
        onAccepted: {
            cs.selectedColor = colorDialog.selectedColor
            cs.colorChanged(cs.selectedColor)
        }
    }
    Column {
        Rectangle {
            id: colorPreview
            width: 100
            height: 60
            color: cs.selectedColor
            border.color: "black"
            anchors.horizontalCenter: parent.horizontalCenter
        }
        
        Text {
            text: cs.colorHex
            font.pixelSize: 16
            anchors.horizontalCenter: parent.horizontalCenter
        }
        
        Button {
            id: colorButton
            text: "Выбрать цвет"
            anchors.horizontalCenter: parent.horizontalCenter
            onClicked: cs.openColorDialog()
        }
    }
}
