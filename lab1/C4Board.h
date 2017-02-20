/*  Marcus Schimizzi
 *  1/23/17
 *
 *  Class interface for the C4Board class, represents the entire Connect 4 board
 */

#ifndef C4BOARD_H
#define C4BOARD_H
#include "C4Col.h"

class C4Board {

  public:
    C4Board(int = 7);
    ~C4Board();
    void display();
    void play();

  private:
    int columns;
    C4Col * board;
    bool checkWin(int);
}; 

#endif
