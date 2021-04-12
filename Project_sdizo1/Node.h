#pragma once
class Node
{
public:
	Node(int val);
	int val();
	void add(Node* temp);
	void print();
private:
	int _val;
	Node* _lchild;
	Node* _rchild;
	static int _level;
};
