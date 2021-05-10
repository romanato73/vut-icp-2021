/**
 * Editor and interpret of the hierarchically structured function blocks
 * Faculty of Information Technology, Brno University of Technology
 *
 * @author Roman Országh <xorsza01@stud.fit.vutbr.cz>
 * @author Albert Groma <xgroma00@stud.fit.vutbr.cz>
 */

#ifndef EDITCATEGORYDIALOG_H
#define EDITCATEGORYDIALOG_H

#include <QDialog>
#include <QJsonArray>

namespace Ui {
class EditCategoryDialog;
}

/**
 * @brief The EditCategoryDialog class
 */
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
    /**
     * @brief ui
     */
    Ui::EditCategoryDialog *ui;
};

#endif // EDITCATEGORYDIALOG_H
