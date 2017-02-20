/*  Marcus Schimizzi
 *  1/25/17
 *
 *  Class implementation for the C4Board class, represents the board for the Connect 4 
 *  game
 */

#include "C4Board.h"
#include <iostream>
using namespace std;

C4Board::C4Board(int columns)
{
  this->columns = columns;
  board = new C4Col [columns];
}

C4Board::~C4Board()
{ delete [] board; }

void C4Board::display()
{
  // Correctly displays current game board to user
  for (int i = board[0].getMaxDiscs(); i >= 0; i--) {
    // Iterate through rows backwards, so board is displayed properly
    for (int j = 0; j < columns; j++) {
      if (i == board[0].getMaxDiscs()) cout << " " << j << " "; 
        //Number columns in first row
      else cout << "|" << board[j].getDisc(i) << " ";
    }
    if (i != board[0].getMaxDiscs()) cout << "|" << endl;
    else cout << endl;
  }
}

void C4Board::play()
{
  int turn = 0;
  bool victory = false; // Victory condition
  while(!victory) {
    // Run program until one player wins
    display();
    int userCol; 
    int player = (turn % 2) + 1; // Keeps track of which player's turn it is
    bool flag = false;

    while(!flag) {  
      // Keeps asking for input until player enters a valid input
      cout << "Player " << player << ", which column would you like to place a disc in? ";
      cin >> userCol;
      if (userCol >= 0 && userCol < 7 && !(board[userCol].isFull()))
        flag = true;
      else
        cout << "Invalid input!\n\n";     
    }
    if (player == 1)
      board[userCol].addDisc('X');
    else
      board[userCol].addDisc('O');  

    turn++;

    if (checkWin(userCol)) {
      // Display congratulatory message and exit if player wins
      display();
      cout << "Congratulations! You won, Player " << player << "!\n";
      victory = true;
    }
  }
} 

bool C4Board::checkWin(int lastPlay)
{
  int lastRow = board[lastPlay].getNumDiscs() - 1;
  char lastChar = board[lastPlay].getDisc(lastRow);
  
  // Check vertical
  int consDiscs = 0;
  int row = lastRow;
  if (lastRow >= 3) {
    while(row >= 0 && board[lastPlay].getDisc(row) == lastChar) {
      consDiscs++;
      row--;  
    }
  }
  if (consDiscs >= 4) return true;

  // Check horizontal
  consDiscs = 1;
  int column = lastPlay;
  
  if (column > 0) column--;
  while(column >= 0 && board[column].getDisc(lastRow) == lastChar) {
    consDiscs++;
    column--;
  }

  column = lastPlay;
  if (column < 7) column++;
  while(column < 7 && board[column].getDisc(lastRow) == lastChar) {
    consDiscs++;
    column++;
  }

  if (consDiscs >= 4) return true;

  // Check Diagonals
  // Check for / diagonal
  consDiscs = 1;
  column = lastPlay;
  row = lastRow;
  
  if (column > 0 && row > 0) {
    column--; row--;
  }
  while(column >= 0 && row >= 0  && board[column].getDisc(row) == lastChar) {
    consDiscs++;
    column--; row--;
  }

  column = lastPlay; row = lastRow;
  if (column < 7 && row < 6) {
    column++; row++;
  }
  while(column < 7 && row < 6  && board[column].getDisc(row) == lastChar) {
    consDiscs++;
    column++; row++;
  }

  if (consDiscs >= 4) return true;

  // Check for \ diagonal
  consDiscs = 1;
  column = lastPlay;
  row = lastRow;
  
  if (column > 0 && row < 6) {
    column--; row++;
  }
  while(column >= 0 && row < 6  && board[column].getDisc(row) == lastChar) {
    consDiscs++;
    column--; row++;
  }

  column = lastPlay; row = lastRow;
  if (column < 7 && row >= 0) {
    column++; row--;
  }
  while(column < 7 && row >=0  && board[column].getDisc(row) == lastChar) {
    consDiscs++;
    column++; row--;
  }

  if (consDiscs >= 4) return true;
  else return false;
} 
