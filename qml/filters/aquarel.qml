import QtQuick 2.15
import QtQuick.Controls
Column {
    spacing: 10
    Text {
        text: "Aquarel"
        font.family: "Helvetica"
        font.pointSize: 14
    }
    ComboBox {
        id: list
        model: ["7x7", "9x9", "11x11"]
        onActivated: {
            aquarel.size = (2 * (list.currentIndex + 1) + 5);
        }
    }
}
