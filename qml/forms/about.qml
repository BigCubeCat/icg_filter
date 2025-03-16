import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Column {
    anchors.fill: parent
    spacing: 10
    
    Label {
        text: "ICG paint"
        font.bold: true
        font.pixelSize: 20
        Layout.alignment: Qt.AlignHCenter
    }
    
    Label {
        text: "Version: 1.0"
        font.pixelSize: 14
        Layout.alignment: Qt.AlignHCenter
    }
    
    Label {
        text: "Authors: @BigCubeCat, @AMChumak"
        font.pixelSize: 12
        Layout.alignment: Qt.AlignHCenter
    }
    //
    // LinkButton {
    //     text: "GitHub Repository"
    //     utl: "https://github.com/BigCubeCat/icg_filter"
    //     Layout.alignment: Qt.AlignHCenter
    // }
    
    ScrollView {
        Layout.fillWidth: true
        Layout.fillHeight: true
        Layout.preferredHeight: 200
        Layout.margins: 10
        width: 300
        
        TextArea {
            id: licenseText
            text: "MIT License\n\n" +
                    "Copyright (c) 2023 Your Name\n\n" +
                    "Permission is hereby granted, free of charge, to any person obtaining a copy " +
                    "of this software and associated documentation files (the \"Software\"), to deal " +
                    "in the Software without restriction, including without limitation the rights " +
                    "to use, copy, modify, merge, publish, distribute, sublicense, and/or sell " +
                    "copies of the Software, and to permit persons to whom the Software is " +
                    "furnished to do so, subject to the following conditions:\n\n" +
                    "The above copyright notice and this permission notice shall be included in all " +
                    "copies or substantial portions of the Software.\n\n" +
                    "THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR " +
                    "IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, " +
                    "FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE " +
                    "AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER " +
                    "LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, " +
                    "OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE " +
                    "SOFTWARE."
            readOnly: true
            wrapMode: Text.WordWrap
            font.family: "Monospace"
            font.pixelSize: 10
        }
    }
}
