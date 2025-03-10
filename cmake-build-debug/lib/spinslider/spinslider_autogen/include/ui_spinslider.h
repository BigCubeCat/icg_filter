/********************************************************************************
** Form generated from reading UI file 'spinslider.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPINSLIDER_H
#define UI_SPINSLIDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SpinSlider
{
public:
    QVBoxLayout *verticalLayout;
    QSlider *horizontalSlider;
    QSpinBox *spinBox;

    void setupUi(QWidget *SpinSlider)
    {
        if (SpinSlider->objectName().isEmpty())
            SpinSlider->setObjectName("SpinSlider");
        SpinSlider->resize(127, 65);
        verticalLayout = new QVBoxLayout(SpinSlider);
        verticalLayout->setObjectName("verticalLayout");
        horizontalSlider = new QSlider(SpinSlider);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout->addWidget(horizontalSlider);

        spinBox = new QSpinBox(SpinSlider);
        spinBox->setObjectName("spinBox");

        verticalLayout->addWidget(spinBox);


        retranslateUi(SpinSlider);

        QMetaObject::connectSlotsByName(SpinSlider);
    } // setupUi

    void retranslateUi(QWidget *SpinSlider)
    {
        SpinSlider->setWindowTitle(QCoreApplication::translate("SpinSlider", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SpinSlider: public Ui_SpinSlider {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPINSLIDER_H
