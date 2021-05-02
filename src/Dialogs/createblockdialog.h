#ifndef CREATEBLOCKDIALOG_H
#define CREATEBLOCKDIALOG_H

#include <QDialog>

namespace Ui {
class CreateBlockDialog;
}

class CreateBlockDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateBlockDialog(QWidget *parent = nullptr);
    ~CreateBlockDialog();

    /**
     * @brief loadCategories Loads the categories
     */
    void loadCategories(QStringList categories);

private slots:
    void on_createBlock_clicked();

private:
    Ui::CreateBlockDialog *ui;
};

#endif // CREATEBLOCKDIALOG_H
