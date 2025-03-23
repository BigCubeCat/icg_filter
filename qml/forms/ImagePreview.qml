import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    id: root
    width: 400
    height: 300

    property alias source: image.source

    function zoomIn() {
        image.scale *= 1.1
    }

    function zoomOut() {
        image.scale = Math.max(0.1, image.scale / 1.1)
    }

    Flickable {
        id: flickable
        anchors.fill: parent
        contentWidth: image.width
        contentHeight: image.height
        clip: true

        Image {
            id: image
            scale: 1.0
            width: implicitWidth * scale
            height: implicitHeight * scale
            asynchronous: true
            fillMode: Image.PreserveAspectFit
        }

        ScrollBar.vertical: ScrollBar {
            policy: image.height > flickable.height ? ScrollBar.AlwaysOn : ScrollBar.AsNeeded
        }

        ScrollBar.horizontal: ScrollBar {
            policy: image.width > flickable.width ? ScrollBar.AlwaysOn : ScrollBar.AsNeeded
        }
    }

    MouseArea {
        anchors.fill: parent
        enabled: image.width > flickable.width || image.height > flickable.height
        property point lastPos: Qt.point(0, 0)
        
        onPressed: lastPos = Qt.point(mouseX, mouseY)
        onPositionChanged: {
            flickable.contentX -= mouseX - lastPos.x
            flickable.contentY -= mouseY - lastPos.y
            lastPos = Qt.point(mouseX, mouseY)
        }
    }
}
