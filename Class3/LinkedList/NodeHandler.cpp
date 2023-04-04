#include "NodeHandler.h"

NodeHandler::NodeHandler()
{
	nodesList[0] = 0;
}

void NodeHandler::CreateNodes(int amount)
{

	int len = *(&nodesList + 1) - nodesList;

	for (size_t i = 0; i < len; i++)
	{
		Node* tempNode = new Node;
		cout << "Insert Node Data Num: ";
		cin >> tempNode->data;
		nodesList[i] = tempNode;
	}
}

void NodeHandler::DisplayNodes()
{
	int len = *(&nodesList + 1) - nodesList;

	for (size_t i = 0; i < len; i++)
	{
		if (nodesList[i]->next == nullptr)
		{
			cout << "Node: " << nodesList[i]->data << ", Next Pointer: NULL." << endl;
		}
		else
		{
			cout << "Node: " << nodesList[i]->data << ", Next Node: " << nodesList[i]->next->data << "." << endl;
		}
	}
}
