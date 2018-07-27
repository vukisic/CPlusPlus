#pragma once
#include<iostream>
#include "Board.h"
using namespace std;

struct AIMove {
	AIMove(){}
	AIMove(int s) { score = s; }
	int x;
	int y;
	int score;
};


class AI
{
private:
	char AIPlayer;
	char HPlayer;
private:
	AIMove GetBestMove(Board&, char);
public:
	AI();
	void init(char);
	void PerformMove(Board&);
	~AI();
};

