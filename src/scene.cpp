#include "scene.h"
#include <Dialogs/createblockdialog.h>
#include <Dialogs/createiodialog.h>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

Scene::Scene(QObject *parent) : QGraphicsScene(parent), gridSize(20)
{
    Q_ASSERT(gridSize > 0);
}

void Scene::setMode(QString value)
{
    mode = value;
}

void Scene::setCreateMode(QString value)
{
    createMode = value;
}

int Scene::roundToGrid(int number)
{
    int remainder = abs(number) % getGridSize();

    if (remainder == 0) return number;

    if (number < 0) {
        return - (abs(number) - remainder);
    } else {
        return number + getGridSize() - remainder;
    }
}

void Scene::drawBackground(QPainter *painter, const QRectF &rect)
{
    QGraphicsScene::drawBackground(painter, rect);

    QPen pen;
    painter->setPen(pen);

    qreal left = int(rect.left()) - (int(rect.left()) % gridSize);
    qreal top = int(rect.top()) - (int(rect.top()) % gridSize);
    QVector<QPointF> points;
    for (qreal x = left; x < rect.right(); x += gridSize){
        for (qreal y = top; y < rect.bottom(); y += gridSize){
            points.append(QPointF(x,y));
        }
    }

    painter->drawPoints(points.data(), points.size());
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    qDebug() << "SceneMode: " << mode << "| CreateMode: " << createMode;

    if (this->mode == "select") {
        // Enable element mooving
        for(auto item : items()) {
            item->setFlag(QGraphicsItem::ItemIsMovable, true);
        }
    } else if (this->mode == "create") {
        if (createMode == "block") {
            // Creates a new block
            CreateBlockDialog dialog;
            dialog.loadCategories(storage->getCategoriesList());

            if (dialog.exec() == QDialog::Accepted) {
                auto block = dialog.block;

                // Add into storage if category set
                if (block->category != "") {
                    storage->addBlock(block);
                    emit onBlockCreate(block->category);
                }

                auto x = round(mouseEvent->scenePos().x() / gridSize) * gridSize + 10;
                auto y = round(mouseEvent->scenePos().y() / gridSize) * gridSize + 10;

                block->setPos(QPointF(x, y));
                addItem(block);
                qDebug() << "Block created";

                blocks.append(block);
            }

            /// algorithm1.c
//            QVector<QPointF> pomArray;
//            for (Block *a : blocks) {
////                qDebug() << a->inPoints;
//                for (QPointF p : a->outPoints){
//                    for (QGraphicsLineItem *l : lines){
//                        if(p == l->line().p1()){
//                            pomArray.append( l->line().p2());
//                        } else if(p == l->line().p2()){
//                            pomArray.append( l->line().p1());
//                        } else {

//                        }
//                    }
//                }
//            }

            /// algorithm2.c
//            QVector<QPointF> pomArray;
//            QVector<QPointF> finalInputs;

//            for (Block *a : blocks) {
//                for (QPointF p : a->inPoints){
//                    compare(p);
//                }
//            }

//        }
//        void compare(QPointF point){
//            // kontrolujem block outputs
//            for (Block *a : blocks) {
//                for (QPointF p : a->outPoints){
//                    if(point == p)
//                        return;
//                }
//            }// kontrolujem input, output
//            for (IO *a : io) {
//                if(point == a->pos)
//                        return;
//            }// kontrolujem const
//            for (ConstV *a : constV) {
//                if(point == a->pos)
//                        return;
//            }// kontrolujem line
//            for (QGraphicsLineItem *l : lines){
//                if(point == l->line().p1()){
//                        pomArray.append( l->line().p2());
//                        compare(l->line().p2());
//                } else if(point == l->line().p2()){
//                        pomArray.append( l->line().p1());
//                        compare(l->line().p1());
//                } else {
//                    finalInputs.append();
//                    finalBlockPointer.append(b);
//                }
//            }

//        }
        /// END



        } else if (createMode == "connection") {
            // Creates a new connection line
            if (mouseEvent->button() == Qt::LeftButton) {
                // Disable element mooving
                for(auto* item : items()){
                    item->setFlag(QGraphicsItem::ItemIsMovable, false);
                }

                line = new Line;
                auto x = round(mouseEvent->scenePos().x() / gridSize) * gridSize;
                auto y = round(mouseEvent->scenePos().y() / gridSize) * gridSize;
                auto pos = QPointF(x, y);

                line->setLine(QLineF(pos, pos));

                addItem(line);
            }
        } else if (createMode == "input" || createMode == "output") {
            // Creates a new input or output
            if (mouseEvent->button() == Qt::LeftButton) {
                CreateIODialog dialog;
                dialog.setType(createMode);

                if (dialog.exec() == QDialog::Accepted) {
                    QFont font;
                    font.setFamily("Open Sans");
                    font.setBold(true);
                    font.setPointSize(12);

                    QGraphicsTextItem *io = new QGraphicsTextItem;

                    io->setFont(font);

                    auto x = round(mouseEvent->scenePos().x() / gridSize) * gridSize;
                    auto y = round(mouseEvent->scenePos().y() / gridSize) * gridSize;

                    if (createMode == "input") {
                        io->setPlainText("IN: " + dialog.name);
                        x -= gridSize/2;
                    } else {
                        io->setPlainText("OUT: " + dialog.name);
                        x += gridSize/2;
                    }

                    io->setPos(QPointF(x, y));

                    addItem(io);
                }
            }
        } else if (createMode == "const") {
            // Creates a new constant
        }
    } else if (this->mode == "edit") {
        // Disable element mooving
        for(auto item : items()) {
            item->setFlag(QGraphicsItem::ItemIsMovable, false);
        }

        // Editing blocks
        for (auto item : items(mouseEvent->scenePos())) {
            if (auto block = dynamic_cast<Block*>(item); block != nullptr) {
                qDebug() << "Edit block";
            }
        }
    } else if (this->mode == "delete") {
        for(auto* item : items(mouseEvent->scenePos())){
            if(auto line = dynamic_cast<QGraphicsLineItem*>(item); line != nullptr) {
                delete line;
                qDebug() << "Line deleted";
            } else if(auto text = dynamic_cast<QGraphicsTextItem*>(item); text != nullptr) {
                delete text;
                qDebug() << "Text deleted";
            } else if(auto block = dynamic_cast<QGraphicsItem*>(item); block != nullptr) {
                delete block;
                qDebug() << "Block deleted";
            } else {
                qDebug() << "Unknown object (not deleted)";
            }
        }
    }

    QGraphicsScene::mousePressEvent(mouseEvent);
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (line) {
        auto p = mouseEvent->scenePos();
        QPointF point;
        auto tmpX = abs(p.x() - line->line().p1().x());
        auto tmpY = abs(p.y() - line->line().p1().y());
        auto pp1 = round(p.x() / gridSize) * gridSize;
        auto pp2 = round(p.y() / gridSize) * gridSize;
        if(tmpX >= tmpY){
            point = QPoint(pp1, line->line().p1().y());
        }else{
            point = QPoint(line->line().p1().x(), pp2);
        }
        line->setLine(QLineF(line->line().p1(), point));
//        qDebug() << "line:screen mouse move";
    }

    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    // Enable element mooving
    for(auto item : items()) {
        item->setFlag(QGraphicsItem::ItemIsMovable, true);
    }

    if (line) {
        auto p = mouseEvent->scenePos();
        QPointF point;
        auto tmpX = abs(p.x() - line->line().p1().x());
        auto tmpY = abs(p.y() - line->line().p1().y());
        auto pp1 = round(p.x() / gridSize) * gridSize;
        auto pp2 = round(p.y() / gridSize) * gridSize;
        if(tmpX >= tmpY){
            point = QPoint(pp1, line->line().p1().y());
        }else{
            point = QPoint(line->line().p1().x(), pp2);
        }
        line->setLine(QLineF(line->line().p1(), point));

        // Delete line if its point else save points
        if (point == line->line().p1()) {
            delete line;
        } else {
            lines.append(line);
        }
        line = nullptr;
//        qDebug() << "line:screen mouse release";
    }

    QGraphicsScene::mouseReleaseEvent(mouseEvent);
}
