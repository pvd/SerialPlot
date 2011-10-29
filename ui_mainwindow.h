/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Sat Oct 29 14:54:30 2011
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
    QVBoxLayout *layoutPlot;
    QWidget *layoutWidget;
    QHBoxLayout *layoutSerialPort;
    QComboBox *cmbPorts;
    QPushButton *btnOpenPort;
    QPushButton *btnClosePort;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnResetZoom;
    QPushButton *btnCreatePlot;
    QPushButton *btnTest;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *layoutParams;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(774, 586);
        MainWindow->setMinimumSize(QSize(772, 480));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 50, 761, 361));
        layoutPlot = new QVBoxLayout(verticalLayoutWidget);
        layoutPlot->setSpacing(6);
        layoutPlot->setContentsMargins(11, 11, 11, 11);
        layoutPlot->setObjectName(QString::fromUtf8("layoutPlot"));
        layoutPlot->setContentsMargins(0, 0, 0, 0);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 441, 32));
        layoutSerialPort = new QHBoxLayout(layoutWidget);
        layoutSerialPort->setSpacing(6);
        layoutSerialPort->setContentsMargins(11, 11, 11, 11);
        layoutSerialPort->setObjectName(QString::fromUtf8("layoutSerialPort"));
        layoutSerialPort->setContentsMargins(0, 0, 0, 0);
        cmbPorts = new QComboBox(layoutWidget);
        cmbPorts->setObjectName(QString::fromUtf8("cmbPorts"));

        layoutSerialPort->addWidget(cmbPorts);

        btnOpenPort = new QPushButton(layoutWidget);
        btnOpenPort->setObjectName(QString::fromUtf8("btnOpenPort"));

        layoutSerialPort->addWidget(btnOpenPort);

        btnClosePort = new QPushButton(layoutWidget);
        btnClosePort->setObjectName(QString::fromUtf8("btnClosePort"));

        layoutSerialPort->addWidget(btnClosePort);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(460, 10, 303, 32));
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

        btnTest = new QPushButton(layoutWidget1);
        btnTest->setObjectName(QString::fromUtf8("btnTest"));

        horizontalLayout_2->addWidget(btnTest);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 410, 701, 111));
        layoutParams = new QHBoxLayout(horizontalLayoutWidget);
        layoutParams->setSpacing(6);
        layoutParams->setContentsMargins(11, 11, 11, 11);
        layoutParams->setObjectName(QString::fromUtf8("layoutParams"));
        layoutParams->setContentsMargins(0, 0, 0, 0);
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
        btnTest->setText(QApplication::translate("MainWindow", "Test", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
