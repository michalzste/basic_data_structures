#include<iostream>
#include"Node.h"

using namespace std;

class Node {
public:
    Node(int val) : _val(val) {}
    int val() { return _val; }
    void add(Node* temp)
    {
        if (temp->val() > _val)
        {
            if (_rchild)
                _rchild->add(temp);
            else
            {
                _rchild = temp;
            }
        }
        else
        {
            if (_lchild)
                _lchild->add(temp);
            else
            {
                _lchild = temp;
            }
        }
    }
    void print()
    {
        for (int ix = 0; ix < _level; ++ix) cout << ' ';
        cout << _val << endl;
        ++_level;
        if (_lchild)
        {
            _lchild->print();
            --_level;
        }
        if (_rchild)
        {
            _rchild->print();
            --_level;
        }
    }
private:
    int _val;
    Node* _lchild =NULL;
    Node* _rchild = NULL;
    static int _level;
};

