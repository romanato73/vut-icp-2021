#include "storage.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonObject>

QString Storage::getFileContent(QString name)
{
    //QString fileName = QDir::currentPath() + "/../../../../src/Storage/" + name;
    QString fileName = QDir::currentPath() + "/../src/Storage/" + name;

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
//    QString fileName = QDir::currentPath() + "/../../../../src/Storage/" + name;
    QString fileName = QDir::currentPath() + "/../src/Storage/" + name;

    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Can not open file: " + file.fileName();
        exit(0);
    }

    file.write(content.toStdString().c_str());

    file.close();
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

void Storage::addBlock(Block *block)
{
    auto object = getCategories();

    // Create new block
    QJsonObject newBlock;

    // Insert values
    newBlock.insert("name", block->name);
    newBlock.insert("inputs", QJsonArray::fromStringList(block->inputs));
    newBlock.insert("outputs", QJsonArray::fromStringList(block->outputs));
    newBlock.insert("code", block->code);

    // Get all blocks from category
    auto blocks = object.value(block->category).toArray();

    // Append new block
    blocks.append(newBlock);

    // Remove category
    object.remove(block->category);

    // Insert category with new block
    object.insert(block->category, blocks);

    QJsonDocument doc(object);
    /** @todo: Change to ::Compact for better size */
    QString jsonString = doc.toJson(QJsonDocument::Indented);

    updateFileContent("categories.json", jsonString);
}

Block *Storage::getBlock(QString category, QString name)
{
    auto block = new Block();

    auto object = getCategories();

    auto blocks = object.value(category).toArray();

    for (auto obj : blocks) {
        auto item = obj.toObject();

        if (item["name"] == name) {
            QStringList inputs;
            QStringList outputs;

            for (auto in : item["inputs"].toArray()) inputs.append(in.toString());
            for (auto in : item["outputs"].toArray()) outputs.append(in.toString());

            block->build(name, inputs, outputs, item["code"].toString());
        }
    }

    return block;
}
