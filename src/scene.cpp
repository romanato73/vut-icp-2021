#include "scene.h"

#include "block.h"
#include "storage.h"

#include <Dialogs/createblockdialog.h>

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

void Scene::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragging = true;
        auto x = event->position().x();
        auto y = event->position().y();
        event->accept();
        qDebug() << "pressed";
        return;
    }
}

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
