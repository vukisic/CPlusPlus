#include<iostream>
#include<thread>
#include<conio.h>
using namespace std;
using namespace chrono;

//Global vars
bool GameOver;
const int Width = 20;
const int Height = 20;
int Snake_x;
int Snake_y;
int Fruit_x;
int Fruit_y;
int score;
int Tail_x[1000];
int Tail_y[1000];
int Tail_length = 0;
enum Directions{STOP=0,RIGHT,LEFT,UP,DOWN};
Directions direction;
char Border = '#';
char Snake = 'O';
char Fruit = '$';

void SetUp()
{
	GameOver = false;
	direction = STOP;
	Snake_x = Width / 2;
	Snake_y = Height / 2;
	Fruit_x = rand() % Width;
	Fruit_y = rand() % Height;
}


void Draw()
{
	system("cls");
	//Top
	for (int i = 0; i < Width; ++i)
		cout << Border;
	cout << endl;

	//Left & Right
	for (int i = 0; i < Width; ++i)
	{
		for (int j = 0; j < Height; ++j)
		{
			if (j == 0)
				cout << Border;
			else if (j == Height-1)
				cout << Border;
			else if (j == Snake_x && i == Snake_y)
				cout << Snake;
			else if (j == Fruit_x && i == Fruit_y)
				cout << Fruit;
			else
			{
				bool print = false;
				for (int k = 0; k < Tail_length; ++k)
				{
					if (Tail_x[k] == j && Tail_y[k] == i)
					{
						cout << Snake;
						print = true;
					}

				}
				if (!print)
					cout << " ";
				
			}
				
		}
		cout << endl;
	}

	//Bottom
	for (int i = 0; i < Width; ++i)
		cout << Border;
	cout << endl;


}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':direction = UP; break;
		case 'a':direction = LEFT; break;
		case 's':direction = DOWN; break;
		case 'd':direction = RIGHT; break;
		case 'x':GameOver = true; break;
		}
	}
}

void Logic()
{
	int prev_tail_x=Tail_x[0];
	int prev_tail_y=Tail_y[0];
	int prev2x;
	int prev2y;
	Tail_x[0] = Snake_x;
	Tail_y[0] = Snake_y;
	for (int i = 1; i < Tail_length; ++i)
	{
		prev2x = Tail_x[i];
		prev2y = Tail_y[i];
		Tail_x[i] = prev_tail_x;
		Tail_y[i] = prev_tail_y;
		prev_tail_x = prev2x;
		prev_tail_y = prev2y;
	}
	switch (direction)
	{
	case UP:--Snake_y; break;
	case LEFT:--Snake_x; break;
	case RIGHT:++Snake_x; break;
	case DOWN:++Snake_y; break;
	//default:break;
	}

	//if (Snake_x > Width || Snake_x <-1|| Snake_y > Height || Snake_y <-1)
	//	GameOver = true;

	if (Snake_x >= Width)
		Snake_x = 0;
	if (Snake_x < 0)
		Snake_x = Width-1;
	if (Snake_y >= Height)
		Snake_y = 0;
	if (Snake_y < 0)
		Snake_y = Height-1;

	for (int i = 0; i < Tail_length; ++i)
	{
		if (Snake_x == Tail_x[i] && Snake_y == Tail_y[i])
			GameOver = true;
	}
	if (Snake_x == Fruit_x && Snake_y == Fruit_y)
	{
		++Tail_length;
		score += 10;
		Fruit_x = rand() % Width;
		Fruit_y = rand() % Height;
	}

}

void Start()
{
	SetUp();
	while (!GameOver)
	{
		Draw();
		Input();
		Logic();
		cout << endl <<"Score: " <<score << endl;
		this_thread::sleep_for(milliseconds(50));
	}
}

int main()
{
	srand(time(NULL));
	thread t(Start);
	t.join();

	system("pause");
	return 0;
}