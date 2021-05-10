/**
 * Editor and interpret of the hierarchically structured function blocks
 * Faculty of Information Technology, Brno University of Technology
 *
 * @author Roman Országh <xorsza01@stud.fit.vutbr.cz>
 * @author Albert Groma <xgroma00@stud.fit.vutbr.cz>
 */

#ifndef LINE_H
#define LINE_H

#include <QGraphicsLineItem>
#include <QGraphicsSceneMouseEvent>
#include <QPen>
#include <QtDebug>
#include <QPainter>
#include <QtMath>
#include <QApplication>

/**
 * @brief The Line class
 */
class Line : public QGraphicsLineItem
{
public:

    /**
     * @brief Line
     * @param parent
     */
    Line(QGraphicsItem  *parent = nullptr);

    /**
     * @brief mapped Sets if the line has been mapped or not
     */
    bool mapped = false;

    /**
     * @brief paint Paints the line
     * @param painter
     * @param option
     * @param widget
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    /**
     * @brief mousePressEvent Handles the mouse press event
     * @param mouseEvent      Mouse event
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);

    /**
     * @brief itemChange Handles the item change event
     * @param change
     * @param value
     * @return
     */
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

private:
    /**
     * @brief offset Sets the offset
     */
    QPointF offset;

    /**
     * @brief computeTopLeftGridPoint Computes the top left grid point
     * @param pointP                  Given point
     * @return                        Point that is calculated to the top left grid point
     */
    QPointF computeTopLeftGridPoint(const QPointF &pointP);
};

#endif // LINE_H
