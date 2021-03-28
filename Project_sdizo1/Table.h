#pragma once
class Table
{
    int* tab; //tablica dynamiczna
    int cnt; //ilosc elementow w tablicy
public:
    Table();
    void clearTable();
    void addValueToTable(int index, int value);
    void pushValueToTable(int value);
    void popValueFromTable();
    void unshiftValueToTable(int value);
    void shiftValueFromTable();
    void searchInTable(int value);
    void printTable();
    void fullfillTable(int count, int scope);
};
