#include "Measure.h"
#include<iostream>
#include <chrono>
#include <cstdlib>
#include "Table.h"
#include "Two_way_list.h"
#include "Heap.h"
#include <math.h>   


using namespace std;
void Measure::measureTableAddBack(int cnt)
{
	long time=0;
	for (int i = 0; i < 200; i++)
	{
		Table myTab;
		
		for (int i = 0; i < cnt; i++)
		{
			int randomNumber = rand() * pow(2, 17) - rand() * pow(2, 17);
			myTab.pushValueToTable(randomNumber);
		}
		int randomVal = rand() * pow(2, 17) - rand() * pow(2, 17);
		auto start = std::chrono::high_resolution_clock::now(); //poczatek odliczania
		myTab.pushValueToTable(randomVal);
		auto stop = std::chrono::high_resolution_clock::now(); //koniec odliczania
		auto int_ns = std::chrono::duration_cast<std::chrono::nanoseconds>( stop - start);
		time += int_ns.count();
	}
	cout << "Sredni czas: " << time/200 << " ilosc el: " << cnt << " operacja: PUSH_TAB" << endl;
}

void Measure::measureTableAddFront(int cnt)
{
	long time = 0;
	for (int i = 0; i < 200; i++)
	{
		Table * myTab = new Table;

		for (int i = 0; i < cnt; i++)
		{
			int randomNumber = rand() * pow(2, 17) - rand() * pow(2, 17);
			myTab->pushValueToTable(randomNumber);
		}
		//measure
		int randomVal = rand() * pow(2, 17) - rand() * pow(2, 17);
		auto start = std::chrono::high_resolution_clock::now(); //poczatek odliczania
		myTab->unshiftValueToTable(randomVal);
		auto stop = std::chrono::high_resolution_clock::now(); //koniec odliczania
		auto int_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		time += int_ns.count();
		delete myTab;
	}
	cout << "Sredni czas: " << time / 200 << " ilosc el: " << cnt << " operacja: UNSHIFT_TAB" << endl;
}

void Measure::measureTableAddMiddle(int cnt)
{
	
	long time = 0;
	for (int i = 0; i < 200; i++)
	{
		Table myTab;

		for (int i = 0; i < cnt; i++)
		{
			int randomNumber = rand() * pow(2, 17) - rand() * pow(2, 17);
			//cout << randomNumber << endl;
			myTab.pushValueToTable(randomNumber);
		}
		//measure
		int randomVal = rand() * pow(2, 17) - rand() * pow(2, 17);
		auto start = std::chrono::high_resolution_clock::now(); //poczatek odliczania
		myTab.addValueToTable(cnt / 2, randomVal);
		auto stop = std::chrono::high_resolution_clock::now(); //koniec odliczania
		auto int_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		time += int_ns.count();
	}
	cout << "Sredni czas: " << time / 200 << " ilosc el: " << cnt << " operacja: ADD_MIDDLE_TAB" << endl;
}

void Measure::measureTableDeleteBack(int cnt)
{

	long time = 0;
	for (int i = 0; i < 200; i++)
	{
		Table myTab;

		for (int i = 0; i < cnt; i++)
		{
			int randomNumber = rand() * pow(2, 17) - rand() * pow(2, 17);
			//cout << randomNumber << endl;
			myTab.pushValueToTable(randomNumber);
		}
		//measure
		auto start = std::chrono::high_resolution_clock::now(); //poczatek odliczania
		myTab.popValueFromTable();
		auto stop = std::chrono::high_resolution_clock::now(); //koniec odliczania
		auto int_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		time += int_ns.count();
	}
	cout << "Sredni czas: " << time / 200 << " ilosc el: " << cnt << " operacja: POP_TAB" << endl;
}

void Measure::measureTableDeleteFront(int cnt)
{

	long time = 0;
	for (int i = 0; i < 200; i++)
	{
		Table myTab;

		for (int i = 0; i < cnt; i++)
		{
			int randomNumber = rand() * pow(2, 17) - rand() * pow(2, 17);
			//cout << randomNumber << endl;
			myTab.pushValueToTable(randomNumber);
		}
		//measure
		auto start = std::chrono::high_resolution_clock::now(); //poczatek odliczania
		myTab.shiftValueFromTable();
		auto stop = std::chrono::high_resolution_clock::now(); //koniec odliczania
		auto int_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		time += int_ns.count();
	}
	cout << "Sredni czas: " << time / 200 << " ilosc el: " << cnt << " operacja: SHIFT_TAB" << endl;
}

