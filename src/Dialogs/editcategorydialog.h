#ifndef EDITCATEGORYDIALOG_H
#define EDITCATEGORYDIALOG_H

#include <QDialog>
#include <QJsonArray>

namespace Ui {
class EditCategoryDialog;
}

class EditCategoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditCategoryDialog(QWidget *parent = nullptr);
    ~EditCategoryDialog();

    /**
     * @brief categoryName Name of the current category
     */
    QString categoryName;

    /**
     * @brief categories All categories
     */
    QStringList categories;

    /**
     * @brief setCategories Sets categories
     * @param categories    Categories that are stored in storage
     */
    void setCategories(QStringList categories);

    /**
     * @brief setCategoryName Sets new category name
     * @param name            The name that is set
     */
    void setCategoryName(QString name);

private slots:
    /**
     * @brief on_categoryUpdate_clicked Updates the category
     */
    void on_categoryUpdate_clicked();

private:
    Ui::EditCategoryDialog *ui;
};

#endif // EDITCATEGORYDIALOG_H
