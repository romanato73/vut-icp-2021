#include "createiodialog.h"
#include "ui_createiodialog.h"

#include <QMessageBox>

CreateIODialog::CreateIODialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateIODialog)
{
    ui->setupUi(this);
}

CreateIODialog::~CreateIODialog()
{
    delete ui;
}

void CreateIODialog::setType(QString type)
{
    this->type = type;

    this->setWindowTitle("Create " + type);
    ui->title->setText("Create " + type);

    if (type != "input") {
        ui->inTypes->setVisible(false);
        ui->ioLabel->setText("Name");
    } else {
        ui->ioLabel->setText("Value");
    }
}

void CreateIODialog::on_create_clicked()
{
    QMessageBox msg;

    name = ui->name->text();

    if (name.isEmpty()) {
        msg.warning(nullptr, "Warning", "Category name can not be empty!");
    } else if (type == "input" && inType.isEmpty()) {
        msg.warning(nullptr, "Warning", "Select input type");
    } else {
        accept();
    }
}

void CreateIODialog::on_InTypeInt_clicked()
{
    this->inType = "int";
}


void CreateIODialog::on_InTypeFloat_clicked()
{
    this->inType = "float";
}


void CreateIODialog::on_InTypeBool_clicked()
{
    this->inType = "bool";
}


void CreateIODialog::on_InTypeString_clicked()
{
    this->inType = "string";
}

