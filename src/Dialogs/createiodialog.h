/**
 * Editor and interpret of the hierarchically structured function blocks
 * Faculty of Information Technology, Brno University of Technology
 *
 * @author Roman Országh <xorsza01@stud.fit.vutbr.cz>
 * @author Albert Groma <xgroma00@stud.fit.vutbr.cz>
 */

#ifndef CREATEIODIALOG_H
#define CREATEIODIALOG_H

#include <QDialog>

namespace Ui {
class CreateIODialog;
}

/**
 * @brief The CreateIODialog class
 */
class CreateIODialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateIODialog(QWidget *parent = nullptr);
    ~CreateIODialog();

    /**
     * @brief name Name of the IO
     */
    QString name;

    /**
     * @brief ioType Type of IO
     */
    QString ioType = "";

    /**
     * @brief setType Sets the dialog type (Input/Output)
     * @param type    The type of the dialog
     */
    void setType(QString type);

private slots:
    /**
     * @brief on_create_clicked Creates the IO
     */
    void on_create_clicked();

    /**
     * @brief on_InTypeInt_clicked Sets the type to INT
     */
    void on_InTypeInt_clicked();

    /**
     * @brief on_InTypeFloat_clicked Sets the type to Float
     */
    void on_InTypeFloat_clicked();

    /**
     * @brief on_InTypeBool_clicked Sets the type to Bool
     */
    void on_InTypeBool_clicked();

    /**
     * @brief on_InTypeString_clicked Sets the type to String
     */
    void on_InTypeString_clicked();

private:
    /**
     * @brief ui
     */
    Ui::CreateIODialog *ui;

    /**
     * @brief type Determines the type of the dialog (Input/Output)
     */
    QString type;
};

#endif // CREATEIODIALOG_H
