#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsItem>
#include <QPointF>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QRectF>
#include <QObject>

#include <QMouseEvent>
#include <QtMath>

class Scene : public QGraphicsScene
{
    Q_OBJECT;
public:
    explicit Scene(QObject *parent = 0);

    /**
     * @brief getGridSize   Gets the grid size.
     * @return              Returns the grid size
     */
    int getGridSize() const {return this->gridSize;}

    /**
     * @brief mode Determines the current mode
     */
    QString mode = "select";

    /**
     * @brief createMode Determines the current create mode (block, line, input, output, const)
     */
    QString createMode;

    /**
     * @brief lineDrawing Determines if we are currently drawing a line
     */
    bool lineDrawing = false;

//    /**
//     * @brief rectangles List of rectangles in scene
//     */
//    QList<QGraphicsItem *> rectangles;

//    /**
//     * @brief lines List of lines in scene
//     */
//    QList<QGraphicsItem *> lines;

//    /**
//     * @brief texts List of texts in scene
//     */
//    QList<QGraphicsItem *> texts;

//    /**
//     * @brief blocks List of blocks in scene
//     */
//    QList<Block *> blocks;

    /**
     * @brief setMode Sets current mode
     * @param mode    The mode to be set
     */
    void setMode(QString value);

    /**
     * @brief setCreateMode Sets current create mode
     * @param mode          The mode to be set
     */
    void setCreateMode(QString value);

protected:
    /**
     * @brief drawBackground    Draws grid background
     * @param painter
     * @param rect
     *
     * @see https://www.walletfox.com/course/qgraphicsitemsnaptogrid.php
     */
    void drawBackground(QPainter *painter, const QRectF &rect) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

//    void mousePressEvent(QMouseEvent *event);

//    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);

private:
//    QGraphicsItem *block{nullptr};
    QGraphicsLineItem *line{nullptr};
    QVector<QPointF> points;

    /**
     * @brief gridSize Determines the grid size
     */
    const int gridSize;

};

#endif // SCENE_H
