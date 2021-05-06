#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsLineItem"
#include "QGraphicsEllipseItem"
#include "QGraphicsTextItem"
#include "Dialogs/createcategorydialog.h"
#include "Dialogs/createblockdialog.h"
#include "Dialogs/editcategorydialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Add fonts
    QFontDatabase::addApplicationFont(":/fonts/FontAwesome5.otf");
    QFontDatabase::addApplicationFont(":/fonts/OpenSans-Regular.ttf");
    QFontDatabase::addApplicationFont(":/fonts/OpenSans-Bold.ttf");

    // Initialize application
    Initialize();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Initialize()
{
    // Add graphics scene
    ui->editor->setScene(scene);

    // Build create mode buttons
    buildCreateModeButtons();

    // Build categories from storage
    auto categories = storage->getCategories();

    for (const QString &category : categories.keys()) {
        auto blocks = categories.value(category).toArray();

        // Build category
        createCategory(category, blocks);
    }
}

void MainWindow::on_addCategory_clicked()
{
    CreateCategoryDialog dialog;

    dialog.setCategories(getCategories(true));

    if (dialog.exec() == QDialog::Accepted) {
        // Add category to storage
        storage->addCategory(dialog.categoryName);
        // Add category to UI
        createCategory(dialog.categoryName);
    }
}

void MainWindow::on_selectMode_clicked()
{
    setMode("select");
}

void MainWindow::on_createMode_clicked()
{
    setMode("create");
}

void MainWindow::on_editMode_clicked()
{
    setMode("edit");
}

void MainWindow::on_deleteMode_clicked()
{
    setMode("delete");
}

void MainWindow::categoryEditBtnClick()
{
    auto btn = sender();
    QString category = btn->objectName().left(btn->objectName().length() - 12);

    EditCategoryDialog dialog;
    dialog.setCategories(getCategories(true));
    dialog.setCategoryName(category);
    if (dialog.exec() == QDialog::Accepted) {
        auto blocks = storage->getCategories().value(category).toArray();
        // Update category in storage
        storage->updateCategory(category, dialog.categoryName);
        // Remove category
        removeCategory(category);
        // Build new category

        createCategory(dialog.categoryName, blocks);

//        updateCategoryName(category, dialog.categoryName);
    }
}

void MainWindow::categoryDeleteBtnClick()
{
    auto btn = sender();

    QString category = btn->objectName().left(btn->objectName().length() - 14);

    // Remove category from storage
    storage->removeCategory(category);
    // Remove category from UI
    removeCategory(category);
}

