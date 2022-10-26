#include <iostream>

struct Tile {
    bool isMine_;
    int state_;
    Tile();
};

class Board {
    public:
        Board(Board const& other);
        Board(int rows, int cols, int mines);
        ~Board();
        void generateMines(int row, int col);
        void dig(int row, int col);
        void flag(int row, int col);
        void action(int action, int row, int col);
        void printBoard();
        int** getOutput();
        int getRows();
        int getCols();
        int gameContinue();
        void newGame();
    
    private:
        bool dead_;
        int rows_;
        int cols_;
        int mines_;
        
        Tile** field_; //tracks locations of mines, number of surrounding mines
        int** output_; // tracks current game state of each tile (undiscovered, flagged, cleared)
        //output_ will be provided through a public member function to allow solver to interact with board without accessing mine locations
        
        int digs_;

        bool isMine(int row, int col);
        bool inBounds(int row, int col);
        bool isFlagged(int row, int col);
        bool checkValidMine(int row, int col);
        int neighbor_count(int row, int col);

        void revealMines();
};