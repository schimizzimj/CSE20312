// Board.cpp
// Implementation for the Board class, used to represent the sudoku board
// and possible values for the empty spaces
//
// Marcus Schimizzi
// 2/13/17

#include "Board.h"

Board::Board()
{ // Constructor, initialize the two arrays
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      actual_board[i][j] = 0; // Initialize the actual board with all zeros
      for (int k = 0; k < 9; k++) possible_board[i][j][k] = true; // Initialize all of the possible board with trues
    }
  }
}

Board::~Board()
{ } // Default deconstructor

void Board::read(string file)
{ // Read in the given file, use it to populate the arrays
  char input;
  int count = 0, line = 0, int_input;
  fstream ifs (file);
  if (ifs.is_open())
  {
    while ( ifs >> input ) // Read in the input until there is no more input
    {
      int_input = input - '0'; // Convert inputted char to an int
      actual_board[line][count] = int_input; // Set values of actual board based on input    
      update(int_input, line, count); // Update the possible values board
      count++;
      if ( count == 9 ) { // For every 9 inputs, go down to the next line
        count = 0; // Reset counter
        line++;
      }  
    }
    ifs.close();
  }else cout << "Unable to open file"; 
}

void Board::update(int input, int row, int column) {
  if (input != 0){
    for (int i = 0; i < 9; i++) {  
      // Set all of the row, column, and values 1-9 to false, except for the current spot on the board
      if (i != column) possible_board[input - 1][row][i] = false; 
      if (i != row) possible_board[input - 1][i][column] = false;
      if (i != input - 1) possible_board[i][row][column] = false;
    } 
    if (column < 3) { 
      // Set all values in the minigrid of the current input to zero

      if (row < 3) {
        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) possible_board[input - 1][j][i] = false;
        }
      }else if (row > 5) {
        for (int i = 0; i < 3; i++) {
          for (int j = 6; j < 9; j++) possible_board[input - 1][j][i] = false;
        }
      }else{
        for (int i = 0; i < 3; i++) {
          for (int j = 3; j < 6; j++) possible_board[input - 1][j][i] = false;
        }
      }
    }else if (column > 5) {
      if (row < 3) {
        for (int i = 6; i < 9; i++) {
          for (int j = 0; j < 3; j++) possible_board[input - 1][j][i] = false;
        }
      }else if (row > 5) {
        for (int i = 6; i < 9; i++) {
          for (int j = 6; j < 9; j++) possible_board[input - 1][j][i] = false;
        }
      }else{
        for (int i = 6; i < 9; i++) {
          for (int j = 3; j < 6; j++) possible_board[input - 1][j][i] = false;
        }
      }
    }else{
      if (row < 3) {
        for (int i = 3; i < 6; i++) {
          for (int j = 0; j < 3; j++) possible_board[input - 1][j][i] = false;
        }
      }else if (row > 5) {
        for (int i = 3; i < 6; i++) {
          for (int j = 6; j < 9; j++) possible_board[input - 1][j][i] = false;
        }
      }else{
        for (int i = 3; i < 6; i++) {
          for (int j = 3; j < 6; j++) possible_board[input - 1][j][i] = false;
        }
      }
    }
    possible_board[input - 1][row][column] = true; 
      // After setting all values in the grid to zero, reset the correct spot to true  
  }
}

