/**
 * Editor and interpret of the hierarchically structured function blocks
 * Faculty of Information Technology, Brno University of Technology
 *
 * @author Roman Országh <xorsza01@stud.fit.vutbr.cz>
 * @author Albert Groma <xgroma00@stud.fit.vutbr.cz>
 */

#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QScrollBar>
#include <QObject>


/**
 * @brief The View class
 */
class View : public QGraphicsView
{
public:
    View() {};

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
