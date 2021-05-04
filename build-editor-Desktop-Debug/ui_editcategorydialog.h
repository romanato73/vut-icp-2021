/********************************************************************************
** Form generated from reading UI file 'editcategorydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITCATEGORYDIALOG_H
#define UI_EDITCATEGORYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditCategoryDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *categoryName;
    QPushButton *categoryUpdate;

    void setupUi(QDialog *EditCategoryDialog)
    {
        if (EditCategoryDialog->objectName().isEmpty())
            EditCategoryDialog->setObjectName(QString::fromUtf8("EditCategoryDialog"));
        EditCategoryDialog->resize(300, 135);
        EditCategoryDialog->setMaximumSize(QSize(300, 135));
        EditCategoryDialog->setWindowOpacity(1.000000000000000);
        EditCategoryDialog->setStyleSheet(QString::fromUtf8("background-color: #fff;"));
        EditCategoryDialog->setModal(true);
        verticalLayout_2 = new QVBoxLayout(EditCategoryDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(EditCategoryDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        QFont font;
        font.setFamily(QString::fromUtf8("Open Sans"));
        widget->setFont(font);
        widget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: #000;"));

        verticalLayout->addWidget(label);

        categoryName = new QLineEdit(widget);
        categoryName->setObjectName(QString::fromUtf8("categoryName"));
        categoryName->setFont(font);
        categoryName->setStyleSheet(QString::fromUtf8("border: 1px solid #DBDBDB;\n"
"padding: 10px;"));

        verticalLayout->addWidget(categoryName);

        categoryUpdate = new QPushButton(widget);
        categoryUpdate->setObjectName(QString::fromUtf8("categoryUpdate"));
        categoryUpdate->setFont(font);
        categoryUpdate->setStyleSheet(QString::fromUtf8("background-color: #6A6FFF;\n"
"color: #fff;\n"
"border: none;\n"
"padding: 10px;"));

        verticalLayout->addWidget(categoryUpdate);


        verticalLayout_2->addWidget(widget);


        retranslateUi(EditCategoryDialog);

        QMetaObject::connectSlotsByName(EditCategoryDialog);
    } // setupUi

    void retranslateUi(QDialog *EditCategoryDialog)
    {
        EditCategoryDialog->setWindowTitle(QCoreApplication::translate("EditCategoryDialog", "Edit category", nullptr));
        label->setText(QCoreApplication::translate("EditCategoryDialog", "Name", nullptr));
        categoryUpdate->setText(QCoreApplication::translate("EditCategoryDialog", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditCategoryDialog: public Ui_EditCategoryDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITCATEGORYDIALOG_H
