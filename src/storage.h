/**
 * Editor and interpret of the hierarchically structured function blocks
 * Faculty of Information Technology, Brno University of Technology
 *
 * @author Roman Országh <xorsza01@stud.fit.vutbr.cz>
 * @author Albert Groma <xgroma00@stud.fit.vutbr.cz>
 */

#ifndef STORAGE_H
#define STORAGE_H

#include "Components/block.h"
#include <QDir>
#include <QString>


/**
 * @brief The Storage class
 */
class Storage
{
public:
    Storage() {};

    /**
     * @brief getCategories Gets categories from storage
     * @return JsonObject of categories
     */
    QJsonObject getCategories();

    /**
     * @brief getCategoriesList Gets categories from storage (as list)
     * @return QStringList of categories
     */
    QStringList getCategoriesList();

    /**
     * @brief addCategory   Adds new category into storage
     * @param name          Name of the category
     */
    void addCategory(QString name);

    /**
     * @brief updateCategory Updates the name of category
     * @param name           Old name of the category
     * @param newName        New Name of the category
     */
    void updateCategory(QString name, QString newName);

    /**
     * @brief removecategory Removes category from storage
     * @param name           Name of the category
     */
    void removeCategory(QString name);

    /**
     * @brief addBlock  Adds block into a category
     * @param block     Block instance
     * @param category  Name of category
     */
    void addBlock(Block *block);

    /**
     * @brief getBlock  Gets the block from storage
     * @param category  Block category
     * @param name      Block name
     * @return          Block instance
     */
    Block *getBlock(QString category, QString name);

    /**
     * @brief hasBlock Checks if storage has block
     * @param block    Block we are searching for
     * @return         True if block found otherwise false
     */
    bool hasBlock(Block *block);

    /**
     * @brief updateBlock Updates the block from storage
     * @param block       The block instance
     */
    void updateBlock(Block *block, Block *newBlock);

    /**
     * @brief deleteBlock Removes block from storage
     * @param block       Block to be deleted
     */
    void removeBlock(Block *block);

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
