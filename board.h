#ifndef BOARD_H
#define BOARD_H
#include <QObject>
#include <QString>

class QQmlEngine;
class QJSEngine;

namespace tile {

class board: public QObject
{
    Q_OBJECT
private:
    struct cube{ int name;};

public:

    board();
    ~board();
    static QObject* getInstace(QQmlEngine *engine, QJSEngine *scriptEngine);
    cube * m_cubes;
    Q_INVOKABLE int move(int index);
    Q_INVOKABLE bool isVictory();
    Q_INVOKABLE void mixCubes();
    Q_INVOKABLE int getName(int index);
    Q_INVOKABLE void setName(int index, int name);
    bool isSolvable(int * arr);
    int * getUniqueRandomNumber();

private:
    static QObject* m_board;
};

}

#endif // BOARD_H
