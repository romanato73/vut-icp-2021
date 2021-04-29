#include "createblockdialog.h"
#include "ui_createblockdialog.h"

CreateBlockDialog::CreateBlockDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateBlockDialog)
{
    ui->setupUi(this);
}

CreateBlockDialog::~CreateBlockDialog()
{
    delete ui;
}
