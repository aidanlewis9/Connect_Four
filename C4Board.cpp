// Aidan Lewis
// C4Board.cpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "C4Board.h"
#include "C4Col.h"
using namespace std;

// constructor
C4Board::C4Board()
{
  numCols = 7;
  Board = new C4Col[numCols];
}

C4Board::C4Board(const C4Board &boardtoCopy) : numCols(boardtoCopy.numCols) {
  
  Board = new C4Col[numCols];
  for (int i = 0; i < numCols; i++) {
    Board[i] = boardtoCopy.Board[i];
  }
}

// destructor
C4Board::~C4Board()
{ 
  delete [] Board;
}

// displays entire board
void C4Board::display()
{
// set column numbers
  for (int col = 1; col <= numCols; col++) {
    cout << col << "   ";
  }
  cout << endl;
// print out the contents of every disc in every column
  for (int i = Board[0].getMaxDiscs() - 1; i >= 0; i--) {
    for (int j = 0; j < numCols; j++) {
      cout << Board[j].getDisc(i) << " | ";
    }
    cout << endl;
  }
  cout << endl;
}

void C4Board::play(int choice)
{
  int turn = 0;
  int colChoice, win;
  while (true) {
    display(); // display board
    cout << "Player " << (turn % 2) + 1 << ": In which column would you like a disc? (Or input -1 to end the game)" << endl; // ask user for input
    if (choice == 1 || ((turn % 2) + 1) == 1) { // if playing against human or human's turn
      cin >> colChoice; // user inputs choice
    }
    else { // if playing against computer
      srand(time(NULL)+turn); // set seed for random number
      colChoice = rand() % 7 + 1; // randomly pick column
      usleep(1000000); // pause for 1 second 
    }
    if (colChoice == -1) break; // if the user chose to quit
    char player = (((turn % 2) + 1) < 2) ? 'X' : 'O'; // determines whether char is X or O
    if (colChoice > 0 && colChoice <= numCols) {
	int colIndex = colChoice - 1;
    	Board[colIndex].addDisc(player); // add disc to chosen row
	int lastDisc = Board[colIndex].getNumDiscs() - 1;
	win = check(colIndex, lastDisc, player); // check if there's a winner
    	turn++; // increment turn
    }
    else {
    	cout << "Invalid input. Please try again." << endl;
    }
    if (win == 1) { // if there is a winner
      display();
      cout << "Player " << ((turn-1) % 2) + 1 << " wins!" << endl << endl;
      break;
    }
  }
}

// checks for 4 in a row
int C4Board::check(int colIndex, int lastDisc, char player) 
{
  int count = 0;
  // check horizontally
  for (int i = 0; i < numCols; i++) {
    if (Board[i].getDisc(lastDisc) == player) {
      count++; // increment if character is same as the last character
    }
    else { // if the character is different, reset count
      count = 0;
    }
    if (count == 4) return 1; // if four in a row, there is a winner
  }
  count = 0;
  // check vertically
  for (int i = 0; i < Board[0].getMaxDiscs(); i++) {
    if (Board[colIndex].getDisc(i) == player) {
      count++;
    }
    else {
      count = 0;
    }
    if (count == 4) return 1;
  }
  count = 0;
  int startRow = lastDisc;
  int startCol = colIndex;
  // check diagonally (bottom-left to top-right)
  while (startRow != 0 && startCol != 0) { // to determine bottom-left
    startCol--, startRow--;
  }
  while (startRow <= 5 && startCol <= 6) {
    if (Board[startCol].getDisc(startRow) == player) {
      count++;
    }
    else {
      count = 0;
    }
    startCol++, startRow++;
    if (count == 4) return 1;
  }
  count = 0;
  startRow = lastDisc;
  startCol = colIndex;
  // check diagonally (top-left to bottom-right)
  while (startRow != 5 && startCol != 0) {
    startCol--, startRow++; // to determine top-left
  }
  while (startRow >= 0 && startCol <= 6) {
    if (Board[startCol].getDisc(startRow) == player) {
      count++;
    }
    else {
      count = 0;
    }
    startCol++, startRow--;
    if (count == 4) return 1;
  }
  return 0;
}
  
