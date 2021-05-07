#ifndef CREATEBLOCKDIALOG_H
#define CREATEBLOCKDIALOG_H

#include <QDialog>

#include <Components/block.h>

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
     * @brief block New Block instance
     */
    Block *block = new Block();

    /**
     * @brief loadCategories Loads the categories
     */
    void loadCategories(QStringList categories);

private slots:
    /**
     * @brief on_createBlock_clicked Creates the block
     */
    void on_createBlock_clicked();

private:
    Ui::CreateBlockDialog *ui;
};

#endif // CREATEBLOCKDIALOG_H
