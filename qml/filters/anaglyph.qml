// anaglyph.qml
import QtQuick 2.15
import QtQuick.Controls 2.15
import components 1.0

Column {
    anchors.fill: parent
    anchors.margins: 20
    spacing: 10

    ImagePicker {
        id: imagePicker
        imageSource: anaglyph.imagePath
        onImageSourceChanged: anaglyph.imagePath = imageSource
    }
}
