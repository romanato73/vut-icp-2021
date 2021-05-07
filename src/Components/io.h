#ifndef IO_H
#define IO_H

#include <QGraphicsItem>

class IO : public QGraphicsItem
{
public:
    IO();

    QString ioType = "const";

    QString constType;

    int x;
    int y;
};

#endif // IO_H
