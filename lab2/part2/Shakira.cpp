/*  Shakira.cpp
 *  The implementation of the Shakira class
 *
 *  Marcus Schimizzi
 *  2/6/17
 */
  
using namespace std;

// base class pointer
Shakira::Shakira (string NameVal, string GenreVal) : Musician (NameVal, GenreVal) {
  

}

void Shakira::sing() {
  cout << "Musician name: " << Name << endl;
  cout << "Genre: " << Genre << endl;
  cout << "WAKA WAKA HEY HEY\n" << endl;

}
