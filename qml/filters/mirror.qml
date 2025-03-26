// mirror.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    anchors.fill: parent
    anchors.margins: 20
    spacing: 10

    Text {
        text: "mirror"
    }
    ComboBox {
        id: comboBox
        width: 120
        currentIndex: mirror.value
        model: ["Vertical", "Horizontal"]
        onActivated: (index) => {
            console.log("Selected:", model[index])
            mirror.value = index
        }
    }
}
