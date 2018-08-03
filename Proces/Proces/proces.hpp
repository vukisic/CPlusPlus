#pragma once
#include<vector>
#include<condition_variable>
using namespace std;

enum INS_TYPE{STANDARD=0,UI};

struct Proces
{
	vector<INS_TYPE> inst;
	int id;
	Proces(vector<INS_TYPE> ins,int i):inst(ins),id(i){}
};

struct UI_Request
{
	int id;
	condition_variable cv;
	bool finished;
	UI_Request(int i) :id(i), finished(false) {}
};