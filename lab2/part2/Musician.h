/*  Musician.h
 *  Interface for base class of Musician
 *
 *  Marcus Schimizzi
 *  2/6/17
 */

#ifndef MUSICIAN_H
#define MUSICIAN_H

#include <string>

class Musician {

  public:

    Musician(string = "empty", string = "empty");

  virtual void sing() = 0;

  private:
  
    string Name;
    string Genre;

};

#endif
