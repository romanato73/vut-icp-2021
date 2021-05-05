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
    if(numOfPorts() % 2 == 0){
        int y = gridSquare * i - gridSquare/2 * (numOfPorts()-1);
        points.append(QPointF( - width/2 - gridSquare, y));
        return QLine( - width/2 - gridSquare, y, - width/2, y);
    }else{
        int y = gridSquare * i - gridSquare/2 * numOfPorts();
        points.append(QPointF( - width/2 - gridSquare, y));
        return QLine( - width/2 - gridSquare, y, - width/2, y);
    }
}

QLine Block::boundBlockOutLines(int i)
{
    if(numOfPorts() % 2 == 0){
        int y = gridSquare * i - gridSquare/2 * (numOfPorts()-1);
        points.append(QPointF(  width/2 + gridSquare, y));
        return QLine( width/2 + gridSquare, y, width/2, y);
    }else{
        int y = gridSquare * i - gridSquare/2 * numOfPorts();
        points.append(QPointF(  width/2 + gridSquare, y));
        return QLine( width/2 + gridSquare, y, width/2, y);
    }
}

int Block::numOfPorts()
{
    return std::max(inputs.count(), outputs.count());
}

void Block::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundRect();
    QBrush brush(Qt::white);

//    if(Pressed){
//        brush.setColor(Qt::red);
//    }else{
//        brush.setColor(Qt::green);
//    }
    painter->fillRect(rec, brush);
    painter->setPen(QPen(Qt::black, penWidth));
    painter->drawRect(rec);

    for(int i = 0; i < inputs.count(); i++){
        painter->drawLine(boundBlockInLines(i));
    }
    for(int i = 0; i < outputs.count(); i++){
        painter->drawLine(boundBlockOutLines(i));
    }

    painter->setPen(QPen(Qt::green, pointsSize));
    painter->drawPoints(points.data(), points.size());

    QFont font = QFont ("Courier");
    painter->setPen(QPen(Qt::green, 20));
    painter->drawText(-width/2, -height/2-addHeight*(numOfPorts()-1)/2- topText, width, addHeight, Qt::AlignHCenter, name);
    font.setStyleHint (QFont::Monospace);
    painter->setPen("black");
    font.setBold(false);
    font.setPointSize (7);
    painter->setFont(font);

    int ii = 0;
    while( ii < inputs.count()){
        painter->drawText( -width/2 + gridSquare/2, points.data()[ii].y(), inputs[ii]);
        ii++;
    }
    while(ii-inputs.count() < outputs.count()){
        painter->drawText( gridSquare/2, points.data()[ii].y(), outputs[ii-inputs.count()]);
        ii++;
    }
}

void Block::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    offset = pos() - computeTopLeftGridPoint(pos());
    QGraphicsItem::mousePressEvent(mouseEvent);
    qDebug() << "inside";
}

QVariant Block::itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value)
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

QPointF Block::computeTopLeftGridPoint(const QPointF &pointP)
{
    Scene* customScene = qobject_cast<Scene*> (scene());
    int gridSize = customScene->getGridSize();
    qreal xV = floor(pointP.x()/gridSize)*gridSize;
    qreal yV = floor(pointP.y()/gridSize)*gridSize;
    return QPointF(xV, yV);
}
