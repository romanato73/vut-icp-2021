#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QDebug>
#include <block.h>
#include <QGraphicsItem>
#include <QPointF>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QRectF>
#include <QObject>

#include <QMouseEvent>
#include <math.h>

class Scene : public QGraphicsScene
{
    Q_OBJECT;
public:
    explicit Scene(QObject *parent = 0);
    int getGridSize() const {return this->gridSize;}

    /**
     * @brief mode Determines the current mode
     */
    QString mode = "select";

    /**
     * @brief rectangles List of rectangles in scene
     */
    QList<QGraphicsItem *> rectangles;

    /**
     * @brief lines List of lines in scene
     */
    QList<QGraphicsItem *> lines;

    /**
     * @brief texts List of texts in scene
     */
    QList<QGraphicsItem *> texts;

    /**
     * @brief blocks List of blocks in scene
     */
    QList<Block *> blocks;

    /**
     * @brief setMode Sets current mode
     * @param mode    The mode to be set
     */
    void setMode(QString mode);

protected:
    /**
     * @brief drawBackground    Draws grid background
     * @param painter
     * @param rect
     *
     * @see https://www.walletfox.com/course/qgraphicsitemsnaptogrid.php
     */
    void drawBackground(QPainter *painter, const QRectF &rect);

    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

//    void mousePressEvent(QMouseEvent *event);

//    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);

private:
    QGraphicsItem *block{nullptr};
    QGraphicsLineItem *line{nullptr};
    const int gridSize;

    bool dragging = false;

};

#endif // SCENE_H
