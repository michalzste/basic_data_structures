#include <iostream>


using namespace std;

class ListEl
{
public:
	int data;
	ListEl* next, * prev;


	ListEl(int data, ListEl* next, ListEl* prev);
};