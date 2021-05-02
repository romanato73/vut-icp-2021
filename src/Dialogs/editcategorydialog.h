#ifndef EDITCATEGORYDIALOG_H
#define EDITCATEGORYDIALOG_H

#include <QDialog>

namespace Ui {
class EditCategoryDialog;
}

class EditCategoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditCategoryDialog(QWidget *parent = nullptr);
    ~EditCategoryDialog();

    QString categoryName;
    QStringList categories;

    void setCategories(QStringList categories);

    void setCategoryName(QString name);

private slots:
    void on_categoryUpdate_clicked();

private:
    Ui::EditCategoryDialog *ui;
};

#endif // EDITCATEGORYDIALOG_H
