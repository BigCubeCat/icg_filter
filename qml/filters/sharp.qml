import QtQuick 2.15
import QtQuick.Controls
import components

Column {
    spacing: 10
    Text {
        text: "Sharp"
    }

    WeightMatrix {
        id: matrix
        title: "Sharpness"
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
