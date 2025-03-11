import QtQuick 2.15
import QtQuick.Controls
import components

Column {
    spacing: 10
    WeightMatrix {
        id: matrix
        title: "Gaussian blur"
        cnt_rows: 3
        cnt_cols: 3

        Component.onCompleted: {
            blur.onChangedSize(cnt_rows)
        }
    }
    ComboBox {
        id: list
        model: ["3x3", "5x5"]
        onActivated: {
            if (list.currentIndex == 0) {
                matrix.innerSetHeight(3);
                matrix.innerSetWidth(3);
                blur.onChangedSize(3);
            } else {
                matrix.innerSetHeight(5);
                matrix.innerSetWidth(5);
                blur.onChangedSize(5);
            }
        }
    }

    Component.onCompleted: {
        blur.set_weight.connect(matrix.innerSetWeight);
        matrix.weightChanged.connect(blur.onChangedWeight);
    }
}