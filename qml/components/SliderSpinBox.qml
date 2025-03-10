import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Item {
    id: root
    // Основное свойство для хранения значения
    property int value: 0
    property string title: ""
    property int step: 1
    
    // Минимальное и максимальное значения диапазона
    property int minValue: 0
    property int maxValue: 100

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
            
            from: root.minValue
            to: root.maxValue
            stepSize: step
            value: root.value
            
            // Обновляем корневое значение при изменении слайдера
            onMoved: root.value = value
        }

        SpinBox {
            Layout.fillWidth: true
            id: spinBox
            editable: true
            
            from: root.minValue
            to: root.maxValue
            value: root.value
            
            // Обновляем корневое значение при изменении спинбокса
            onValueModified: root.value = value
            
            // Валидатор для целых чисел
            validator: IntValidator {
                bottom: root.minValue
                top: root.maxValue
            }
        }
    }

    // Обновление значений при изменении корневого свойства
    onValueChanged: {
        if (slider.value !== value) slider.value = value
        if (spinBox.value !== value) spinBox.value = value
    }
}
