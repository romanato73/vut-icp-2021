#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsLineItem"
#include "QGraphicsEllipseItem"
#include "QGraphicsTextItem"
#include "Dialogs/createcategorydialog.h"
#include "Dialogs/createblockdialog.h"
#include <Dialogs/editcategorydialog.h>

#include <QChar>
#include <QFile>
#include <QFontDatabase>
#include <QJsonDocument>
#include <QJsonObject>

#include <Components/customblock.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFontDatabase::addApplicationFont(":/fonts/FontAwesome5.otf");

    // Initialize application
    Initialize();

    auto line = this->scene->addLine(150,150,50,30);
    line->setPen(QPen({Qt::red}, 3));
    line->setFlag(QGraphicsItem::ItemIsSelectable);
    line->setFlag(QGraphicsItem::ItemIsMovable);

    scene->addEllipse(150,150,50,30);

    auto text = scene->addText("Ahoj svet");
    text->setTextInteractionFlags(Qt::TextEditorInteraction);

    this->scene->removeItem(text);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Initialize()
{
    // Add graphics scene
    ui->editor->setScene(scene);

    auto test = new CustomBlock();
    scene->addItem(test);

    // Build categories from storage
    auto categories = Storage::getCategories();

    for (const QString &category : categories.keys()) {
        auto items = categories.value(category);
        this->createNewCategory(category);

        // Build blocks
    }
}

void MainWindow::on_addCategory_clicked()
{
    CreateCategoryDialog dialog;
    dialog.setModal(true);
    dialog.setCategories(this->getCategories(true));
    if (dialog.exec() == QDialog::Accepted) {
        Storage::addCategory(dialog.categoryName);
        this->createNewCategory(dialog.categoryName);
    }
}

void MainWindow::on_selectMode_clicked()
{
    this->mode = "select";
    this->scene->setMode(this->mode);
    this->setButtonActive(this->mode);
}

void MainWindow::on_createMode_clicked()
{
    this->mode = "create";
    this->scene->setMode(this->mode);
    this->setButtonActive(this->mode);

//    CreateBlockDialog dialog;
//    dialog.setModal(true);
//    if (dialog.exec() == QDialog::Accepted) {

//    }
}

void MainWindow::on_editMode_clicked()
{
    this->mode = "edit";
    this->scene->setMode(this->mode);
    this->setButtonActive(this->mode);
}

void MainWindow::on_deleteMode_clicked()
{
    this->mode = "delete";
    this->scene->setMode(this->mode);
    this->setButtonActive(this->mode);
}

void MainWindow::categoryEditBtnClick()
{
    auto btn = sender();
    int editPos = btn->objectName().lastIndexOf(QChar('E'));
    auto categoryFullName = btn->objectName().left(editPos);
    int categoryPos = categoryFullName.lastIndexOf(QChar('C'));
    auto categoryName = categoryFullName.left(categoryPos);

    EditCategoryDialog dialog;
    dialog.setModal(true);
    dialog.setCategories(this->getCategories(true));
    dialog.setCategoryName(categoryName);
    if (dialog.exec() == QDialog::Accepted) {
        // Update category in storage
        Storage::updateCategory(categoryName, dialog.categoryName);
        // Update category in UI
        this->updateCategoryName(categoryFullName, dialog.categoryName);
    }
}

void MainWindow::categoryDeleteBtnClick()
{
    auto btn = sender();
    int deletePos = btn->objectName().lastIndexOf(QChar('D'));
    auto categoryFullName = btn->objectName().left(deletePos);
    int categoryPos = categoryFullName.lastIndexOf(QChar('C'));
    auto categoryName = categoryFullName.left(categoryPos);

    // Remove category from storage
    Storage::removeCategory(categoryName);
    // Remove category from UI
    this->removeCategory(categoryFullName);
}

