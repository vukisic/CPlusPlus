#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<chrono>
#include"SortingAlgorithms.hpp"
using namespace std;
using namespace std::chrono;

int ar[10] = { 0,9,-22,7,30,-15,9,5,1,2 };

int main()
{
	
	system_clock::time_point start;
	system_clock::time_point end;
	duration<double, milli> d;

	start = system_clock::now();
	BubbleSort<int>(ar, 10, true);
	end = system_clock::now();
	d = end - start;
	cout << "Bubble Sort: " << d.count() << " ms" << endl;


	start = system_clock::now();
	SelectionSort<int>(ar, 10, false);
	end = system_clock::now();
	d = end - start;
	cout << "Selection Sort: " << d.count() << " ms" << endl;

	start = system_clock::now();
	InsertionSort(ar, 10, true);
	end = system_clock::now();
	d = end - start;
	cout << "Insertion Sort: " << d.count() << " ms" << endl;

	start = system_clock::now();
	MergeSort<int>(ar, 0, 9, false);
	end = system_clock::now();
	d = end - start;
	cout << "Merge Sort: " << d.count() << " ms" << endl;
	
	start = system_clock::now();
	QuickSort<int>(ar, 0, 9, true);
	end = system_clock::now();
	d = end - start;
	cout << "Quick Sort: " << d.count() << " ms" << endl;

	
	//PrintArray<int>(ar, 10);
	system("pause");
	return 0;
}

