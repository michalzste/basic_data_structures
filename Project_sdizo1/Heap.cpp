#include "Heap.h"
#include <string>
#include <iostream>
#include <vector>
#include<fstream>

using namespace std;

Heap::Heap() : heap(nullptr), cnt(0)
{

}

void Heap::pushToHeap(int value)
{
    int* NewTab = new int[cnt + 1];
    for (int i = 0; i < cnt; i++) // kopiuje wartosci przed indexem
        NewTab[i] = heap[i];
    NewTab[cnt] = value;

    delete[] heap;
    heap = NewTab;
    cnt++;


    int index = cnt - 1; //indeks aktualnie dodanego elementu
    while (index > 0)
    {
        if (heap[(index - 1) / 2] < heap[index])
        {
            int temp = heap[index];
            heap[index] = heap[(index - 1) / 2];
            heap[(index - 1) / 2] = temp;
            index = (index - 1) / 2;
        }
        else return;
    }
}
void Heap::popFromHeap()
{
    if (cnt == 0) return;
    int* NewTab = new int[cnt - 1];
    for (int i = 0; i < cnt - 1; i++)
        NewTab[i] = heap[i];

    delete[] heap;
    heap = NewTab;
    cnt--;
}
void Heap::popRoot()
{
    if (cnt == 0) return;
    int* NewTab = new int[cnt - 1];
    NewTab[0] = heap[cnt - 1];
    for (int i = 1; i < cnt - 1; i++)
        NewTab[i] = heap[i];

    delete[] heap;
    heap = NewTab;
    cnt--; //Usuwamy korzeń - zamiana z ostatnim lisciem

    //Sprawdzamy warunki na kopiec
    int index = 0;
    while (index < cnt - 1)
    {
        if (heap[index] < heap[2 * index + 1] && heap[2 * index + 1] > heap[2 * index + 2])
        {
            int temp = heap[index];
            heap[index] = heap[index * 2 + 1];
            heap[index * 2 + 1] = temp;
            index = index * 2 + 1;
        }
        else if (heap[index] < heap[2 * index + 2] && heap[2 * index + 1] < heap[2 * index + 2])
        {
            int temp = heap[index];
            heap[index] = heap[index * 2 + 2];
            heap[index * 2 + 2] = temp;
            index = index * 2 + 2;
        }
        else return;
   }
}
void Heap::loadFromFile(char filename[])
{
    string line;
    ifstream myfile(filename);

    if (myfile.is_open())
    {
        int* newTab;
        getline(myfile, line);
        newTab = new int[stoi(line)];
        delete[] heap;
        heap = newTab;
        while (getline(myfile, line))
        {
            this->pushToHeap(stoi(line));
        }
        myfile.close();

       
    }
}
void Heap::printTree() {

 
       
    if (cnt > 0)
    {
        std::vector<int> tree;
        for (int i = 0;i<cnt;i++) {
            tree.push_back(heap[i]);
        }

        unsigned mlength = 0;
        for (int& element : tree) {
            auto clength = std::to_string(element).size();
            if (clength > mlength) {
                mlength = std::to_string(element).size();
            }
        }
        cout << string(mlength - to_string(tree[0]).size(), ' ');
        printer.print(tree, 0, mlength);

        cout << "\n\n\n";
   }
    
}
void Heap::searchInHeap(int value)
{
    for (int i = 0; i < cnt; i++)
    {
        if (heap[i] == value)
        {
            cout << "Found " << value << " at index " << i << "\n";
        }
    }
}