void MainWindow::setMode(const QString &value)
{
    if (value == "create") {
        setCreateModeButtons(true);
    } else {
        setCreateModeButtons(false);
    }

    mode = value;
    scene->setMode(value);
    setButtonActive(value);
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

void MainWindow::createCategory(QString name, QJsonArray blocks)
{
    QFont fa, text;
    fa.setFamily("Font Awesome 5 Free");
    fa.setBold(true);
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
    header->layout()->setContentsMargins(0, 0, 0, 0);
    category->layout()->addWidget(header);

    // Set title
    auto title = new QLabel();
    title->setObjectName(name + "CategoryTitle");
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
    editBtn->setStyleSheet("background-color: none!important; border: none!important;");
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
    deleteBtn->setStyleSheet("background-color: none!important; border: none!important;");
    header->layout()->addWidget(deleteBtn);
    connect(deleteBtn, &QPushButton::clicked, this, &MainWindow::categoryDeleteBtnClick);

    // Create category items
    auto items = new QWidget();
    items->setObjectName(name + "CategoryItems");
    items->setLayout(new QGridLayout);
    category->layout()->addWidget(items);

    ui->Categories->layout()->addWidget(category);

    // Build category blocks
    for (auto block : blocks) {
        auto object = block.toObject();

        auto blockName = object.value("name").toString();

        createCategoryBlock(name, blockName);
    }
}

void MainWindow::removeCategory(QString name)
{
    QString nameCategory = name + "Category";

    for (auto item : ui->Categories->children()) {
        if (item->objectName() == nameCategory) {
            delete item;
        }
    }
}

void MainWindow::updateCategoryName(QString name, QString newName)
{
    auto nameCategory = name + "Category";

    for (auto item : ui->Categories->children()) {
        if (item->objectName() == nameCategory) {
            // Update label
            auto label = item->findChild<QLabel *>(nameCategory + "Title");
            label->setObjectName(newName + "CategoryTitle");
            label->setText(newName);

            // Update items
            auto items = item->findChild<QWidget *>(nameCategory + "Items");
            items->setObjectName(newName + "CategoryItems");

            // Update buttons
            auto editBtn = item->findChild<QPushButton *>(nameCategory + "Edit");
            editBtn->setObjectName(newName + "CategoryEdit");
            auto deleteBtn = item->findChild<QPushButton *>(nameCategory + "Delete");
            deleteBtn->setObjectName(newName + "CategoryDelete");

            // Update item object
            item->setObjectName(newName + "Category");
            break;
        }
    }
}

void MainWindow::createCategoryBlock(QString category, QString name)
{
    auto categoryItems = ui->Categories->findChild<QWidget *>(category + "CategoryItems");

    qDebug() << categoryItems->maximumSize();

    auto btn = new QPushButton(name);
    btn->setMinimumSize(80, 30);
    btn->setMaximumSize(80, 30);

    categoryItems->layout()->addWidget(btn);
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

void MainWindow::buildCreateModeButtons()
{
    QFont fa, text;
    fa.setFamily("Font Awesome 5 Free");
    fa.setBold(true);
    text.setFamily("Open Sans");

    if (ui->createModeButtons->layout() == nullptr) {
        ui->createModeButtons->setLayout(new QHBoxLayout());
    }

    auto layout = ui->createModeButtons->layout();

    // Create buttons
    auto block = new QPushButton("square");
    block->setObjectName("blockMode");
    block->setFont(fa);
    block->setMinimumSize(30, 30);
    block->setStyleSheet("border-color: #6A6FFF;");
    block->setVisible(false);

    auto connection = new QPushButton("slash");
    connection->setObjectName("connectionMode");
    connection->setFont(fa);
    connection->setMinimumSize(30, 30);
    connection->setVisible(false);

    auto input = new QPushButton("IN");
    input->setObjectName("inputMode");
    input->setFont(text);
    input->setMinimumSize(30, 30);
    input->setVisible(false);

    auto output = new QPushButton("OUT");
    output->setObjectName("outputMode");
    output->setFont(text);
    output->setMinimumSize(30, 30);
    output->setVisible(false);

    auto constant = new QPushButton("CONST");
    constant->setObjectName("constMode");
    constant->setFont(text);
    constant->setMinimumSize(30, 30);
    constant->setVisible(false);

    // Add to layout
    layout->addWidget(block);
    layout->addWidget(connection);
    layout->addWidget(input);
    layout->addWidget(output);
    layout->addWidget(constant);

    // Connect buttons to function
    connect(block, &QPushButton::clicked, this, &MainWindow::switchCreateModeButtons);
    connect(connection, &QPushButton::clicked, this, &MainWindow::switchCreateModeButtons);
    connect(input, &QPushButton::clicked, this, &MainWindow::switchCreateModeButtons);
    connect(output, &QPushButton::clicked, this, &MainWindow::switchCreateModeButtons);
    connect(constant, &QPushButton::clicked, this, &MainWindow::switchCreateModeButtons);

    // Add into vector
    createModeButtons.append({block, connection, input, output, constant});

    // Set the default create mode
    scene->setCreateMode("block");
}

void MainWindow::setCreateModeButtons(bool visible)
{
    if (visible) {
        // Set visibility to true
        for (auto btn : createModeButtons) {
            btn->setVisible(true);
        }
    } else {
        // Set visibility to false
        for (auto btn : createModeButtons) {
            btn->setVisible(false);
        }
    }
}

void MainWindow::switchCreateModeButtons()
{
    auto modeBtn = sender();

    // Set border color to active
    for (auto btn : createModeButtons) {
        if (btn->objectName() == modeBtn->objectName()) {
            btn->setStyleSheet("border-color: #6A6FFF;");
        } else {
            btn->setStyleSheet("border-color: transparent;");
        }
    }

    QString mode = modeBtn->objectName().left(modeBtn->objectName().length() - 4);

    scene->setCreateMode(mode);

    qDebug() << "Switched";
}

void MainWindow::on_Square_clicked()
{
    QGraphicsRectItem *rect = scene->addRect(0, 0, 40, 40, QPen(Qt::black, 5));
    /** @todo implement resizing */
    rect->setFlags(QGraphicsItem::ItemIsMovable);
}

void MainWindow::on_Line_clicked()
{
    QGraphicsLineItem *line = scene->addLine(scene->width()/2, scene->height()/2, 20, 0, QPen(Qt::black, 6));
    /** @todo implement resizing */
    line->setFlags(QGraphicsItem::ItemIsMovable);
}

void MainWindow::on_Text_clicked()
{    
    QGraphicsTextItem *text = scene->addText("Text");
    text->setPos(scene->width()/2, scene->height()/2);
    text->setFlags(QGraphicsItem::ItemIsMovable);
    text->setTextInteractionFlags(Qt::TextEditorInteraction);

}
