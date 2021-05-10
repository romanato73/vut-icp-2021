/**
 * Editor and interpret of the hierarchically structured function blocks
 * Faculty of Information Technology, Brno University of Technology
 *
 * @author Roman Országh <xorsza01@stud.fit.vutbr.cz>
 * @author Albert Groma <xgroma00@stud.fit.vutbr.cz>
 */

#ifndef PROGRAMGENERATOR_H
#define PROGRAMGENERATOR_H

#include <QString>

#include <Components/block.h>


/**
 * @brief The ProgramGenerator class
 */
class ProgramGenerator
{
public:
    /**
     * @brief ProgramGenerator Generates the output code of connected blocks
     */
    ProgramGenerator();

    /**
     * @brief setPath   Sets the path for output file
     * @param path      The actual path
     */
    void setPath(QString path);

    /**
     * @brief setBlocks Sets sorted blocks
     * @param blocks    Sorted blocks
     */
    void setBlocks(QVector<Block *> blocks);

    /**
     * @brief generateProgram Generates the program
     */
    void generateProgram();

private:

    /**
     * @brief path Path to the file
     */
    QString path;

    /**
     * @brief blocks Sorted blocks
     */
    QVector<Block *> blocks;

    /**
     * @brief content Content of the output file
     */
    QString content = "";

    /**
     * @brief index Index of the block (unique ID for functions and IO of the block)
     */
    int index = 0;

    /**
     * @brief generateFunction  Generates the function for each block
     * @param block             Block instance
     * @return                  The function code
     */
    QString generateFunction(Block *block);

    /**
     * @brief generateMain  Generates the main function
     * @return              The code of the main function
     */
    QString generateMain();
};

#endif // PROGRAMGENERATOR_H
