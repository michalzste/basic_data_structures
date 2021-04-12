#include "Menu.h"
#include<iostream>
#include "Table.h"
#include "Two_way_list.h"
#include "Heap.h"
using namespace std;

Table myTab;
Two_way_list myList;
Heap heap;

void Menu::heapLoop() {
    int subselect = 10;
    while (subselect != 0)
    {
        cout << "*******************HEAP(MAX)********************" << endl;
        cout << "1.Push to heap" << endl;
        cout << "2.Pop from heap" << endl;
        cout << "3.Pop root" << endl;
        cout << "4.Find index of value" << endl;
        cout << "5.Print heap" << endl;
        cout << "6.Load heap from file" << endl;
        cout << "0.EXIT" << endl;
        cin >> subselect;
        system("cls");

        switch (subselect)
        {
        case 1:
            int value;
            cout << "Value: \n";
            cin >> value;
            heap.pushToHeap(value);
            break;
        case 2:

            heap.popFromHeap();
            break;
        case 3:
            heap.popRoot();
            break;
        case 4:
            int value2;
            cout << "Value: " << endl;
            cin >> value2;
            heap.searchInHeap(value2);
            break;
        case 5:
            heap.printTree();
            break;
        case 6:
            cout << "Give filename: ";
            char filename[15];
            cin >> filename;
            heap.loadFromFile(filename);
            break;

        }
    }
}
void Menu::arrayLoop() {
    int subselect = 10;
    while (subselect != 0)
    {
        cout << "*******************ARRAY********************" << endl;
        cout << "1.Push to array" << endl;
        cout << "2.Put in any place in array" << endl;
        cout << "3.Pop from array" << endl;
        cout << "4.Unshift to array" << endl;
        cout << "5.Shift from array" << endl;
        cout << "6.Find index of value" << endl;
        cout << "7.Print array" << endl;
        cout << "8.Load array from file" << endl;
        cout << "9.Delete from array" << endl;
        cout << "0.EXIT" << endl;
        cin >> subselect;
        system("cls");

        switch (subselect)
        {
        case 1:
            int value;
            cout << "Value: \n";
            cin >> value;
            myTab.pushValueToTable(value);
            break;
        case 2:
            int value1;
            int index;
            cout << "Value: \n";
            cin >> value1;
            cout << "Index: \n";
            cin >> index;
            myTab.addValueToTable(index, value1);
            break;
        case 3:
            myTab.popValueFromTable();
            break;
        case 4:
            int value2;
            cout << "Value: \n";
            cin >> value2;
            myTab.unshiftValueToTable(value2);
            break;
        case 5:
            myTab.shiftValueFromTable();
            break;
        case 6:
            int searchValue;
            cout << "Value: \n";
            cin >> searchValue;
            myTab.searchInTable(searchValue);
            break;
        case 7:
            myTab.printTable();
            break;
        case 8:
            cout << "Give filename: ";
            char filename[15];
            cin >> filename;
            myTab.loadFromFile(filename);
            break;
        case 9:
            int index2;         
            cout << "Index: \n";
            cin >> index2;
            myTab.deleteFromTable(index2);
            break;
        }
    }
}
void Menu::listLoop()
{
    int subselect = 10;
    while (subselect != 0)
    {
        cout << "*******************DOUBLY LINKED LIST********************" << endl;
        cout << "1.Push to list" << endl;
        cout << "2.Pop from list" << endl;
        cout << "3.Unshift to list" << endl;
        cout << "4.Shift from list" << endl;
        cout << "5.Put in any place in list" << endl;
        cout << "6.Delete from list" << endl;
        cout << "7.Find index of value" << endl;
        cout << "8.Print list" << endl;
        cout << "9.Load list from file" << endl;
        
        cout << "0.EXIT" << endl;
        cin >> subselect;
        system("cls");

        switch (subselect)
        {
        case 1:
            int value;
            cout << "Value: \n";
            cin >> value;
            myList.pushToList(value);
            break;
        case 2:
            myList.popFromList();
            break;
        case 3:
            int value2;
            cout << "Value: \n";
            cin >> value2;
            myList.unshiftToList(value2);
            break;
        case 4:
            myList.shiftFromList();
            break;
        case 5:
            int value4;
            int index;
            cout << "Value: " << endl;
            cin >> value4;
            cout << "Index: " << endl;
            cin >> index;
            myList.addToList(value4, index);
            break;
        case 6:
            int index2;
            cout << "Index: " << endl;
            cin >> index2;
            myList.deleteFromList(index2);
            break;
        case 7:
            int searchValue2;
            cout << "Value: " << endl;
            cin >> searchValue2;
            myList.searchInList(searchValue2);
            break;
        case 8:
            myList.printList();
            break;
        case 9:
            cout << "Give filename: ";
            char filename2[15];
            cin >> filename2;
            myList.loadFromFile(filename2);
            break;
        }
    }
}
void Menu::startLoop() {
    while (select != 0)
    {
        cout << "*******************MENU********************" << endl;
        cout << "1.Array" << endl;
        cout << "2.Doubly linked list" << endl;
        cout << "3.Heap (MAX)" << endl;
        cin >> select;
        system("cls");


        switch (select)
        {
        case 1:
            arrayLoop();
            break;
        case 2:
            listLoop();
            break;
        case 3:
            heapLoop();
            break;
        case 4:
            break;
        case 5:
            break;
        }
    }

    system("PAUSE");
}