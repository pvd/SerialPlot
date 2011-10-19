/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Oct 12 20:16:57 2011
**      by: Qt User Interface Compiler version 4.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *plotLayout;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QComboBox *cmbPorts;
    QPushButton *btnOpenPort;
    QPushButton *btnClosePort;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnResetZoom;
    QPushButton *btnCreatePlot;
    QPushButton *btnAddSamples;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(774, 480);
        MainWindow->setMinimumSize(QSize(772, 480));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 50, 761, 361));
        plotLayout = new QVBoxLayout(verticalLayoutWidget);
        plotLayout->setSpacing(6);
        plotLayout->setContentsMargins(11, 11, 11, 11);
        plotLayout->setObjectName(QString::fromUtf8("plotLayout"));
        plotLayout->setContentsMargins(0, 0, 0, 0);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 441, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        cmbPorts = new QComboBox(layoutWidget);
        cmbPorts->setObjectName(QString::fromUtf8("cmbPorts"));

        horizontalLayout->addWidget(cmbPorts);

        btnOpenPort = new QPushButton(layoutWidget);
        btnOpenPort->setObjectName(QString::fromUtf8("btnOpenPort"));

        horizontalLayout->addWidget(btnOpenPort);

        btnClosePort = new QPushButton(layoutWidget);
        btnClosePort->setObjectName(QString::fromUtf8("btnClosePort"));

        horizontalLayout->addWidget(btnClosePort);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(460, 10, 301, 32));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        btnResetZoom = new QPushButton(layoutWidget1);
        btnResetZoom->setObjectName(QString::fromUtf8("btnResetZoom"));

        horizontalLayout_2->addWidget(btnResetZoom);

        btnCreatePlot = new QPushButton(layoutWidget1);
        btnCreatePlot->setObjectName(QString::fromUtf8("btnCreatePlot"));

        horizontalLayout_2->addWidget(btnCreatePlot);

        btnAddSamples = new QPushButton(layoutWidget1);
        btnAddSamples->setObjectName(QString::fromUtf8("btnAddSamples"));

        horizontalLayout_2->addWidget(btnAddSamples);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 774, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        btnOpenPort->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        btnClosePort->setText(QApplication::translate("MainWindow", "Close", 0, QApplication::UnicodeUTF8));
        btnResetZoom->setText(QApplication::translate("MainWindow", "Reset Zoom", 0, QApplication::UnicodeUTF8));
        btnCreatePlot->setText(QApplication::translate("MainWindow", "CreatePlot", 0, QApplication::UnicodeUTF8));
        btnAddSamples->setText(QApplication::translate("MainWindow", "AddSamples", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
