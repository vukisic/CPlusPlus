#include "Board.h"


Board::Board()
{
	ClearBoard(); //Fill board with spaces
	size = 3; //Fixed size of table
}

void Board::ClearBoard()
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {

			board[i][j] = ' ';
		}
	}
}

void Board::PrintBoard()
{
	cout << endl;
	cout << "  |1 2 3|" << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "---------" << endl;
		cout << i + 1 << " |" << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "|" << endl;
	}
	cout << "---------" << endl;
}

//Get X coordinate
int Board::GetX()
{
	int x;
	bool isInputBad = true;

	while (isInputBad == true)
	{
		cout << "Enter X coordinates:";
		cin >> x;

		if (x<1 || x>3)
		{
			cout << "Invald Input!" << endl;
		}
		else
		{
			isInputBad = false;
		}
	}
	return x - 1;
}

// Get X coordinate
int Board::GetY()
{
	int y;
	bool isInputBad = true;

	while (isInputBad == true)
	{
		cout << "Enter Y coordinates:";
		cin >> y;

		if (y<1 || y>3)
		{
			cout << "Invald Input!" << endl;
		}
		else
		{
			isInputBad = false;
		}
	}
	return y - 1;
}

//Add 'X' or 'O' to table
bool Board::PlaceSymbol(int x, int y, char symbol)
{
	if (board[x][y] == ' ')
	{
		board[x][y] = symbol;
		return true;
	}
	else
	{
		return false;
	}
}

//Check for end of the game
int Board::Check()
{

	bool end = false;
	char ch = ' ';

	//Check rows
	for (int i = 0; i < size; ++i) {
		ch = board[0][i];
		if (ch != ' ') {
			end = true;
			for (int j = 0; j < size; ++j) {
				if (board[j][i] != ch) {
					end = false;
					break;
				}
			}
			if (end == true) {
				if (ch == 'X')
					return X_VAL;
				else
					return O_VAL;
			}
		}
	}


	//Check columns
	for (int j = 0; j < size; ++j) {
		ch = board[j][0];
		if (ch != ' ') {
			end = true;
			for (int i = 0; i < size; ++i) {
				if (board[j][i] != ch) {
					end = false;
					break;
				}
			}
			if (end == true) {
				if (ch == 'X')
					return X_VAL;
				else
					return O_VAL;
			}
		}
	}

	//Check top Left diagonal
	ch = board[0][0];
	if (ch != ' ') {
		end = true;
		for (int i = 0; i < size; ++i) {
			if (board[i][i] != ch) {
				end = false;
				break;
			}
		}
		if (end == true) {
			if (ch == 'X')
				return X_VAL;
			else
				return O_VAL;
		}
	}

	//Check top Right diagonal
	ch = board[size-1][0];
	if (ch != ' ') {
		end = true;
		for (int i = 0; i < size; ++i) {
			if (board[size-i-1][i] != ch) {
				end = false;
				break;
			}
		}
		if (end == true) {
			if (ch == 'X')
				return X_VAL;
			else
				return O_VAL;
		}
	}

	//is draw?
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (board[i][j] == ' ')
				return NO_VAL; //Exists at least one empty cell
		}
	}

	return DRAW_VAL;
	
}

Board::~Board()
{
}
