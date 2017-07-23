// Aidan Lewis
// C4Col.h
#include <iostream>
#include "C4Col.h"
using namespace std;

C4Col::C4Col() // default constructor
{
  numDiscs = 0;
  maxDiscs = 6;
  Discs = new char[maxDiscs];
  // each slot is initially empty
  for (int i = 0; i < maxDiscs; i++) {
    Discs[i] = ' ';
  }

}

C4Col::C4Col(const C4Col &columntoCopy) : maxDiscs(columntoCopy.maxDiscs) // copy constructor
{
  Discs = new char[maxDiscs];
  
  for (int i = 0; i < maxDiscs; i++) {
    Discs[i] = columntoCopy.Discs[i];
  }
}

C4Col::~C4Col() // destructor
{
  delete [] Discs;
}

// member functions

int C4Col::isFull()
{
  if (numDiscs == maxDiscs) {
    return 1; // if the column is full
  } else {
    return 0; // if not full
  }
}

char C4Col::getDisc(int disc)
{
  if ((disc < getMaxDiscs()) && (disc >= 0)) {
    return Discs[disc]; // return X, O, or blank space
  } else { // in case of invalid input
    cout << "Error. The disc number is invalid." << endl;
    return ' ';
  }
}

int C4Col::getMaxDiscs()
{
  return maxDiscs;
}

void C4Col::addDisc(char newDisc)
{
  if (!isFull()) { // if the column is not full
    Discs[numDiscs++] = newDisc; // add a new disc
  } else {
    cout << "The column is full. You lose your turn." << endl;
  }
}

int C4Col::getNumDiscs()
{
  return numDiscs; // returns current number of discs
}


