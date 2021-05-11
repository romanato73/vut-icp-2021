#include "io.h"

IO::IO(QGraphicsItem *parent)
{
    if(parent){}
    setFlags(ItemIsMovable | ItemSendsGeometryChanges);
}

void IO::build(QString name, QString valType, QString type)
{
    this->name = name;
    this->ioValType = valType;
    this->ioType = type;

    QFont font;
    font.setFamily("Open Sans");
    font.setPointSize(12);
    font.setBold(true);

    if (ioType == "input") plainText = ioValType + ": " + name;
    else if (ioType == "output") plainText = name;

    auto fm = QFontMetrics(font);
    this->width = fm.width(this->plainText);
}

QRectF IO::boundingRect() const
{
    int lettersPerGrid = floor(width/gridSize);

    if (ioType == "input") return QRectF(-(pointsSize/2 + gridSize * (lettersPerGrid + 1) + spacer),
                                         -gridSize,
                                         pointsSize + gridSize * (lettersPerGrid + 1) + spacer,
                                         gridSize * 2);
    else if (ioType == "output") return QRectF(-pointsSize/2,
                                               -gridSize,
                                               pointsSize + gridSize * (lettersPerGrid + 1) + spacer,
                                               gridSize * 2);
    else return QRectF(0, 0, 0, 0);
}

void IO::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(option){}
    if(widget){}
    coordinates = QPoint(0, 0);

    if (ioType == "input") {
        painter->setPen(QPen(Qt::green, pointsSize));
        painter->drawPoint(coordinates);
        painter->setPen(Qt::black);
        painter->drawText(-boundingRect().width() + spacer, 5, plainText);
    } else if (ioType == "output") {
        painter->setPen(QPen(Qt::green, pointsSize));
        painter->drawPoint(coordinates);
        painter->setPen(Qt::black);
        painter->drawText(spacer, 5, plainText);
    }
}

void IO::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    offset = pos() - computeTopLeftGridPoint(pos());
    QGraphicsItem::mousePressEvent(mouseEvent);
}

QVariant IO::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionChange && scene()) {
        QPointF newPos = value.toPointF();
        if(QApplication::mouseButtons() == Qt::LeftButton) {
            QPointF closestPoint = computeTopLeftGridPoint(newPos);
            return  closestPoint += offset;
        } else {
            return newPos;
        }
    } else {
        return QGraphicsItem::itemChange(change, value);
    }
}

QPointF IO::computeTopLeftGridPoint(const QPointF &pointP)
{
    int gridSize = 20;
    qreal xV = floor(pointP.x()/gridSize)*gridSize;
    qreal yV = floor(pointP.y()/gridSize)*gridSize;
    return QPointF(xV, yV);
}
