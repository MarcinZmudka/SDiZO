#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<cstdlib>
#include <string>

#include "table.h"
#include "list.h"
#include "heap.h"
#include "tree.h"
#include <windows.h>
using namespace std;
double PCFreq = 0.0;
__int64 CounterStart = 0;

void StartCounter() // sekunda trwa tysiąc
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}


int main (){
  Table * table = new Table();
  /*StartCounter();
  Sleep(1000);
  cout << GetCounter() <<"\n";*/
  int choose;
  while( choose != 5){
    system("cls");
    cout << "Welcome !\n"
         << " 1 - table\n"
         << " 2 - list\n "
         << " 3 - heap\n"
         << " 4 - RBT\n"
         << " 5 - end \n";
    cin >> choose;
    switch( choose ){
      case 1: table();
      continue;
      case 2: list();
      continue;
      case 3: heap();
      continue;
      case 4: tree();
      continue;
      case 5:
      break;
    }
  }

  return 0;
}

/*void table(){
  int choose;
  Table * table = new Table();
  while( choose != 5){
    system("cls");
    cout << " 1 - Dodaj na poczatek\n"
         << " 2 - Dodaj na koniec\n "
         << " 3 - Dodaj na dowolna pozycje\n"
         << " 4 - Usun pierwszy indeks\n"
         << " 5 - Usun ostatni indeks \n"
         << " 6 - Usun dowolny indeks \n"
         << " 7 - Pokaż \n";
    cin >> choose;
    switch( choose ){
      case 1:
        int i = 0;
        cout << "Podaj cyfre";
        cin >> i;
        table->addFirst(i);
      continue;
      case 2: //list();
      continue;
      case 3:// heap();
      continue;
      case 4:// tree();
      continue;
      case 5:
      break;
    }
  }
}*/
