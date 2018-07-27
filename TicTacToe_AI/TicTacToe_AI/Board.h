#pragma once
#include<iostream>
using namespace std;

enum STATE{NO_VAL,X_VAL,O_VAL,DRAW_VAL}; //for winner and draw NO_VAL = game continue 

class Board
{
	friend class AI;
protected:
	char board[3][3];
	int size;
public:
	Board();
	void ClearBoard();
	void PrintBoard();
	int GetX();
	int GetY();
	bool PlaceSymbol(int, int, char);
	int Check();
	~Board();
};

