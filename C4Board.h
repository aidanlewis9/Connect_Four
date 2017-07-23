// Aidan Lewis
// C4Board.h

#ifndef C4Board_H
#define C4Board_H

#include "C4Col.h" // include C4Col class

class C4Board {
  public:
    C4Board(); // constructor
    C4Board(const C4Board &); // copy constructor
    ~C4Board(); // destructor
    void display();
    void play(int);
 
 // private variables/member functions 
  private:
    int numCols;
    C4Col * Board;
    int check(int, int, char);

};

#endif
