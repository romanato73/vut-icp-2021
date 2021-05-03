#include "block.h"

Block::Block()
{
    Pressed = false;
    build("ADD",QStringList{"a1","a2"},QStringList{"a","b","c"},"code");
    setFlags(ItemIsSelectable | ItemIsMovable | ItemSendsGeometryChanges);
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
    return QRectF(- blkWidth/2 + penWidth,-(blkHeight + addBlkHeight * max)/2 + penWidth,
                  blkWidth - 2 * penWidth, blkHeight + addBlkHeight * max - 2 * penWidth);

}

QLine Block::boundBlockInLines( int i)
{
    int max = std::max(inputs.count(), outputs.count()); 
    if(max % 2 == 0){
        int y = gridSquare/2 * i - gridSquare/2 * (max-1);
        points.append(QPointF( - blkWidth/2 - gridSquare, y));
        return QLine( - blkWidth/2 - gridSquare, y, - blkWidth/2, y);
    }else{
        int y = gridSquare * i - gridSquare/2 * max;
        points.append(QPointF( - blkWidth/2 - gridSquare, y));
        return QLine( - blkWidth/2 - gridSquare, y, - blkWidth/2, y);
    }
}

QLine Block::boundBlockOutLines(int i)
{
    int max = std::max(inputs.count(), outputs.count());
    if(max % 2 == 0){
        int y = 10 * i - gridSquare/2 * (max-1);
        points.append(QPointF(  blkWidth/2 + gridSquare, y));
        return QLine( blkWidth/2 + gridSquare, y, blkWidth/2, y);
    }else{
        int y = 20 * i - 10 * max;
        points.append(QPointF(  blkWidth/2 + gridSquare, y));
        return QLine( blkWidth/2 + gridSquare, y, blkWidth/2, y);
    }
}

void Block::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rec = boundingRect();
    QBrush brush(Qt::white);

//    if(Pressed){
//        brush.setColor(Qt::red);
//    }else{
//        brush.setColor(Qt::green);
//    }
    painter->fillRect(rec, brush);
    painter->setPen(QPen(Qt::black, penWidth));
    painter->drawRect(rec);


    QStringList inputs = QStringList{"a","a"};
    QStringList outputs = QStringList{"a","a"};

    for(int i = 0; i < inputs.count(); i++){
        painter->drawLine(boundBlockInLines(i));
    }
    for(int i = 0; i < outputs.count(); i++){
        painter->drawLine(boundBlockOutLines(i));
    }

    painter->setPen(QPen(Qt::green, 8));
    painter->drawPoints(points.data(), points.size());
}

void Block::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    Pressed = true;
    update();
    QGraphicsItem::mousePressEvent(mouseEvent);
}

void Block::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{

}
