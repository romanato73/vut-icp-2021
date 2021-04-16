/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *toolButton_2;
    QToolButton *toolButton_4;
    QToolButton *toolButton_3;
    QToolButton *toolButton;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QToolButton *toolButton_5;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QToolButton *toolButton_6;
    QGridLayout *gridLayout;
    QToolButton *toolButton_7;
    QToolButton *toolButton_9;
    QToolButton *toolButton_8;
    QToolButton *toolButton_11;
    QToolButton *toolButton_10;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QToolButton *toolButton_12;
    QGridLayout *gridLayout_3;
    QToolButton *toolButton_15;
    QToolButton *toolButton_13;
    QToolButton *toolButton_14;
    QToolButton *toolButton_16;
    QSpacerItem *verticalSpacer;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer_4 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        toolButton_2 = new QToolButton(centralwidget);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));

        horizontalLayout_2->addWidget(toolButton_2);

        toolButton_4 = new QToolButton(centralwidget);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));

        horizontalLayout_2->addWidget(toolButton_4);

        toolButton_3 = new QToolButton(centralwidget);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));

        horizontalLayout_2->addWidget(toolButton_3);

        toolButton = new QToolButton(centralwidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        horizontalLayout_2->addWidget(toolButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        toolButton_5 = new QToolButton(centralwidget);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));

        horizontalLayout_3->addWidget(toolButton_5);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalSpacer_5 = new QSpacerItem(20, 5, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        toolButton_6 = new QToolButton(centralwidget);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));

        horizontalLayout_4->addWidget(toolButton_6);


        verticalLayout_3->addLayout(horizontalLayout_4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        toolButton_7 = new QToolButton(centralwidget);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));

        gridLayout->addWidget(toolButton_7, 0, 0, 1, 1);

        toolButton_9 = new QToolButton(centralwidget);
        toolButton_9->setObjectName(QString::fromUtf8("toolButton_9"));

        gridLayout->addWidget(toolButton_9, 0, 2, 1, 1);

        toolButton_8 = new QToolButton(centralwidget);
        toolButton_8->setObjectName(QString::fromUtf8("toolButton_8"));

        gridLayout->addWidget(toolButton_8, 0, 1, 1, 1);

        toolButton_11 = new QToolButton(centralwidget);
        toolButton_11->setObjectName(QString::fromUtf8("toolButton_11"));

        gridLayout->addWidget(toolButton_11, 1, 0, 1, 1);

        toolButton_10 = new QToolButton(centralwidget);
        toolButton_10->setObjectName(QString::fromUtf8("toolButton_10"));

        gridLayout->addWidget(toolButton_10, 0, 3, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        toolButton_12 = new QToolButton(centralwidget);
        toolButton_12->setObjectName(QString::fromUtf8("toolButton_12"));

        horizontalLayout_5->addWidget(toolButton_12);


        verticalLayout_3->addLayout(horizontalLayout_5);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        toolButton_15 = new QToolButton(centralwidget);
        toolButton_15->setObjectName(QString::fromUtf8("toolButton_15"));

        gridLayout_3->addWidget(toolButton_15, 0, 0, 1, 1);

        toolButton_13 = new QToolButton(centralwidget);
        toolButton_13->setObjectName(QString::fromUtf8("toolButton_13"));

        gridLayout_3->addWidget(toolButton_13, 0, 2, 1, 1);

        toolButton_14 = new QToolButton(centralwidget);
        toolButton_14->setObjectName(QString::fromUtf8("toolButton_14"));

        gridLayout_3->addWidget(toolButton_14, 0, 1, 1, 1);

        toolButton_16 = new QToolButton(centralwidget);
        toolButton_16->setObjectName(QString::fromUtf8("toolButton_16"));

        gridLayout_3->addWidget(toolButton_16, 0, 3, 1, 1);


        verticalLayout_3->addLayout(gridLayout_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_3);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        horizontalLayout->addWidget(graphicsView);


        verticalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        toolButton_2->setText(QCoreApplication::translate("MainWindow", "N", nullptr));
        toolButton_4->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        toolButton_3->setText(QCoreApplication::translate("MainWindow", "E", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Categories", nullptr));
        toolButton_5->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Default", nullptr));
        toolButton_6->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        toolButton_7->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        toolButton_9->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        toolButton_8->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        toolButton_11->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        toolButton_10->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Logical Blocks", nullptr));
        toolButton_12->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_15->setText(QCoreApplication::translate("MainWindow", "11", nullptr));
        toolButton_13->setText(QCoreApplication::translate("MainWindow", "33", nullptr));
        toolButton_14->setText(QCoreApplication::translate("MainWindow", "22", nullptr));
        toolButton_16->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
