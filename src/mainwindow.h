#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "storage.h"
#include "scene.h"

#include <QDir>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    /**
     * @brief Initialize scene and buttons
     */
    void Initialize();

private slots:
    void on_addCategory_clicked();

    /**
     * Modes
     */
    void on_selectMode_clicked();
    void on_createMode_clicked();
    void on_editMode_clicked();
    void on_deleteMode_clicked();

    /**
     * @brief categoryEditBtn Handles the category edit buttons
     */
    void categoryEditBtnClick();

    /**
     * @brief categoryDeleteBtnClick Handles the category delete button
     */
    void categoryDeleteBtnClick();

private:
    /**
     * @brief ui The main UI
     */
    Ui::MainWindow *ui;

    /**
     * @brief scene The main scene for render
     */
    Scene *scene = new Scene();

    /**
     * @brief mode Sets the current application mode
     */
    QString mode;

    /**
     * @brief getCategories Gets all created categories
     * @param base If true gets also base categories
     * @return List of categories
     */
    QStringList getCategories(bool base = false);

    /**
     * @brief createNewCategory Creates a new category
     * @param name Name of category
     */
    void createNewCategory(QString name);

    /**
     * @brief removecategory    Removes the category from the UI
     * @param name              Name of the category
     */
    void removeCategory(QString name);

    /**
     * @brief updateCategoryName Updates the category name in UI
     * @param name               Old name of the category
     * @param newName            New name of the category
     */
    void updateCategoryName(QString name, QString newName);

    /**
     * @brief setButtonActive Sets the clicked button to active
     * @param name Name of button
     */
    void setButtonActive(QString mode);
};
#endif // MAINWINDOW_H