void Measure::measureTableDeleteMiddle(int cnt)
{

	long time = 0;
	for (int i = 0; i < 200; i++)
	{
		Table myTab;

		for (int i = 0; i < cnt; i++)
		{
			int randomNumber = rand() * pow(2, 17) - rand() * pow(2, 17);
			//cout << randomNumber << endl;
			myTab.pushValueToTable(randomNumber);
		}
		//measure
		auto start = std::chrono::high_resolution_clock::now(); //poczatek odliczania
		myTab.deleteFromTable(cnt/2);
		auto stop = std::chrono::high_resolution_clock::now(); //koniec odliczania
		auto int_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		time += int_ns.count();
	}
	cout << "Sredni czas: " << time / 200 << " ilosc el: " << cnt << " operacja: DELETE_MIDDLE_TAB" << endl;
}

void Measure::measureTableSearch(int cnt)
{

	long time = 0;
	for (int i = 0; i < 200; i++)
	{
		Table myTab;

		for (int i = 0; i < cnt; i++)
		{
			int randomNumber = rand();
			myTab.pushValueToTable(randomNumber);
		}
		//measure
		int randomVal = rand();
		auto start = std::chrono::high_resolution_clock::now(); //poczatek odliczania
		myTab.searchInTable(randomVal);
		auto stop = std::chrono::high_resolution_clock::now(); //koniec odliczania
		auto int_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		time += int_ns.count();
	}
	cout << "Sredni czas: " << time / 200 << " ilosc el: " << cnt << " operacja: SEARCH_TAB" << endl;
}

void Measure::measureListAddBack(int cnt)
{

	long time = 0;
	for (int i = 0; i < 200; i++)
	{
		Two_way_list list;

		for (int i = 0; i < cnt; i++)
		{
			int randomNumber = rand() * pow(2, 17) - rand() * pow(2, 17);
			list.pushToList(randomNumber);
		}
		//measure
		int randomVal = rand() * pow(2, 17) - rand() * pow(2, 17);
		auto start = std::chrono::high_resolution_clock::now(); //poczatek odliczania
		list.pushToList(randomVal);
		auto stop = std::chrono::high_resolution_clock::now(); //koniec odliczania
		auto int_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		time += int_ns.count();
	}
	cout << "Sredni czas: " << time / 200 << " ilosc el: " << cnt << " operacja: PUSH_LIST" << endl;
}

void Measure::measureListAddFront(int cnt)
{

	long time = 0;
	for (int i = 0; i < 200; i++)
	{
		Two_way_list list;

		for (int i = 0; i < cnt; i++)
		{
			int randomNumber = rand() * pow(2, 17) - rand() * pow(2, 17);
			list.pushToList(randomNumber);
		}
		//measure
		int randomVal = rand() * pow(2, 17) - rand() * pow(2, 17);
		auto start = std::chrono::high_resolution_clock::now(); //poczatek odliczania
		list.unshiftToList(randomVal);
		auto stop = std::chrono::high_resolution_clock::now(); //koniec odliczania
		auto int_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		time += int_ns.count();
	}
	cout << "Sredni czas: " << time / 200 << " ilosc el: " << cnt << " operacja: UNSHIFT_LIST" << endl;
}

void Measure::measureListAddMiddle(int cnt)
{

	long time = 0;
	for (int i = 0; i < 200; i++)
	{
		Two_way_list list;

		for (int i = 0; i < cnt; i++)
		{
			int randomNumber = rand() * pow(2, 17) - rand() * pow(2, 17);
			list.pushToList(randomNumber);
		}
		//measure
		int randomVal = rand() * pow(2, 17) - rand() * pow(2, 17);
		auto start = std::chrono::high_resolution_clock::now(); //poczatek odliczania
		list.addToList(randomVal, cnt/2);
		auto stop = std::chrono::high_resolution_clock::now(); //koniec odliczania
		auto int_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		time += int_ns.count();
	}
	cout << "Sredni czas: " << time / 200 << " ilosc el: " << cnt << " operacja: ADD_LIST" << endl;
}

void Measure::measureListDeleteMiddle(int cnt)
{

	long time = 0;
	for (int i = 0; i < 200; i++)
	{
		Two_way_list list;

		for (int i = 0; i < cnt; i++)
		{
			int randomNumber = rand() * pow(2, 17) - rand() * pow(2, 17);
			list.pushToList(randomNumber);
		}
		//measure
		auto start = std::chrono::high_resolution_clock::now(); //poczatek odliczania
		list.deleteFromList(cnt / 2);
		auto stop = std::chrono::high_resolution_clock::now(); //koniec odliczania
		auto int_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		time += int_ns.count();
	}
	cout << "Sredni czas: " << time / 200 << " ilosc el: " << cnt << " operacja: DELETE_LIST" << endl;
}

