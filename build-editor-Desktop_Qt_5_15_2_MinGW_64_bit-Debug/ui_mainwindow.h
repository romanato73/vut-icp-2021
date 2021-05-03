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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *Container;
    QGridLayout *gridLayout;
    QWidget *Sidebar;
    QVBoxLayout *verticalLayout;
    QLabel *ModeLabel;
    QWidget *ModeButtons;
    QHBoxLayout *horizontalLayout;
    QPushButton *selectMode;
    QPushButton *createMode;
    QPushButton *editMode;
    QPushButton *deleteMode;
    QScrollArea *scrollArea;
    QWidget *Categories;
    QVBoxLayout *verticalLayout_9;
    QWidget *CategoriesTitle;
    QHBoxLayout *horizontalLayout_4;
    QLabel *CategoriesLabel;
    QPushButton *addCategory;
    QWidget *DefaultCategory;
    QVBoxLayout *verticalLayout_7;
    QWidget *DefaultCategoryTitle;
    QHBoxLayout *horizontalLayout_9;
    QLabel *DeafaultCategoryLabel;
    QWidget *DefaultCategoryItems;
    QGridLayout *gridLayout_6;
    QPushButton *Text;
    QPushButton *Square;
    QPushButton *Line;
    QWidget *LogicalCategory;
    QVBoxLayout *verticalLayout_8;
    QWidget *LogicalCategoryTitle;
    QHBoxLayout *horizontalLayout_10;
    QLabel *LogicalCategoryLabel;
    QWidget *LogicalCategoryItems;
    QGridLayout *gridLayout_7;
    QPushButton *NOT;
    QPushButton *XOR;
    QPushButton *AND;
    QPushButton *OR;
    QWidget *widget;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QLabel *label;
    QGraphicsView *editor;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1000, 600);
        MainWindow->setMinimumSize(QSize(1000, 600));
        QFont font;
        font.setFamily(QString::fromUtf8("Open Sans"));
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"	border: none;\n"
"}\n"
"\n"
" QScrollBar {\n"
"    background-color: #F8F8F8;\n"
"    width: 10px;\n"
"	border: none;\n"
" }\n"
"\n"
"QScrollBar::handle {\n"
"	background-color: #DBDBDB;\n"
"}"));
        Container = new QWidget(MainWindow);
        Container->setObjectName(QString::fromUtf8("Container"));
        Container->setFont(font);
        Container->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(Container);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        Sidebar = new QWidget(Container);
        Sidebar->setObjectName(QString::fromUtf8("Sidebar"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Sidebar->sizePolicy().hasHeightForWidth());
        Sidebar->setSizePolicy(sizePolicy);
        Sidebar->setMinimumSize(QSize(300, 600));
        Sidebar->setMaximumSize(QSize(300, 16777215));
        Sidebar->setSizeIncrement(QSize(0, 0));
        Sidebar->setLayoutDirection(Qt::LeftToRight);
        Sidebar->setStyleSheet(QString::fromUtf8("background-color: #F8F8F8;"));
        verticalLayout = new QVBoxLayout(Sidebar);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 10, 0, 10);
        ModeLabel = new QLabel(Sidebar);
        ModeLabel->setObjectName(QString::fromUtf8("ModeLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Open Sans"));
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        ModeLabel->setFont(font1);
        ModeLabel->setStyleSheet(QString::fromUtf8("color: #000000;\n"
"margin-left: 15px;"));
        ModeLabel->setMargin(0);

        verticalLayout->addWidget(ModeLabel);

        ModeButtons = new QWidget(Sidebar);
        ModeButtons->setObjectName(QString::fromUtf8("ModeButtons"));
        sizePolicy.setHeightForWidth(ModeButtons->sizePolicy().hasHeightForWidth());
        ModeButtons->setSizePolicy(sizePolicy);
        ModeButtons->setFont(font);
        ModeButtons->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #DBDBDB;\n"
