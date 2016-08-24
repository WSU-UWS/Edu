#include<iostream>
using namespace std;

class Player
{
    private:
        int xPos;
        int yPos;
        int type;
        string name;
    public:
        Player(string username, int player);
        void play();
        int getXPos();
        int getYPos();
        int getType();
};

