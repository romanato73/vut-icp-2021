/**
 * Editor and interpret of the hierarchically structured function blocks
 * Faculty of Information Technology, Brno University of Technology
 *
 * @author Roman Országh <xorsza01@stud.fit.vutbr.cz>
 * @author Albert Groma <xgroma00@stud.fit.vutbr.cz>
 */

#ifndef IOH
#define IOH

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QFont>
#include <QApplication>
#include <QDebug>
#include <QtMath>

/**
 * @brief The IO class
 */
class IO : public QGraphicsItem
{
public:
    IO(QGraphicsItem  *parent = nullptr);

    /**
     * @brief name Name of the io
     */
    QString name;

    /**
     * @brief ioType IO type (input, output)
     */
    QString ioType;

    /**
     * @brief ioValType Value type (int, float, bool, string)
     */
    QString ioValType;

    /**
     * @brief plainText Text to be added into scene
     */
    QString plainText;

    /**
     * @brief width, height Width and height of the IO
     */
    int width = 0, height = 0;

    /**
     * @brief coordinates Coordinates of the IO
     */
    QPointF coordinates;

    /**
     * @brief build Builds IO
     * @param name Name of the IO
     * @param type Type of the IO
     */
    void build(QString name, QString valType, QString type);

    /**
     * @brief boundingRect Custom function for boundingRect
     * @return             Coordinates of the bounding rectangle
     */
    QRectF boundingRect() const override;

    /**
     * @brief paint     Paints the IO
     * @param painter
     * @param option
     * @param widget
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    /**
     * @brief mousePressEvent Mouse events with IO
     * @param mouseEvent      Mouse event pointer
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;

    /**
     * @brief itemChange Item change handler
     * @param change
     * @param value
     * @return
     */
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
private:
    /**
     * @brief gridSize Size of the grid in scene
     */
    int gridSize = 20;

    /**
     * @brief pointsSize Size of the point
     */
    int pointsSize = 8;

    /**
     * @brief spacer Spacer width
     */
    int spacer = 10;

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

#endif // IOH
