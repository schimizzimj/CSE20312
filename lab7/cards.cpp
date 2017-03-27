/* 
 * cards.cpp
 * This file reads in a list of cardholders and the cards they have and then * outputs the names of these card holders in the order of highest card to 
 * lowest card.
 *
 * Marcus Schimizzi
 * 3/20/17
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct cardholder {
  // Struct to represent a person and their card
  string name;
  char rank;
  char suit; 
};

bool sortMain(const cardholder &h1, const cardholder &h2); // top level sorting function
int sortRank(char r1, char r2); // sorts cards by their rank
bool sortSuit(char s1, char s2); // sort cards by their suit

int main() {
  int nCards;
  cin >> nCards;
  while (nCards != -1) {
    // Run while loop until -1 signifies no more groups of people
    vector<cardholder> hand;
    for (int i = 0; i < nCards; i++) {
      cardholder player;
      string rank, name;
      char suit;
      cin >> name;
      player.name = name;
      cin >> rank;
      if (rank == "10") player.rank = ':'; // An input of 10 would not fit into a char, so instead store a 10 as ':', which equals ten when subtracting '0'
      else player.rank = rank[0];
      cin >> suit;
      player.suit = suit;
      
      // Sorting function, felt like making my own
      if ( i == 0 ) hand.push_back(player); // places first player's hand
      else if(sortMain(hand.back(), player)) hand.push_back(player); // deals with special case of back of vector to eliminate seg faults
      else {
        // Iterate to the proper place in the vector and insert the player's card
        auto it = hand.begin();
        while(sortMain(*it, player)){
          it++;
        }
        hand.insert(it, player);
      }
    }
    for (int i = 0; i < nCards; i++) {
      cout << hand[i].name;
      if (i != nCards - 1) cout << ", ";
    } // print out the sorted names of the players in the round
    cout << endl;
    cin >> nCards;
  }
}

bool sortMain(const cardholder &hand1, const cardholder &hand2) {
  // Ties sortRank and sortSuit together, first sorting by rank and then sorting by suit if two cards have the same rank
  int s = sortRank(hand1.rank, hand2.rank);
  switch (s){
    case 0: return false;
      break;
    case 1: return true;
      break;
    case 2: return sortSuit(hand1.suit, hand2.suit); // ranks are equal, sort by suit
      break;
    default: cout << "Something went wrong..." << endl;
      return 3; // Default case that indicates something went horribly wrong, s should never be anything but 0, 1, or 2
      break;
  }
}

int sortRank(char rank1, char rank2) {
  // Create sorting lookup table
  char sort_param[4] = {'J','Q','K','A'};
  int sort_val[4] = {11, 12, 13, 14};
  int val1, val2; 
  
  if (rank1 <= 58) val1 = rank1 - '0'; // if rank is a number already, simply set it
  else for (int i = 0; i < 4; i++){
    // else, check for the value in the lookup table, and set value base on this
    if (rank1 == sort_param[i]) val1 = sort_val[i];
  }
 
  if (rank2 <= 58) val2 = rank2 - '0';
  else for (int i = 0; i < 4; i++){
    if (rank2 == sort_param[i]) val2 = sort_val[i];
  }
  
  if (val1 > val2) return 1; // hand 1 is in proper spot
  else if (val2 > val1) return 0; // hands must be switched
  else return 2; // ranks are equal, further comparison necessary
}

bool sortSuit(char suit1, char suit2) {
  // Create lookup table for suits
  char sort_param[2][4] = { {'C','D','H','S'}, {'1','2','3','4'} };
  int val1, val2;
  
  for(int i = 0; i < 4; i++) {
    // look for suit value in lookup table, set corresponding value
    if (suit1 == sort_param[0][i]) val1 = sort_param[1][i] - '0';
    if (suit2 == sort_param[0][i]) val2 = sort_param[1][i] - '0';
  }
  
  if (val1 > val2) return true;
  else return false;
}
