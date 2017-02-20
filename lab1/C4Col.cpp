/*  Marcus Schimizzi
 *  1/23/17
 *
 *  Class implementation for the C4Col class, which represents an individual column in
 *  a Connect Four game
 */

#include "C4Col.h"
#include <iostream>

using std::cout;

C4Col::C4Col()
{
  numDiscs = 0; maxDiscs = 6;
  Discs = new char [maxDiscs];
  for (int i = 0; i < 6; i++) Discs[i] = ' ';
}

C4Col::~C4Col()
{ delete [] Discs; }

int C4Col::isFull()
{
  if (numDiscs == maxDiscs) return 1;
  else return 0;
}

char C4Col::getDisc(int row)
{
  if (row >= 0 || row < 6) return Discs[row];
  else cout << "Input invalid. Please try again.";
}

int C4Col::getMaxDiscs()
{ return maxDiscs; }

int C4Col::getNumDiscs()
{ return numDiscs; }

void C4Col::addDisc(char newDisc)
{
  if (isFull()) cout << "The column is full. Please try another.\n";
  else Discs[numDiscs++] = newDisc;   
}