QStringList MainWindow::getCategories(bool base)
{
    QStringList defaultCategories;

    if (base) {
        defaultCategories = QStringList{"CategoriesTitle", "verticalLayout_9"};
    } else {
        defaultCategories = QStringList{"DefaultCategory", "LogicalCategory", "CategoriesTitle", "verticalLayout_9"};
    }

    QStringList categories{};

    for (auto item : ui->Categories->children()) {
        if (defaultCategories.contains(item->objectName())) continue;

        categories.append(item->objectName());
    }

    return categories;
}

void MainWindow::createNewCategory(QString name)
{
    QFont fa, text;
    fa.setFamily("Font Awesome 5 Free");
    text.setFamily("Open Sans");
    text.setPointSize(10);
    text.setBold(true);

    // Create widget
    auto category = new QWidget(ui->Categories);
    category->setObjectName(name + "Category");
    category->setLayout(new QVBoxLayout);

    // Create header
    auto header = new QWidget(category);
    header->setObjectName(name + "CategoryHeader");
    header->setLayout(new QHBoxLayout);
    category->layout()->addWidget(header);

    // Set title
    auto title = new QLabel();
    title->setObjectName(name + "CategoryLabel");
    title->setFont(text);
    title->setText(name);
    header->layout()->addWidget(title);

    // Set edit button
    auto editBtn = new QPushButton();
    editBtn->setObjectName(name + "CategoryEdit");
    editBtn->setFont(fa);
    editBtn->setText("edit");
    editBtn->setMinimumSize(20, 20);
    editBtn->setMaximumSize(20, 20);
    editBtn->setStyleSheet("background-color: none;");
    header->layout()->addWidget(editBtn);
    // Connect button
    connect(editBtn, &QPushButton::clicked, this, &MainWindow::categoryEditBtnClick);

    // Set delete button
    auto deleteBtn = new QPushButton();
    deleteBtn->setObjectName(name + "CategoryDelete");
    deleteBtn->setFont(fa);
    deleteBtn->setText("trash");
    deleteBtn->setMinimumSize(20, 20);
    deleteBtn->setMaximumSize(20, 20);
    deleteBtn->setStyleSheet("background-color: none;");
    header->layout()->addWidget(deleteBtn);
    connect(deleteBtn, &QPushButton::clicked, this, &MainWindow::categoryDeleteBtnClick);

    // Create category items
    auto items = new QWidget();
    items->setLayout(new QGridLayout);

    ui->Categories->layout()->addWidget(category);
}

void MainWindow::removeCategory(QString name)
{
    for (auto item : ui->Categories->children()) {
        if (item->objectName() == name) {
            delete item;
        }
    }
}

void MainWindow::updateCategoryName(QString name, QString newName)
{
    for (auto item : ui->Categories->children()) {
        if (item->objectName() == name) {
            // Update label
            auto label = item->findChild<QLabel *>(name + "Label");
            label->setObjectName(newName + "CategoryLabel");
            label->setText(newName);

            // Update buttons
            auto editBtn = item->findChild<QPushButton *>(name + "Edit");
            editBtn->setObjectName(newName + "CategoryEdit");
            auto deleteBtn = item->findChild<QPushButton *>(name + "Delete");
            deleteBtn->setObjectName(newName + "CategoryDelete");

            // Update item object
            item->setObjectName(newName + "Category");
            break;
        }
    }
}

void MainWindow::setButtonActive(QString mode)
{
    QString activeStyle = "background-color: #6A6FFF;color: #ffffff;";

    // Remove active status from other buttons
    ui->selectMode->setStyleSheet("");
    ui->createMode->setStyleSheet("");
    ui->editMode->setStyleSheet("");
    ui->deleteMode->setStyleSheet("");

    // Update active status
    if (mode == "select") ui->selectMode->setStyleSheet(activeStyle);
    else if (mode == "create") ui->createMode->setStyleSheet(activeStyle);
    else if (mode == "edit") ui->editMode->setStyleSheet(activeStyle);
    else if (mode == "delete") ui->deleteMode->setStyleSheet(activeStyle);
}
