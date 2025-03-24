import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: root
    width: 600
    height: 400
    color: "#f0f0f0"

    property real currentScale: 1.0

    // Flickable для автоматической прокрутки, если изображение выходит за границы области
    Flickable {
        id: flickable
        anchors.fill: parent
        clip: true
        contentWidth: image.implicitWidth * currentScale
        contentHeight: image.implicitHeight * currentScale

        Image {
            id: image
            anchors.centerIn: parent
            image: controller.image
            smooth: true
            width: implicitWidth * currentScale
            height: implicitHeight * currentScale
        }
    }

    // Методы масштабирования
    function zoomIn() {
        currentScale *= 1.2;
    }

    function zoomOut() {
        currentScale /= 1.2;
    }

    function zoomReset() {
        currentScale = 1.0;
    }

    // Масштабирование изображения по размеру области виджета
    function fit() {
        // Вычисляем коэффициенты масштабирования по ширине и высоте
        var scaleX = flickable.width / image.implicitWidth;
        var scaleY = flickable.height / image.implicitHeight;
        currentScale = Math.min(scaleX, scaleY);
    }
}

