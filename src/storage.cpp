#include "storage.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonObject>

QString Storage::getFileContent(QString name)
{
    //QString path = QDir::currentPath() + "/../src/Storage/";
    QString fileName = ":/storage/" + name;

    QFile file(fileName);

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
    QString path = QDir::currentPath() + "/../src/Storage/";

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

QStringList Storage::getCategoriesList()
{
    auto object = getCategories();

    QStringList list = object.keys();

    return list;
}

void Storage::addCategory(QString name)
{
    auto object = getCategories();

    object.insert(name, QJsonArray());

    QJsonDocument doc(object);
    /** @todo: Change to ::Compact for better size */
    QString jsonString = doc.toJson(QJsonDocument::Indented);

    updateFileContent("categories.json", jsonString);
}

void Storage::updateCategory(QString name, QString newName)
{
    auto object = getCategories();

    auto categoryValue = object.take(name);

    object.insert(newName, categoryValue);

    QJsonDocument doc(object);
    /** @todo: Change to ::Compact for better size */
    QString jsonString = doc.toJson(QJsonDocument::Indented);

    updateFileContent("categories.json", jsonString);
}

void Storage::removeCategory(QString name)
{
    auto object = getCategories();

    object.remove(name);

    QJsonDocument doc(object);
    /** @todo: Change to ::Compact for better size */
    QString jsonString = doc.toJson(QJsonDocument::Indented);

    updateFileContent("categories.json", jsonString);
}

void Storage::addBlock(QString category, Block block)
{
    auto content = getFileContent("categories.json");
}
