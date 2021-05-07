#include "io.h"

IO::IO(QGraphicsItem *parent) :
    QGraphicsTextItem(parent)
{

}

void IO::build(QString name, QString type)
{
    this->name = name;
    this->ioType = type;

//    QFont font;
//    font.setFamily("Open Sans");
//    font.setPointSize(12);
//    font.setBold(true);

//    if (ioType == "input") this->plainText = "IN:" + name;
//    else this->plainText = "OUT:" + name;

//    auto fm = QFontMetrics(font);
//    this->width = fm.horizontalAdvance(this->plainText);
}

QRectF IO::boundingRect() const
{
    return QRectF(-gridSquare, (-gridSquare)/2, 3 * gridSquare, gridSquare);
}

void IO::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setPen(Qt::black);
//    painter->drawRect(boundingRect());
//    QRectF rec = QRectF( - gridSquare,- gridSquare/2, 3 * gridSquare, gridSquare);
//    painter->setPen(QPen(Qt::black, penWidth));
//    painter->drawRect(rec);
//    // input, output points
    painter->setPen(QPen(Qt::green, pointsSize));
    painter->drawPoint(0,0);

//    painter->setPen(Qt::black);
//    if (ioType == "input") painter->drawText(QPointF(-width - 10, 5), plainText);
//    else painter->drawText(QPointF(width, 5), plainText);

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
