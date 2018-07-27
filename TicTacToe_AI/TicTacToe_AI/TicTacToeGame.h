#pragma once
#include<iostream>
#include "Board.h"
using namespace std;

class TicTacToeGame
{
private:

	Board board;

public:
	
	TicTacToeGame();
	
	void PlayGame(); //Main method

	~TicTacToeGame();
};

