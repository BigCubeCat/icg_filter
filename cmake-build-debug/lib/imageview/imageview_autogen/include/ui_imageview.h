/********************************************************************************
** Form generated from reading UI file 'imageview.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEVIEW_H
#define UI_IMAGEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageView
{
public:
    QVBoxLayout *verticalLayout;

    void setupUi(QWidget *ImageView)
    {
        if (ImageView->objectName().isEmpty())
            ImageView->setObjectName("ImageView");
        ImageView->resize(400, 300);
        ImageView->setStyleSheet(QString::fromUtf8("border: 4px dashed black;"));
        verticalLayout = new QVBoxLayout(ImageView);
        verticalLayout->setObjectName("verticalLayout");

        retranslateUi(ImageView);

        QMetaObject::connectSlotsByName(ImageView);
    } // setupUi

    void retranslateUi(QWidget *ImageView)
    {
        ImageView->setWindowTitle(QCoreApplication::translate("ImageView", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ImageView: public Ui_ImageView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEVIEW_H
