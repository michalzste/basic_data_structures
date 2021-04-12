#include<iostream>
#include "Tree.h"
using namespace std;




class Tree 
{
public:
    Tree() : _root(0) {}
    void add(int val)
    {
        Node* temp = new Node(val);
        if (!_root)
            _root = temp;
        else
            _root->add(temp);
    }
    void print()
    {
        if (!_root)
            return;
        _root->print();
    }
private:
    Node* _root;
};

