/*  Shakira.h
 *  Interface for Shakira class
 *
 *  Marcus Schimizzi
 *  2/6/17
 */

#ifndef SHAKIRA_H
#define SHAKIRA_H

#include <string>
#include "Musician.h"

class Shakira : public Musician {

  public:

    Shakira(string = "Shakira", string = "Pop");
    virtual void sing();

};

#endif
