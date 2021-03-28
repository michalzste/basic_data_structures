#include "Table.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Table::Table() : tab(nullptr) , cnt(0)
{
    
} 

void Table::clearTable()
{
    if (cnt == 0)
        return;

    delete[] tab; //tutaj tez powinny byc nawiasy kwadratowe
    tab = nullptr; //delete u¿yte na nullptr nie bedzie powodowac bledu
    cnt = 0; //
}

void Table::addValueToTable(int index, int value)
{
    if (index < 0 || index > cnt)return;
    int* NewTab = new int[cnt + 1]; //nowa tablica
    for (int i = 0; i < index; ++i) // kopiuje wartosci przed indexem
        NewTab[i] = tab[i];

    NewTab[index] = value; //na index wstawiam zadana wartosc
    for (int i = index + 1; i < cnt + 1; ++i) // i kopiuje reszte
        NewTab[i] = tab[i - 1];

    delete[] tab; //zwalniam pamiec zajmowana przez poprzednia tablice
    tab = NewTab; // przypisuje wskaznik na nowa tablice.
    ++cnt; // zwiekszam licznik
}

void Table::pushValueToTable(int value)
{
    int* NewTab = new int[cnt + 1];
    for (int i = 0; i < cnt; i++) // kopiuje wartosci przed indexem
        NewTab[i] = tab[i];
    NewTab[cnt] = value;
   
    delete[] tab;
    tab = NewTab;
    cnt++;
}

void Table::popValueFromTable()
{
    if (cnt == 0) return;
    int* NewTab = new int[cnt - 1];
    for (int i = 0; i < cnt - 1; i++)
        NewTab[i] = tab[i];
  
    delete[] tab;
    tab = NewTab;   
    cnt--;
}

void Table::shiftValueFromTable()
{
    if (cnt == 0) return;
    int* NewTab = new int[cnt - 1];
    for (int i = 1; i < cnt; i++)
        NewTab[i - 1] = i;

    delete[] tab;
    tab = NewTab;
    cnt--;
}

void Table::unshiftValueToTable(int value)
{
    int* NewTab = new int[cnt + 1];
    NewTab[0] = value;
    for (int i = 0; i < cnt; i++)
        NewTab[i + 1] = tab[i];

    delete[] tab;
    tab = NewTab;
    cnt++;
}

void Table::printTable()
{   
    cout << "Table: ";
    for (int i = 0; i < cnt; i++)
        cout << tab[i]<<" ";
    cout << "\n";
}

void Table::searchInTable(int value)
{
    for (int i = 0; i < cnt; i++)
    {
        if (tab[i] == value)
        {
            cout << "Found " << value << " at index " << i<<"\n";
        }
    }
}

void Table::fullfillTable(int count, int scope)
{
    int* NewTab = new int[count];
    for (int i = 0; i < count; i++)
        NewTab[i] = rand() % scope;

    delete[] tab;
    tab = NewTab;
    cnt = count;
}