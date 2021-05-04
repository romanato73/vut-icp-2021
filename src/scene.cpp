#include "scene.h"

#include "block.h"
#include "storage.h"
#include "line.h"

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
    if (this->mode == "create") {
        CreateBlockDialog dialog;
        dialog.loadCategories(Storage::getCategoriesList());

        if (dialog.exec() == QDialog::Accepted) {


        }
        block = new Block();
        // if even then pos.y = centre of square in grid
        auto x = round(mouseEvent->scenePos().x() / 20) * 20 + 10;
        auto y = round(mouseEvent->scenePos().y() / 20) * 20 + 10;
        // else pos.y = side of square in grid

        auto pos = QPointF(x, y);

        block->setPos(pos);
        addItem(block);
        qDebug() << "block created";
    } else if (this->mode == "edit") {

        if(mouseEvent->button() == Qt::RightButton){
            line = new Line;
            auto x = round(mouseEvent->scenePos().x() / 20) * 20;
            auto y = round(mouseEvent->scenePos().y() / 20) * 20;
            auto pos = QPointF(x, y);

            line->setLine(QLineF(pos, pos));
            points.append(QPointF(pos));
            addItem(line);
            qDebug() << "line created";
        }
    } else if (this->mode == "delete") {
        for(auto* item : items(mouseEvent->scenePos())){
            if(auto line = dynamic_cast<QGraphicsLineItem*>(item); line != nullptr){
                qDebug() << "Line";
            }else if(auto text = dynamic_cast<QGraphicsTextItem*>(item); text != nullptr){
                qDebug() << "Text";
            }else if(auto block = dynamic_cast<QGraphicsItem*>(item); block != nullptr){
                qDebug() << "Block";
            }else{
                qDebug() << "????";
            }
        }
    }
    QGraphicsScene::mousePressEvent(mouseEvent);
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(line){
        auto p = mouseEvent->scenePos();
        QPointF point;
        auto tmpX = abs(p.x() - line->line().p1().x());
        auto tmpY = abs(p.y() - line->line().p1().y());
        auto pp1 = round(p.x() / 20) * 20;
        auto pp2 = round(p.y() / 20) * 20;
        if(tmpX >= tmpY){
            point = QPoint(pp1, line->line().p1().y());
        }else{
            point = QPoint(line->line().p1().x(), pp2);
        }
        line->setLine(QLineF(line->line().p1(), point));
        qDebug() << "line:screen mouse move";
    }
    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if(line){
        auto p = mouseEvent->scenePos();
        QPointF point;
        auto tmpX = abs(p.x() - line->line().p1().x());
        auto tmpY = abs(p.y() - line->line().p1().y());
        auto pp1 = round(p.x() / 20) * 20;
        auto pp2 = round(p.y() / 20) * 20;
        if(tmpX >= tmpY){
            point = QPoint(pp1, line->line().p1().y());
        }else{
            point = QPoint(line->line().p1().x(), pp2);
        }
        line->setLine(QLineF(line->line().p1(), point));
        points.append(point);
        line = nullptr;
        qDebug() << "line:screen mouse release";
    }
    QGraphicsScene::mouseMoveEvent(mouseEvent);
}
