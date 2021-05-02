#include "createblockdialog.h"
#include "ui_createblockdialog.h"

#include <QMessageBox>

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

void CreateBlockDialog::loadCategories(QStringList categories)
{
    for (auto category : categories) {
        ui->blockCategory->addItem(category);
    }
}

void CreateBlockDialog::on_createBlock_clicked()
{
    QMessageBox msg;

    auto blockName = ui->blockName->text();
    auto blockCategory = ui->blockCategory->currentText();
    auto inputs = ui->inputs->toPlainText();
    auto outputs = ui->outputs->toPlainText();
    auto code = ui->code->toPlainText();

    if (blockName.isEmpty() || blockCategory.isEmpty()) {
        msg.critical(nullptr, "Error", "Block name and category can not be empty!");
    }

//    if (this->categories.contains(this->categoryName + "Category")) {
//        msg.critical(nullptr, "Error", "This category already exists.");
//    } else if (this->categoryName.isEmpty()) {
//        msg.warning(nullptr, "Warning", "Category name can not be empty!");
//    } else {
//        // Accepted
//        accept();
//    }
}
