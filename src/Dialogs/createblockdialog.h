/**
 * Editor and interpret of the hierarchically structured function blocks
 * Faculty of Information Technology, Brno University of Technology
 *
 * @author Roman Országh <xorsza01@stud.fit.vutbr.cz>
 * @author Albert Groma <xgroma00@stud.fit.vutbr.cz>
 */

#ifndef CREATEBLOCKDIALOG_H
#define CREATEBLOCKDIALOG_H

#include <QDialog>

#include <Components/block.h>
#include "storage.h"

namespace Ui {
class CreateBlockDialog;
}

/**
 * @brief The CreateBlockDialog class
 */
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
     * @brief storage Set storage for checking block existence in storage
     */
    Storage *storage = new Storage();

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
    /**
     * @brief ui
     */
    Ui::CreateBlockDialog *ui;

    /**
     * @brief isValidIO Checks if io is valid
     * @return          True if valid otherwise false
     */
    bool isValidIO();
};

#endif // CREATEBLOCKDIALOG_H
