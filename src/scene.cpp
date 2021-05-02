#include "scene.h"

#include "block.h"
#include "storage.h"

#include <Dialogs/createblockdialog.h>

Scene::Scene()
{

}

void Scene::setMode(QString mode)
{
    this->mode = mode;
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
    if (this->mode == "create") {
        CreateBlockDialog dialog;
        dialog.loadCategories(Storage::getCategoriesList());

        if (dialog.exec() == QDialog::Accepted) {
            auto block = new Block();

            qDebug() << "block created";
        }
    }
}
