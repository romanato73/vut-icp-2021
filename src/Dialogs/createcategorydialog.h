#ifndef CREATECATEGORYDIALOG_H
#define CREATECATEGORYDIALOG_H

#include <QDialog>

namespace Ui {
class CreateCategoryDialog;
}

class CreateCategoryDialog : public QDialog
{
    Q_OBJECT

public:  
    explicit CreateCategoryDialog(QWidget *parent = nullptr);
    ~CreateCategoryDialog();

    /**
     * @brief categoryName Category name
     */
    QString categoryName;

    /**
     * @brief categories List of categories
     */
    QStringList categories;

    /**
     * @brief setCategories Sets the categories to prevent duplicates
     * @param categories
     */
    void setCategories(QStringList categories);

private slots:
    /**
     * @brief on_categoryAdd_clicked Creates the category
     */
    void on_categoryAdd_clicked();

private:
    Ui::CreateCategoryDialog *ui;
};

#endif // CREATECATEGORYDIALOG_H
