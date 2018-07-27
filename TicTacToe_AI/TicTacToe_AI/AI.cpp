#include "AI.h"
#include<vector>


AIMove AI::GetBestMove(Board& board, char player)
{
	int end = board.Check();

	//Only for checking
	int ai = AIPlayer == 'X' ? (1) : 2;
	int human = HPlayer == 'X' ? (1) : 2;

	//Base case , check for end 
	if (end == ai) 
	{
		return AIMove(10);
	}
	else if (end == human) 
	{
		return AIMove(-10);
	}
	else if (end == DRAW_VAL)
	{
		return AIMove(0);
	}

	//Possible moves with scores
	vector<AIMove> moves;

	//MINMAX Algorithm
	for (int y = 0; y < board.size; ++y) {
		for (int x = 0; x < board.size; ++x) {
			if (board.board[x][y] == ' ') {
				AIMove move;
				move.x = x;
				move.y = y;
				//Try to place symbol and calculate score for that move
				board.PlaceSymbol(x, y, player);

				if (player == AIPlayer) 
				{
					//For AI player
					move.score = GetBestMove(board, HPlayer).score;
				}
				else
				{
					//For Human palyer
					move.score = GetBestMove(board, AIPlayer).score;
				}

				moves.push_back(move);

				board.board[x][y] = ' ';
			}
		}
	}

	//Pick best move for current player
	int BestMoveIndex = 0;
	if (player == AIPlayer) 
	{
		//AI PLAYER
		int BestScore = -10000;
		for (int i = 0; i < moves.size(); ++i) {
			if (moves[i].score > BestScore) {
				BestMoveIndex = i;
				BestScore = moves[i].score;
			}
		}
	}
	else
	{
		//HUMAN PLAYER
		int BestScore = 10000;
		for (int i = 0; i < moves.size(); ++i) {
			if (moves[i].score < BestScore) {
				BestMoveIndex = i;
				BestScore = moves[i].score;
			}
		}
	}

	return moves[BestMoveIndex];
}

AI::AI()
{
}

void AI::init(char aiplayer)
{
	AIPlayer = aiplayer;
	if (AIPlayer == 'X')
		HPlayer = 'O';
	else
		HPlayer = 'X';
}

void AI::PerformMove(Board& board)
{
	AIMove best = GetBestMove(board, AIPlayer);
	//Place best possible move on table
	board.PlaceSymbol(best.x, best.y, AIPlayer);
}

AI::~AI()
{
}
