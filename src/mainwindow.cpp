#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsLineItem"
#include "QGraphicsEllipseItem"
#include "QGraphicsTextItem"
#include "Dialogs/createcategorydialog.h"
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
    ui->editor->setLayout(new QVBoxLayout);
    ui->editor->layout()->setContentsMargins(0, 0, 0, 0);

    ui->editor->layout()->addWidget(view);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    // Add graphics scene
    view->setScene(scene);

    // Add block created signal
    connect(view->scene(), SIGNAL(onBlockCreate(QString)), this, SLOT(updateGUI(QString)));

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

void MainWindow::updateGUI(QString category)
{
    auto blocks = (new Storage)->getCategories().value(category).toArray();

    // Remove category
    removeCategory(category);
    // Build new category
    createCategory(category, blocks);
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

void MainWindow::categoryBlockClick()
{
    if (mode == "edit") {
        // Edit block
        qDebug() << "Editing block";
    } else if (mode == "delete") {
        // Delete block
        qDebug() << "Deleting block";
    } else {
        // Place into scene
        auto category = sender()->objectName().left(sender()->objectName().size() - 4);
        auto btn = reinterpret_cast<QPushButton *>(sender());

        if (btn) {
            auto block = storage->getBlock(category, btn->text());

            auto center = view->mapToScene(view->viewport()->rect().center());
            auto x = round(center.x() / 20) * 20 + 10;
            auto y = round(center.y() / 20) * 20 + 10;

            block->setPos(x, y);
            scene->addItem(block);
        }
    }
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
    QFont text;
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
    editBtn->setIcon(QIcon(":/icons/edit_black.svg"));
    editBtn->setMinimumSize(20, 20);
    editBtn->setMaximumSize(20, 20);
    editBtn->setStyleSheet("background-color: none!important; border: none!important;");
    header->layout()->addWidget(editBtn);
    // Connect button
    connect(editBtn, &QPushButton::clicked, this, &MainWindow::categoryEditBtnClick);

    // Set delete button
    auto deleteBtn = new QPushButton();
    deleteBtn->setObjectName(name + "CategoryDelete");
    deleteBtn->setIcon(QIcon(":/icons/trash_black.svg"));
    deleteBtn->setMinimumSize(20, 20);
    deleteBtn->setMaximumSize(20, 20);
    deleteBtn->setStyleSheet("background-color: none!important; border: none!important;");
    header->layout()->addWidget(deleteBtn);
    connect(deleteBtn, &QPushButton::clicked, this, &MainWindow::categoryDeleteBtnClick);

    // Create category items
    auto items = new QWidget();
    items->setObjectName(name + "CategoryItems");
    items->setContentsMargins(0, 0, 0, 0);

    auto gridLayout = new QGridLayout;
    gridLayout->setContentsMargins(0, 0, 0, 0);
    gridLayout->setAlignment(Qt::AlignLeft);
    items->setLayout(gridLayout);

    // Build category blocks
    unsigned row = 0;
    unsigned col = 0;

    mapper = new QSignalMapper(this);

    for (auto block : blocks) {
        auto object = block.toObject();

        auto blockName = object.value("name").toString();
        qDebug() << blockName;

        auto btn = new QPushButton(blockName);
        btn->setObjectName(name + "Item");
        btn->setMinimumSize(60, 30);
        btn->setMaximumSize(60, 30);

        gridLayout->addWidget(btn, row, col);

        if (col != 0 && col % 3 == 0) {
            row++;
            col = 0;
        } else {
            col++;
        }

        connect(btn, &QPushButton::clicked, this, &MainWindow::categoryBlockClick);
    }

    category->layout()->addWidget(items);

    ui->Categories->layout()->addWidget(category);
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

void MainWindow::setButtonActive(QString mode)
{
    QString activeStyle = "background-color: #6A6FFF;color: #ffffff;";

    // Remove active status from other buttons
    ui->selectMode->setStyleSheet("");
    ui->selectMode->setChecked(false);

    ui->createMode->setStyleSheet("");
    ui->createMode->setChecked(false);

    ui->editMode->setStyleSheet("");
    ui->editMode->setChecked(false);

    ui->deleteMode->setStyleSheet("");
    ui->deleteMode->setChecked(false);

    // Update active status
    if (mode == "select") {
        ui->selectMode->setStyleSheet(activeStyle);
        ui->selectMode->setChecked(true);
    } else if (mode == "create") {
        ui->createMode->setStyleSheet(activeStyle);
        ui->createMode->setChecked(true);
    } else if (mode == "edit") {
        ui->editMode->setStyleSheet(activeStyle);
        ui->editMode->setChecked(true);
    } else if (mode == "delete") {
        ui->deleteMode->setStyleSheet(activeStyle);
        ui->deleteMode->setChecked(true);
    }
}

void MainWindow::buildCreateModeButtons()
{
    QFont text;
    text.setFamily("Open Sans");

    if (ui->createModeButtons->layout() == nullptr) {
        ui->createModeButtons->setLayout(new QHBoxLayout());
    }

    auto layout = ui->createModeButtons->layout();

    // Create buttons
    auto block = new QPushButton();
    block->setObjectName("blockMode");
    block->setIcon(QIcon(":icons/square.svg"));
    block->setMinimumSize(30, 30);
    block->setStyleSheet("border-color: #6A6FFF;");
    block->setVisible(false);

    auto connection = new QPushButton();
    connection->setObjectName("connectionMode");
    connection->setIcon(QIcon(":icons/slash.svg"));
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
}

void MainWindow::on_Square_clicked()
{
    QGraphicsRectItem *rect = scene->addRect(0, 0, 40, 40, QPen(Qt::black, 5));
    rect->setPos(view->mapToScene(view->viewport()->rect().center()));
    /** @todo implement resizing */
    rect->setFlags(QGraphicsItem::ItemIsMovable);
}

void MainWindow::on_Text_clicked()
{    
    QFont font;
    font.setFamily("Open Sans");
    font.setBold(true);
    font.setPointSize(12);
    QGraphicsTextItem *text = scene->addText("Text");
    text->setDefaultTextColor(Qt::black);
    text->setFont(font);
    text->setPos(view->mapToScene(view->viewport()->rect().center()));
    text->setFlags(QGraphicsItem::ItemIsMovable);
    text->setTextInteractionFlags(Qt::TextEditorInteraction);

}

void MainWindow::on_AND_clicked()
{
    auto block = new Block();
    block->build("AND", {"A", "B"}, {"Y"}, "int ADD(int A, int B) { return A & B }");

    auto center = view->mapToScene(view->viewport()->rect().center());
    auto x = round(center.x() / 20) * 20 + 10;
    auto y = round(center.y() / 20) * 20 + 10;

    block->setPos(QPointF(x, y));

    scene->addItem(block);
    scene->blocks.append(block);
}

void MainWindow::on_NOT_clicked()
{
    auto block = new Block();
    block->build("NOT", {"A"}, {"Y"}, "int NOT(int A) { return ~A }");

    auto center = view->mapToScene(view->viewport()->rect().center());
    auto x = round(center.x() / 20) * 20 + 10;
    auto y = round(center.y() / 20) * 20 + 10;

    block->setPos(QPointF(x, y));

    scene->addItem(block);
    scene->blocks.append(block);
}

void MainWindow::on_OR_clicked()
{
    auto block = new Block();
    block->build("OR", {"A", "B"}, {"Y"}, "int ADD(int A, int B) { return A | B }");

    auto center = view->mapToScene(view->viewport()->rect().center());
    auto x = round(center.x() / 20) * 20 + 10;
    auto y = round(center.y() / 20) * 20 + 10;

    block->setPos(QPointF(x, y));

    scene->addItem(block);
    scene->blocks.append(block);
}

void MainWindow::on_XOR_clicked()
{
    auto block = new Block();
    block->build("XOR", {"A", "B"}, {"Y"}, "int ADD(int A, int B) { return A ^ B }");

    auto center = view->mapToScene(view->viewport()->rect().center());
    auto x = round(center.x() / 20) * 20 + 10;
    auto y = round(center.y() / 20) * 20 + 10;

    block->setPos(QPointF(x, y));

    scene->addItem(block);
    scene->blocks.append(block);
}

void MainWindow::on_buildProgram_clicked()
{
    scene->buildProgram();
}

