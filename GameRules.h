#include<iostream>
#include "Board.h"
#include "Player.h"
#include<cmath>
#include<algorithm>

using namespace std;

class GameRules
{
public:
    int neighbours(int row, int col, Board current, int UDLR[4]);
    int removeNeigh(int row, int col, Board current, int neigh);
    int countNeigh(int UDLR[4]);
    int maxResult(int UDLR[4], int neigh, int playerType, string strUDLR[]);
    int maxComb(int neigh, int UDLR[4], int playerType);
};
