#pragma once
 #include"Node.h"
class Tree
{
public:
	Tree();
	void add(int val);
	void print();
private:
	Node* _root;

};