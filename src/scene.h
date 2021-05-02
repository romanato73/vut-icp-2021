#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QDebug>

class Scene : public QGraphicsScene
{
public:
    Scene();

    QString mode = "select";

    void setMode(QString mode);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
};

#endif // SCENE_H
