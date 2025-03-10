// mirror.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    spacing: 10
    SelectBox {
        model: ["Vertical", "Horizontal"]
        title: "mirror type"
        value: mirror.value
    }
}
