// emboss.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
  anchors.fill: parent
  anchors.margins: 20
  spacing: 10

  Text {
    text: "emboss"
  }

  SliderSpinBox {
    minValue: -2
    maxValue: 2
    title: "offset X"
    value: emboss.offsetX
    onValueChanged: emboss.offsetX = value
  }

  SliderSpinBox {
    minValue: -2
    maxValue: 2
    title: "offset Y"
    value: emboss.offsetY
    onValueChanged: emboss.offsetY = value
  }

  ColorSelect {
    selectedColor: "#888888"  // Начальный цвет
    previewSize: 120
    onColorChanged: {
      console.log("New color selected:", colorHex)
      emboss.color = colorHex
    }
  }
}
