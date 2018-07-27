#include<iostream>
#define N 9
using namespace std;

//Row check
bool UsedInARow(int grid[N][N], int row, int num)
{
	for (int i = 0; i < N; ++i)
	{
		if (grid[row][i] == num)
			return true;
	}
	return false;
}

//Column check
bool UsedInACol(int grid[N][N], int col, int num)
{
	for (int i = 0; i < N; ++i)
	{
		if (grid[i][col] == num)
			return true;
	}
	return false;
}

//3x3 Box check
bool UsedInABox(int grid[N][N], int StartRow, int StartCol, int num)
{
	for(int i=0;i<3;++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (grid[i + StartRow][j + StartCol] == num)
				return true;
		}
	}
	return false;
}

//Combo of Row,Column and Box check
bool IsSafe(int grid[N][N], int row, int col, int num)
{
	return !UsedInARow(grid, row, num) && !UsedInACol(grid, col, num) && !UsedInABox(grid, row - row % 3, col - col % 3, num);
}

//Find Empty Cell
bool EmptyCell(int grid[N][N], int &row, int &col)
{
	for (row = 0; row < N; ++row)
	{
		for (col = 0; col < N; ++col)
		{
			if (grid[row][col] == 0)
				return true;
		}
	}
	return false;
}

//Solver
bool Solve(int grid[N][N])
{
	int row=0, col=0;

	//No Empty Cells in grid -> Game is finished
	if (!EmptyCell(grid, ref(row), ref(col)))
		return true;

	for (int num = 1; num <= 9; ++num)
	{
		if (IsSafe(grid, row, col, num))
		{
			//If is safe, put number in that cell
			grid[row][col] = num;

			//Try now to solve sudoku
			if (Solve(grid))
				return true;

			//If can't solve -> unmake change and try with different number
			grid[row][col] = 0;
		}
	}
	return false;
}

//Print Grid
void PrintGrid(int grid[N][N])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (j % 3 == 0)
				cout << "| ";

			cout << grid[i][j]<<" ";

			if (j == N-1)
				cout <<"|"<< endl;

		}
		if (i == 2 || i==5 || i==8)
			cout << "-------------------------" << endl;
		else
			cout << endl;
	}
}
int main()
{

	int grid[N][N]={{ 1, 0, 0, 0, 5, 2, 6, 0, 0 },
					{ 0, 0, 0, 0, 0, 6, 0, 4, 7 },
					{ 6, 2, 0, 0, 0, 0, 8, 0, 0 },
					{ 0, 9, 0, 3, 0, 0, 1, 0, 0 },
					{ 0, 0, 3, 0, 4, 1, 0, 0, 2 },
					{ 0, 1, 4, 6, 0, 0, 5, 0, 0 },
					{ 0, 0, 0, 5, 7, 0, 0, 8, 0 },
					{ 0, 3, 8, 9, 0, 4, 0, 2, 0 },
					{ 4, 0, 1, 0, 0, 0, 0, 0, 9 } };

	
	if (Solve(grid)==true)
		PrintGrid(grid);
	else
		cout << "No solution!" << endl;

	system("pause");
	return 0;
}

