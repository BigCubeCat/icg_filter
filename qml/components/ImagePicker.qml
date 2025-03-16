import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs 

Rectangle {
    id: root
    width: 120
    height: 150
    color: "#eee"
    radius: 4
    border.color: "#ccc"

    // Свойство для доступа к выбранному пути изображения
    property alias imageSource: previewImage.source

    onImageSourceChanged: {
        if (imageSource !== "") {
            // Вызываем обработчик при изменении изображения
            fileHandler.setImagePath(imageSource)
        }
    }

    // Кликабельная область для выбора изображения
    MouseArea {
        anchors.fill: parent
        onClicked: fileDialog.open()
    }

    Column {
        anchors.fill: parent
        spacing: 8
        topPadding: 8

        // Область превью
        Image {
            id: previewImage
            width: 120
            height: 120
            anchors.horizontalCenter: parent.horizontalCenter
            fillMode: Image.PreserveAspectFit
            source: ""

            // Плейсхолдер когда изображение не выбрано
            Rectangle {
                anchors.fill: parent
                visible: previewImage.status !== Image.Ready
                color: "transparent"
                border.color: "#aaa"
                border.width: 2

                Text {
                    anchors.centerIn: parent
                    text: "Выберите\nизображение"
                    horizontalAlignment: Text.AlignHCenter
                    color: "#666"
                    font.pixelSize: 12
                }
            }
        }

        // Кнопка удаления изображения
        Button {
            anchors.horizontalCenter: parent.horizontalCenter
            width: 100
            height: 20
            text: "Очистить"
            visible: previewImage.source !== ""
            font.pixelSize: 10
            onClicked: previewImage.source = ""
        }
    }

    // Диалог выбора файла
    FileDialog {
        id: fileDialog
        title: "Выберите изображение"
        nameFilters: ["Изображения (*.png *.jpg *.jpeg *.bmp *.gif)"]
        
        onAccepted: {
            console.log(selectedFile)
            previewImage.source = selectedFile
        }
    }
}

