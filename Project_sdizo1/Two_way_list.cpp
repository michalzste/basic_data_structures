#include"Two_way_list.h"
#include<iostream>
#include <cstdlib>
#include <string>
#include<fstream>
using namespace std;

Two_way_list::Two_way_list() : head(nullptr), tail(nullptr), elementsCounter(0)
{
}

void Two_way_list::pushToList(int val)
{
	if (this->head == nullptr)
	{
		ListElement* newEl = new ListElement(val, nullptr, nullptr);
		this->head = newEl;
		this->tail = newEl;
		this->elementsCounter = this->elementsCounter + 1;
		return;
	}
	ListElement* newEl = new ListElement(val, this->tail, nullptr);
	this->tail->next = newEl;
	this->tail = newEl;
	this->elementsCounter = this->elementsCounter + 1;
}

void Two_way_list::popFromList()
{
	if (this->elementsCounter == 0)return;
	if (head == tail)
	{
		head = NULL;
		tail = NULL;
		elementsCounter--;
		return;
	}
	this->tail->prev->next = NULL;
	ListElement* temp = tail->prev;
	delete tail;
	this->tail = temp;
	elementsCounter--;
}

void Two_way_list::unshiftToList(int val)
{
	if (this->head == nullptr)
	{
		ListElement* newEl = new ListElement(val, nullptr, nullptr);
		this->head = newEl;
		this->tail = newEl;
		this->elementsCounter = this->elementsCounter + 1;
		return;
	}
	ListElement* newEl = new ListElement(val, nullptr, this->head);
	this->head->prev = newEl;
	this->head = newEl;
	this->elementsCounter= this->elementsCounter+1;
}

void Two_way_list::shiftFromList()
{
	if (this->elementsCounter == 0)return;
	this->head->next->prev = NULL;
	ListElement* temp = head->next;
	delete head;
	this->head = temp;
	elementsCounter--;
}

void Two_way_list::printList()
{
	cout << "List: ";
	ListElement* temp = this->head;
	while (temp != nullptr)
	{
		if (temp == this->head) cout << "HEAD ===> ";
		cout << temp->key << " ";
		if (temp == this->tail)cout << "<==== TAIL"<<endl;
		temp = temp->next;
	}
}

void Two_way_list::addToList(int value, int index)
{
	if (index > elementsCounter || index < 0)return;
	if (index == 0) 
	{
		unshiftToList(value);
		return;
	}
	if (index == elementsCounter)
	{
		pushToList(value);
		return;
	}
	ListElement* temp = this->head;
	for (int i = 0; i < index; i++)
	{
		temp = temp->next;
	}
	ListElement* newEl = new ListElement(value, temp->prev, temp);
	temp->prev->next = newEl;
	temp->prev = newEl;
	this->elementsCounter = this->elementsCounter + 1;
}

void Two_way_list::deleteFromList(int index)
{
	if (index < 0 || index > elementsCounter) return;
	if (index == 0)
	{
		this->shiftFromList();
		return;
	}
	if (index == elementsCounter-1)
	{
		this->popFromList();
		return;
	}

	ListElement* temp = head;
	for (int i = 0; i < index; i++)temp = temp->next;
	temp->next->prev = temp->prev;
	temp->prev->next = temp->next;
	delete temp;
	elementsCounter--;
}

void Two_way_list::searchInList(int value)
{
	ListElement* temp = head;
	for (int i = 0; i < elementsCounter; i++)
	{
		if (temp->key == value) cout << "Found " << value << " at index: " << i << endl;
		temp = temp->next;
	}
}

void Two_way_list::loadFromFile(char filename[])
{
	string line;
	ifstream myfile(filename);
	bool sizeF = true;

	if (myfile.is_open())
	{
		getline(myfile, line);
		elementsCounter = stoi(line);
		getline(myfile, line);
		ListElement* temp = new ListElement(stoi(line), NULL, NULL);
		head = temp;
		tail = temp;
		for (int i = 1; i < elementsCounter; i++)
		{
			getline(myfile, line);
			temp->next = new ListElement(stoi(line), temp, NULL);
			tail = temp->next;
			temp = temp->next;
		}
	
		myfile.close();
	}
}