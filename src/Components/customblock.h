#ifndef CUSTOMBLOCK_H
#define CUSTOMBLOCK_H

#include <QGraphicsItem>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>
#include <QVariant>
#include <QGraphicsSceneMouseEvent>

class CustomBlock : public QGraphicsItem
{
public:
    explicit CustomBlock(QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const override
    {
        qreal penWidth = 1;
        return QRectF(-20 - penWidth / 2, -20 - penWidth / 2,
                      20 + penWidth, 20 + penWidth);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override
    {
        painter->drawRect(-20, -20, 20, 20);
    }

protected:
//    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;

    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // CUSTOMBLOCK_H
