#pragma once
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;


template<class T>
void PrintArray(T *arr, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << arr[i]<<" ";
	}
	cout << endl;
}
//### BubbleSort ################################################
template<class T>
void BubbleSort(T* arr, int len, bool op=true)
{
	if (op)
	{
		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < len; ++j)
			{
				if (arr[i] < arr[j])
				{
					T temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < len; ++i)
		{
			for (int j = 0; j < len; ++j)
			{
				if (arr[i] > arr[j])
				{
					T temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
		}
	}
}

//### SelectionSort ################################################
template<class T>
void SelectionSort(T* arr, int len, bool op = true)
{
	if (op)
	{
		int indmin;
		for (int i = 0; i < len - 1; ++i)
		{
			indmin = i;
			for (int j = i + 1; j < len; ++j)
			{
				if (arr[j] < arr[indmin])
				{
					indmin = j;
				}
			}
			T temp = arr[i];
			arr[i] = arr[indmin];
			arr[indmin] = temp;
		}
	}
	else
	{
		int indmin;
		for (int i = 0; i < len - 1; ++i)
		{
			indmin = i;
			for (int j = i + 1; j < len; ++j)
			{
				if (arr[j] > arr[indmin])
				{
					indmin = j;
				}
			}
			T temp = arr[i];
			arr[i] = arr[indmin];
			arr[indmin] = temp;
		}
	}
}

//### InsertionSort ################################################
template<class T>
void InsertionSort(T* arr, int len, bool op = true)
{
	if (op)
	{
		int key;
		int i;
		for (int j = 1; j < len; ++j)
		{
			key = arr[j];
			i = j - 1;
			while (i >= 0 && arr[i] > key)
			{
				arr[i + 1] = arr[i];
				--i;
			}
			arr[i + 1] = key;
		}
	}
	else
	{
		int key;
		int i;
		for (int j = 1; j < len; ++j)
		{
			key = arr[j];
			i = j - 1;
			while (i >= 0 && arr[i] < key)
			{
				arr[i + 1] = arr[i];
				--i;
			}
			arr[i + 1] = key;
		}
	}
}

//### MergeSort ################################################

template<class R>
void merge01(R* arr, int begin, int q, int end, bool op)
{
	if (op)
	{
		int i, j, k;
		int n1 = q - begin + 1;
		int n2 = end - q;

		R* l = (R*)malloc(sizeof(R)*n1);
		R* r = (R*)malloc(sizeof(R)*n2);

		for (i = 0; i < n1; ++i)
			l[i] = arr[begin + i];
		for (j = 0; j < n2; ++j)
			r[j] = arr[q + 1 + j];

		i = j = 0;
		k = begin;

		while (i < n1 && j < n2)
		{
			if (l[i] <= r[j])
				arr[k++] = l[i++];
			else
				arr[k++] = r[j++];
		}

		while (i < n1) arr[k++] = l[i++];
		while (j < n2) arr[k++] = r[j++];

		free(l);
		free(r);
	}
	else
	{
		int i, j, k;
		int n1 = q - begin + 1;
		int n2 = end - q;

		R* l = (R*)malloc(sizeof(R)*n1);
		R* r = (R*)malloc(sizeof(R)*n2);

		for (i = 0; i < n1; ++i)
			l[i] = arr[begin + i];
		for (j = 0; j < n2; ++j)
			r[j] = arr[q + 1 + j];

		i = j = 0;
		k = begin;

		while (i < n1 && j < n2)
		{
			if (l[i] > r[j])
				arr[k++] = l[i++];
			else
				arr[k++] = r[j++];
		}

		while (i < n1) arr[k++] = l[i++];
		while (j < n2) arr[k++] = r[j++];

		free(l);
		free(r);
	}
	
}

template<class T>
void MergeSort(T *arr, int begin,int end, bool op)
{
	if (begin < end)
	{
		int q = (begin + end) / 2;
		MergeSort(arr, begin, q,op);
		MergeSort(arr, q + 1, end,op);
		merge01<T>(arr, begin, q, end, op);
	}
}

//### QuickSort ################################################
template<class T>
int Partition01(T* arr, int p, int r, bool op)
{
	if (op)
	{
		T x = arr[r];
		int i = p - 1;
		for (int j = p; j < r; ++j)
		{
			if (arr[j] <= x)
			{
				++i;
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		T tmp = arr[i + 1];
		arr[i + 1] = arr[r];
		arr[r] = tmp;

		return i + 1;
	}
	else
	{
		T x = arr[r];
		int i = p - 1;
		for (int j = p; j < r; ++j)
		{
			if (arr[j] > x)
			{
				++i;
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		T tmp = arr[i + 1];
		arr[i + 1] = arr[r];
		arr[r] = tmp;

		return i + 1;
	}
	
}

template<class T>
void QuickSort(T* arr, int p, int r,bool op)
{
	if (p < r)
	{
		int q = Partition01<T>(arr, p, r,op);
		QuickSort(arr, p, q - 1,op);
		QuickSort(arr, q + 1, r,op);
	}
}
