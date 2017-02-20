/*  CardDeck.h
 *  The interface for the CardDeck class
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
    friend ostream& operator<<(ostream &, CardDeck &);

  private:
    int * deck;
    int nCards;
};

#endif
