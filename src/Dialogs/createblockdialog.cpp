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

    // Checks the block name inputs outputs and code
    if (block->name.isEmpty() || block->inputs.isEmpty() || block->outputs.isEmpty() || block->code.isEmpty()) {
        msg.critical(nullptr, "Error", "Fill all fields!");
    } else if (storage->hasBlock(block)) {
        msg.critical(nullptr, "Error", "This category already contains block with this name.");
    } else {
        accept();
    }
}
