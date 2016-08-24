#include "Board.h"
#include<iostream>
using namespace std;

bool Board::isFull()
{
    for (int i=0; i < maxRow; i++)
    {
        for (int j = 0; j < maxCol; j++)
        {
            if (pBoard[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}

void Board::placeFinal(int userX, int userY, int type, int total)
{
    if (total == 0)
    {
        pBoard[userX][userY] = type;
    }
    else
    {
        pBoard[userX][userY] = type * total;
    }

}

void Board::placeInit(int userX, int userY, int type)
{
    pBoard[userX][userY] = type;
}

bool Board::isValid(int userX, int userY)
{
    if (userX < 0 || userX >= maxRow || userY < 0 || userY >= maxCol)
    {
        return false;
    }
    return true;
}


int Board::getRow()
{
    return maxRow;
}

int Board::getCol()
{
    return maxCol;
}


void Board::init()
{

    cout << "Give me board height\n>";
    cin >> maxRow;
    cout << "Give me board width\n>";
    cin >> maxCol;
    for (int i = 0; i < maxRow; i++)
    {
        for (int j = 0; j < maxCol; j++)
        {
            pBoard[i][j] = 0;
        }
    }
}

void Board::displayBoard()
{
    for(int i = 0; i < maxRow; i++)
    {
        for (int j = 0; j < maxCol; j++)
        {
            cout << pBoard[i][j] << " | ";
        }
        cout << "\n";
    }
}

