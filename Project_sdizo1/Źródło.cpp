#include <iostream>
#include <numeric>
#include <chrono>
#include <cstdlib>
#include "Table.h"


Table myTab; //utworzenie obiektu

int main()
{
 
    myTab.addValueToTable(0, 15);
    myTab.pushValueToTable(5);
    myTab.unshiftValueToTable(50);
    
    myTab.printTable();

    myTab.searchInTable(5);

    myTab.fullfillTable(100, 1000);
    myTab.printTable();

    auto start = std::chrono::high_resolution_clock::now(); //poczatek odliczania
  
    auto stop = std::chrono::high_resolution_clock::now(); //koniec odliczania
    std::chrono::duration < double > czas = stop - start; //odejmij czasy
    std::cout << "Sredni czas dodawania elementow do tablicy:" << czas.count()  << "\n"; //wyswietl w sekundach
}