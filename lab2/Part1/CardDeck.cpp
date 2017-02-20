/*  CardDeck.cpp
 *  The class implementation for the CardDeck class
 *
 *  Marcus Schimizzi
 *  1/30/17
 */

#include "CardDeck.h"

CardDeck::CardDeck(int nCards)
{ 
  deck = new int [nCards];  
  for (int i = 0; i < nCards; i++) deck[i] = i;
  this->nCards = nCards;
}

CardDeck::~CardDeck()
{ delete [] deck;  }

int CardDeck::getSize()
{ return nCards; }

void CardDeck::shuffle()
{   
  int temp;
  for (int i = 0; i < nCards; i++) {
    int newIndex = rand() % nCards;
    temp = deck[i];
    deck[i] = deck[newIndex];
    deck[newIndex] = temp;
  }
}

ostream& operator<<(ostream& os, CardDeck& d)
{
  for (int i = 0; i < d.getSize(); i++) {
    os << d.deck[i] << ", ";     
  }
  cout << endl;
}
