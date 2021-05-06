#include "io.h"

IO::IO(QGraphicsItem *parent) :
    QGraphicsTextItem(parent)
{

}

QRectF IO::boundingRect() const
{
    return QRectF( - gridSquare,- gridSquare/2, 3 * gridSquare, gridSquare);
}

void IO::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    // box
    QRectF rec = QRectF( - gridSquare,- gridSquare/2, 3 * gridSquare, gridSquare);
    painter->setPen(QPen(Qt::black, penWidth));
    painter->drawRect(rec);
//    // input, output points
    painter->setPen(QPen(Qt::green, pointsSize));
    painter->drawPoint(0,0);
//    painter->drawPoints(inPoints.data(), inPoints.size());
//    painter->drawPoints(outPoints.data(), outPoints.size());
//    // name text and input, output text
//    QFont font = QFont ("Courier");
//    painter->setPen(QPen(Qt::green, 20));
//    painter->drawText(-width/2,
//                      -height/2-addHeight*(numOfPorts() - 1 + (numOfPorts() % 2))/2 - topText,
//                      width, addHeight, Qt::AlignHCenter, name);
//    font.setStyleHint (QFont::Monospace);
//    painter->setPen("black");
//    font.setBold(false);
//    font.setPointSize (7);
//    painter->setFont(font);
}
