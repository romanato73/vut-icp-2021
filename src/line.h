#ifndef LINE_H
#define LINE_H

#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QtDebug>
#include <QPainter>

class Line : public QGraphicsLineItem
{
public:
    Line();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

private:

};

#endif // LINE_H
