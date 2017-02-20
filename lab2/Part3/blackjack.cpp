/*  blackjack.cpp
 *  Serves as the main program for the blackjack game
 *
 *  Marcus Schimizzi
 *  2/6/17
 */

#include <time.h>
#include "CardDeck.h"

int main() {
  srand(time(NULL));
  CardDeck deck;
  int keepPlaying = 1;
  while (keepPlaying) {
    deck.play();
    cout << "User wins: " << deck.getUserWins() << "    Dealer Wins: " << deck.getDealerWins() << endl;
    do { 
      cout << "Would you like to keep playing (1 for yes, 0 for no)?";
      cin >> keepPlaying;
    }while(keepPlaying != 0 && keepPlaying != 1);
  }
}
