#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QGraphicsLineItem"
#include "QGraphicsEllipseItem"
#include "QGraphicsTextItem"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize graphics scene
    QGraphicsScene *scene = new QGraphicsScene(ui->editor);
    ui->editor->setScene(scene);

    auto line = scene->addLine(150,150,50,30);
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