void Board::solve()
{
  bool solved = false;
  while (!solved) {    
    solved = true; // Set flag   
 
    // Elimination method
    int value, count, changes = 1;
    while (changes != 0){
      changes = 0; // Reset changes variable
      for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
          if (actual_board[i][j] == 0) {
            // Loop through non-zero board entries, check if cell has only one possible value 
            count = 0;
            for (int k = 0; k < 9; k++) {
              if (possible_board[k][i][j] == 1) {
                count++;
                value = k + 1;
              }
            }
            if (count == 1) {
              // Set actual board value and update the board if there is only one value possible
              actual_board[i][j] = value;
              update(value, i, j);
              changes++;
            }
          }
        }
      }
    }

    // Singleton Method
    bool v_allzero = true, h_allzero = true, g_allzero = true;
    changes = 1;
    while (changes != 0) { // Loop until no more changes are made
      changes = 0;
      for (int w = 0; w < 9; w++) {
        for (int x = 0; x < 9; x++) {
          if (actual_board[w][x] == 0) {
            for (int y = 0; y < 9; y++) {
              // Vertical and horizontal
              for (int z = 0; z < 9; z++) {
                if (possible_board[y][w][z] == 1 && z != x) h_allzero = false;
                if (possible_board[y][z][x] == 1 && z != w) v_allzero = false;
              }
              // Minigrids
              /*if (w < 3) {
                if (x < 3) {
                  for (int a = 0; a < 3; a++) {
                    for (int b = 0; b < 3; b++) {
                      if (possible_board[y][a][b] == 1 && (a != w && b != x)) g_allzero = false;
                    }
                  }
                }else if (x > 5) {
                  for (int a = 0; a < 3; a++) {
                    for (int b = 6; b < 9; b++) {
                      if (possible_board[y][a][b] == 1 && (a != w && b != x)) g_allzero = false;
                    }
                  }
                }else{
                  for (int a = 0; a < 3; a++) {
                    for (int b = 3; b < 6; b++) {
                      if (possible_board[y][a][b] == 1 && (a != w && b != x)) g_allzero = false;
                    }
                  }
                }
              }else if (w > 5) {
                if (x < 3) {
                  for (int a = 6; a < 9; a++) {
                    for (int b = 0; b < 3; b++) {
                      if (possible_board[y][a][b] == 1 && (a != w && b != x)) g_allzero = false;
                    }
                  }
                }else if (x > 5) {
                  for (int a = 6; a < 9; a++) {
                    for (int b = 6; b < 9; b++) {
                      if (possible_board[y][a][b] == 1 && (a != w && b != x)) g_allzero = false;
                    }
                  }
                }else{
                  for (int a = 6; a < 9; a++) {
                    for (int b = 3; b < 6; b++) {
                      if (possible_board[y][a][b] == 1 && (a != w && b != x)) g_allzero = false;
                    }
                  }
                }
              }else{
                if (x < 3) {
                  for (int a = 3; a < 6; a++) {
                    for (int b = 0; b < 3; b++) {
                      if (possible_board[y][a][b] == 1 && (a != w && b != x)) g_allzero = false;
                    }
                  }
                }else if (x > 5) {
                  for (int a = 3; a < 6; a++) {
                    for (int b = 6; b < 9; b++) {
                      if (possible_board[y][a][b] == 1 && (a != w && b != x)) g_allzero = false;
                    }
                  }
                }else{
                  for (int a = 3; a < 6; a++) {
                    for (int b = 3; b < 6; b++) {
                      if (possible_board[y][a][b] == 1 && (a != w && b != x)) g_allzero = false;
                    }
                  }
                }
              } Minigrids section not working, but it isn't needed to solve given puzzles */
              if (h_allzero == true | v_allzero == true) {
                actual_board[w][x] = y+1;
                update(y+1, w, x);
                changes++;
              }
              h_allzero = true; v_allzero = true; //g_allzero = true;
            }
          }
        }
      }
    }

    //Check if puzzle is solved
    for(int m = 0; m < 9; m++) {
      for (int n = 0; n < 9; n++) if (actual_board[m][n] == 0) solved = false;
    }
  }
}

void Board::print()
{
  // Loop through board of actual values and print them out
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) cout << actual_board[i][j] << " ";
  cout << endl;
  }
}

void Board::print_possible()
{
  // Prints one grid for each layer, representing values 1-9, labeling each
  for (int i = 0; i < 9; i++) {
    cout << "\nBoard for number: " << i+1 << "\n\n";
    for (int j = 0; j < 9; j++) {
      for (int k = 0; k < 9; k++) {
        cout << possible_board[i][j][k] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }  
}
