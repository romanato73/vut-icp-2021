#ifndef BLOCK_H
#define BLOCK_H

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
#include <scene.h>

class Block : public QGraphicsItem
{
public:
    Block(QGraphicsItem  *parent = nullptr);

    /**
     * @brief build     Builds a block
     * @param name      Name of block
     * @param inputs    Array of inputs
     * @param outputs   Array of outputs
     * @param code      Code
     */
    void build(QString name, QStringList inputs, QStringList outputs, QString code);

    QRectF boundingRect() const;
    QRectF boundRect();
    QLine boundBlockInLines( int i);
    QLine boundBlockOutLines( int i);
    int numOfPorts();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

private:
    QString name;
    QStringList inputs;
    QStringList outputs;
    QString code;

    QVector<QPointF> points;

    qreal penWidth = 4;
    int blkWidth = 100;
    int blkHeight = 40;
    int addBlkHeight = 20;

    int gridSquare = 20;
    int pointsSize = 8;
    int topText = 15;

    QPointF offset;
    QPointF computeTopLeftGridPoint(const QPointF &pointP);
};

#endif // BLOCK_H










//#ifndef BLOCK_H
//#define BLOCK_H

//#include <QString>
//#include <QStringList>
//#include <QUuid>

//#include <QPainter>
//#include <QGraphicsItem>

//class Block
//{
//public:
//    /**
//      * @todo: Problem if in composite block is same block more than 1 time
//      */

//    /**
//     * @brief id Unique ID
//     */
//    QUuid id;

//    /**
//     * @brief name Block name
//     */
//    QString name;

//    /**
//     * @brief inputs List of inputs
//     */
//    QStringList inputs;

//    /**
//     * @brief outputs List of outputs
//     */
//    QStringList outputs;

//    /**
//     * @brief code Code in C/C++
//     */
//    QString code;

//    /**
//     * @brief composite Detects that this block is composite
//     */
//    bool composite = false;

//    /**
//      * These properties used only if block is a composite block.
//      */

//    /**
//     * @brief x The x coordinate
//     */
//    int x;

//    /**
//     * @brief y The y coordinate
//     */
//    int y;

//    /**
//     * @brief width Width of composite block
//     */
//    int width;

//    /**
//     * @brief height Height of composite block
//     */
//    int height;

//    /**
//     * @brief blocks Child blocks
//     */
//    QList<Block> blocks;

//    /**
//     * @brief connections Connections with each blocks
//     */
//    QStringList connections;

//    /**
//     * @brief Block     Builds a block
//     * @param name      Name of the block
//     * @param inputs    Block inputs
//     * @param outputs   Block outputs
//     * @param code      Block code (C/C++ style)
//     */
//    Block(QString name, QStringList inputs, QStringList outputs, QString code);

//    /**
//     * @brief setName   Sets the name to the block
//     * @param name      New name
//     */
//    void setName(QString name);

//    /**
//     * @brief setInputs Sets the inputs to the block
//     * @param inputs    List of inputs
//     */
//    void setInputs(QStringList inputs);

//    /**
//     * @brief setOutputs    Sets the outputs to the block
//     * @param outputs       List of outputs
//     */
//    void setOutputs(QStringList outputs);

//    /**
//     * @brief setCode   Sets the code to the block
//     * @param code      Code of the block
//     */
//    void setCode(QString code);

//    /**
//     * @brief isComposite   Checks if its composite block or not
//     * @return              True if its composite block otherwise false
//     */
//    bool isComposite();

//    /**
//     * @brief getBlocks Gets the block list (if composite)
//     * @return          List of blocks
//     */
//    QList<Block> getBlocks();

//    /**
//     * @brief addBlock  Adds block into blocks (if composite)
//     * @param block     Block added into blocks
//     */
//    void addBlock(Block block);

//    /**
//     * @brief getBlock  Gets block from blocks (if composite)
//     * @param name      The name of the block
//     * @return          Block instance
//     */
//    Block getBlock(QString name);

//    /**
//     * @brief removeBlock   Removes the block by name
//     * @param name          Name of the block
//     */
//    void removeBlock(QString name);

//    /**
//     * @brief removeBlock   Removes the block by instance
//     * @param block         Block instance
//     */
//    void removeBlock(Block block);

//    /**
//     * @brief createConnection  Creates connection between two blocks
//     * @param block1            Block1 instance
//     * @param point1            Input/Output of the block1
//     * @param block2            Block2 instance
//     * @param point2            Input/Output of the block2
//     */
//    void createConnection(Block block1, QString point1, Block block2, QString point2);

//    /**
//     * @brief destroyConnection  Destroys connection between two blocks
//     * @param block1            Block1 instance
//     * @param point1            Input/Output of the block1
//     * @param block2            Block2 instance
//     * @param point2            Input/Output of the block2
//     */
//    void destroyConnection(Block block1, QString point1, Block block2, QString point2);

//private:

//};

//#endif // BLOCK_H
