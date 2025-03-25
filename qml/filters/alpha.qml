// alpha.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
  anchors.fill: parent
  anchors.margins: 20
  spacing: 10
  Text {
      text: "alpha filter"
  }

  SliderSpinBox {
    minValue: 1
    maxValue: 99
    title: "percent"
    value: alpha.percent
    onValueChanged: alpha.percent = value
  }

  ComboBox {
      id: comboBox
      width: 120
      currentIndex: alpha.variant
      model: ["Scale image", "Tile filling", "Ignore"]

      onActivated: (index) => {
        console.log("Selected:", model[index])
        alpha.variant = index
      }
  }
  ImagePicker {
    id: imagePicker
    imageSource: alpha.imagePath
    onImageSourceChanged: alpha.imagePath = imageSource
  }
}
