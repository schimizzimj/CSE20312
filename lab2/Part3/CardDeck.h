/*  CardDeck.h
 *  The interface for the CardDeck class, adjusted for the Blackjack game
 *
 *  Marcus Schimizzi
 *  1/30/17
 */

#ifndef CARDDECK_H
#define CARDDECK_H

#include <cstdlib>
#include<iostream>
using namespace std;

class CardDeck {

  public:
    CardDeck(int = 52);
    ~CardDeck();
    int getSize();
    void shuffle();
    int deal();
    void play();
    friend ostream& operator<<(ostream &, CardDeck &);
    int getUserWins();
    int getDealerWins();

  private:
    int * deck;
    int nCards;
    int dealCount, userHand, dealerHand, dealerWins, userWins;
};

#endif
