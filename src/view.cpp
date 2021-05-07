#include "view.h"

View::View()
{

}

void View::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        dragging = true;
        startX = event->x();
        startY = event->y();
        setCursor(Qt::ClosedHandCursor);
        event->accept();
        return;
    }

    event->ignore();

    QGraphicsView::mousePressEvent(event);
}

void View::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton) {
        dragging = false;
        setCursor(Qt::ArrowCursor);
        event->accept();
        return;
    }

    event->ignore();

    QGraphicsView::mouseReleaseEvent(event);
}

void View::mouseMoveEvent(QMouseEvent *event)
{
    if (dragging) {
        horizontalScrollBar()->setValue(horizontalScrollBar()->value() - (event->x() - startX));
        verticalScrollBar()->setValue(verticalScrollBar()->value() - (event->y() - startY));
        startX = event->x();
        startY = event->y();
        event->accept();
        return;
    }
    event->ignore();

    QGraphicsView::mouseMoveEvent(event);
}
