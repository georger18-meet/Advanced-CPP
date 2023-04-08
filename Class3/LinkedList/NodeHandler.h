#pragma once
#include<iostream>
#include<array>
#include "Node.h"
using namespace std;

class NodeHandler
{
public:
	NodeHandler();

	void CreateNodes(int amount);
	void SortNodes();
	void DisplayNodes();

private:
	Node* _nodesList[10];
	Node* _nodePtr;
};