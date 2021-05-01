#ifndef STORAGE_H
#define STORAGE_H

#include "block.h"
#include <QDir>
#include <QString>



class Storage
{
public:
    Storage();

    /**
     * @brief storagePath Path to the storage
     */
    QString path = QDir::currentPath() + "/../src/Storage/";

    /**
     * @brief getCategories Gets categories from storage
     * @return JsonObject of categories
     */
    QJsonObject getCategories();

    /**
     * @brief addCategory   Adds new category into storage
     * @param name          Name of the category
     */
    void addCategory(QString name);

    /**
     * @brief addBlock  Adds block into a category
     * @param block     Block instance
     * @param category  Name of category
     */
    void addBlock(Block block, QString category);

private:
    /**
     * @brief openFile  Opens the desired file
     * @param name      Name of the file
     * @return          File pointer
     */
    QString getFileContent(QString name);

    /**
     * @brief updateFileContent Updates the file content
     * @param name              The name of file
     * @param content           The content
     */
    void updateFileContent(QString name, QString content);
};

#endif // STORAGE_H
