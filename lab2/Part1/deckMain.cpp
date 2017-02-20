/*  deckMain.cpp
 *  Main/driver file for the CardDeck class
 *
 *  Marcus Schimizzi
 *  1/30/17
 */

#include <iostream>
#include <cstdlib>
#include<time.h>
using namespace std;

#include "CardDeck.h"

int main() {
  srand(time(NULL));
  
  CardDeck Deck(10);
  cout << "Unshuffled: \n" << Deck << "\n";
  Deck.shuffle();
  cout << "Shuffled: \n" << Deck << "\n";
}
