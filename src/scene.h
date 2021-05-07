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

#include <Components/block.h>
#include <Components/line.h>
#include "storage.h"

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
     * @brief storage Access to storage
     */
    Storage *storage = new Storage();

    /**
     * @brief mode Determines the current mode
     */
    QString mode = "select";

    /**
     * @brief createMode Determines the current create mode (block, line, input, output, const)
     */
    QString createMode;

    /**
     * @brief lines List of lines in scene
     */
    QVector<Line *> lines;

    /**
     * @brief blocks List of blocks in scene
     */
    QVector<Block *> blocks;

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

    /**
     * @brief buildProgram Builds the code from program
     */
    void buildProgram();

    /**
     * @brief followLine Helper function for building program that follows lines from inputs
     * @param point      Point that is used to find another lines
     */
    void followLine(QPointF point);

signals:
    /**
     * @brief onBlockCreate Send signal on block create
     * @param category      Category name of the block
     */
    void onBlockCreate(QString category);

protected:
    /**
     * @brief drawBackground    Draws grid background
     * @param painter
     * @param rect
     *
     * @see https://www.walletfox.com/course/qgraphicsitemsnaptogrid.php
     */
    void drawBackground(QPainter *painter, const QRectF &rect) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

private:
    /**
     * @brief line Line instance (for drawing)
     */
    Line *line = nullptr;

    /**
     * @brief lineStartPoint Line start point (for drawing)
     */
    QPointF lineStartPoint;

    /**
     * @brief gridSize Determines the grid size
     */
    const int gridSize;

};

#endif // SCENE_H
