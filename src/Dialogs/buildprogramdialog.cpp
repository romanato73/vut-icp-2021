#include "buildprogramdialog.h"
#include "ui_buildprogramdialog.h"

#include <QFileDialog>
#include <QMessageBox>

BuildProgramDialog::BuildProgramDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BuildProgramDialog)
{
    ui->setupUi(this);
}

BuildProgramDialog::~BuildProgramDialog()
{
    delete ui;
}

void BuildProgramDialog::on_choosePath_clicked()
{
    QFileDialog dialog;

    dialog.setOption(QFileDialog::ShowDirsOnly, true);

    if (dialog.exec() == QFileDialog::Accepted) {
        QString dirPath = dialog.directory().path() + "/";
        if (ui->fileName->text().isEmpty()) {
            ui->path->setText(dirPath);
        } else {
            ui->path->setText(dirPath + ui->fileName->text() + ".txt");
        }

        path = dirPath;
    }
}


void BuildProgramDialog::on_fileName_textChanged(const QString &arg1)
{
    if (arg1.isEmpty()) {
        ui->path->setText(path);
    } else {
        ui->path->setText(path + arg1 + ".txt");
    }

}


void BuildProgramDialog::on_buildProgram_clicked()
{
    QMessageBox msg;

    if (ui->fileName->text().isEmpty() || path.isEmpty()) {
        msg.critical(nullptr, "Error", "File name or path can not be empty.");
    } else {
        filePath = ui->path->text();
        accept();
    }
}

