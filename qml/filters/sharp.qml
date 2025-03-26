import QtQuick 2.15
import QtQuick.Controls
import components

Column {
    anchors.fill: parent
    spacing: 10
    Text {
        text: "Sharpness"
        font.family: "Helvetica"
        font.pointSize: 16
        font.bold: true
        width: parent.width
        wrapMode: Text.WordWrap
    }
    Text {
        width: parent.width
        text: "Данный фильтр повышает резкость изображения."
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
        ToolTip.text: "Матрица весов - это ядро свёртки из-за которой происходит увеличение резкости"
    }
    WeightMatrix {
        id: matrix
        cnt_rows: 3
        cnt_cols: 3

        Component.onCompleted: {
            sharp.onReset()
        }
    }

    Component.onCompleted: {
        sharp.set_weight.connect(matrix.innerSetWeight);
        matrix.weightChanged.connect(sharp.onChangedWeight);
    }
}