"	border: none;\n"
"	color: #000;\n"
"	width: 60px;\n"
"	height: 60px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #EAEAEA;\n"
"}"));
        horizontalLayout = new QHBoxLayout(ModeButtons);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        selectMode = new QPushButton(ModeButtons);
        selectMode->setObjectName(QString::fromUtf8("selectMode"));
        selectMode->setMaximumSize(QSize(30, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Font Awesome 5 Free Solid"));
        font2.setBold(true);
        font2.setWeight(75);
        selectMode->setFont(font2);
        selectMode->setStyleSheet(QString::fromUtf8("background-color: #6A6FFF;\n"
"color: #ffffff;"));

        horizontalLayout->addWidget(selectMode);

        createMode = new QPushButton(ModeButtons);
        createMode->setObjectName(QString::fromUtf8("createMode"));
        createMode->setMaximumSize(QSize(30, 30));
        createMode->setFont(font2);

        horizontalLayout->addWidget(createMode);

        editMode = new QPushButton(ModeButtons);
        editMode->setObjectName(QString::fromUtf8("editMode"));
        editMode->setMaximumSize(QSize(30, 30));
        editMode->setFont(font2);

        horizontalLayout->addWidget(editMode);

        deleteMode = new QPushButton(ModeButtons);
        deleteMode->setObjectName(QString::fromUtf8("deleteMode"));
        deleteMode->setMaximumSize(QSize(30, 30));
        deleteMode->setFont(font2);

        horizontalLayout->addWidget(deleteMode);


        verticalLayout->addWidget(ModeButtons);

        scrollArea = new QScrollArea(Sidebar);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setMinimumSize(QSize(0, 0));
        scrollArea->setMaximumSize(QSize(300, 16777215));
        scrollArea->setStyleSheet(QString::fromUtf8(""));
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setWidgetResizable(true);
        Categories = new QWidget();
        Categories->setObjectName(QString::fromUtf8("Categories"));
        Categories->setGeometry(QRect(0, 0, 300, 215));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Categories->sizePolicy().hasHeightForWidth());
        Categories->setSizePolicy(sizePolicy2);
        Categories->setMinimumSize(QSize(0, 0));
        Categories->setMaximumSize(QSize(300, 16777215));
        Categories->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #000;\n"
"	background-color: #EAEAEA;\n"
"	border: none;\n"
"}"));
        verticalLayout_9 = new QVBoxLayout(Categories);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        CategoriesTitle = new QWidget(Categories);
        CategoriesTitle->setObjectName(QString::fromUtf8("CategoriesTitle"));
        CategoriesTitle->setStyleSheet(QString::fromUtf8(""));
        horizontalLayout_4 = new QHBoxLayout(CategoriesTitle);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        CategoriesLabel = new QLabel(CategoriesTitle);
        CategoriesLabel->setObjectName(QString::fromUtf8("CategoriesLabel"));
        CategoriesLabel->setFont(font1);
        CategoriesLabel->setStyleSheet(QString::fromUtf8("color: #000;"));

        horizontalLayout_4->addWidget(CategoriesLabel);

        addCategory = new QPushButton(CategoriesTitle);
        addCategory->setObjectName(QString::fromUtf8("addCategory"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(addCategory->sizePolicy().hasHeightForWidth());
        addCategory->setSizePolicy(sizePolicy3);
        addCategory->setMinimumSize(QSize(20, 20));
        addCategory->setMaximumSize(QSize(20, 20));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Font Awesome 5 Free Solid"));
        addCategory->setFont(font3);
        addCategory->setLayoutDirection(Qt::LeftToRight);
        addCategory->setStyleSheet(QString::fromUtf8("background-color: none;"));

        horizontalLayout_4->addWidget(addCategory);


        verticalLayout_9->addWidget(CategoriesTitle);

        DefaultCategory = new QWidget(Categories);
        DefaultCategory->setObjectName(QString::fromUtf8("DefaultCategory"));
        verticalLayout_7 = new QVBoxLayout(DefaultCategory);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        DefaultCategoryTitle = new QWidget(DefaultCategory);
        DefaultCategoryTitle->setObjectName(QString::fromUtf8("DefaultCategoryTitle"));
        horizontalLayout_9 = new QHBoxLayout(DefaultCategoryTitle);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        DeafaultCategoryLabel = new QLabel(DefaultCategoryTitle);
        DeafaultCategoryLabel->setObjectName(QString::fromUtf8("DeafaultCategoryLabel"));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Open Sans"));
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        DeafaultCategoryLabel->setFont(font4);
        DeafaultCategoryLabel->setStyleSheet(QString::fromUtf8("color: #000;"));

        horizontalLayout_9->addWidget(DeafaultCategoryLabel);


        verticalLayout_7->addWidget(DefaultCategoryTitle);

        DefaultCategoryItems = new QWidget(DefaultCategory);
        DefaultCategoryItems->setObjectName(QString::fromUtf8("DefaultCategoryItems"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(DefaultCategoryItems->sizePolicy().hasHeightForWidth());
        DefaultCategoryItems->setSizePolicy(sizePolicy4);
        DefaultCategoryItems->setLayoutDirection(Qt::LeftToRight);
        gridLayout_6 = new QGridLayout(DefaultCategoryItems);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        Text = new QPushButton(DefaultCategoryItems);
        Text->setObjectName(QString::fromUtf8("Text"));
        Text->setMinimumSize(QSize(30, 30));
        Text->setMaximumSize(QSize(30, 30));
        Text->setFont(font);

        gridLayout_6->addWidget(Text, 0, 2, 1, 1);

        Square = new QPushButton(DefaultCategoryItems);
        Square->setObjectName(QString::fromUtf8("Square"));
        Square->setMinimumSize(QSize(30, 30));
        Square->setMaximumSize(QSize(30, 30));
        Square->setFont(font);

        gridLayout_6->addWidget(Square, 0, 0, 1, 1);

        Line = new QPushButton(DefaultCategoryItems);
        Line->setObjectName(QString::fromUtf8("Line"));
        Line->setMinimumSize(QSize(30, 30));
        Line->setMaximumSize(QSize(30, 30));
        Line->setFont(font);

        gridLayout_6->addWidget(Line, 0, 1, 1, 1);


        verticalLayout_7->addWidget(DefaultCategoryItems);


        verticalLayout_9->addWidget(DefaultCategory);

        LogicalCategory = new QWidget(Categories);
        LogicalCategory->setObjectName(QString::fromUtf8("LogicalCategory"));
        verticalLayout_8 = new QVBoxLayout(LogicalCategory);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        LogicalCategoryTitle = new QWidget(LogicalCategory);
        LogicalCategoryTitle->setObjectName(QString::fromUtf8("LogicalCategoryTitle"));
        LogicalCategoryTitle->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_10 = new QHBoxLayout(LogicalCategoryTitle);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        LogicalCategoryLabel = new QLabel(LogicalCategoryTitle);
        LogicalCategoryLabel->setObjectName(QString::fromUtf8("LogicalCategoryLabel"));
        sizePolicy.setHeightForWidth(LogicalCategoryLabel->sizePolicy().hasHeightForWidth());
        LogicalCategoryLabel->setSizePolicy(sizePolicy);
        LogicalCategoryLabel->setFont(font4);
        LogicalCategoryLabel->setStyleSheet(QString::fromUtf8("color: #000;"));

        horizontalLayout_10->addWidget(LogicalCategoryLabel);


        verticalLayout_8->addWidget(LogicalCategoryTitle);

        LogicalCategoryItems = new QWidget(LogicalCategory);
        LogicalCategoryItems->setObjectName(QString::fromUtf8("LogicalCategoryItems"));
        sizePolicy4.setHeightForWidth(LogicalCategoryItems->sizePolicy().hasHeightForWidth());
        LogicalCategoryItems->setSizePolicy(sizePolicy4);
        LogicalCategoryItems->setLayoutDirection(Qt::LeftToRight);
        gridLayout_7 = new QGridLayout(LogicalCategoryItems);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        NOT = new QPushButton(LogicalCategoryItems);
        NOT->setObjectName(QString::fromUtf8("NOT"));
        NOT->setMinimumSize(QSize(30, 30));
        NOT->setMaximumSize(QSize(16777215, 16777215));
        NOT->setFont(font);

        gridLayout_7->addWidget(NOT, 0, 1, 1, 1);

        XOR = new QPushButton(LogicalCategoryItems);
        XOR->setObjectName(QString::fromUtf8("XOR"));
        XOR->setMinimumSize(QSize(30, 30));
        XOR->setMaximumSize(QSize(16777215, 16777215));
        XOR->setFont(font);

        gridLayout_7->addWidget(XOR, 0, 3, 1, 1);

        AND = new QPushButton(LogicalCategoryItems);
        AND->setObjectName(QString::fromUtf8("AND"));
        AND->setMinimumSize(QSize(30, 30));
        AND->setMaximumSize(QSize(16777215, 16777215));
        AND->setFont(font);

        gridLayout_7->addWidget(AND, 0, 0, 1, 1);

        OR = new QPushButton(LogicalCategoryItems);
        OR->setObjectName(QString::fromUtf8("OR"));
        OR->setMinimumSize(QSize(30, 30));
        OR->setMaximumSize(QSize(16777215, 16777215));
        OR->setFont(font);

        gridLayout_7->addWidget(OR, 0, 2, 1, 1);


        verticalLayout_8->addWidget(LogicalCategoryItems);


        verticalLayout_9->addWidget(LogicalCategory);

        scrollArea->setWidget(Categories);

        verticalLayout->addWidget(scrollArea);

        widget = new QWidget(Sidebar);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        pushButton->setMaximumSize(QSize(30, 30));
        pushButton->setFont(font3);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: #27ae60;\n"
"	border: none;\n"
"	color: #fff;\n"
"	width: 60px;\n"
"	height: 60px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #2ecc71;\n"
"}"));

        gridLayout_2->addWidget(pushButton, 0, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color:#000;"));

        gridLayout_2->addWidget(label, 0, 1, 1, 1);


        verticalLayout->addWidget(widget);


        gridLayout->addWidget(Sidebar, 0, 1, 1, 1);

        editor = new QGraphicsView(Container);
        editor->setObjectName(QString::fromUtf8("editor"));
        editor->setMinimumSize(QSize(550, 0));
        editor->setFont(font);
        editor->setStyleSheet(QString::fromUtf8("border: none;"));
        editor->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        editor->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        editor->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        editor->setDragMode(QGraphicsView::NoDrag);

        gridLayout->addWidget(editor, 0, 2, 1, 1);

        MainWindow->setCentralWidget(Container);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ModeLabel->setText(QCoreApplication::translate("MainWindow", "Modes", nullptr));
#if QT_CONFIG(tooltip)
        selectMode->setToolTip(QCoreApplication::translate("MainWindow", "Select mode", nullptr));
#endif // QT_CONFIG(tooltip)
        selectMode->setText(QCoreApplication::translate("MainWindow", "mouse-pointer", nullptr));
#if QT_CONFIG(tooltip)
        createMode->setToolTip(QCoreApplication::translate("MainWindow", "Create mode", nullptr));
#endif // QT_CONFIG(tooltip)
        createMode->setText(QCoreApplication::translate("MainWindow", "plus", nullptr));
#if QT_CONFIG(tooltip)
        editMode->setToolTip(QCoreApplication::translate("MainWindow", "Edit mode", nullptr));
#endif // QT_CONFIG(tooltip)
        editMode->setText(QCoreApplication::translate("MainWindow", "edit", nullptr));
#if QT_CONFIG(tooltip)
        deleteMode->setToolTip(QCoreApplication::translate("MainWindow", "Delete mode", nullptr));
#endif // QT_CONFIG(tooltip)
        deleteMode->setText(QCoreApplication::translate("MainWindow", "trash", nullptr));
        CategoriesLabel->setText(QCoreApplication::translate("MainWindow", "Categories", nullptr));
#if QT_CONFIG(tooltip)
        addCategory->setToolTip(QCoreApplication::translate("MainWindow", "Add new category", nullptr));
#endif // QT_CONFIG(tooltip)
        addCategory->setText(QCoreApplication::translate("MainWindow", "plus", nullptr));
        DeafaultCategoryLabel->setText(QCoreApplication::translate("MainWindow", "Default", nullptr));
        Text->setText(QCoreApplication::translate("MainWindow", "T", nullptr));
        Square->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
        Line->setText(QCoreApplication::translate("MainWindow", "L", nullptr));
        LogicalCategoryLabel->setText(QCoreApplication::translate("MainWindow", "Logical blocks", nullptr));
        NOT->setText(QCoreApplication::translate("MainWindow", "NOT", nullptr));
        XOR->setText(QCoreApplication::translate("MainWindow", "XOR", nullptr));
        AND->setText(QCoreApplication::translate("MainWindow", "AND", nullptr));
        OR->setText(QCoreApplication::translate("MainWindow", "OR", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "tools", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Build program", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H