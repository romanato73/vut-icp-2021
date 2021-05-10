#include "programgenerator.h"

#include <QFile>

ProgramGenerator::ProgramGenerator()
{

}

void ProgramGenerator::setPath(QString path)
{
    this->path = path;
}

void ProgramGenerator::setBlocks(QVector<Block *> blocks)
{
    this->blocks = blocks;
}

void ProgramGenerator::generateProgram()
{
    // Generate functions for each block
    for (auto block : blocks) {
        // Initialize id for block
        block->id = index++;

        // Generate functions for each block
        content += generateFunction(block) + "\n";
    }

    // Generate main
    content += generateMain();

    // Initialize file
    QFile file(path);

    // Try to open file
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Can not open file: " + file.fileName();
        exit(0);
    }

    // Write into file and close
    file.write(content.toStdString().c_str());

    file.close();
}

QString ProgramGenerator::generateFunction(Block *block)
{
    QString code = "";
    QString header = "";
    QString params = "";
    QString footer = "\n}\n";

    // Initialize header | void _BLOCK_X (X -> index)
    header = "void _" + block->name + "_" + QString::number(block->id);

    // Initialize input params
    for (int i = 0; i < block->inputs.size(); i++) {
        // Define Input
        auto inputType = block->inputs.at(i).split(":").at(0);
        auto inputName = block->inputs.at(i).split(":").at(1);

        params += inputType + " " + inputName + ", ";
    }

    // Initialize output params
    for (int i = 0; i < block->outputs.size(); i++) {
        // Define output
        auto outputType = block->outputs.at(i).split(":").at(0);
        auto outputName = block->outputs.at(i).split(":").at(1);

        params += outputType + " &" + outputName;
        // Add comma if not last
        if (i < block->outputs.size() - 1) {
            params += ", ";
        }
    }

    // Create header
    header += "(" + params + ")";

    // Append into code
    code += header + " {\n";
    code += block->code;
    code += footer;

    return code;
}

QString ProgramGenerator::generateMain()
{
    QString header = "int main() {\n";
    QString code = "";
    QString footer = "\nreturn 0;\n}";

    // Append header
    code += header;

    // Define variables
    for (auto block : blocks) {
        // type inX_BLOCK_Y (type -> varType, X -> index, Y -> name of output)
        for (int i = 0; i < block->inputs.size(); i++) {
            // Input definition
            auto inputType = block->inputs.at(i).split(":").at(0);
            auto inputName = block->inputs.at(i).split(":").at(1);

            code += inputType + " in" + QString::number(block->id) + "_" + block->name + "_" + inputName;

            // Check for connection
            if (block->connectedInputs.at(i) != nullptr) {
                // Connected via input -> define value
                auto io = block->connectedInputs.at(i);
                code += " = " + io->name;
            }

            code += ";\n";
        }

        // type outX_BLOCK_Y (type -> varType, X -> index, Y -> name of output)
        for (int i = 0; i < block->outputs.size(); i++) {
            // Output definition
            auto outputType = block->outputs.at(i).split(":").at(0);
            auto outputName = block->outputs.at(i).split(":").at(1);

            code += outputType + " out" + QString::number(block->id) + "_" + block->name + "_" + outputName;
            code += ";\n";
        }
    }

    code += "\n";

    // Initialize inputs and call functions
    for (auto block : blocks) {
        QString params = "";
        // _BLOCK_X(ins, outs) (X -> index)

        // Initialize input params
        for (int i = 0; i < block->inputs.size(); i++) {
            auto inputType = block->inputs.at(i).split(":").at(0);
            auto inputName = block->inputs.at(i).split(":").at(1);

            // Define Input
            params += "in" + QString::number(block->id) + "_" + block->name + "_" + inputName;
            params += ", ";

            // Check if connected (initialize input with output of origin block)
            if (block->connectedBlocks.at(i) != nullptr) {
                // Connected to a block initialize with its output
                auto origin = block->connectedBlocks.at(i);
                auto originOutName = origin->outputs.at(block->connectedBlocksOut.at(i)).split(":").at(1);

                code += "in" + QString::number(block->id) + "_" + block->name + "_" + inputName;
                code += " = ";
                code += "out" + QString::number(origin->id) + "_" + origin->name + "_" + originOutName;
                code += ";\n";
            }
        }

        // Prepare output params
        for (int i = 0; i < block->outputs.size(); i++) {
            // Define output
            auto outputName = block->outputs.at(i).split(":").at(1);
            params += "out" + QString::number(block->id) + "_" + block->name + "_" + outputName;

            if (i < block->outputs.size() - 1) {
                params += ", ";
            }
        }

        // Call function
        code += "\n";
        code += "_" + block->name + "_" + QString::number(block->id) + "(" + params + ");\n";
    }

    code += footer;

    return code;
}
