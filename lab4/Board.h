// Board.h
// Interface for the Board class, which represents the board for a sudoku
// game
//
// Marcus Schimizzi
// 2/13/17

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Board{

  public:
    Board(); // Class constructor
    ~Board(); // Class deconstructor
    void read(string); // Takes sudoku puzzle from file given and uses it to populate the boards 
    void update(int input, int row, int column); // Updates possible values board after a new actual value is entered
    void solve(); // Uses elimination and singleton algorithms to solve the puzzles
    void print(); // Properly displays puzzles to the user
    void print_possible(); // Used in order to view all of the layers of the possible values board

  private:
    int actual_board[9][9]; // 2D array used to store the actual sudoku board
    bool possible_board[9][9][9]; // 3D array used to store the possible values of every space on the board

};

#endif
