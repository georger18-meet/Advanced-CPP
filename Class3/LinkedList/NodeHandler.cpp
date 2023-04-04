#include "NodeHandler.h"

NodeHandler::NodeHandler()
{
	nodesList[0] = nullptr;
}

void NodeHandler::CreateNodes(int amount)
{
	nodesList[amount];

	int len = *(nodesList + 1) - *nodesList;

	cout << len;

	for (size_t i = 0; i < len; i++)
	{
		Node* tempNode = new Node;
		cout << "Insert Node Data Num: ";
		cin >> tempNode->data;
		nodesList[i] = tempNode;
	}
}
