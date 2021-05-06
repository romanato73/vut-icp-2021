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

    /**
     * @brief setType Sets the dialog type (Input/Output)
     * @param type    The type of the dialog
     */
    void setType(QString type);

private slots:
    void on_create_clicked();

private:
    Ui::CreateIODialog *ui;

    /**
     * @brief type Determines the type of the dialog (Input/Output)
     */
    QString type;
};

#endif // CREATEIODIALOG_H
