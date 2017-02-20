/*  Musician.cpp
 *  The parent class for this inheritance example
 *
 *  Marcus Schimizzi
 *  2/6/17
 */
  
using namespace std;

// base class pointer
Musician::Musician (string NameVal, string GenreVal) {
  
  Name = NameVal;
  Genre = GenreVal;

}

void Musician::sing() {
  cout << "Musician name: " << Name << endl;
  cout << "Genre: " << Genre << endl;

}
