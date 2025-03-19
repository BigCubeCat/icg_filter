import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    id: root
    // Основное свойство для хранения значения
    property string title: ""
    property double step: 0.1
    property real realValue: 0.0
    property real realFrom: 0.1
    property real realTo: 10.0
    property int decimals: 1
    property real factor: Math.pow(10, root.decimals)

    // Размеры виджета по умолчанию
    implicitWidth: 150
    implicitHeight: 100

    ColumnLayout {
        anchors.fill: parent
        spacing: 10

        Text {
            text: title
            font.family: "Helvetica"
            font.pointSize: 14
        }

        Slider {
            id: slider
            Layout.fillWidth: true
            
            from: root.realFrom
            to: root.realTo
            stepSize: step
            value: root.realValue
            
            // Обновляем корневое значение при изменении слайдера
            onMoved: root.realValue = value
        }
        
        SpinBox{
            id: spinBox
            stepSize: step*factor
            value: realValue * factor
            to : realTo*factor
            from : realFrom*factor
            validator: DoubleValidator {
                bottom: Math.min(spinBox.from, spinBox.to)*spinBox.factor
                top:  Math.max(spinBox.from, spinBox.to)*spinBox.factor
            }

            textFromValue: function(value, locale) {
                return parseFloat(value*1.0/factor).toFixed(decimals);
            }

            onValueModified: root.realValue = value / factor

        }
        
    }

    // Обновление значений при изменении корневого свойства
    onRealValueChanged: {
        if (slider.value !== realValue) slider.value = realValue
        if (spinBox.value !== realValue * factor) spinBox.value = realValue * factor
    }

}
