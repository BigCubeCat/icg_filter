import QtQuick 2.15
import QtQuick.Controls
import components

Column {
    anchors.fill: parent
    spacing: 10

    Text {
        text: "Blur"
        font.family: "Helvetica"
        font.pointSize: 16
        font.bold: true
        width: parent.width
        wrapMode: Text.WordWrap
    }
    Text {
        width: parent.width
        text: "Данный фильтр \"размывает\" изображение. Если размер матрицы < 7x7, то используется размытие Гаусса, иначе берётся среднее значение."
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
        id: matrixtitle
        width: parent.width
        text: "Матрица весов"
        font.family: "Helvetica"
        font.pointSize: 14
        font.bold: true
        topPadding: 40
        wrapMode: Text.WordWrap
        ToolTip.visible: _mouseArea.containsMouse
        ToolTip.text: "Матрица весов - это ядро свёртки из-за которой происходит размытие"
    }
    WeightMatrix {
        id: matrix
        cnt_rows: 3
        cnt_cols: 3

        Component.onCompleted: {
            blur.onChangedSize(cnt_rows)
        }
    }

    Text {
        MouseArea {
            id: _mouseAreaSec
            hoverEnabled: true
            anchors.fill: parent
        }
        width: parent.width
        topPadding: 20
        text: "Размер области:"
        font.family: "Helvetica"
        font.pointSize: 10
        font.bold: true
        wrapMode: Text.WordWrap
        ToolTip.visible: _mouseAreaSec.containsMouse
        ToolTip.text: "Размер области определяет размер матрицы весов (если размер < 7x7) или размер области, по которой считается среднее (если размер >= 7x7)"
    }
    ComboBox {
        id: list
        model: ["3x3", "5x5", "7x7", "9x9", "11x11"]
        onActivated: {
            matrix.innerSetHeight(2 * (list.currentIndex + 1) + 1);
            matrix.innerSetWidth(2 * (list.currentIndex + 1) + 1);
            blur.onChangedSize(2 * (list.currentIndex + 1) + 1);
            if (list.currentIndex > 1) {
                matrix.visible = false
                matrixtitle.visible = false
            } else {
                matrix.visible = true
                matrixtitle.visible = true
            }
        }
    }

    Component.onCompleted: {
        blur.set_weight.connect(matrix.innerSetWeight);
        matrix.weightChanged.connect(blur.onChangedWeight);
    }
}
