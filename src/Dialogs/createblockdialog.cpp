#include "createblockdialog.h"
#include "ui_createblockdialog.h"

#include <QMessageBox>

CreateBlockDialog::CreateBlockDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateBlockDialog)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    this->setModal(true);
}

CreateBlockDialog::~CreateBlockDialog()
{
    delete ui;
}

void CreateBlockDialog::loadCategories(QStringList categories)
{
    for (const QString &category : categories) {
        ui->blockCategory->addItem(category);
    }
}

void CreateBlockDialog::on_createBlock_clicked()
{
    QMessageBox msg;

    // Sets the block data
    block->name = ui->blockName->text();
    block->category = ui->blockCategory->currentText();
    block->code = ui->code->toPlainText();

    // Split inputs and outputs into string list
    block->inputs = ui->inputs->toPlainText().split('\n');
    block->outputs = ui->outputs->toPlainText().split('\n');

    if (block->name.isEmpty()) {
        msg.critical(nullptr, "Error", "Block name can not be empty!");
    } else {
        /** @todo: Check if block does not already exists in category */
        accept();
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
