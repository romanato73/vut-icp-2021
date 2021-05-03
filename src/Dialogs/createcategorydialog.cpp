#include "createcategorydialog.h"
#include "ui_createcategorydialog.h"

#include <QMessageBox>

CreateCategoryDialog::CreateCategoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateCategoryDialog)
{
    ui->setupUi(this);
}

CreateCategoryDialog::~CreateCategoryDialog()
{
    delete ui;
}

void CreateCategoryDialog::setCategories(QStringList categories)
{
    this->categories = categories;
}

void CreateCategoryDialog::on_categoryAdd_clicked()
{
    QMessageBox msg;

    this->categoryName = ui->categoryName->displayText();

    if (this->categories.contains(this->categoryName + "Category")) {
        msg.critical(nullptr, "Error", "This category already exists.");
    } else if (this->categoryName.isEmpty()) {
        msg.warning(nullptr, "Warning", "Category name can not be empty!");
    } else {
        // Accepted
        accept();
    }
}
