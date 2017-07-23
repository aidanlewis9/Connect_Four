// Aidan Lewis
// C4Col.h

#ifndef C4Col_H
#define C4Col_H

class C4Col {
  public:
    C4Col(); // constructor
    C4Col(const C4Col &); // copy constructor
    ~C4Col(); // destructor
  // member functions
    int isFull();
    char getDisc(int);
    int getMaxDiscs();
    void addDisc(char);
    int getNumDiscs();
 // private variables 
  private:
    int numDiscs;
    int maxDiscs;
    char * Discs;
};

#endif
