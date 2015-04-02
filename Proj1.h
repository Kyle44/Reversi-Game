// File: Proj1.h

#ifndef PROJ1_H
#define PROJ1_H

#include <string>

using namespace std;

class Uno {
 public:
  // Constructor for an Uno class
  Uno() ;
  
  // input: Who's turn it is
  // output: Next person's turn
  char WhosTurn(char playerSymbol);

  // input: Who's turn it is, and the addresses to 2 integers
  // output: The player's move choice passes back to main()
  void GetNextMove(char &playerSymbol, int &row, int &col);
 private:

};


#endif
