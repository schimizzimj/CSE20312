// Sudoku.h
// Class interface for the Sudoku class, which represents the whole board
//
// Marcus Schimizzi
// 2/13/17

class Sudoku{

  public:
    Sudoku();
    ~Sudoku();
    print();
  private:
    vector< vector<Cell> > board;
}
