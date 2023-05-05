#include "NodeHandler.h"

int main()
{
	NodeHandler nh = NodeHandler();

	nh.CreateNodes(5);

	cout << endl << "Before Sorting: " << endl;
	nh.DisplayList();

	cout << endl << "After Sorting: " << endl;
	nh.SortList();
	nh.DisplayList();

	nh.DeleteNode(2);
	cout << endl << "After Deleting Node: " << endl;
	nh.DisplayList();

	return 0;
}