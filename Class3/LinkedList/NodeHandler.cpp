#include "NodeHandler.h"

NodeHandler::NodeHandler()
{
	_nodesList[0] = 0;
	_nodePtr = _nodesList[0];
}

void NodeHandler::CreateNodes(int amount)
{

	int len = *(&_nodesList + 1) - _nodesList;

	for (size_t i = 0; i < len; i++)
	{
		Node* tempNode = new Node;
		cout << "Insert Node Data Num: ";
		cin >> tempNode->data;
		_nodesList[i] = tempNode;
	}

	_nodePtr = _nodesList[0];
}

void NodeHandler::SortNodes()
{
	int len = *(&_nodesList + 1) - _nodesList;


	Node* tempNode;

	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if ((_nodesList[i]->data) > (_nodesList[j]->data))
			{
				tempNode = *(_nodesList + j);
				*(_nodesList + j) = *(_nodesList + i);
				*(_nodesList + i) = tempNode;
			}
		}
	}
}

void NodeHandler::DisplayNodes()
{
	int len = *(&_nodesList + 1) - _nodesList;

	for (size_t i = 0; i < len; i++)
	{
		if (_nodesList[i]->next == nullptr)
		{
			cout << "Node: " << _nodesList[i]->data << ", Next Pointer: NULL." << endl;
		}
		else
		{
			cout << "Node: " << _nodesList[i]->data << ", Next Node: " << _nodesList[i]->next->data << "." << endl;
		}
	}
}
