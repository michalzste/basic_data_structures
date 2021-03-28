#include "Menu.h"
#include<iostream>
#include "Table.h"
using namespace std;

Table myTab;
void Menu::arrayLoop() {
    int subselect = 10;
    while (subselect != 0)
    {
        cout << "*******************ARRAY********************" << endl;
        cout << "1.Push to array" << endl;
        cout << "2. Put in any place in array" << endl;
        cout << "3.Pop from array" << endl;
        cout << "4.Unshift to array" << endl;
        cout << "5.Shift from array" << endl;
        cout << "6.Find index of value" << endl;
        cout << "7.Print array" << endl;
        cout << "8.Load array from file" << endl;
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
        }
    }
}
void Menu::startLoop() {
    while (select != 0)
    {
        cout << "*******************MENU********************" << endl;
        cout << "1.Array" << endl;
        cin >> select;
        system("cls");


        switch (select)
        {
        case 1:
            arrayLoop();
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        }
    }

    system("PAUSE");
}