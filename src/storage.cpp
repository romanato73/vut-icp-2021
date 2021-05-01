#include "storage.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonObject>

Storage::Storage()
{

}

QString Storage::getFileContent(QString name)
{
    QFile file(path + name);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Can not open file: " + file.fileName();
        exit(0);
    }

    auto content = file.readAll();

    file.close();

    return content;
}

void Storage::updateFileContent(QString name, QString content)
{
    QFile file(path + name);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Can not open file: " + file.fileName();
        exit(0);
    }

    file.write(content.toStdString().c_str());
}

QJsonObject Storage::getCategories()
{
    auto content = getFileContent("categories.json");

    QJsonDocument json = QJsonDocument::fromJson(content.toUtf8());
    QJsonObject categories = json.object();

    return categories;
}

void Storage::addCategory(QString name)
{
    auto content = getFileContent("categories.json");

    QJsonDocument json = QJsonDocument::fromJson(content.toUtf8());
    QJsonObject object = json.object();

    object.insert(name, QJsonObject());

    QJsonDocument doc(object);
    /** @todo: Change to ::Compact for better size */
    QString jsonString = doc.toJson(QJsonDocument::Indented);

    updateFileContent("categories.json", jsonString);
}

void Storage::addBlock(Block block, QString category)
{

}
