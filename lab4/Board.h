// Board.h
// Interface for the Board class, which represents the board for a sudoku
// game
//
// Marcus Schimizzi
// 2/13/17

class Board{

  public:
    Board();
    ~Board();
    print();

  private:
    int actual_board[9][9];
    bool possible_board[9][9][9];

};
