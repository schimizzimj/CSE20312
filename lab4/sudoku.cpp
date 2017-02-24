/* sudoku.cpp
 * Main driver file for the sudoku puzzle solving program
 *
 * Marcus Schimizzi
 * 2/13/17
 */

#include "Board.h"

int main( int argc, char *argv[] ) {

  if ( argc != 2) {
    // Display usage message if user does not supply proper amount of arguments
    cout << "usage: " << argv[0] << " <filename>\n";
    return 1;
  }else{
    Board b; // Instantiate an object of the Board class
    b.read(argv[1]); // Read in file and populate the Board object
    b.solve(); // Use elimination and singleton algorithms to solve the puzzle
    b.print(); // Output the solved puzzle 
    return 0;
  }
}
