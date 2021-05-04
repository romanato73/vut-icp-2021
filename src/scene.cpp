#include "scene.h"

#include "block.h"
#include "storage.h"
//#include "line.h"

#include <Dialogs/createblockdialog.h>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

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
    qDebug() << "ffff";
    if (this->mode == "create") {
        CreateBlockDialog dialog;
        dialog.loadCategories(Storage::getCategoriesList());

        if (dialog.exec() == QDialog::Accepted) {


            qDebug() << "block created";
        }
        block = new Block();

        // if even then pos.y = centre of square in grid
        auto x = floor(mouseEvent->scenePos().x() / 20) * 20 + 10;
        auto y = floor(mouseEvent->scenePos().y() / 20) * 20 + 10;
        // else pos.y = side of square in grid

        auto pos = QPointF(x, y);
        qDebug() << pos;

        block->setPos(pos);
        addItem(block);
    } else if (this->mode == "edit") {
        // if even then pos.y = centre of square in grid
        auto x = floor(mouseEvent->scenePos().x() / 20) * 20;
        auto y = floor(mouseEvent->scenePos().y() / 20) * 20;

        auto pos = QPointF(x, y);
        qDebug() << pos;

//        line = new Line;
//        line->setLine(QLineF(mouseEvent->scenePos(), mouseEvent->scenePos()));
//        addItem(line);

        if(mouseEvent->button() == Qt::LeftButton){
            line = addLine(QLineF(mouseEvent->scenePos(), pos));
        }



        QGraphicsScene::mousePressEvent(mouseEvent);
    } else if (this->mode == "delete") {
        for(auto* item : items(mouseEvent->scenePos())){
            if(auto line = dynamic_cast<QGraphicsLineItem*>(item); line != nullptr){
                qDebug() << "Line";
            }else if(auto text = dynamic_cast<QGraphicsTextItem*>(item); text != nullptr){
                qDebug() << "Text";
            }else{
                qDebug() << "????";
            }
        }
    }
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    //line
    if(line){
        line->setLine(QLineF(line->line().p1(),mouseEvent->scenePos()));
    }


    //block
//    bool even = true;
//    // if even then pos.y = centre of square in grid
//    auto x = floor(mouseEvent->scenePos().x() / 20) * 20 + 10;
//    auto y = floor(mouseEvent->scenePos().y() / 20) * 20 + 10;
//    // else pos.y = side of square in grid
//    if(!even){
//        y -= 10;
//    }

//    auto pos = QPointF(x, y);
//    qDebug() << pos;

    //    block->setPos(pos);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    //line
    if(line){
        line->setLine(QLineF(line->line().p1(),mouseEvent->scenePos()));
        line = nullptr;
    }
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
