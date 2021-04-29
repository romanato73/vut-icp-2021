#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

    void on_selectMode_clicked();
    void on_createMode_clicked();
    void on_editMode_clicked();
    void on_deleteMode_clicked();

private:
    /**
     * @brief ui The main UI
     */
    Ui::MainWindow *ui;

    /**
     * @brief scene The main scene for render
     */
    QGraphicsScene *scene;

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
     * @brief setButtonActive Sets the clicked button to active
     * @param name Name of button
     */
    void setButtonActive(QString mode);
};
#endif // MAINWINDOW_H
