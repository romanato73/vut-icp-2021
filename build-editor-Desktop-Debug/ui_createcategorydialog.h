/********************************************************************************
** Form generated from reading UI file 'createcategorydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATECATEGORYDIALOG_H
#define UI_CREATECATEGORYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateCategoryDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *createCategoryLabel;
    QLabel *label;
    QLineEdit *categoryName;
    QPushButton *categoryAdd;

    void setupUi(QDialog *CreateCategoryDialog)
    {
        if (CreateCategoryDialog->objectName().isEmpty())
            CreateCategoryDialog->setObjectName(QString::fromUtf8("CreateCategoryDialog"));
        CreateCategoryDialog->resize(300, 165);
        CreateCategoryDialog->setMaximumSize(QSize(300, 165));
        CreateCategoryDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
"	background-color: #fff;\n"
"	border: 1px solid #DBDBDB;\n"
"}\n"
"\n"
"QLabel {\n"
"	color: #000;\n"
"}\n"
"\n"
"QPushButton {\n"
"	background-color: #6A6FFF;\n"
"	color: #fff;\n"
"	border: none;\n"
"	padding: 10px;\n"
"}\n"
"\n"
"QLineEdit {\n"
"	background-color: #fff;\n"
"	border: 1px solid #DBDBDB;\n"
"	padding: 10px;\n"
"}"));
        CreateCategoryDialog->setModal(true);
        verticalLayout_2 = new QVBoxLayout(CreateCategoryDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(CreateCategoryDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        QFont font;
        font.setFamily(QString::fromUtf8("Open Sans"));
        widget->setFont(font);
        widget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        createCategoryLabel = new QLabel(widget);
        createCategoryLabel->setObjectName(QString::fromUtf8("createCategoryLabel"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Open Sans"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        createCategoryLabel->setFont(font1);
        createCategoryLabel->setStyleSheet(QString::fromUtf8(""));
        createCategoryLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(createCategoryLabel);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(label);

        categoryName = new QLineEdit(widget);
        categoryName->setObjectName(QString::fromUtf8("categoryName"));
        categoryName->setFont(font);
        categoryName->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(categoryName);

        categoryAdd = new QPushButton(widget);
        categoryAdd->setObjectName(QString::fromUtf8("categoryAdd"));
        categoryAdd->setFont(font);
        categoryAdd->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(categoryAdd);


        verticalLayout_2->addWidget(widget);


        retranslateUi(CreateCategoryDialog);

        QMetaObject::connectSlotsByName(CreateCategoryDialog);
    } // setupUi

    void retranslateUi(QDialog *CreateCategoryDialog)
    {
        CreateCategoryDialog->setWindowTitle(QCoreApplication::translate("CreateCategoryDialog", "Add a category", nullptr));
        createCategoryLabel->setText(QCoreApplication::translate("CreateCategoryDialog", "Create a category", nullptr));
        label->setText(QCoreApplication::translate("CreateCategoryDialog", "Name", nullptr));
        categoryAdd->setText(QCoreApplication::translate("CreateCategoryDialog", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateCategoryDialog: public Ui_CreateCategoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATECATEGORYDIALOG_H
