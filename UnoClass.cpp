// UnoClass.cpp

#include <iostream>
#include "Proj1.h"

Uno::Uno()
{

}



char Uno::WhosTurn(char playerSymbol)
{
  if (playerSymbol == 'X')
    playerSymbol = 'O';
  else 
    playerSymbol = 'X';
  return playerSymbol;
	 
}

void Uno::GetNextMove(char &playerSymbol, int &row, int &col)
{
  cin >> col >> row;
}
