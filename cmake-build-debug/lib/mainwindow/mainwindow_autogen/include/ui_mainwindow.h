/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtQuickWidgets/QQuickWidget>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionLine;
    QAction *actionFill;
    QAction *actionStamp;
    QAction *actionAbout;
    QAction *actionHelp;
    QAction *actionZoomIn;
    QAction *actionZoomOut;
    QAction *actionOpen_Folder;
    QAction *actionConfig;
    QAction *actionApply;
    QAction *actionResetZoom;
    QAction *actionNext;
    QAction *actionPrevious;
    QAction *actionShowToolbar;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuTools;
    QMenu *menuPixel;
    QMenu *menuMatrix;
    QMenu *menuBasics;
    QMenu *menuHelp;
    QMenu *menuZoom;
    QMenu *menuView;
    QMenu *menuImage;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *dockLayout;
    QQuickWidget *quickWidget;
    QPushButton *applyButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 583);
        MainWindow->setMinimumSize(QSize(640, 480));
        QIcon icon;
        if (QIcon::hasThemeIcon(QIcon::ThemeIcon::EditCopy)) {
            icon = QIcon::fromTheme(QIcon::ThemeIcon::EditCopy);
        } else {
            icon.addFile(QString::fromUtf8(":/assets/assets/no.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        }
        MainWindow->setWindowIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/assets/assets/icons/open.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/assets/assets/icons/save.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        actionSave->setIcon(icon2);
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName("actionSave_As");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/assets/assets/icons/save_as.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        actionSave_As->setIcon(icon3);
        actionLine = new QAction(MainWindow);
        actionLine->setObjectName("actionLine");
        actionLine->setCheckable(true);
        actionLine->setChecked(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/assets/assets/icons/line.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        actionLine->setIcon(icon4);
        actionFill = new QAction(MainWindow);
        actionFill->setObjectName("actionFill");
        actionFill->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/assets/assets/icons/fill.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        actionFill->setIcon(icon5);
        actionStamp = new QAction(MainWindow);
        actionStamp->setObjectName("actionStamp");
        actionStamp->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/assets/assets/icons/shape.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        actionStamp->setIcon(icon6);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/assets/assets/icons/about.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        actionAbout->setIcon(icon7);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName("actionHelp");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/assets/assets/icons/docs.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        actionHelp->setIcon(icon8);
        actionZoomIn = new QAction(MainWindow);
        actionZoomIn->setObjectName("actionZoomIn");
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/assets/assets/icons/resize.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        actionZoomIn->setIcon(icon9);
        actionZoomOut = new QAction(MainWindow);
        actionZoomOut->setObjectName("actionZoomOut");
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/assets/assets/icons/reset.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        actionZoomOut->setIcon(icon10);
        actionOpen_Folder = new QAction(MainWindow);
        actionOpen_Folder->setObjectName("actionOpen_Folder");
        actionConfig = new QAction(MainWindow);
        actionConfig->setObjectName("actionConfig");
        actionConfig->setCheckable(true);
        actionConfig->setChecked(true);
        actionApply = new QAction(MainWindow);
        actionApply->setObjectName("actionApply");
        actionResetZoom = new QAction(MainWindow);
        actionResetZoom->setObjectName("actionResetZoom");
        actionNext = new QAction(MainWindow);
        actionNext->setObjectName("actionNext");
        actionPrevious = new QAction(MainWindow);
        actionPrevious->setObjectName("actionPrevious");
        actionShowToolbar = new QAction(MainWindow);
        actionShowToolbar->setObjectName("actionShowToolbar");
        actionShowToolbar->setCheckable(true);
        actionShowToolbar->setChecked(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        scrollArea->setAutoFillBackground(true);
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignmentFlag::AlignCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 554, 501));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 23));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuTools = new QMenu(menubar);
        menuTools->setObjectName("menuTools");
        menuPixel = new QMenu(menuTools);
        menuPixel->setObjectName("menuPixel");
        menuMatrix = new QMenu(menuTools);
        menuMatrix->setObjectName("menuMatrix");
        menuBasics = new QMenu(menuTools);
        menuBasics->setObjectName("menuBasics");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        menuZoom = new QMenu(menubar);
        menuZoom->setObjectName("menuZoom");
        menuView = new QMenu(menubar);
        menuView->setObjectName("menuView");
        menuImage = new QMenu(menubar);
        menuImage->setObjectName("menuImage");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName("dockWidget");
        dockWidget->setAllowedAreas(Qt::DockWidgetArea::LeftDockWidgetArea|Qt::DockWidgetArea::RightDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName("dockWidgetContents");
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_3->setObjectName("verticalLayout_3");
        dockLayout = new QVBoxLayout();
        dockLayout->setSpacing(0);
        dockLayout->setObjectName("dockLayout");
        quickWidget = new QQuickWidget(dockWidgetContents);
        quickWidget->setObjectName("quickWidget");
        quickWidget->setMinimumSize(QSize(200, 0));
        quickWidget->setResizeMode(QQuickWidget::ResizeMode::SizeRootObjectToView);
        quickWidget->setSource(QUrl(QString::fromUtf8("")));

        dockLayout->addWidget(quickWidget);

        applyButton = new QPushButton(dockWidgetContents);
        applyButton->setObjectName("applyButton");

        dockLayout->addWidget(applyButton);


        verticalLayout_3->addLayout(dockLayout);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::DockWidgetArea::RightDockWidgetArea, dockWidget);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuTools->menuAction());
        menubar->addAction(menuZoom->menuAction());
        menubar->addAction(menuImage->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuTools->addAction(actionApply);
        menuTools->addSeparator();
        menuTools->addAction(menuBasics->menuAction());
        menuTools->addAction(menuPixel->menuAction());
        menuTools->addAction(menuMatrix->menuAction());
        menuPixel->addSeparator();
        menuMatrix->addSeparator();
        menuBasics->addSeparator();
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionHelp);
        menuZoom->addAction(actionZoomIn);
        menuZoom->addAction(actionZoomOut);
        menuZoom->addAction(actionResetZoom);
        menuView->addAction(actionConfig);
        menuView->addAction(actionShowToolbar);
        menuImage->addAction(actionPrevious);
        menuImage->addAction(actionNext);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "ICG Paint", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(tooltip)
        actionOpen->setToolTip(QCoreApplication::translate("MainWindow", "Open image file", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(tooltip)
        actionSave->setToolTip(QCoreApplication::translate("MainWindow", "Save image file", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_As->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
#if QT_CONFIG(tooltip)
        actionSave_As->setToolTip(QCoreApplication::translate("MainWindow", "Save image file with other file name", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSave_As->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionLine->setText(QCoreApplication::translate("MainWindow", "Line", nullptr));
#if QT_CONFIG(tooltip)
        actionLine->setToolTip(QCoreApplication::translate("MainWindow", "Draw line", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionLine->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFill->setText(QCoreApplication::translate("MainWindow", "Fill", nullptr));
#if QT_CONFIG(tooltip)
        actionFill->setToolTip(QCoreApplication::translate("MainWindow", "Fill some area", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionFill->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionStamp->setText(QCoreApplication::translate("MainWindow", "Stamp", nullptr));
#if QT_CONFIG(tooltip)
        actionStamp->setToolTip(QCoreApplication::translate("MainWindow", "Stamp figure", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionStamp->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
#if QT_CONFIG(tooltip)
        actionAbout->setToolTip(QCoreApplication::translate("MainWindow", "About author", nullptr));
#endif // QT_CONFIG(tooltip)
        actionHelp->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
#if QT_CONFIG(tooltip)
        actionHelp->setToolTip(QCoreApplication::translate("MainWindow", "Documentation", nullptr));
#endif // QT_CONFIG(tooltip)
        actionZoomIn->setText(QCoreApplication::translate("MainWindow", "Zoom in", nullptr));
#if QT_CONFIG(tooltip)
        actionZoomIn->setToolTip(QCoreApplication::translate("MainWindow", "Resize canvas", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionZoomIn->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+=", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZoomOut->setText(QCoreApplication::translate("MainWindow", "Zoom out", nullptr));
#if QT_CONFIG(shortcut)
        actionZoomOut->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+-", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen_Folder->setText(QCoreApplication::translate("MainWindow", "Open Folder", nullptr));
        actionConfig->setText(QCoreApplication::translate("MainWindow", "Config Sidebar", nullptr));
        actionApply->setText(QCoreApplication::translate("MainWindow", "Apply Filter", nullptr));
        actionResetZoom->setText(QCoreApplication::translate("MainWindow", "Reset zoom", nullptr));
        actionNext->setText(QCoreApplication::translate("MainWindow", "Next", nullptr));
        actionPrevious->setText(QCoreApplication::translate("MainWindow", "Previous", nullptr));
        actionShowToolbar->setText(QCoreApplication::translate("MainWindow", "Show Toolbar", nullptr));
#if QT_CONFIG(tooltip)
        menuFile->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuTools->setTitle(QCoreApplication::translate("MainWindow", "Filter", nullptr));
        menuPixel->setTitle(QCoreApplication::translate("MainWindow", "Pixel", nullptr));
        menuMatrix->setTitle(QCoreApplication::translate("MainWindow", "Matrix", nullptr));
        menuBasics->setTitle(QCoreApplication::translate("MainWindow", "Basics", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuZoom->setTitle(QCoreApplication::translate("MainWindow", "Zoom", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuImage->setTitle(QCoreApplication::translate("MainWindow", "Image", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
#if QT_CONFIG(whatsthis)
        dockWidget->setWhatsThis(QCoreApplication::translate("MainWindow", "sidebar", nullptr));
#endif // QT_CONFIG(whatsthis)
        dockWidget->setWindowTitle(QCoreApplication::translate("MainWindow", "Config", nullptr));
        applyButton->setText(QCoreApplication::translate("MainWindow", "APPLY", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
