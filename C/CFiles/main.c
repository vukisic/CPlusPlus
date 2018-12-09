#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ARRAY 20
#define MAX_NAME 30

typedef struct item_st
{
	char name[MAX_NAME];
	double price;
}ITEM;

ITEM items[MAX_ARRAY];
int counter = 0;

FILE* safe_fopen(char* name,const char* mode , int code);
void read_from_file(FILE* in);
void print_in_file(FILE* out);

int main()
{
	char inFileName[MAX_NAME];
	char outFileName[MAX_NAME];
	printf("\nEnter Input File Name:");
	scanf("%s", inFileName);
	printf("\nEnter Output File Name:");
	scanf("%s", outFileName);

	FILE* inFile = safe_fopen(inFileName, "r", 1);
	FILE* outFile = safe_fopen(outFileName, "w", 2);

	read_from_file(inFile);
	print_in_file(outFile);

	fclose(inFile);
	fclose(outFile);
	system("pause");
	return 0;
}

FILE* safe_fopen(char* name,const char* mode, int code)
{
	FILE* fp = fopen(name, mode);
	if (fp == NULL)
	{
		printf("\nError with opening file %s !\n", name);
		system("pause");
		exit(code);
	}
	return fp;
}

void read_from_file(FILE* in)
{
	char tempName[MAX_NAME];
	double tempPrice=0;

	while ((fscanf(in, "%s %lf", tempName, &tempPrice)) != EOF)
	{
		if (counter == MAX_ARRAY)
		{
			printf("Error MAX elements %d", MAX_ARRAY);
			return;
		}
		else
		{
			strcpy(items[counter].name, tempName);
			items[counter].price = tempPrice;
			++counter;
		}
	}
}

void print_in_file(FILE* out)
{
	for (int i = 0; i < counter; ++i)
	{
		fprintf(out, "%s %.4lf\n", items[i].name, items[i].price);
	}
}