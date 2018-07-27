#include "TicTacToeGame.h"
#include"AI.h"


TicTacToeGame::TicTacToeGame()
{
	board.ClearBoard();
}



void TicTacToeGame::PlayGame() 
{
	char Player1 = 'X';
	char Player2 = 'O';
	char CurrPlayer='X';
	bool EndGame = false;
	int x = 0, y = 0;
	AI ap;
	ap.init(Player2); //AI symbol is 'O'
	bool SinglePlayer = true;
	char op = ' ';

	cout << "Multiplayer or Singleplayer?[M/S]?" << endl;
	cout << ">>";
	cin >> op;

	if (op == 'm' || op == 'M')
		SinglePlayer = false;
	

	while (EndGame==false) 
	{
		if (SinglePlayer == true)
		{
			board.PrintBoard();
			if (CurrPlayer == 'X')
			{
				x = board.GetX();
				y = board.GetY();

				if (board.PlaceSymbol(x, y, CurrPlayer) == false)
				{
					cout << endl << "Cannot place " << CurrPlayer << " on that spot!" << endl;
				}
				else
				{

					if (board.Check() == X_VAL) {
						cout << "The game is over!" << endl;
						cout << "Player " << "X" << " WON!" << endl;
						EndGame = true;
					}
					else if (board.Check() == O_VAL)
					{
						cout << "The game is over!" << endl;
						cout << "Player " << "O" << " WON!" << endl;
						EndGame = true;
					}
					else if (board.Check() == DRAW_VAL)
					{
						cout << "DRAW!!!" << endl;
						EndGame = true;
					}
					else
					{
						CurrPlayer = 'O'; //Change player
					}
				}
			}
			else
			{
				ap.PerformMove(board);
				CurrPlayer = 'O';

				if (board.Check() == X_VAL) {
					cout << "The game is over!" << endl;
					cout << "Player " << "X" << " WON!" << endl;
					EndGame = true;

				}
				else if (board.Check() == O_VAL)
				{
					cout << "The game is over!" << endl;
					cout << "Player " << "O" << " WON!" << endl;
					EndGame = true;
				}
				else if (board.Check() == DRAW_VAL)
				{
					cout << "DRAW!!!" << endl;
					EndGame = true;
				}
				else
				{
					CurrPlayer = 'X'; //Change player
				}
			}
		}
		else 
		{
			board.PrintBoard();
			if (CurrPlayer == 'X')
			{
				x = board.GetX();
				y = board.GetY();

				if (board.PlaceSymbol(x, y, CurrPlayer) == false)
				{
					cout << endl << "Cannot place " << CurrPlayer << " on that spot!" << endl;
				}
				else
				{

					if (board.Check() == X_VAL) {
						cout << "The game is over!" << endl;
						cout << "Player " << "X" << " WON!" << endl;
						EndGame = true;
					}
					else if (board.Check() == O_VAL)
					{
						cout << "The game is over!" << endl;
						cout << "Player " << "O" << " WON!" << endl;
						EndGame = true;
					}
					else if (board.Check() == DRAW_VAL)
					{
						cout << "DRAW!!!" << endl;
						EndGame = true;
					}
					else
					{
						CurrPlayer = 'O'; //Change player
					}
				}
			}
			else 
			{
				x = board.GetX();
				y = board.GetY();

				if (board.PlaceSymbol(x, y, CurrPlayer) == false)
				{
					cout << endl << "Cannot place " << CurrPlayer << " on that spot!" << endl;
				}
				else
				{

					if (board.Check() == X_VAL) {
						cout << "The game is over!" << endl;
						cout << "Player " << "X" << " WON!" << endl;
						EndGame = true;
					}
					else if (board.Check() == O_VAL)
					{
						cout << "The game is over!" << endl;
						cout << "Player " << "O" << " WON!" << endl;
						EndGame = true;
					}
					else if (board.Check() == DRAW_VAL)
					{
						cout << "DRAW!!!" << endl;
						EndGame = true;
					}
					else
					{
						CurrPlayer = 'X'; //Change player
					}
				}

			}
		}
	}
	board.PrintBoard();
	board.ClearBoard();
}



TicTacToeGame::~TicTacToeGame()
{
}
