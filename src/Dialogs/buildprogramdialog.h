/**
 * Editor and interpret of the hierarchically structured function blocks
 * Faculty of Information Technology, Brno University of Technology
 *
 * @author Roman Országh <xorsza01@stud.fit.vutbr.cz>
 * @author Albert Groma <xgroma00@stud.fit.vutbr.cz>
 */


#ifndef BUILDPROGRAMDIALOG_H
#define BUILDPROGRAMDIALOG_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class BuildProgramDialog;
}

/**
 * @brief The BuildProgramDialog class
 */
class BuildProgramDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BuildProgramDialog(QWidget *parent = nullptr);
    ~BuildProgramDialog();

    /**
     * @brief filePath Path to the file
     */
    QString filePath;

private slots:
    /**
     * @brief on_choosePath_clicked Choose path handler
     */
    void on_choosePath_clicked();

    /**
     * @brief on_fileName_textChanged   Update path with fileName if file name changed
     * @param arg1                      The actual value of fileName
     */
    void on_fileName_textChanged(const QString &arg1);

    /**
     * @brief on_buildProgram_clicked Handles the dialog for building program.
     */
    void on_buildProgram_clicked();

private:
    /**
     * @brief ui
     */
    Ui::BuildProgramDialog *ui;

    /**
     * @brief path Current path for the file
     */
    QString path = "";
};

#endif // BUILDPROGRAMDIALOG_H
