#ifndef IO_H
#define IO_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPen>
#include <QGraphicsTextItem>

class IO : public QGraphicsTextItem
{
public:
    IO(QGraphicsItem  *parent = nullptr);

    QString name;
    QString ioType;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    qreal penWidth = 4;
    int gridSquare = 20;
    int pointsSize = 8;
};

#endif // IO_H
