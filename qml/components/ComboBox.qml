import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ColumnLayout {
    id: root
    property int value: 0
    property string title: ""
    property alias model: comboBox.model

    spacing: 20

    Text {
        text: title
        font.pixelSize: 16
    }

    ComboBox {
        id: comboBox
        width: 120
        currentIndex: root.value

        onActivated: (index) => {
            console.log("Selected:", model[index])
            root.value = index
        }
    }
}
