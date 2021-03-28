#include <iostream>
#include "ListEl.h"
using namespace std;

class List2Dir
{
public:
	unsigned int count;
	ListEl *head, *tail;


	List2Dir();
	void popFront();
	void pushFront(ListEl *& head);
	void printList();

};
