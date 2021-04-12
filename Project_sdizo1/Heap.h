#pragma once
#include <vector>
#include <string>
#include"TreePrinter.h"

class Heap
{
    int* heap; //tablica dynamiczna
    int cnt; //ilosc elementow w kopcu
    TreePrinter printer;
public:
    Heap();
    void pushToHeap(int value);
    void popFromHeap();
    void popRoot();
    void loadFromFile(char filename[]);
    void printTree();
    void searchInHeap(int value);
 
};
