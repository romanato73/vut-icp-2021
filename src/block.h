#ifndef BLOCK_H
#define BLOCK_H

#include <QString>
#include <QStringList>



class Block
{
public:
    Block();

    /**
     * @brief build     Builds a block
     * @param name      Name of block
     * @param inputs    Array of inputs
     * @param outputs   Array of outputs
     * @param code      Code
     */
    void build(QString name, QStringList inputs, QStringList outputs, QString code);

private:
    QString name;
    QStringList inputs;
    QStringList outputs;
    QString code;
};

#endif // BLOCK_H
