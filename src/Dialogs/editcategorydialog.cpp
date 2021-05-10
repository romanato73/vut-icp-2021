#include "editcategorydialog.h"
#include "ui_editcategorydialog.h"

#include <QMessageBox>

EditCategoryDialog::EditCategoryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditCategoryDialog)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::Dialog | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    this->setModal(true);
}

EditCategoryDialog::~EditCategoryDialog()
{
    delete ui;
}

void EditCategoryDialog::setCategories(QStringList categories)
{
    this->categories = categories;
}

void EditCategoryDialog::setCategoryName(QString name)
{
    this->categoryName = name;

    ui->categoryName->setText(name);
}

void EditCategoryDialog::on_categoryUpdate_clicked()
{
    QMessageBox msg;

    this->categoryName = ui->categoryName->text();

    // Checks the category and name
    if (this->categories.contains(this->categoryName + "Category")) {
        msg.critical(nullptr, "Error", "This category already exists.");
    } else if (this->categoryName.isEmpty()) {
        msg.warning(nullptr, "Warning", "Category name can not be empty!");
    } else {
        // Accepted
        accept();
    }
}
