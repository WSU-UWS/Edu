class Board
{
    private:
        int maxRow;
        int maxCol;
    public:
        int getRow();
        int getCol();
        void init();
        void displayBoard();
        bool isValid(int userX, int userY);
        void placeInit(int userX, int userY, int type);
        void placeFinal(int userX, int userY, int type, int total);
        bool isFull();
        int pBoard[5][5];

};


