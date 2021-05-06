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
}

void CreateIODialog::on_create_clicked()
{
    QMessageBox msg;

    name = ui->name->text();

    if (name.isEmpty()) {
        msg.warning(nullptr, "Warning", "Category name can not be empty!");
    } else {
        accept();
    }
}
