//#include "customblock.h"

//#include <QApplication>
//#include <scene.h>

//CustomBlock::CustomBlock(QGraphicsItem *parent) : QGraphicsItem(parent)
//{
//    setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable | QGraphicsItem::ItemSendsGeometryChanges);
//}

//void CustomBlock::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
//{
//    prepareGeometryChange();

//    auto x = round(event->scenePos().x() / 20) * 20;
//    auto y = round(event->scenePos().y() / 20) * 20;

//    auto pos = QPointF(x, y);

//    qDebug() << pos;

//    this->setPos(pos);
//}

////QVariant CustomBlock::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
////{
////    if (change == ItemPositionChange && scene()) {
////        QPointF newPos = value.toPointF();
////        if(QApplication::mouseButtons() == Qt::LeftButton &&
////                qobject_cast<Scene*> (scene())){
////            Scene* customScene = qobject_cast<Scene *> (scene());
////            int gridSize = customScene->getGridSize();
////            qreal xV = round(newPos.x()/gridSize)*gridSize;
////            qreal yV = round(newPos.y()/gridSize)*gridSize;
////            qDebug() << "[" << xV << "," << yV << "]";
////            return QPointF(xV, yV);
////        } else {
////            return newPos;
////        }
////    } else {
////        qDebug() << "Here";
////        return QGraphicsItem::itemChange(change, value);
////    }
////}
