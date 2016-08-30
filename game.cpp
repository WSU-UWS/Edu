#include<iostream>
using namespace std;
#include "GameRules.h"

void turn(Player test, Board &current, GameRules rules);

int main()
{

    GameRules rules;
    Board board;
    board.init();
    Player human("god", 1);
    Player ai("peasant", 2);

    cout << endl;

    board.displayBoard();
    do
    {
        turn(human, board, rules);
        turn(ai, board, rules);
    }
    while (board.isFull() == false); //problem -> board may be complete but must prompt user 2 to play what do


    return 0;
}

void turn(Player test, Board &current, GameRules rules)
{
    int UDLR[4] = {0, 0, 0, 0};
    string strUDLR[4];
    do
    {
        test.play();
        current.isValid(test.getXPos(), test.getYPos());
    }
    while (current.isValid(test.getXPos(), test.getYPos()) == false);
    current.placeInit(test.getXPos(), test.getYPos(), test.getType());
    int x = rules.neighbours(test.getXPos(), test.getYPos(), current, UDLR);
    int y = rules.countNeigh(UDLR);
    int z = rules.maxComb(y, UDLR, test.getType());
    //int z = rules.maxResult(UDLR, y, test.getType(), strUDLR);
    current.placeFinal(test.getXPos(), test.getYPos(), test.getType(), z);
    current.displayBoard();
}

