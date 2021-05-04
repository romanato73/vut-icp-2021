#include "block.h"

Block::Block()
{
    Pressed = false;
    build("ADD",QStringList{"a1","a2","g3","g4","a5","a6","g7","gdh8","gg9","h10"},QStringList{"a1","b2","c3","gdh4","a5","a6","g7","gdh8"},"code");
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
    return QRectF(- blkWidth/2 + penWidth,-(blkHeight + addBlkHeight * (max-1))/2 - gridSquare/2 * (max % 2)+ penWidth,
                  blkWidth - 2 * penWidth, blkHeight + addBlkHeight * (max-1) - 2 * penWidth);

}

QLine Block::boundBlockInLines( int i)
{
    if(numOfPorts() % 2 == 0){
        int y = gridSquare * i - gridSquare/2 * (numOfPorts()-1);
        points.append(QPointF( - blkWidth/2 - gridSquare, y));
        return QLine( - blkWidth/2 - gridSquare, y, - blkWidth/2, y);
    }else{
        int y = gridSquare * i - gridSquare/2 * numOfPorts();
        points.append(QPointF( - blkWidth/2 - gridSquare, y));
        return QLine( - blkWidth/2 - gridSquare, y, - blkWidth/2, y);
    }
}

QLine Block::boundBlockOutLines(int i)
{
    if(numOfPorts() % 2 == 0){
        int y = gridSquare * i - gridSquare/2 * (numOfPorts()-1);
        points.append(QPointF(  blkWidth/2 + gridSquare, y));
        return QLine( blkWidth/2 + gridSquare, y, blkWidth/2, y);
    }else{
        int y = gridSquare * i - gridSquare/2 * numOfPorts();
        points.append(QPointF(  blkWidth/2 + gridSquare, y));
        return QLine( blkWidth/2 + gridSquare, y, blkWidth/2, y);
    }
}

int Block::numOfPorts()
{
    return std::max(inputs.count(), outputs.count());
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
    painter->drawText(-blkWidth/2, -blkHeight/2-addBlkHeight*(numOfPorts()-1)/2-15, blkWidth, addBlkHeight, Qt::AlignHCenter, name);
    font.setStyleHint (QFont::Monospace);
    painter->setPen("black");
    font.setBold(false);
    font.setPointSize (7);
    painter->setFont(font);

    int ii = 0;
    while( ii < inputs.count()){
        painter->drawText( -blkWidth/2 + gridSquare/2, points.data()[ii].y(), inputs[ii]);
        ii++;
    }
    while(ii-inputs.count() < outputs.count()){
        painter->drawText( gridSquare/2, points.data()[ii].y(), outputs[ii-inputs.count()]);
        ii++;
    }
//    painter->
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
