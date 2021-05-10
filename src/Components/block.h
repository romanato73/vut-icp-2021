/**
 * Editor and interpret of the hierarchically structured function blocks
 * Faculty of Information Technology, Brno University of Technology
 *
 * @author Roman Országh <xorsza01@stud.fit.vutbr.cz>
 * @author Albert Groma <xgroma00@stud.fit.vutbr.cz>
 */

#ifndef BLOCK_H
#define BLOCK_H

#include "io.h"

#include <QString>
#include <QStringList>
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>
#include <QPointF>
#include <QFont>
#include <QGraphicsSceneMouseEvent>
#include <QApplication>
#include <QtMath>


/**
 * @brief The Block class
 */
class Block : public QGraphicsItem
{
public:
    /**
     * @brief Block
     * @param parent
     */
    Block(QGraphicsItem *parent = nullptr);

    /**
     * @brief id ID of block when building a program
     */
    int id;

    /**
     * @brief name Name of the block
     */
    QString name;

    /**
     * @brief category Block category
     */
    QString category;

    /**
     * @brief inputs Names of the block inputs
     */
    QStringList inputs;

    /**
     * @brief outputs Names of the block outputs
     */
    QStringList outputs;

    /**
     * @brief code The code of the block
     */
    QString code;

    /**
     * @brief inPoints Exact position of the input points
     */
    QVector<QPointF> inPoints{};

    /**
     * @brief Not connected inputs
     */
    QVector<int> inNotConnected{};

    /**
     * @brief Exact position of the output points
     */
    QVector<QPointF> outPoints{};

    /**
     * @brief Not connected outputs
     */
    QVector<int> outNotConnected{};

    /**
     * @brief connectedBlocks Connected blocks to each input (index of vector is number of input)
     */
    QVector<Block *> connectedBlocks{};

    /**
     * @brief connectedBlocksOut Connected blocks to each input and their output index
     */
    QVector<int> connectedBlocksOut{};

    /**
     * @brief connectedInputs Connected inputs to this block
     */
    QVector<IO *> connectedInputs{};

    /**
     * @brief connectedOutputs Connected outputs to this block
     */
    QVector<IO *> connectedOutputs{};

    /**
     * @brief build     Builds a block
     * @param name      Name of block
     * @param inputs    Array of inputs
     * @param outputs   Array of outputs
     * @param code      Code
     */
    void build(QString name, QStringList inputs, QStringList outputs, QString code);

    /**
     * @brief boundingRect  Custom bounding rect function
     * @return              Coordinates of the bounding rectangle
     */
    QRectF boundingRect() const;

    /**
     * @brief boundRect Creates the bound rectangle
     * @return          Coordinates of the bound rectangle
     */
    QRectF boundRect();

    /**
     * @brief boundBlockInLines Gneerates the input lines
     * @param i                 Number of the input line
     * @return                  The generated line
     */
    QLine boundBlockInLines(int i);

    /**
     * @brief boundBlockOutLines    Generates the output lines
     * @param i                     Number of the output line
     * @return                      The generated line
     */
    QLine boundBlockOutLines(int i);

    /**
     * @brief numOfPorts    The number of the ports
     * @return              Number of ports of block
     */
    int numOfPorts();

    /**
     * @brief paint     Paints the block
     * @param painter
     * @param option
     * @param widget
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:

    /**
     * @brief mousePressEvent Handles the mouse press
     * @param mouseEvent      Mouse event
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);

    /**
     * @brief itemChange    Handles the item change event
     * @param change
     * @param value
     * @return
     */
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

private:
    /**
     * @brief penWidth Sets the width of the pen
     */
    qreal penWidth = 4;

    /**
     * @brief width Initial width of the block
     */
    int width = 100;

    /**
     * @brief height Initial height of the block
     */
    int height = 40;

    /**
     * @brief addHeight Added height to the block
     */
    int addHeight = 20;

    /**
     * @brief gridSquare Grid square size
     */
    int gridSquare = 20;

    /**
     * @brief pointsSize Size of the point at IO
     */
    int pointsSize = 8;

    /**
     * @brief topText Added padding from top of the text
     */
    int topText = 15;

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

#endif // BLOCK_H
