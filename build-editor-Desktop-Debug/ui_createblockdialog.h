/********************************************************************************
** Form generated from reading UI file 'createblockdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEBLOCKDIALOG_H
#define UI_CREATEBLOCKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateBlockDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *blockNameLabel;
    QLineEdit *blockName;
    QLabel *blockCategoryLabel;
    QComboBox *blockCategory;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QWidget *inputsWidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *inputsLabel;
    QTextEdit *inputs;
    QWidget *outputsWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *outputsLabel;
    QTextEdit *outputs;
    QWidget *codeWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *codeLabel;
    QTextEdit *code;
    QPushButton *createBlock;

    void setupUi(QDialog *CreateBlockDialog)
    {
        if (CreateBlockDialog->objectName().isEmpty())
            CreateBlockDialog->setObjectName(QString::fromUtf8("CreateBlockDialog"));
        CreateBlockDialog->resize(600, 400);
        CreateBlockDialog->setMinimumSize(QSize(0, 0));
        CreateBlockDialog->setMaximumSize(QSize(600, 400));
        CreateBlockDialog->setStyleSheet(QString::fromUtf8("background-color:#fff;color:#000;"));
        verticalLayout = new QVBoxLayout(CreateBlockDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        blockNameLabel = new QLabel(CreateBlockDialog);
        blockNameLabel->setObjectName(QString::fromUtf8("blockNameLabel"));

        verticalLayout->addWidget(blockNameLabel);

        blockName = new QLineEdit(CreateBlockDialog);
        blockName->setObjectName(QString::fromUtf8("blockName"));
        blockName->setStyleSheet(QString::fromUtf8("border: 1px solid #DBDBDB;\n"
"padding: 10px;"));

        verticalLayout->addWidget(blockName);

        blockCategoryLabel = new QLabel(CreateBlockDialog);
        blockCategoryLabel->setObjectName(QString::fromUtf8("blockCategoryLabel"));

        verticalLayout->addWidget(blockCategoryLabel);

        blockCategory = new QComboBox(CreateBlockDialog);
        blockCategory->setObjectName(QString::fromUtf8("blockCategory"));
        blockCategory->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"	border: 1px solid #DBDBDB;\n"
"	padding: 10px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"	border: 1px solid #DBDBDB;\n"
"}"));

        verticalLayout->addWidget(blockCategory);

        widget = new QWidget(CreateBlockDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        inputsWidget = new QWidget(widget);
        inputsWidget->setObjectName(QString::fromUtf8("inputsWidget"));
        inputsWidget->setMaximumSize(QSize(150, 16777215));
        verticalLayout_2 = new QVBoxLayout(inputsWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        inputsLabel = new QLabel(inputsWidget);
        inputsLabel->setObjectName(QString::fromUtf8("inputsLabel"));

        verticalLayout_2->addWidget(inputsLabel);

        inputs = new QTextEdit(inputsWidget);
        inputs->setObjectName(QString::fromUtf8("inputs"));
        inputs->setStyleSheet(QString::fromUtf8("border: 1px solid #DBDBDB;\n"
"padding: 10px;"));

        verticalLayout_2->addWidget(inputs);


        horizontalLayout->addWidget(inputsWidget);

        outputsWidget = new QWidget(widget);
        outputsWidget->setObjectName(QString::fromUtf8("outputsWidget"));
        outputsWidget->setMaximumSize(QSize(150, 16777215));
        verticalLayout_4 = new QVBoxLayout(outputsWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        outputsLabel = new QLabel(outputsWidget);
        outputsLabel->setObjectName(QString::fromUtf8("outputsLabel"));

        verticalLayout_4->addWidget(outputsLabel);

        outputs = new QTextEdit(outputsWidget);
        outputs->setObjectName(QString::fromUtf8("outputs"));
        outputs->setStyleSheet(QString::fromUtf8("border: 1px solid #DBDBDB;\n"
"padding: 10px;"));

        verticalLayout_4->addWidget(outputs);


        horizontalLayout->addWidget(outputsWidget);

        codeWidget = new QWidget(widget);
        codeWidget->setObjectName(QString::fromUtf8("codeWidget"));
        verticalLayout_3 = new QVBoxLayout(codeWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        codeLabel = new QLabel(codeWidget);
        codeLabel->setObjectName(QString::fromUtf8("codeLabel"));

        verticalLayout_3->addWidget(codeLabel);

        code = new QTextEdit(codeWidget);
        code->setObjectName(QString::fromUtf8("code"));
        code->setStyleSheet(QString::fromUtf8("border: 1px solid #DBDBDB;\n"
"padding: 10px;"));

        verticalLayout_3->addWidget(code);


        horizontalLayout->addWidget(codeWidget);


        verticalLayout->addWidget(widget);

        createBlock = new QPushButton(CreateBlockDialog);
        createBlock->setObjectName(QString::fromUtf8("createBlock"));
        createBlock->setStyleSheet(QString::fromUtf8("background-color: #6A6FFF;\n"
"color: #fff;\n"
"border: none;\n"
"padding: 10px;"));

        verticalLayout->addWidget(createBlock);


        retranslateUi(CreateBlockDialog);

        QMetaObject::connectSlotsByName(CreateBlockDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateBlockDialog)
    {
        CreateBlockDialog->setWindowTitle(QCoreApplication::translate("CreateBlockDialog", "Create block", nullptr));
        blockNameLabel->setText(QCoreApplication::translate("CreateBlockDialog", "Name", nullptr));
        blockCategoryLabel->setText(QCoreApplication::translate("CreateBlockDialog", "Category", nullptr));
        blockCategory->setPlaceholderText(QCoreApplication::translate("CreateBlockDialog", "Choose category", nullptr));
        inputsLabel->setText(QCoreApplication::translate("CreateBlockDialog", "Inputs", nullptr));
        outputsLabel->setText(QCoreApplication::translate("CreateBlockDialog", "Outputs", nullptr));
        codeLabel->setText(QCoreApplication::translate("CreateBlockDialog", "Code", nullptr));
        createBlock->setText(QCoreApplication::translate("CreateBlockDialog", "Create block", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateBlockDialog: public Ui_CreateBlockDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEBLOCKDIALOG_H
