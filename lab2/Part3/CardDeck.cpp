/*  CardDeck.cpp
 *  The class implementation for the CardDeck class, adjusted to better suit the Blackjack
 *  game
 *
 *  Marcus Schimizzi
 *  2/6/17
 */

#include "CardDeck.h"

CardDeck::CardDeck(int nCards)
{ 
  deck = new int [nCards];  
  for (int i = 0; i < nCards; i++) deck[i] = i;
  this->nCards = nCards;
  dealCount = 0; userHand = 0; dealerHand = 0; userWins = 0; dealerWins = 0;
  shuffle();
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

int CardDeck::deal()
{
  int cardChoice;
  cardChoice = deck[dealCount] % 12;
  dealCount++;
  if (nCards - dealCount <= 15) {
    delete [] deck;
    deck = new int [nCards];
    for (int i = 0; i < nCards; i++) deck[i] = 1;
    dealCount = 0;
    shuffle();
  } 
  if (cardChoice == 0) return 11;
  else if (cardChoice >= 10) return 10;
  else return cardChoice+1;
}

void CardDeck::play()
{
  int choice = -1;
  dealerHand += deal() + deal();
  userHand += deal() + deal();
  while (dealerHand < 17) dealerHand += deal();
  
  while (choice != 0) {
    cout << "Your current hand is: " << userHand << "\nEnter 1 for hit or 0 for stand: ";
    cin >> choice;
    if (choice != 0 && choice != 1) cout << "Please enter a valid input.";
    if (choice == 1) userHand += deal();
    if (userHand >= 21) choice = 0;
  } 
  
  cout << "You have: " << userHand << "   Dealer has: " << dealerHand << "\n\n";
 
  if ((userHand > dealerHand | dealerHand > 21) && userHand <= 21) {
    userWins++;
    cout << "You win!\n";
  } else {
    dealerWins++;
    cout << "The dealer wins.\n";
  }
  dealerHand = 0; userHand = 0;
}

ostream& operator<<(ostream& os, CardDeck& d)
{
  for (int i = 0; i < d.getSize(); i++) {
    os << d.deck[i] << ", ";     
  }
  cout << endl;
}

int CardDeck::getUserWins()
{ return userWins; }

int CardDeck::getDealerWins()
{ return dealerWins; }
