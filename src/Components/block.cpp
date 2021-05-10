#include "block.h"

Block::Block(QGraphicsItem *parent) :
    QGraphicsItem(parent)
{
    setFlags(ItemIsMovable | ItemSendsGeometryChanges);
}

void Block::build(QString name, QStringList inputs, QStringList outputs, QString code)
{
    this->name = name;
    this->inputs = inputs;
    this->outputs = outputs;
    this->code = code;
}

QRectF Block::boundingRect() const
{
    int max = std::max(inputs.count(), outputs.count());
    int x = - width/2 + penWidth;
    int y = -(height + addHeight * (max-1))/2 - gridSquare/2 * (max % 2)+ penWidth;
    int w = width - 2 * penWidth;
    int h = height + addHeight * (max-1) - 2 * penWidth;
    return QRectF(x - pointsSize - gridSquare,y - topText,w + 2 * (pointsSize+gridSquare),h + topText);
}

QRectF Block::boundRect()
{
    int max = std::max(inputs.count(), outputs.count());
    return QRectF(- width/2 + penWidth,-(height + addHeight * (max-1))/2 - gridSquare/2 * (max % 2)+ penWidth,
                  width - 2 * penWidth, height + addHeight * (max-1) - 2 * penWidth);

}
QLine Block::boundBlockInLines(int i)
{
    int y = gridSquare * i - gridSquare/2 * (numOfPorts() - 1 + (numOfPorts() % 2));
    if(inPoints.size() > i){
        inPoints[i] = QPointF( - width/2 - gridSquare, y);
    } else {
        inPoints.append(QPointF( - width/2 - gridSquare, y));
        inNotConnected.append(i);
    }
    return QLine( - width/2 - gridSquare, y, - width/2, y);
}

QLine Block::boundBlockOutLines(int i)
{
    int y = gridSquare * i - gridSquare/2 * (numOfPorts() - 1 + (numOfPorts() % 2));
    if(outPoints.size() > i){
        outPoints[i] = QPointF(width/2 + gridSquare, y);
    } else {
        outPoints.append(QPointF(width/2 + gridSquare, y));
        outNotConnected.append(i);
    }
    return QLine( width/2 + gridSquare, y, width/2, y);
}

int Block::numOfPorts()
{
    return std::max(inputs.count(), outputs.count());
}

void Block::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundRect();
    QBrush brush(Qt::white);
    painter->fillRect(rec, brush);
    painter->setPen(QPen(Qt::black, penWidth));
    painter->drawRect(rec);

    // input, output lines
    for(int i = 0; i < inputs.count(); i++){
        painter->drawLine(boundBlockInLines(i));
    }

    for(int i = 0; i < outputs.count(); i++){
        painter->drawLine(boundBlockOutLines(i));
    }

    // input, output points
    painter->setPen(QPen(Qt::green, pointsSize));
    painter->drawPoints(inPoints.data(), inPoints.size());
    painter->drawPoints(outPoints.data(), outPoints.size());

    // name text and input, output text
    QFont font = QFont ("Courier");
    painter->setPen(QPen(Qt::green, 20));
    painter->drawText(-width/2,
                      -height/2-addHeight*(numOfPorts() - 1 + (numOfPorts() % 2))/2 - topText,
                      width, addHeight, Qt::AlignHCenter, name);
    font.setStyleHint (QFont::Monospace);
    painter->setPen("black");
    font.setBold(false);
    font.setPointSize (7);
    painter->setFont(font);

    for(int i = 0; i < inputs.count(); i++){
        painter->drawText( -width/2 + gridSquare/2, inPoints.data()[i].y(), inputs[i]);
    }

    for(int i = 0; i < outputs.count(); i++){
        painter->drawText( gridSquare/2, outPoints.data()[i].y(), outputs[i]);
    }
}

void Block::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    offset = pos() - computeTopLeftGridPoint(pos());
    QGraphicsItem::mousePressEvent(mouseEvent);
}

QVariant Block::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange && scene()) {
        QPointF newPos = value.toPointF();
        if(QApplication::mouseButtons() == Qt::LeftButton) {
            QPointF closestPoint = computeTopLeftGridPoint(newPos);
            return  closestPoint+=offset;
        } else {
            return newPos;
        }
    } else {
        return QGraphicsItem::itemChange(change, value);
    }
}

QPointF Block::computeTopLeftGridPoint(const QPointF &pointP)
{
    int gridSize = 20;
    qreal xV = floor(pointP.x()/gridSize)*gridSize;
    qreal yV = floor(pointP.y()/gridSize)*gridSize;
    return QPointF(xV, yV);
}
