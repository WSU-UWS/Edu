#include<iostream>
using namespace std;
#include "Board.h"
#include "Player.h"
#include<cmath>
#include<algorithm>
//#include "GameRules.h"

void turn(Player test, Board &current); //prototype
int neighbours(int row, int col, Board current);
void optimumNumbers(int up, int down, int left, int right);

//void neighbours(int row, int col);

int main()
{
    Board board;
    board.init();
    Player human("god", 1);
    Player ai("peasant", 2);

    cout << endl;

    board.displayBoard();
    do
    {
        turn(human, board);
        turn(ai, board);
    }
    while (board.isFull() == false); //problem -> board may be complete but must prompt user 2 to play what do


    return 0;
}

void turn(Player test, Board &current)
{
    do
    {
        test.play();
        current.isValid(test.getXPos(), test.getYPos());
    }
    while (current.isValid(test.getXPos(), test.getYPos()) == false);
    current.placeInit(test.getXPos(), test.getYPos(), test.getType());
    int x = neighbours(test.getXPos(), test.getYPos(), current);
    current.placeFinal(test.getXPos(), test.getYPos(), test.getType(), x);
    current.displayBoard();
}

int neighbours(int row, int col, Board current)
{
    //calculates optimum capture and clears what is captured
    int neighbours = 0;
    int up = current.pBoard[row-1][col];
    int down = current.pBoard[row+1][col];
    int left = current.pBoard[row][col-1];
    int right = current.pBoard[row][col+1];

    if (row == 0)
    {
        up = 0;
    }

    if (row == current.getRow()-1)
    {
        down = 0;
    }

    if (col == 0)
    {
        left = 0;
    }

    if (col == current.getCol()-1)
    {
        right = 0;
    }

    optimumNumbers(up, down, left, right);
    /** plan
    * check addition of neigbours
    *if <= 6, clear neighbours and return
    * else check combinations of 2s and 3s
    * ignore any combinations greater than 6, return greatest combination <=6
    */
    neighbours = std::abs(up) + std::abs(down) + std::abs(left) + std::abs(right);

    cout << endl << "UP is " << up << " down is " <<  down << " left is " << left << " right is " << right << endl;
    //cout << endl << "neighbours = " << neighbours << endl;

    return neighbours;

}

void optimumNumbers(int up, int down, int left, int right)
{
    int test[4] = {std::abs(up), std::abs(down), std::abs(left), std::abs(right)};

    cout << "using these numbers, up, down, left, right " << test[0] << "," << test[1] <<"," << test[2] <<"," <<     test[3] <<  endl;
    do {
    cout << test[0] << ' ' << test[1] << ' ' << test[2] << ' ' << test[3] << '\n';
  } while ( std::next_permutation(test,test+4));



}
