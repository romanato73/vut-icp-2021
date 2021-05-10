/**
 * Editor and interpret of the hierarchically structured function blocks
 * Faculty of Information Technology, Brno University of Technology
 *
 * @author Roman Országh <xorsza01@stud.fit.vutbr.cz>
 * @author Albert Groma <xgroma00@stud.fit.vutbr.cz>
 */

#ifndef CREATECATEGORYDIALOG_H
#define CREATECATEGORYDIALOG_H

#include <QDialog>

namespace Ui {
class CreateCategoryDialog;
}

/**
 * @brief The CreateCategoryDialog class
 */
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
    /**
     * @brief ui
     */
    Ui::CreateCategoryDialog *ui;
};

#endif // CREATECATEGORYDIALOG_H
