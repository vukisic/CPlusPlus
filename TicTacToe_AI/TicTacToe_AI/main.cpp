#include<iostream>
#include"TicTacToeGame.h"
#include<cctype>
using namespace std;


int main() {

	TicTacToeGame game;
	bool isDone = false;
	char op = ' ';
	while (isDone == false) {
		game.PlayGame();
		cout << "Would you like to play again?[Y/N]" << endl;
		cout << ">>";
		cin >> op;
		if (op == 'n' || op=='N')
			isDone = true;
	}
	

	system("pause");
	return 0;
	
}