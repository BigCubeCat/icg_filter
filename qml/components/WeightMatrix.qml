import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import weightMatrixModel


Item {
    id: root
    signal weightChanged(rows: int, index: int, newval: string)

    signal innerSetWeight(index: int, value: int)
    function onSetWeight(index: int, value: int) {
        table.model.setData(index, value)
    }
    // Характеристики матрицы
    implicitWidth: 200
    implicitHeight: 200
    property int minValue: -100
    property int maxValue: 100
    property int cnt_rows: 1
    property int cnt_cols: 1
    property string title: ""

    ColumnLayout {
        id: clayout
        anchors.fill: parent
        spacing: 10

        Text {
            id: tablelabel
            text: title
            font.family: "Helvetica"
            font.pointSize: 14
        }

        TableView {
            id: table
            width: parent.width
            height: parent.height - tablelabel.height
            columnSpacing: 0
            rowSpacing: 0
            clip: true

            model: WeightMatrixModel {
                rows: cnt_rows
                columns: cnt_cols
            } // set this to your object

            delegate: Rectangle {
                implicitWidth: 30
                implicitHeight: 30
                border.color: "#000000"
                border.width: 1
                TextField {
                    id: valField
                    width: parent.width
                    height: parent.height
                    text: modelData
                    validator: IntValidator {
                        bottom: minValue; top: maxValue
                    }
                    onTextEdited: {
                        weightChanged(table.model.rows, index, text)
                    }
                }
            }
        }
    }
    Component.onCompleted: {
        table.model.updated.connect(weightChanged)
        innerSetWeight.connect(onSetWeight)
    }
}

