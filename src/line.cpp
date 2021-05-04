#include "line.h"

Line::Line()
{
    setPen(QPen(Qt::black,6));
    setFlag(ItemIsMovable);
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(pen());
    painter->drawLine(line());
}

void Line::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    qDebug() << this << mouseEvent->pos() << mouseEvent->scenePos() << mouseEvent->screenPos();
    Line::mousePressEvent(mouseEvent);
}

void Line::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

}
