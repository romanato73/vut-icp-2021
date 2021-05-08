#ifndef CREATEIODIALOG_H
#define CREATEIODIALOG_H

#include <QDialog>

namespace Ui {
class CreateIODialog;
}

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

    QString inType;

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

    void on_InTypeInt_clicked();

    void on_InTypeFloat_clicked();

    void on_InTypeBool_clicked();

    void on_InTypeString_clicked();

private:
    Ui::CreateIODialog *ui;

    /**
     * @brief type Determines the type of the dialog (Input/Output)
     */
    QString type;
};

#endif // CREATEIODIALOG_H
