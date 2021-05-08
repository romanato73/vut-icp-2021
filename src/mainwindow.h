#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "storage.h"
#include "scene.h"
#include "view.h"

#include <QDir>
#include <QFile>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QPushButton>
#include <QChar>
#include <QFontDatabase>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QSignalMapper>

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

public slots:
    void updateGUI(QString category);

    /**
     * @brief addBlockToScene Handles the block and add it into scene
     */
    void categoryBlockClick();

private slots:
    void on_addCategory_clicked();

    /**
     * Handles all the modes
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

    void on_Square_clicked();

    void on_Text_clicked();

    void on_AND_clicked();

    void on_NOT_clicked();

    void on_OR_clicked();

    void on_XOR_clicked();

    void on_buildProgram_clicked();

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
     * @brief view Program view
     */
    View *view = new View();

    /**
     * @brief storage Application storage
     */
    Storage *storage = new Storage();

    /**
     * @brief mapper Signal ampper
     */
    QSignalMapper *mapper;

    /**
     * @brief mode Sets the current application mode
     */
    QString mode;

    /**
     * @brief setMode Sets the mode
     * @param value   Sets the mode to value
     */
    void setMode(const QString &value);

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
    void createCategory(QString name, QJsonArray blocks = QJsonArray());

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
     * @brief createCategoryBlock   Creates button inside category
     * @param name                  Name of the block
     */
    void createCategoryBlock(QString category, QString name);

    /**
     * @brief setButtonActive Sets the clicked button to active
     * @param name Name of button
     */
    void setButtonActive(QString mode);

    /**
     * @brief createModeButtons Create mode buttons (block, line, input, output, const)
     */
    QVector<QPushButton *> createModeButtons;

    /**
     * @brief createModeButtons Draws mode buttons into UI
     * @param set               If true sets the UI otherwise delete UI
     */
    void buildCreateModeButtons();

    /**
     * @brief setCreateModeButtons  Sets the visibility for create mode buttons (block, line, input, output, const)
     * @param visible               If true buttons are visible otherwise false
     */
    void setCreateModeButtons(bool visible);

    /**
     * @brief createModeSwitch Switches the current create mode (block, line, input, output, const)
     */
    void switchCreateModeButtons();
};
#endif // MAINWINDOW_H
