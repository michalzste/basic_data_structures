#pragma once

class ListElement
{
public:
	ListElement(int key, ListElement* prev, ListElement* next);
	int key;
	ListElement* next, *prev;
};