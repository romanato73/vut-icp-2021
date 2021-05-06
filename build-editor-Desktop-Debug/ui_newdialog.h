/********************************************************************************
** Form generated from reading UI file 'newdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWDIALOG_H
#define UI_NEWDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *categoryName;
    QPushButton *categoryUpdate;

    void setupUi(QDialog *NewDialog)
    {
        if (NewDialog->objectName().isEmpty())
            NewDialog->setObjectName(QString::fromUtf8("NewDialog"));
        NewDialog->resize(300, 165);
        NewDialog->setMaximumSize(QSize(300, 165));
        NewDialog->setWindowOpacity(1.000000000000000);
        NewDialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
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
        NewDialog->setModal(true);
        verticalLayout_2 = new QVBoxLayout(NewDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget = new QWidget(NewDialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        QFont font;
        font.setFamily(QString::fromUtf8("Open Sans"));
        widget->setFont(font);
        widget->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Open Sans"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

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

        categoryUpdate = new QPushButton(widget);
        categoryUpdate->setObjectName(QString::fromUtf8("categoryUpdate"));
        categoryUpdate->setFont(font);
        categoryUpdate->setStyleSheet(QString::fromUtf8(""));

        verticalLayout->addWidget(categoryUpdate);


        verticalLayout_2->addWidget(widget);


        retranslateUi(NewDialog);

        QMetaObject::connectSlotsByName(NewDialog);
    } // setupUi

    void retranslateUi(QDialog *NewDialog)
    {
        NewDialog->setWindowTitle(QCoreApplication::translate("NewDialog", "Edit a category", nullptr));
        label_2->setText(QCoreApplication::translate("NewDialog", "Edit a category", nullptr));
        label->setText(QCoreApplication::translate("NewDialog", "Name", nullptr));
        categoryUpdate->setText(QCoreApplication::translate("NewDialog", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewDialog: public Ui_NewDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWDIALOG_H
