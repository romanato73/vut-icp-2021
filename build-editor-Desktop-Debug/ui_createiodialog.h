/********************************************************************************
** Form generated from reading UI file 'createiodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEIODIALOG_H
#define UI_CREATEIODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateIODialog
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *title;
    QLabel *label_2;
    QLineEdit *name;
    QPushButton *create;

    void setupUi(QDialog *CreateIODialog)
    {
        if (CreateIODialog->objectName().isEmpty())
            CreateIODialog->setObjectName(QString::fromUtf8("CreateIODialog"));
        CreateIODialog->resize(300, 160);
        CreateIODialog->setMaximumSize(QSize(300, 160));
        CreateIODialog->setStyleSheet(QString::fromUtf8("QDialog {\n"
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
        verticalLayout = new QVBoxLayout(CreateIODialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(CreateIODialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        title = new QLabel(widget);
        title->setObjectName(QString::fromUtf8("title"));
        QFont font;
        font.setFamily(QString::fromUtf8("Open Sans"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        title->setFont(font);
        title->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(title);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        name = new QLineEdit(widget);
        name->setObjectName(QString::fromUtf8("name"));

        verticalLayout_2->addWidget(name);

        create = new QPushButton(widget);
        create->setObjectName(QString::fromUtf8("create"));

        verticalLayout_2->addWidget(create);


        verticalLayout->addWidget(widget);


        retranslateUi(CreateIODialog);

        QMetaObject::connectSlotsByName(CreateIODialog);
    } // setupUi

    void retranslateUi(QDialog *CreateIODialog)
    {
        CreateIODialog->setWindowTitle(QString());
        title->setText(QString());
        label_2->setText(QCoreApplication::translate("CreateIODialog", "Name", nullptr));
        create->setText(QCoreApplication::translate("CreateIODialog", "Create", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateIODialog: public Ui_CreateIODialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEIODIALOG_H
