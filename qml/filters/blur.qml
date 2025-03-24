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
        model: ["3x3", "5x5", "7x7", "9x9", "11x11"]
        onActivated: {
            matrix.innerSetHeight(2 * (list.currentIndex + 1) + 1);
            matrix.innerSetWidth(2 * (list.currentIndex + 1) + 1);
            blur.onChangedSize(2 * (list.currentIndex + 1) + 1);
        }
    }

    Component.onCompleted: {
        blur.set_weight.connect(matrix.innerSetWeight);
        matrix.weightChanged.connect(blur.onChangedWeight);
    }
}