#include "GameRules.h"
#include<sstream>

int GameRules::removeNeigh(int row, int col, Board current, int neigh)
{
    int sumNeigh;
    return sumNeigh;
}

int GameRules::neighbours(int row, int col, Board current, int UDLR[4])
{
    int neighbours = 0;
    int up = current.pBoard[row-1][col];
    int down = current.pBoard[row+1][col];
    int left = current.pBoard[row][col-1];
    int right = current.pBoard[row][col+1];

    if (row == 0)
        up = 0;

    if (row == current.getRow()-1)
        down = 0;

    if (col == 0)
        left = 0;

    if (col == current.getCol()-1)
        right = 0;

    neighbours = std::abs(up) + std::abs(down) + std::abs(left) + std::abs(right);
    UDLR[0] = up;
    UDLR[1] = down;
    UDLR[2] = left;
    UDLR[3] = right;
    cout << endl;
    for(int i = 0; i < 4; i++)
        cout << UDLR[i];
    cout << endl;
    return neighbours;
}

int GameRules::countNeigh(int UDLR[4])
{
    int neighbours = 0;
    for(int i = 0; i < 4; i++)
    {
        if (UDLR[i] != 0)
        {
            neighbours++;
        }
    }
    cout << "You have " << neighbours << " neighbours." << endl;

    return neighbours;
}

int GameRules::maxResult(int UDLR[4], int neigh, int playerType, string strUDLR[])
{
    int TPC = 0;
    int strUDLRMap[4] = {0, 0, 0, 0};
    int counter = 0;

    int up = UDLR[0];
    int down = UDLR[1];
    int left = UDLR[2];
    int right = UDLR[3];

    if (up != 0)
    {
        strUDLR[counter] = "UP";
        strUDLRMap[counter] = up;
        counter++;
    }
    if (down != 0)
    {
        strUDLR[counter] = "DOWN";
        strUDLRMap[counter] = down;
        counter++;
    }
    if (left != 0)
    {
        strUDLR[counter] = "LEFT";
        strUDLRMap[counter] = left;
        counter++;
    }
    if (right != 0)
    {
        strUDLR[counter] = "RIGHT";
        strUDLRMap[counter] = right;
    }

    if (neigh == 0 || neigh == 1)
    {
        return playerType;
    }
    TPC = maxComb(neigh, strUDLRMap, playerType);
    return TPC;


}

int GameRules::maxComb(int neigh, int UDLR[4], int playerType)
{
    int strUDLRMap[4] = {0, 0, 0, 0};
    for(int i = 0; i < 4; i++)
    {
        strUDLRMap[i] = std::abs(UDLR[i]);
    }
    std::sort(strUDLRMap, strUDLRMap+4);

    if (neigh == 0 || neigh == 1)
    {
        return playerType;
    }
    else if (neigh == 2)
    {
        int total = 0;
        do
        {
            if (strUDLRMap[0] + strUDLRMap[1] > total && (strUDLRMap[0] + strUDLRMap[1]) <= 6)
            {
                total = strUDLRMap[0] + strUDLRMap[1];
            }
        }
        while ( std::next_permutation(strUDLRMap,strUDLRMap+4) );

        if (total != 0 && total <= 6)
        {
            return total;
        }
        else
        {
            maxComb(neigh-1, strUDLRMap, playerType);
        }
    }
    else if (neigh == 3)
    {
        int total = 0;

        do
        {
            if ((strUDLRMap[0] + strUDLRMap[1] + strUDLRMap[2] > total) && (strUDLRMap[0] + strUDLRMap[1] + strUDLRMap[2] <= 6))
            {
                total = strUDLRMap[0] + strUDLRMap[1] + strUDLRMap[2];
            }
        }
        while ( std::next_permutation(strUDLRMap,strUDLRMap+4) );

        if (total != 0 && total <= 6)
        {
            return total;
        }
        else
        {
            maxComb(neigh-1, strUDLRMap, playerType);
        }
    }
    else if (neigh == 4)
    {
        int total = strUDLRMap[0] + strUDLRMap[1] + strUDLRMap[2] + strUDLRMap[3];
        if (total <= 6)
        {
            return total;
        }
        else
        {
            maxComb(neigh-1, strUDLRMap, playerType);
        }
    }
}
