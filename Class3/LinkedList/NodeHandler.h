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
	void DisplayNodes();

private:
	Node* nodesList[10];
};