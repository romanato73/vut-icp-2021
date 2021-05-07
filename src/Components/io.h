#ifndef IO_H
#define IO_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPen>
#include <QGraphicsTextItem>
#include <QDebug>

class IO : public QGraphicsTextItem
{
public:
    IO(QGraphicsItem  *parent = nullptr);

    /**
     * @brief name Name of the io
     */
    QString name;

    /**
     * @brief ioType IO type (input, output, constant)
     */
    QString ioType;

    /**
     * @brief plainText Text to be added into scene
     */
    QString plainText;

    /**
     * @brief build Builds IO
     * @param name Name of the IO
     * @param type Type of the IO
     */
    void build(QString name, QString type);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    qreal penWidth = 4;
    int gridSquare = 20;
    int pointsSize = 8;
};

#endif // IO_H
