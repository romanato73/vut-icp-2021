#include "line.h"

Line::Line(QGraphicsItem *parent) :
    QGraphicsLineItem(parent)
{
    setPen(QPen(Qt::black,6));
    setFlags( ItemIsMovable | ItemSendsGeometryChanges);
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen());
    painter->drawLine(line());
    painter->setPen(QPen(Qt::green, 8));
    painter->drawPoint(line().p1());
    painter->drawPoint(line().p2());
    qDebug() << "line:paints line";
}

void Line::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    offset = pos() - computeTopLeftGridPoint(pos());
    QGraphicsLineItem::mousePressEvent(mouseEvent);
    qDebug() << "line: object press";
}

QVariant Line::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange && scene()) {
        QPointF newPos = value.toPointF();
        if(QApplication::mouseButtons() == Qt::LeftButton &&
            qobject_cast<Scene*> (scene())){
                QPointF closestPoint = computeTopLeftGridPoint(newPos);
                return  closestPoint+=offset;
            }
        else
            return newPos;
    }
    else
        return QGraphicsItem::itemChange(change, value);
}

QPointF Line::computeTopLeftGridPoint(const QPointF &pointP)
{
    Scene* customScene = qobject_cast<Scene*> (scene());
    int gridSize = customScene->getGridSize();
    qreal xV = floor(pointP.x()/gridSize)*gridSize;
    qreal yV = floor(pointP.y()/gridSize)*gridSize;
    return QPointF(xV, yV);
}

