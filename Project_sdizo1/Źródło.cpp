#include <iostream>
#include <numeric>
#include <chrono>
#include <cstdlib>
#include "Menu.h"

 //utworzenie obiektu

int main()
{
 
    Menu menu;
    menu.startLoop();

    auto start = std::chrono::high_resolution_clock::now(); //poczatek odliczania
  
    auto stop = std::chrono::high_resolution_clock::now(); //koniec odliczania
    std::chrono::duration < double > czas = stop - start; //odejmij czasy
    std::cout << "Sredni czas dodawania elementow do tablicy:" << czas.count()  << "\n"; //wyswietl w sekundach
}