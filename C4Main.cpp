// Aidan Lewis
// C4Main.cpp

#include <iostream>

#include "C4Board.h" // class definition for C4Board below
using namespace std;

int main() {
  C4Board c4; // instantiate an instance of a C4Board object 
  int choice;
  while (choice != 1 && choice != 2) { // lets user choose opponent
    cout << "To play another player, input 1. To play the computer, input 2:" << endl;
    cin >> choice; // user inputs choice
  }
  // play game
  c4.play(choice);
}
