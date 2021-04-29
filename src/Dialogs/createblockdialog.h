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

    void loadCategories();

private:
    Ui::CreateBlockDialog *ui;
};

#endif // CREATEBLOCKDIALOG_H
