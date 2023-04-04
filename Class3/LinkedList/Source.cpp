#include "NodeHandler.h"

int main()
{
	NodeHandler nh = NodeHandler();
	nh.CreateNodes(10);
	nh.DisplayNodes();

	return 0;
}