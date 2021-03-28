#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;


class lista {
private:
    int key;
    lista* next;
public:
    void push(class lista* head, int x);
    void wypisz(class lista* head);
}*head = NULL, * tmp = NULL;   // tmp=ogon

void lista::push(class lista* head, int x)
{
    if (tmp == NULL)
    {
        head->key = x;
        head->next = NULL;
        tmp = head;
    }
    else {
        head = (class lista*)new lista;
        head->key = x;
        head->next = NULL;
        tmp->next = head;
        tmp = head;
    }



}

void lista::wypisz(class lista* head) {


    while (head)
    {
        cout << "Wartosc:  " << head->key << " Adres " << head; // wypisuje wartoœæ i adres


        cout << "\n\n";
        head = head->next;
    }
}

