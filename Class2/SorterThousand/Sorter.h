#pragma once
#include <iostream>
//#include <algorithm>
using namespace std;

class Sorter 
{
public:
	Sorter();

	void SetValuesToIndex(int val);
	void SortArray();
	void SortArrayToIndex(int val);

	void PrintArray();
	void PrintArrayToIndex(int val);

private:
	int _numArray[1000];
	int* _arrPtr;
};