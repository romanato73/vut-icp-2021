/**
 * Editor and interpret of the hierarchically structured function blocks
 * Faculty of Information Technology, Brno University of Technology
 *
 * @author Roman Országh <xorsza01@stud.fit.vutbr.cz>
 * @author Albert Groma <xgroma00@stud.fit.vutbr.cz>
 */

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

/**
 * @brief The MainWindow class
 */
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
    /**
     * @brief updateGUI Slot for updating category in the GUI
     * @param category  The category to be updated
     */
    void updateGUI(QString category);

private slots:
    /**
     * @brief on_addCategory_clicked Handles the add category button
     */
    void on_addCategory_clicked();

    /**
     * @brief on_selectMode_clicked Handles the select mode button
     */
    void on_selectMode_clicked();

    /**
     * @brief on_createMode_clicked Handles the create mode button
     */
    void on_createMode_clicked();

    /**
     * @brief on_editMode_clicked Handles the edit mode button
     */
    void on_editMode_clicked();

    /**
     * @brief on_deleteMode_clicked Handles the delete mode button
     */
    void on_deleteMode_clicked();

    /**
     * @brief categoryEditBtn Handles the category edit buttons
     */
    void on_categoryEditBtnClick();

    /**
     * @brief categoryDeleteBtnClick Handles the category delete button
     */
    void on_categoryDeleteBtnClick();

    /**
     * @brief addBlockToScene Handles the block and add it into scene
     */
    void on_categoryBlockClick();

    /**
     * @brief on_Square_clicked Adds square to the scene
     */
    void on_Square_clicked();

    /**
     * @brief on_Text_clicked Adds the text to the scene
     */
    void on_Text_clicked();

    /**
     * @brief on_AND_clicked Adds the default ADD block to the scene
     */
    void on_AND_clicked();

    /**
     * @brief on_NOT_clicked Adds the default NOT block to the scene
     */
    void on_NOT_clicked();

    /**
     * @brief on_OR_clicked Adds the default OR block to the scene
     */
    void on_OR_clicked();

    /**
     * @brief on_XOR_clicked Adds the XOR block to the scene
     */
    void on_XOR_clicked();

    /**
     * @brief on_buildProgram_clicked Program builder button handler
     */
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
    QString mode = "select";

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

    /**
     * @brief on_defaultBlockClick Create default block to the scene
     * @param block                The clicked default block
     */
    void buildDefaultBlock(Block *block);
};
#endif // MAINWINDOW_H
