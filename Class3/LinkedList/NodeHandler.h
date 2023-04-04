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

private:
	Node* nodesList[];
};