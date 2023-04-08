#include "NodeHandler.h"

int main()
{
	NodeHandler nh = NodeHandler();
	nh.CreateNodes(10);

	cout << endl << "Before Sorting: " << endl;
	nh.DisplayNodes();

	nh.SortNodes();
	cout << endl << "After Sorting: " << endl;
	nh.DisplayNodes();

	nh.AffixNodesNextPointers(false);
	cout << endl << "Next Pointers Affixed, Not Looping List: " << endl;
	nh.DisplayNodes();

	nh.AffixNodesNextPointers(true);
	cout << endl << "Next Pointers Affixed, Looping List: " << endl;
	nh.DisplayNodes();

	return 0;
}