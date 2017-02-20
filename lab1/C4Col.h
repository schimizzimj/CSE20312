/* Marcus Schimizzi
   1/23/17

   Class interface for the C4Col class, represents a column in a Connect Four game
*/

#ifndef C4COL_H
#define C4COL_H

class C4Col {

 public:
  
  C4Col();
  ~C4Col();   
  int isFull();
  char getDisc(int);
  int getMaxDiscs();
  int getNumDiscs();
  void addDisc(char);

 private: 

  int numDiscs;
  int maxDiscs;
  char * Discs;
}; 

#endif
