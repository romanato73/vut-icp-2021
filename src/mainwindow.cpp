#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsLineItem"
#include "QGraphicsEllipseItem"
#include "QGraphicsTextItem"
#include "Dialogs/createcategorydialog.h"
#include "Dialogs/createblockdialog.h"

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize graphics scene
    Initialize();

    auto line = this->scene->addLine(150,150,50,30);
    line->setPen(QPen({Qt::red}, 3));
    line->setFlag(QGraphicsItem::ItemIsSelectable);
    line->setFlag(QGraphicsItem::ItemIsMovable);

    scene->addEllipse(150,150,50,30);

    auto text = scene->addText("Ahoj svet");
    text->setTextInteractionFlags(Qt::TextEditorInteraction);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Initialize()
{
    // Add graphics scene
    scene = new QGraphicsScene(ui->editor);
    ui->editor->setScene(scene);

    // Build categories from storage
    auto categories = storage->getCategories();

    for (const QString &category : categories.keys()) {
        auto items = categories.value(category);
        this->createNewCategory(category);
    }
}

void MainWindow::on_addCategory_clicked()
{
    CreateCategoryDialog dialog;
    dialog.setModal(true);
    dialog.setCategories(this->getCategories(true));
    if (dialog.exec() == QDialog::Accepted) {
        this->storage->addCategory(dialog.categoryName);
        this->createNewCategory(dialog.categoryName);
    }
}

void MainWindow::on_selectMode_clicked()
{
    this->mode = "select";
    this->setButtonActive(this->mode);
}

void MainWindow::on_createMode_clicked()
{
    this->mode = "create";
    this->setButtonActive(this->mode);

    CreateBlockDialog dialog;
    dialog.setModal(true);
    if (dialog.exec() == QDialog::Accepted) {

    }
}

void MainWindow::on_editMode_clicked()
{
    this->mode = "edit";
    this->setButtonActive(this->mode);
}

void MainWindow::on_deleteMode_clicked()
{
    this->mode = "delete";
    this->setButtonActive(this->mode);
}

QStringList MainWindow::getCategories(bool base)
{
    QStringList defaultCategories;

    if (base) {
        defaultCategories = {"CategoriesTitle", "verticalLayout_9"};
    } else {
        defaultCategories = {"DefaultCategory", "LogicalCategory", "CategoriesTitle", "verticalLayout_9"};
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
    header->layout()->addWidget(editBtn);

    // Set delete button
    auto deleteBtn = new QPushButton();
    deleteBtn->setObjectName(name + "CategoryDelete");
    deleteBtn->setFont(fa);
    deleteBtn->setText("trash");
    deleteBtn->setMinimumSize(20, 20);
    deleteBtn->setMaximumSize(20, 20);
    header->layout()->addWidget(deleteBtn);

    // Create category items
    auto items = new QWidget();
    items->setLayout(new QGridLayout);

    ui->Categories->layout()->addWidget(category);
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
