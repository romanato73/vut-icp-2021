#include "scene.h"

#include "block.h"
#include "storage.h"

#include <Dialogs/createblockdialog.h>
#include <QGraphicsSceneMouseEvent>

Scene::Scene(QObject *parent) : QGraphicsScene(parent), gridSize(20)
{
    Q_ASSERT(gridSize > 0);
}

void Scene::setMode(QString mode)
{
    this->mode = mode;
}

void Scene::drawBackground(QPainter *painter, const QRectF &rect)
{
    QPen pen;
    painter->setPen(pen);

    qreal left = int(rect.left()) - (int(rect.left()) % gridSize);
    qreal top = int(rect.top()) - (int(rect.top()) % gridSize);
    QVector<QPointF> points;
    for (qreal x = left; x < rect.right(); x += gridSize){
        for (qreal y = top; y < rect.bottom(); y += gridSize){
            points.append(QPointF(x,y));
        }
    }

    painter->drawPoints(points.data(), points.size());
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (this->mode == "create") {
        CreateBlockDialog dialog;
        dialog.loadCategories(Storage::getCategoriesList());

        if (dialog.exec() == QDialog::Accepted) {


            qDebug() << "block created";
        }
        block = new Block();

        bool even = true;
        // if even then pos.y = centre of square in grid
        auto x = floor(mouseEvent->scenePos().x() / 20) * 20 + 10;
        auto y = floor(mouseEvent->scenePos().y() / 20) * 20 + 10;
        // else pos.y = side of square in grid
        if(!even){
            y += 10;
        }

        auto pos = QPointF(x, y);
        qDebug() << pos;

        block->setPos(pos);
        addItem(block);
    }
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
//    auto x = round(mouseEvent->scenePos().x() / 20) * 20;
//    auto y = round(mouseEvent->scenePos().y() / 20) * 20;

//    auto pos = QPointF(x, y);

//    qDebug() << pos;

//    block->setPos(pos);
}

//void Scene::mousePressEvent(QMouseEvent *event)
//{
//    if (event->button() == Qt::LeftButton) {
//        dragging = true;
//        auto x = event->position().x();
//        auto y = event->position().y();
//        event->accept();
//        qDebug() << "pressed";
//        return;
//    }
//}

//void Scene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
//{
//    if (this->mode == "create") {
//        CreateBlockDialog dialog;
//        dialog.loadCategories(Storage::getCategoriesList());

//        if (dialog.exec() == QDialog::Accepted) {
////            auto block = new Block();

//            qDebug() << "block created";
//        }
//    }
//}
