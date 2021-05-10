/**
 * Editor and interpret of the hierarchically structured function blocks
 * Faculty of Information Technology, Brno University of Technology
 *
 * @author Roman Országh <xorsza01@stud.fit.vutbr.cz>
 * @author Albert Groma <xgroma00@stud.fit.vutbr.cz>
 */

#ifndef EDITBLOCKDIALOG_H
#define EDITBLOCKDIALOG_H

#include <QDialog>

#include <Components/block.h>

namespace Ui {
class EditBlockDialog;
}

/**
 * @brief The EditBlockDialog class
 */
class EditBlockDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditBlockDialog(QWidget *parent = nullptr);
    ~EditBlockDialog();

    /**
     * @brief block Block instance
     */
    Block *block;

    /**
     * @brief initializeForm Initializes the form with the block data
     * @param origin         Pointer to the origin block
     */
    void initializeForm(Block *origin);

private slots:
    /**
     * @brief on_editBlock_clicked Edit block button handler
     */
    void on_editBlock_clicked();

private:
    /**
     * @brief ui
     */
    Ui::EditBlockDialog *ui;

    /**
     * @brief inputsForm Value of the inputs in string
     */
    QString inputsForm = "";

    /**
     * @brief outputsForm Value of the outputs in string
     */
    QString outputsForm = "";
};

#endif // EDITBLOCKDIALOG_H
