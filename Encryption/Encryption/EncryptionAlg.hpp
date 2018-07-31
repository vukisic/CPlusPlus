#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

string Monoalphabetic(string text, int key)
{
	for (int i = 0; i < text.size(); ++i)
	{
		if (text[i] >= 65 && text[i] <= 90)
		{
			if (text[i] + key > 90)
			{
				text[i] = text[i] + key - 26;
			}
			else
			{
				text[i] = text[i] + key;
			}
		}
		else if (text[i] >= 97 && text[i] <= 122)
		{
			if (text[i] + key > 122)
			{
				text[i] = text[i] + key - 26;
			}
			else
			{
				text[i] = text[i] + key;
			}
		}
	}
	return text;
}

string OneTime(string text, string key)
{
	if (key.size() != text.size())
	{
		cout << "Error: Key and Text must be the same size!" << endl;
		return " ";
	}
	else
	{
		for (int i = 0; i < text.size(); ++i)
		{
			text[i] = text[i] xor key[i];
		}
		return text;
	}
}

string Vigenere(string text, string key)
{
	string tempkey = "";
	for (int i = 0, j = 0; i < text.size(); ++i, ++j)
	{
		if (j == key.size())
			j = 0;
		tempkey += key[j];
	}

	for (int i = 0; i < text.size(); ++i)
	{
		if (text[i] >= 65 && text[i] <= 90)
		{
			text[i] = (((text[i] + tempkey[i]) % 26) + 'A');
		}
		else if (text[i] >= 97 && text[i] <= 122)
		{
			text[i] = (((text[i] + tempkey[i]) % 26) + 'a');
		}
	}

	return text;
}

string Homophone(string text)
{
	string tmp = "";
	int keys[26] = { 0,2,3,4,5,7,8,9,10,12,13,14,15,16,17,19,20,21,22,23,24,26,27,28,29,30 };
	for (int i = 0; i < text.size(); ++i)
	{
		if (text[i] >= 65 && text[i] <= 90)
		{
			int index = text[i] - 65;
			if (text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U')
				tmp+=to_string( keys[index] + (rand() % 2));
			else
				tmp += to_string(keys[index]);
		}
		else if (text[i] >= 97 && text[i] <= 122)
		{
			int index = text[i] - 97;
			if (text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U')
				tmp += to_string(keys[index] + (rand() % 2));
			else
				tmp += to_string(keys[index]);
		}
	}
	return tmp;
}

int FindKey(int key, int* keys, int keys_size)
{
	for (int index = 0; index < keys_size; ++index)
	{
		if (keys[index] == key)
			return index;
	}
	return -1;
}

string Transposition(string text, int* rowk, int *colk, int row_size, int col_size)
{
	string temp(text.size(), 'x');
	for (int row = 0; row < row_size; ++row)
	{
		for (int col = 0; col < col_size; ++col)
		{
			int row_o = FindKey(row, rowk, row_size);
			int col_o = FindKey(col, colk, col_size);

			int index_in = row * col_size + col;
			int index_out = row_o * col_size + col_o;

			temp[index_out] = text[index_in];
		}
	}
	return temp;
}

//---------------------------------------------------------------------------------------

const int row = 5;
const int col = 5;
char matrix[row][col] = {
	'F','T','N','A','B',
	'C','D','E','G','H',
	'I','K','L','M','O',
	'P','Q','R','S','U',
	'V','W','X','Y','Z'
};

struct Point
{
	int x;
	int y;
	Point(int xx, int yy) { x = xx; y = yy; }
};

void FindInMatrix(Point& p, char letter)
{
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (letter == matrix[i][j])
			{
				p.x = i;
				p.y = j;
				return;
			}
		}
	}
}

char FindLetter(Point p)
{
	return matrix[p.x][p.y];
}

void EncryptCoordinates(Point& a, Point& b)
{
	if (a.y == b.y)
	{
		a.x = (a.x + 1) % row;
		b.x = (b.x + 1) % row;
	}
	else if (a.x == b.x)
	{
		a.y = (a.y + 1) % col;
		b.y = (b.y + 1) % col;
	}
	else
	{
		int temp = a.y;
		a.y = b.y;
		b.y = temp;
	}
}

string PlayFair(string text)
{

	Point a(0, 0);
	Point b(0, 0);
	int newlen = 0;
	if (text.size() % 2 == 0)
		newlen = text.size();
	else
		newlen = text.size() + 1;
	string temp(newlen, 'X');

	for (int i = 0; i < text.size(); ++i)
		temp[i] = text[i];

	for (int i = 0; i < newlen; i=i+2)
	{
		FindInMatrix(a, temp[i]);
		FindInMatrix(b, temp[i + 1]);

		EncryptCoordinates(a, b);

		temp[i] = FindLetter(a);
		temp[i + 1] = FindLetter(b);
	}

	return temp;
}