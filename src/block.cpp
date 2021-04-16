#include "block.h"

#include <QPainter>

Block::Block(QWidget *parent) : QWidget(parent)
{

}

void Block::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter p(this);
    p.drawRect(0, 0, 100, 200);
}
