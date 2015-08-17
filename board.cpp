
#include <QQmlApplicationEngine>
#include "board.h"

using namespace tile;

board::board()
{
    m_cubes = new cube[16];
    for (int i = 0; i < 16; i++)
    {
        if (i == 15)
            m_cubes[i].name = 0;
        m_cubes[i].name = i + 1;
    }
}

board::~board()
{
    delete [] m_cubes;
    m_cubes = nullptr;
}

QObject* board::m_board(nullptr);

QObject* board::getInstace(QQmlEngine *engine, QJSEngine *scriptEngine) {

    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)
    if (!m_board) {
        m_board = new board;
    }

    return m_board;
}

int board::move(int index)
{

    bool moves = true;

    if ( (index + 1) <= 15)
    {
        if (m_cubes[index + 1].name == 0)
        {
            if ((index + 1) % 4)
            {
                setName(index + 1,getName(index));
                setName(index,0);
                index += 1;
                moves = false;
            }
        }
    }
    if ( (index + 4) <= 15 && moves)
    {
        if (m_cubes[index + 4].name == 0)
        {
            setName(index + 4,getName(index));
            setName(index,0);
            moves = false;
            index += 4;
        }
    }
    if ( (index - 1) >= 0 && moves)
    {
        if (m_cubes[index - 1].name == 0)
        {
            if ((index) % 4)
            {
                setName(index-1,getName(index));
                setName(index,0);
                moves = false;
                index -= 1;
            }
        }
    }
    if ( (index - 4) >= 0 && moves)
    {
        if (m_cubes[index - 4].name == 0)
        {
            setName(index-4,getName(index));
            setName(index,0);
            index -= 4;
            moves = false;
        }
    }
    moves = true;
    return index;
}

bool board::isVictory()
{
    bool isVictory = false;

    for (int i = 0; getName(i) == (i + 1); i++)
    {
        if ( i == 14 && getName(i+1) == 0)
            isVictory = true;
    }
    return isVictory;
}

void board::mixCubes()
{
    int * arr = getUniqueRandomNumber();
    int j = 0;
    for(int i = 0; i < 16; i++)
    {
        if (i == 15)
            setName(i,0);
        else
            setName(i,arr[j]);
        j++;
    }
    delete [] arr;
}

int board::getName(int index)
{
    return m_cubes[index].name;
}

void board::setName(int index, int name)
{
    m_cubes[index].name = name;
}

bool board::isSolvable(int * arr)
{
    int n = 0;
    int e = 4;
    for ( int i = 0; i < 15; i++)
    {
        for (int j = i + 1; j < 15; j++)
        {
            if (arr[i] > arr[j])
            {
                n++;
            }
        }
    }
    n += e;
    if (n % 2)
        return false;
    else return true;
}

int * board::getUniqueRandomNumber()
{
    int *arr = new int[15];
    for (int i = 0; i < 15; i++)
    {
        int  n = rand() % 15 + 1;

        for( int j = 0; j <= i; j++)
        {
            if(arr[j] == n || arr[0] == n)
            {
                n = rand() % 15 + 1;
                j = 0;
            }
            else if(j == i && arr[j] != n)
                arr[i] = n;
        }
    }
    if(isSolvable(arr))
        return arr;
    else getUniqueRandomNumber();
}
