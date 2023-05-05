#pragma once
#include<iostream>
#include<array>
#include "Node.h"
using namespace std;

class NodeHandler
{
public:
	NodeHandler() { _headPtrNode = nullptr; }

	void InsertNode(int data);
	void DeleteNode(int data);
	void DisplayList();
	void SortList();

	void CreateNodes(int amount);

	void EmptyList();

private:
	Node* _headPtrNode;
};