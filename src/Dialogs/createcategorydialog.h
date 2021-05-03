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

    QString categoryName;
    QStringList categories;

    void setCategories(QStringList categories);

private slots:
    void on_categoryAdd_clicked();

private:
    Ui::CreateCategoryDialog *ui;
};

#endif // CREATECATEGORYDIALOG_H
