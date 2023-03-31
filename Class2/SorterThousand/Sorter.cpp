#include "Sorter.h"

Sorter::Sorter()
{
	int len = *(&_numArray + 1) - _numArray;

	for (int i = 0; i < len; ++i) {
		_numArray[i] = 0;
	}

	_arrPtr = _numArray;
}

void Sorter::SetValuesToIndex(int val)
{
	int len = *(&_numArray + 1) - _numArray;

	if (val <= len)
	{
		for (int i = 0; i < val; ++i) {
			cout << "Set Value For " << i << ": ";
			cin >> _numArray[i];
		}
		cout << endl;
	}
	else
	{
		cout << "Index Out Of Range, Make Sure You Set A Number Smaller/Equal To " << len << endl << endl;
	}
}

void Sorter::SortArray()
{
	int len = *(&_numArray + 1) - _numArray;

	//sort(_numArray, _numArray + len);

	int temp;

	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (*(_arrPtr + i)> *(_arrPtr + j))
			{
				temp = *(_arrPtr + j);
				*(_arrPtr + j) = *(_arrPtr + i);
				*(_arrPtr + i) = temp;
			}
		}
	}
}

void Sorter::SortArrayToIndex(int val)
{
	int len = *(&_numArray + 1) - _numArray;

	if (val <= len)
	{
		//sort(_numArray, _numArray + val);

		int temp;

		for (int i = 0; i < val - 1; i++)
		{
			for (int j = i + 1; j < val; j++)
			{
				if (*(_arrPtr + i) > *(_arrPtr + j))
				{
					temp = *(_arrPtr + j);
					*(_arrPtr + j) = *(_arrPtr + i);
					*(_arrPtr + i) = temp;
				}
			}
		}
	}
	else
	{
		cout << "Index Out Of Range, Make Sure You Set A Number Smaller/Equal To " << len << endl << endl;
	}
}

void Sorter::PrintArray()
{
	int len = *(&_numArray + 1) - _numArray;

	for (int i = 0; i < len; ++i) {
		cout << i << ": " << _numArray[i] << endl;
	}
	cout << endl;
}

void Sorter::PrintArrayToIndex(int val)
{
	int len = *(&_numArray + 1) - _numArray;

	if (val <= len)
	{
		for (int i = 0; i < val; ++i) {
			cout << i << ": " << _numArray[i] << endl;
		}
		cout << endl;
	}
	else
	{
		cout << "Index Out Of Range, Make Sure You Set A Number Smaller/Equal To " << len << endl << endl;
	}
}
