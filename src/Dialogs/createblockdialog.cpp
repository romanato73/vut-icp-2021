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

    // Set no category if set
    if (block->category == "No Category") block->category = "";

    // Checks the block name inputs outputs and code
    if (block->name.isEmpty() || block->inputs.isEmpty() || block->outputs.isEmpty() || block->code.isEmpty()) {
        msg.critical(nullptr, "Error", "Fill all fields!");
    } else if (storage->hasBlock(block)) {
        msg.critical(nullptr, "Error", "This category already contains block with this name.");
    } else {
        if (isValidIO()) accept();
    }
}

bool CreateBlockDialog::isValidIO()
{
    QMessageBox msg;

    QStringList validTypes{"int", "float", "bool", "string"};

    // Check if inputs are valid
    QStringList inNames;
    for (auto names : block->inputs) {
        if (!names.contains(":")) {
            msg.warning(nullptr, "Warning", "Invalid usage of input.");
            return false;
        }

        // Check type
        auto inType = names.split(":").at(0);
        if (!validTypes.contains(inType)) {
            msg.warning(nullptr, "Warning", "Input type " + inType + " is invalid. (Allowed: int, float, bool, string)");
            return false;
        }

        // Append name
        auto inName = names.split(":").at(1);
        inNames.append(inName);
    }

    // Check for unique input
    auto inIt = std::unique(inNames.begin(), inNames.end());
    bool inIsUnique = (inIt == inNames.end());
    if (!inIsUnique) {
        msg.warning(nullptr, "Warning", "Inputs can not have same name!");
        return false;
    }

    // Check if outputs are valid
    QStringList outNames;
    for (auto names : block->outputs) {
        if (!names.contains(":")) {
            msg.warning(nullptr, "Warning", "Invalid usage of output.");
            return false;
        }

        // Check type
        auto outType = names.split(":").at(0);
        if (!validTypes.contains(outType)) {
            msg.warning(nullptr, "Warning", "Output type " + outType + " is invalid. (Allowed: int, float, bool, string)");
            return false;
        }

        // Append name
        auto outName = names.split(":").at(1);
        outNames.append(outName);
    }

    // Check for unique output
    auto outIt = std::unique(outNames.begin(), outNames.end());
    bool outIsUnique = (outIt == outNames.end());
    if (!outIsUnique) {
        msg.warning(nullptr, "Warning", "Outputs can not have same name!");
        return false;
    }

    return true;
}