void Measure::measureListDeleteBack(int cnt)
{

	long time = 0;
	for (int i = 0; i < 200; i++)
	{
		Two_way_list list;

		for (int i = 0; i < cnt; i++)
		{
			int randomNumber = rand() * pow(2, 17) - rand() * pow(2, 17);
			list.pushToList(randomNumber);
		}
		//measure
		auto start = std::chrono::high_resolution_clock::now(); //poczatek odliczania
		list.popFromList();
		auto stop = std::chrono::high_resolution_clock::now(); //koniec odliczania
		auto int_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		time += int_ns.count();
	}
	cout << "Sredni czas: " << time / 200 << " ilosc el: " << cnt << " operacja: POP_LIST" << endl;
}

void Measure::measureListDeleteFront(int cnt)
{

	long time = 0;
	for (int i = 0; i < 200; i++)
	{
		Two_way_list list;

		for (int i = 0; i < cnt; i++)
		{
			int randomNumber = rand() * pow(2, 17) - rand() * pow(2, 17);
			list.pushToList(randomNumber);
		}
		//measure
		auto start = std::chrono::high_resolution_clock::now(); //poczatek odliczania
		list.shiftFromList();
		auto stop = std::chrono::high_resolution_clock::now(); //koniec odliczania
		auto int_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		time += int_ns.count();
	}
	cout << "Sredni czas: " << time / 200 << " ilosc el: " << cnt << " operacja: SHIFT_LIST" << endl;
}

void Measure::measureListSearch(int cnt)
{

	long time = 0;
	for (int i = 0; i < 200; i++)
	{
		Two_way_list list;

		for (int i = 0; i < cnt; i++)
		{
			int randomNumber = rand();
			list.pushToList(randomNumber);
		}
		//measure
		int randVal = rand();
		auto start = std::chrono::high_resolution_clock::now(); //poczatek odliczania
		list.searchInList(randVal);
		auto stop = std::chrono::high_resolution_clock::now(); //koniec odliczania
		auto int_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		time += int_ns.count();
	}
	cout << "Sredni czas: " << time / 200 << " ilosc el: " << cnt << " operacja: SEARCH_LIST" << endl;
}

void Measure::measureHeapAdd(int cnt)
{
	long time = 0;
	for (int i = 0; i < 200; i++)
	{
		Heap heap;

		for (int i = 0; i < cnt; i++)
		{
			int randomNumber = rand() * pow(2, 17) - rand() * pow(2, 17);
			heap.pushToHeap(randomNumber);
		}
		int randomVal = rand() * pow(2, 17) - rand() * pow(2, 17);
		auto start = std::chrono::high_resolution_clock::now(); //poczatek odliczania
		heap.pushToHeap(randomVal);
		auto stop = std::chrono::high_resolution_clock::now(); //koniec odliczania
		auto int_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		time += int_ns.count();
	}
	cout << "Sredni czas: " << time / 200 << " ilosc el: " << cnt << " operacja: PUSH_HEAP" << endl;
}

void Measure::measureHeapDelete(int cnt)
{
	long time = 0;
	for (int i = 0; i < 200; i++)
	{
		Heap heap;

		for (int i = 0; i < cnt; i++)
		{
			int randomNumber = rand() * pow(2, 17) - rand() * pow(2, 17);
			heap.pushToHeap(randomNumber);
		}
		int randomVal = rand() * pow(2, 17) - rand() * pow(2, 17);
		auto start = std::chrono::high_resolution_clock::now(); //poczatek odliczania
		heap.popRoot();
		auto stop = std::chrono::high_resolution_clock::now(); //koniec odliczania
		auto int_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		time += int_ns.count();
	}
	cout << "Sredni czas: " << time / 200 << " ilosc el: " << cnt << " operacja: POP_HEAP" << endl;
}

void Measure::measureHeapSearch(int cnt)
{
	long time = 0;
	for (int i = 0; i < 200; i++)
	{
		Heap heap;

		for (int i = 0; i < cnt; i++)
		{
			int randomNumber = rand();
			heap.pushToHeap(randomNumber);
		}
		int randomVal = rand();
		auto start = std::chrono::high_resolution_clock::now(); //poczatek odliczania
		heap.searchInHeap(randomVal);
		auto stop = std::chrono::high_resolution_clock::now(); //koniec odliczania
		auto int_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
		time += int_ns.count();
	}
	cout << "Sredni czas: " << time / 200 << " ilosc el: " << cnt << " operacja: SEARCH_HEAP" << endl;
}