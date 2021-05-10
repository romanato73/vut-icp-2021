#include "editblockdialog.h"
#include "ui_editblockdialog.h"

#include <QMessageBox>

EditBlockDialog::EditBlockDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditBlockDialog)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    this->setModal(true);
}

EditBlockDialog::~EditBlockDialog()
{
    delete ui;
}

void EditBlockDialog::initializeForm(Block *origin)
{
    block = origin;

    // Sets the inputs and ouputs
    inputsForm = block->inputs.join('\n');
    outputsForm = block->outputs.join('\n');

    // Set data into dialog
    ui->blockName->setText(block->name);
    ui->inputs->setText(inputsForm);
    ui->outputs->setText(outputsForm);
    ui->code->setText(block->code);
}

void EditBlockDialog::on_editBlock_clicked()
{
    QMessageBox msg;

    // Set the block
    block->name = ui->blockName->text();
    block->code = ui->code->toPlainText();
    block->inputs = ui->inputs->toPlainText().split('\n');
    block->outputs = ui->outputs->toPlainText().split('\n');

    // Check name, inputs, outputs, code
    if (block->name.isEmpty() || block->inputs.isEmpty() || block->outputs.isEmpty() || block->code.isEmpty()) {
        msg.critical(nullptr, "Error", "Block name can not be empty!");
    } else {
        accept();
    }
}

