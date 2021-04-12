#include"ListElement.h"

class Two_way_list
{
private:
	ListElement* head;
	ListElement* tail;
	int elementsCounter;
public:
	Two_way_list();
	void pushToList(int value);
	void popFromList();
	void unshiftToList(int value);
	void shiftFromList();
	void addToList(int value, int index);
	void deleteFromList(int index);
	void printList();
	void searchInList(int value);
	void loadFromFile(char filename[]);
};