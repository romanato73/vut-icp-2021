#include "block.h"

Block::Block()
{

}

void Block::build(QString name, QStringList inputs, QStringList outputs, QString code)
{
    this->name = name;
    this->inputs = inputs;
    this->outputs = outputs;
    this->code = code;
}
