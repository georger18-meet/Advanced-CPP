#include "Sorter.h"

int main()
{
    Sorter sorter;
    //sorter.PrintArray();
    sorter.SetValuesToIndex(10);

    cout << "Before Sorting: " << endl;
    sorter.PrintArrayToIndex(10);
    
    //sorter.SortArray();
    sorter.SortArrayToIndex(10);
    cout << "After Sorting: " << endl;
    sorter.PrintArrayToIndex(10);
    
    return 0;
}