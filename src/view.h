#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QScrollBar>
#include <QObject>



class View : public QGraphicsView
{
public:
    View();

private:
    /**
     * @see https://stackoverflow.com/questions/4753681/how-to-pan-images-in-qgraphicsview
     */

    /**
     * @brief mousePressEvent
     * @param event
     */
    void mousePressEvent(QMouseEvent *event) override;

    /**
     * @brief mouseReleaseEvent
     * @param event
     */
    void mouseReleaseEvent(QMouseEvent *event) override;

    /**
     * @brief mouseMoveEvent
     * @param event
     */
    void mouseMoveEvent(QMouseEvent *event) override;

    /**
     * @brief dragging Sets dragging flag
     */
    bool dragging = false;

    /**
     * @brief startX, startY Sets the X and Y position of View
     */
    int startX, startY;
};

#endif // VIEW_H
