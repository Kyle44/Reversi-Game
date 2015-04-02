/*****************************************
 ** File:    Proj1.cpp
 ** Project: CMSC 202 Project 1
 ** Author:  Kyle Fritz
 ** Date:    3/6/2014
 ** Lecture Section: 7208 (16)
 ** Discussion Section: 7210 (18)
 ** E-mail:  fritzk1@umbc.edu 
 **
 **   This file contains the main driver program for Project 1.
 ** This program reads the file specified as the first command line
 ** argument, which determines the size of the board.  You can then
 ** play some Reversi.
 **
 ***********************************************/


#include <iostream>
#include <stdlib.h> // Library for atoi

#include "Proj1.h"

using namespace std;

const int MIN_SIZE = 4;
const int MAX_SIZE = 10;


int main(int argc, char *argv[]) {

  int size = atoi(argv[1]);
  // Makes sure that argument fits the constraints
  if(size > MAX_SIZE || size < MIN_SIZE || size % 2 != 0){
    cout << "The board doesn't fit the constraints." << endl;
    return 0;
  }

  cout << "Welcome to Reversi!" << endl;

  char board[size][size];

  int i;
  int j;

  // Makes the board
  for (i = 0; i < size; i++)
    for (j = 0; j < size; j++)
      board[i][j] = '-';

  // Object for class "Uno"
  Uno One;

  // Variable for number of moves
  int k;

  // Variables for player's move
  int x;
  int y;

  char player = 'X';

  // For loop long enough for entire board
  for (k = 0; k < size * size; k++){

    cout << "Player " << player << "'s move: ";

    // Gets the player's move
    One.GetNextMove(player, y, x);

    // Makes sure that the move can be made on the board
    // While loop if move already on board, then not on board at all
    while (board[x - 1][y - 1] == 'X' || board[x - 1][y - 1] == 'O'){
      cout << x << " " << y << " has already been played!" << endl;
      cout << "Player " << player << "'s move: ";
      cin >> x >> y;
      while (x > size || y > size || x < 1 || y < 1){
	cout << x << " " << y << " is not on the board!" << endl;
	cout << "Player " << player << "'s move: ";
	cin >> x >> y;
      }
    }

    // While loop if move not on board, then already on board
    while (x > size || y > size || x < 1 || y < 1){
      cout << x << " " << y << " is not on the board!" << endl;
       cout << "Player " << player << "'s move: ";
       cin >> x >> y;
       while (board[x - 1][y - 1] == 'X' || board[x - 1][y - 1] == 'O'){
	 cout << x << " " << y << " has already been played!" << endl;
	 cout << "Player " << player << "'s move: ";
	 cin >> x >> y;	 
       }
    }
    
    // Places correct symbol on correct space on board
    board[x - 1][y - 1] = player;

    // Reversi to check downward
    int x2 = x;
    if (x2 < size)
      while (board[x2][y - 1] != '-' and board[x2][y - 1] != player){
	x2++;
      }
    int x2Actual;
    if (x2 <= size and board[x2][y - 1] == player)
      for (x2Actual = x2; x2Actual >= x; x2Actual--){
	board[x2Actual][y - 1] = player;
      }

    // Reversi to check upward
    int x3 = x - 2;
    if (x3 > 0)
      while (board[x3][y - 1] != '-' and board[x3][y - 1] != player and x3 > 0)
	x3--;
    int x3Actual;
    if (board[x3][y - 1] == player)
      for (x3Actual = x3; x3Actual < x; x3Actual++)
        board[x3Actual][y - 1] = player;

    // Reversi to check the right
    int y2 = y;
    if (y2 < size)
      while (board[x - 1][y2] != '-' and board[x - 1][y2] != player)
	y2++;
    int y2Actual;
    if (y2 <= size and board[x - 1][y2] == player)
      for (y2Actual = y2; y2Actual >= y; y2Actual--)
        board[x - 1][y2Actual] = player;

    // Reversi to check the left
    int y3 = y - 2;
    if (y3 > 0)
      while (board[x - 1][y3] != '-' and board[x - 1][y3] != player and y3 > 0)
	y3--;
    int y3Actual;
    if (board[x - 1][y3] == player)
      for (y3Actual = y3; y3Actual < y; y3Actual++)
        board[x - 1][y3Actual] = player;
    

    // Prints the board after move
    for (i = 0; i < size; i++){
      for (j = 0; j < size; j++)
	cout << board[i][j];
      cout << endl;
    }
    // Switches who's turn it is
    player = One.WhosTurn(player);
  }
  int xTotal = 0;
  int oTotal = 0;
  // Counts the X's and O's
  for (i = 0; i < size; i++){
    for (j = 0; j < size; j++){
      if (board[i][j] == 'X')
	xTotal += 1;
      else
	oTotal += 1;
    }
  }
  
  // Determines who wins
  cout << "Player X controls " << xTotal << " squares." << endl;
  cout << "Player O controls " << oTotal << " squares." << endl;
  if (xTotal > oTotal)
    cout << "Player X wins!" << endl;
  else
    cout << "Player O wins!" << endl;
  
  return 0;
  
}
