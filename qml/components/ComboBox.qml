import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ColumnLayout {
    id: combo
    property int value: 0
    property string title: ""
    property alias model: comboBox.model

    anchors.centerIn: parent
    spacing: 20

    Text {
        text: title
        font.pixelSize: 16
    }

    ComboBox {
        id: comboBox
        currentIndex: value
        implicitWidth: 200
        Layout.alignment: Qt.AlignHCenter

        // Стилизация выпадающего списка
        delegate: ItemDelegate {
            width: comboBox.width
            contentItem: Text {
                text: modelData
                color: "black"
                font: comboBox.font
                elide: Text.ElideRight
                verticalAlignment: Text.AlignVCenter
                leftPadding: 5
            }
            highlighted: comboBox.highlightedIndex === index
        }

        // Обработчик выбора элемента
        onActivated: {
            console.log("Выбран элемент:", model[currentIndex])
            combo.value = currentIndex
        }
    }
}
