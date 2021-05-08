#include "scene.h"
#include <Dialogs/createblockdialog.h>
#include <Dialogs/createiodialog.h>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <Components/io.h>

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

void Scene::buildProgram()
{
    for (auto block : blocks) {
        // Set not connected
        std::iota(block->inNotConnected.begin(), block->inNotConnected.end(), 0);
        std::iota(block->outNotConnected.begin(), block->outNotConnected.end(), 0);

        // Set connections placeholders
        block->connectedBlocks.resize(block->inPoints.size());
        block->connectedIOs.resize(block->inPoints.size());

        qDebug() << block->name + ": " << block->inNotConnected.size() << " " << block->outNotConnected.size();
    }

    // Iterate through all blocks
    for (auto block : blocks) {

        qDebug() << block->name;

        // Iterate through inputs
        for (int i = 0; i < block->inputs.size() ; i++) {
            // Unmap lines
            for (auto line : lines) { line->mapped = false; }

            finding = "inputs";

            auto in = block->inPoints.at(i);
            // Input coordinates
            auto inCoords = QPointF(block->x() + in.x(), block->y() + in.y());
//            qDebug() << "Input[" << block->inputs.at(i) << "]" << inCoords;

            // Iterate throuh lines
            for (auto line : lines) {
//                qDebug() << line->pos();
                auto lineCoordsStart = line->mapToScene(line->line().p1());
                auto lineCoordsEnd = line->mapToScene(line->line().p2());

                // Match coordinates
                if (inCoords == lineCoordsStart) {
                    line->mapped = true;
//                    qDebug() << inCoords << " == " << lineCoordsStart;
                    followLine(block, i, lineCoordsEnd);
                } else if (inCoords == lineCoordsEnd) {
                    line->mapped = true;
//                    qDebug() << inCoords << " == " << lineCoordsEnd;
                    followLine(block, i, lineCoordsStart);
                }
            }
        }

        for (int i = 0; i < block->outputs.size(); i++) {
            finding = "outputs";

            auto out = block->outPoints.at(i);

            auto outCoords = QPointF(block->x() + out.x(), block->y() + out.y());

            for (auto line : lines) {
                auto lineCoordsStart = line->mapToScene(line->line().p1());
                auto lineCoordsEnd = line->mapToScene(line->line().p2());

                // Match coordinates
                if (outCoords == lineCoordsStart) {
                    line->mapped = true;
//                    qDebug() << inCoords << " == " << lineCoordsStart;
                    followLine(block, i, lineCoordsEnd);
                } else if (outCoords == lineCoordsEnd) {
                    line->mapped = true;
//                    qDebug() << inCoords << " == " << lineCoordsEnd;
                    followLine(block, i, lineCoordsStart);
                }
            }
        }
    }
}

void Scene::followLine(Block *origin, int index, QPointF point)
{
//    qDebug() << "finding path " << point;

    if (finding == "outputs") {
        // Find outputs
        for (auto io : ios) {
            if (io->ioType != "output") continue;

            auto coordinates = io->mapToScene(io->coordinates);
    //        qDebug() << "IO: " << io->coordinates << ": Point" << point;
            if (coordinates == point) {
                qDebug() << "Connected to " + io->name;
                origin->outNotConnected[index] = -1;
                return;
            }
        }

        // If no element found find line or end algorithm
        for (auto line : lines) {
            // Skip mapped lines
            if (line->mapped) continue;

            auto lineCoordsStart = line->mapToScene(line->line().p1());
            auto lineCoordsEnd = line->mapToScene(line->line().p2());

            // Match coordinates
            if (point == lineCoordsStart) {
                line->mapped = true;
                followLine(origin, index, lineCoordsEnd);
            } else if (point == lineCoordsEnd) {
                line->mapped = true;
                followLine(origin, index, lineCoordsStart);
            }
        }

        return;
    }

    // First we need to find a block
    for (auto block : blocks) {
        // Iterate through outputs (we want only outputs connected to inputs)
        for (int i = 0; i < block->outputs.size() ; i++) {
            auto out = block->outPoints.at(i);
            // Output coordinates
            auto outCoords = QPointF(block->x() + out.x(), block->y() + out.y());
//            qDebug() << "Output[" << block->outputs.at(i) << "]" << outCoords;

            // If match found connect blocks
            if (point == outCoords) {
//                qDebug() << "Output[" << block->outputs.at(i) << "]" << outCoords;
                qDebug() << "Connected to: " << block->name;
                block->outNotConnected[i] = -1;
                origin->inNotConnected[index] = -1;
                origin->connectedBlocks[index] = block;
                return;
            }
        }
    }

    // Find inputs
    for (auto io : ios) {
        if (io->ioType == "output") continue;

        auto coordinates = io->mapToScene(io->coordinates);
//        qDebug() << "IO: " << io->coordinates << ": Point" << point;
        if (coordinates == point) {
            qDebug() << "Connected to " + io->name;
            origin->inNotConnected[index] = -1;
            origin->connectedIOs[index] = io;
            return;
        }
    }

    // If no element found find line or end algorithm
    for (auto line : lines) {
        // Skip mapped lines
        if (line->mapped) continue;

        auto lineCoordsStart = line->mapToScene(line->line().p1());
        auto lineCoordsEnd = line->mapToScene(line->line().p2());

        // Match coordinates
        if (point == lineCoordsStart) {
            line->mapped = true;
            followLine(origin, index, lineCoordsEnd);
        } else if (point == lineCoordsEnd) {
            line->mapped = true;
            followLine(origin, index, lineCoordsStart);
        }
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
//    qDebug() << "SceneMode: " << mode << "| CreateMode: " << createMode;
    qDebug() << "MOUSE "  << mouseEvent->scenePos().x() << ":" << mouseEvent->scenePos().y();

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

                    auto io = new IO();

                    auto x = round(mouseEvent->scenePos().x() / gridSize) * gridSize;
                    auto y = round(mouseEvent->scenePos().y() / gridSize) * gridSize;

                    io->build(dialog.name, dialog.inType, createMode);
                    io->setPos(QPointF(x, y));

                    addItem(io);
                    ios.append(io);
                }
            }
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
            if(auto line = dynamic_cast<Line*>(item); line != nullptr) {
                delete line;
                lines.removeOne(line);
                qDebug() << "Line deleted";
            } else if(auto text = dynamic_cast<QGraphicsTextItem*>(item); text != nullptr) {
                delete text;
                qDebug() << "Text deleted";
            } else if(auto block = dynamic_cast<Block*>(item); block != nullptr) {
                qDebug() << "Block " + block->name + " deleted";
                delete block;
                blocks.removeOne(block);
            } else if (auto io = dynamic_cast<IO *>(item); io != nullptr) {
                qDebug() << "IO " + io->name + " deleted";
                delete io;
                ios.removeOne(io);
            } else {
                auto element = dynamic_cast<QGraphicsItem*>(item);
                if (element) {
                    delete element;
                    qDebug() << "Graphics item deleted";
                }
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
