#ifndef LINE_H
#define LINE_H

#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QtDebug>
#include <QPainter>
#include <QtMath>
#include <QApplication>


class Line : public QGraphicsLineItem
{
public:
    Line(QGraphicsItem  *parent = nullptr);

    /**
     * @brief mapped Sets if the line has been mapped or not
     */
    bool mapped = false;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

private:
    QPointF offset;
    QPointF computeTopLeftGridPoint(const QPointF &pointP);
};

#endif // LINE_H
