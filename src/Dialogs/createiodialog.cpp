#include "createiodialog.h"
#include "ui_createiodialog.h"

#include <QMessageBox>

CreateIODialog::CreateIODialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateIODialog)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    this->setModal(true);
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

    if (type == "input") {
        ui->ioLabel->setText("Value");
    } else {
        ui->inTypes->setVisible(false);
        ui->ioLabel->setText("Name");
    }
}

void CreateIODialog::on_create_clicked()
{
    QMessageBox msg;

    name = ui->name->text();
    ioType = "";

    if (name.isEmpty()) {
        msg.warning(nullptr, "Warning", "Category name can not be empty!");
    } else if (name == "input" && ioType.isEmpty()) {
        msg.warning(nullptr, "Warning", "Select io type");
    } else {
        accept();
    }
}

void CreateIODialog::on_InTypeInt_clicked()
{
    this->ioType = "int";
}


void CreateIODialog::on_InTypeFloat_clicked()
{
    this->ioType = "float";
}


void CreateIODialog::on_InTypeBool_clicked()
{
    this->ioType = "bool";
}


void CreateIODialog::on_InTypeString_clicked()
{
    this->ioType = "string";
}

