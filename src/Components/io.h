#ifndef IOH
#define IOH

#include <QGraphicsItem>
#include <QObject>
#include <QPainter>
#include <QFont>
#include <QApplication>
#include <QDebug>
#include <QtMath>

class IO : public QGraphicsItem
{
public:
    IO(QGraphicsItem  *parent = nullptr);

    /**
     * @brief name Name of the io
     */
    QString name;

    /**
     * @brief ioType IO type (input, output, constant)
     */
    QString ioType;


    QString ioInType;

    /**
     * @brief plainText Text to be added into scene
     */
    QString plainText;

    int width = 0, height = 0;

    QPoint coordinates;

    /**
     * @brief build Builds IO
     * @param name Name of the IO
     * @param type Type of the IO
     */
    void build(QString name, QString inType, QString type);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent) override;
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
private:
    int gridSize = 20;

    int pointsSize = 8;

    int spacer = 10;

    QPointF offset;
    QPointF computeTopLeftGridPoint(const QPointF &pointP);
};

#endif // IOH
