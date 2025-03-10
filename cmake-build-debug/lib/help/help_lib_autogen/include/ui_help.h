/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_HelpDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;

    void setupUi(QDialog *HelpDialog)
    {
        if (HelpDialog->objectName().isEmpty())
            HelpDialog->setObjectName("HelpDialog");
        HelpDialog->setWindowModality(Qt::WindowModality::ApplicationModal);
        HelpDialog->resize(338, 300);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HelpDialog->sizePolicy().hasHeightForWidth());
        HelpDialog->setSizePolicy(sizePolicy);
        HelpDialog->setMinimumSize(QSize(338, 300));
        HelpDialog->setMaximumSize(QSize(338, 300));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/assets/assets/icons/icon.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        HelpDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(HelpDialog);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(HelpDialog);
        label->setObjectName("label");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMinimumSize(QSize(64, 0));
        label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);


        retranslateUi(HelpDialog);

        QMetaObject::connectSlotsByName(HelpDialog);
    } // setupUi

    void retranslateUi(QDialog *HelpDialog)
    {
        HelpDialog->setWindowTitle(QCoreApplication::translate("HelpDialog", "About ICG Paint", nullptr));
        label->setText(QCoreApplication::translate("HelpDialog", "Select a color and a tool on the toolbar and start drawing with the mouse on the canvas.\n"
"Use the File menu to open and save files.\n"
"Use the Tools menu to select tools.\n"
"Use the View menu to resize the image or clear the image.\n"
"Use the Help menu to open additional information.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelpDialog: public Ui_HelpDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
