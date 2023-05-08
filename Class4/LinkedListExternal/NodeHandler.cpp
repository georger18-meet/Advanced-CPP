#include "NodeHandler.h"

void NodeHandler::InsertNode(int data)
{
	// Check for Existing Instance
	Node* tempNode = _headPtrNode;
	while (tempNode != nullptr)
	{
		if (tempNode->data == data)
		{
			tempNode->instances++;
			return;
		}
		// Move to next element
		tempNode = tempNode->next;
	}

	// Creating the New Node
	Node* newNode = new Node();
	newNode->data = data;

	// Setting the HeadPtrNode
	if (_headPtrNode == nullptr)
	{
		_headPtrNode = newNode;
		return;
	}

	// Go to the List's last element
	tempNode = _headPtrNode;
	while (tempNode->next != nullptr)
	{
		// Move to next element
		tempNode = tempNode->next;
	}

	// Insert New Node as Last Element
	tempNode->next = newNode;
}

void NodeHandler::DeleteNode(int data)
{
	cout << "Deleting Node with Data Value " << data << endl;

	// Check for Existing Instance
	Node* tempNode = _headPtrNode;
	while (tempNode != nullptr)
	{
		if (tempNode->data == data)
		{
			if (tempNode->instances > 1)
			{
				tempNode->instances--;
				cout << "Deleted Instance from Node Successfully!" << endl << endl;
				return;
			}
		}
		// Move to next element
		tempNode = tempNode->next;
	}

	Node* tempNodeOne = _headPtrNode;
	Node* tempNodeTwo = nullptr;

	// Check if the List is Empty.
	if (_headPtrNode == nullptr)
	{
		cout << "List Is Empty!" << endl;
		return;
	}

	while (tempNodeOne != nullptr)
	{
		if (tempNodeOne->data == data)
		{
			if (tempNodeOne == _headPtrNode)	// If deleting Head

			{
				_headPtrNode = _headPtrNode->next;
				delete tempNodeOne;
			}
			else
			{
				tempNodeTwo->next = tempNodeOne->next;
				delete tempNodeOne;
			}
			cout << "Deleted Node Successfully!" << endl << endl;
			return;
		}
		tempNodeTwo = tempNodeOne;
		tempNodeOne = tempNodeOne->next;
	}

	cout << "Node Was Not Found!!!" << endl << endl;
}

void NodeHandler::DisplayList()
{
	Node* tempNode = _headPtrNode;

	// Check if the List is Empty.
	if (_headPtrNode == nullptr)
	{
		cout << "List Is Empty!" << endl << endl;
		return;
	}

	// Print Nodes
	while (tempNode != nullptr)
	{
		if (tempNode->next == nullptr)
		{
			cout << "Node: " << tempNode->data << ", Instances: " << tempNode->instances << ", Next Pointer: NULL." << endl;
		}
		else
		{
			cout << "Node: " << tempNode->data << ", Instances: " << tempNode->instances << ", Next Node: " << tempNode->next->data << "." << endl;
		}

		tempNode = tempNode->next;
	}

	std::cout << endl;
}

void NodeHandler::SortList()
{
	// Check if the List is Empty.
	if (_headPtrNode == nullptr)
	{
		cout << "List Is Empty!" << endl << endl;
		return;
	}

	Node* tempNodeOne = _headPtrNode;
	Node* tempNodeTwo = nullptr;
	Node* tempNodeThree = nullptr;
	int listLen = 0;

	// Find length of the list.
	while (tempNodeOne != nullptr) {
		tempNodeOne = tempNodeOne->next;
		listLen++;
	}

	// Sort Algorithm
	for (int i = 0; i < listLen; i++)
	{
		tempNodeOne = _headPtrNode;
		while (tempNodeOne != nullptr)
		{
			if (tempNodeOne->next != nullptr)
			{
				while (tempNodeOne->next != nullptr && tempNodeOne->data > tempNodeOne->next->data)
				{
					tempNodeTwo = tempNodeOne->next;
					tempNodeOne->next = tempNodeTwo->next;
					tempNodeTwo->next = tempNodeOne;

					if (tempNodeOne != _headPtrNode)
					{
						tempNodeThree->next = tempNodeTwo;
						tempNodeThree = tempNodeThree->next;
						tempNodeTwo = tempNodeOne->next;
					}
					else
					{
						_headPtrNode = tempNodeTwo;
					}
				}
			}

			tempNodeThree = tempNodeOne;
			tempNodeOne = tempNodeOne->next;
		}
	}

	//cout << "Sorted Successfully!" << endl << endl;
}

void NodeHandler::CreateNodes(int amount)
{
	int tempNum;
	for (int i = 0; i < amount; i++)
	{
		cout << "Insert Node Data Num: ";
		cin >> tempNum;
		InsertNode(tempNum);
	}
}

void NodeHandler::EmptyList()
{
	Node* tempHead = _headPtrNode;
	Node* next = nullptr;

	while (tempHead != nullptr)
	{
		next = tempHead;
		tempHead = tempHead->next;
		delete next;
	}

	_headPtrNode = nullptr;
}
