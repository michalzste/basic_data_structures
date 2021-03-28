#include<iostream>
#include"ListEl.h"
using namespace std;

ListEl::ListEl(int data, ListEl* next, ListEl* prev)
{
	this->data = data;
	this->next = next;
	this->prev = prev;

}