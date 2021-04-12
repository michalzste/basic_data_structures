#pragma once
class Measure
{

public:

    void measureTableAddFront(int cnt);
    void measureTableAddBack(int cnt);
    void measureTableAddMiddle(int cnt);
    void measureTableDeleteFront(int cnt);
    void measureTableDeleteBack(int cnt);
    void measureTableDeleteMiddle(int cnt);
    void measureTableSearch(int cnt); //metody do pomiaru czasu operacji na tablicy

    void measureListAddFront(int cnt);
    void measureListAddBack(int cnt);
    void measureListAddMiddle(int cnt);
    void measureListDeleteFront(int cnt);
    void measureListDeleteBack(int cnt);
    void measureListDeleteMiddle(int cnt);
    void measureListSearch(int cnt); //metody do pomiaru czasu operacji na liscie

    void measureHeapAdd(int cnt);
    void measureHeapDelete(int cnt);
    void measureHeapSearch(int cnt); //metody do pomiaru czasu operacji na kopcu

}; 
