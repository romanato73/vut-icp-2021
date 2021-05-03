#ifndef STORAGE_H
#define STORAGE_H

#include "block.h"
#include <QDir>
#include <QString>



class Storage
{
public:
    /**
     * @brief getCategories Gets categories from storage
     * @return JsonObject of categories
     */
    static QJsonObject getCategories();

    /**
     * @brief getCategoriesList Gets categories from storage (as list)
     * @return QStringList of categories
     */
    static QStringList getCategoriesList();

    /**
     * @brief addCategory   Adds new category into storage
     * @param name          Name of the category
     */
    static void addCategory(QString name);

    /**
     * @brief updateCategory Updates the name of category
     * @param name           Old name of the category
     * @param newName        New Name of the category
     */
    static void updateCategory(QString name, QString newName);

    /**
     * @brief removecategory Removes category from storage
     * @param name           Name of the category
     */
    static void removeCategory(QString name);

    /**
     * @brief addBlock  Adds block into a category
     * @param block     Block instance
     * @param category  Name of category
     */
    static void addBlock(Block block, QString category);

private:
    Storage() {};

    /**
     * @brief openFile  Opens the desired file
     * @param name      Name of the file
     * @return          File pointer
     */
    static QString getFileContent(QString name);

    /**
     * @brief updateFileContent Updates the file content
     * @param name              The name of file
     * @param content           The content
     */
    static void updateFileContent(QString name, QString content);
};

#endif // STORAGE_H
