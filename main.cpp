#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<cstdlib>
#include <string>
#include <windows.h>
#include <chrono>
#include "table.h"
#include "list.h"
#include "heap.h"
#include "tree.h"
using namespace std;
double PCFreq = 0.0;
__int64 CounterStart = 0;
void StartCounter()
{
    LARGE_INTEGER li;
    if( !QueryPerformanceFrequency( & li ) )
         cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double( li.QuadPart ) / 1000.0;

    QueryPerformanceCounter( & li );
    CounterStart = li.QuadPart;
}
double GetCounter()
{
    LARGE_INTEGER li;
    QueryPerformanceCounter( & li );
    return double( li.QuadPart - CounterStart ) / PCFreq;
}
/******************************************************************************/
void tableMenu(){
  int choose;
  Table * table = new Table();
  while(choose != 9){
    system("cls");
    cout << " 1 - Dodaj na poczatek\n"
         << " 2 - Dodaj na koniec\n"
         << " 3 - Dodaj na dowolna pozycje\n"
         << " 4 - Usun pierwszy indeks\n"
         << " 5 - Usun ostatni indeks\n"
         << " 6 - Usun dowolny indeks\n"
         << " 7 - Pokaz \n"
         << " 8 - dodaj 30 liczb\n"
         << " 9 - Wyjdz \n";
    cin >> choose;
    int i = 0, j=0;
    switch( choose ){
      case 1:
        cout << "Podaj cyfre";
        cin >> i;
        StartCounter();
        table->addFirst(i);
        cout << endl << "Czas: " << GetCounter() << endl;
        system("pause");
        break;
      case 2:
        cout << "Podaj cyfre";
        cin >> i;
        StartCounter();
        table->addLast(i);
        cout << endl << "Czas: " << GetCounter() << endl;
        system("pause");
        break;
      case 3:
        cout << "Podaj cyfre :";
        cin >> i;
        cout << "Podaj indeks :";
        cin >> j;
        StartCounter();
        table->addRandom(i, j);
        cout << endl << "Czas: " << GetCounter() << endl;
        system("pause");
        break;
      case 4:
        StartCounter();
        table->deleteFirst();
        cout << endl << "Czas: " << GetCounter() << endl;
        system("pause");
        break;
      case 5:
        StartCounter();
        table->deleteLast();
        cout << endl << "Czas: " << GetCounter() << endl;
        system("pause");
        break;
      case 6:
        cout << "Podaj indeks :";
        cin >> j;
        StartCounter();
        table->deleteNumber(j);
        cout << endl << "Czas: " << GetCounter() << endl;
        system("pause");
        break;
      case 7:
        StartCounter();
        table->show();
        cout << endl << "Czas: " << GetCounter() << endl;
        system("pause");
        break;
      case 8:
        for(int i=0; i<30; i++){
          table->addLast(i+100);
        }
        break;
      case 9:
        break;
      default: cout << "\nWybrales zly numer\n";
      break;
    }
  }
}
/******************************************************************************/
void listMenu(){
  int choose = 0;
  List * list = new List();
  while(list->getPrev()){
    list = list->getPrev();
  }
  while(choose != 8){
    system("cls");
    cout << " 1 - Dodaj wartosc\n"
         << " 2 - Usun pierwszy element\n"
         << " 3 - Usun ostatni element\n"
         << " 4 - Usun dowolna wartosc\n"
         << " 5 - Pokaz\n"
         << " 6 - Wyszukaj \n"
         << " 7 - dodaj 30 liczb\n"
         << " 8 - Wyjdz \n";
    cin >> choose;
    int i = 0, j=0;;
    switch( choose ){
      case 1:
        cout << "Podaj cyfre : ";
        cin >> i;
        cout << "Podaj poprzedzajaca wartosc : ";
        cin >> j;
        StartCounter();
        list->add(j, i);
        cout << endl << "Czas: " << GetCounter() << endl;
        system("pause");
        break;
      case 2:
        list = list->getNext();
        StartCounter();
        list->getPrev()->deleteFirst();
        cout << endl << "Czas: " << GetCounter() << endl;
        system("pause");
        break;
      case 3:
        StartCounter();
        list->deleteLast();
        cout << endl << "Czas: " << GetCounter() << endl;
        system("pause");
        break;
      case 4:
        cout << "Podaj wartosc : ";
        cin >> j;
        StartCounter();
        list->deleteNumber(j);
        cout << endl << "Czas: " << GetCounter() << endl;
        system("pause");
        break;
      case 5:
        StartCounter();
        list->show();
        cout << endl << "Czas: " << GetCounter() << endl;
        system("pause");
        break;
      case 6:
        cout << "\nPodaj liczby do wyszukania : ";
        cin  >> i;
        StartCounter();
        list->search(i);
        cout << endl << "Czas: "  << GetCounter() << endl;
        system("pause");
        break;
      case 7:
        for(int i=0; i<30; i++){
          list->add(10, i+100);
        }
        break;
      case 8:
        break;
      default: cout << "\nWybrales zly numer\n";
        break;
    }
  }
}
/******************************************************************************/
void heapMenu(){
  int choose = 0;
  Heap * heap = new Heap();
  while(choose != 6){
    system("cls");
    cout << " 1 - Dodaj\n" // ??????????
         << " 2 - Usun\n" // ??????????
         << " 3 - Pokaz \n"
         << " 4 - Wyszukaj \n"
         << " 5 - dodaj 30 licz\n"
         << " 6 - Wyjdz\n";
    cin >> choose;
    int i = 0, j=0;;
    switch( choose ){
      case 1:
        cout << "Podaj cyfre :";
        cin >> i;
        StartCounter();
        heap->add(i);
        cout << endl << "Czas: " << GetCounter() << endl;
        system("pause");
        break;
      case 2:
        cout << "Podaj wartosc :";
        cin >> j;
        StartCounter();
        heap->erase(j);
        cout << endl << "Czas: " << GetCounter() << endl;
        system("pause");
        break;
      case 3:
        StartCounter();
        heap->show();
        cout << endl << "Czas: " << GetCounter() << endl;
        system("pause");
        break;
      case 4:
        cout << "\nPodaj liczby do wyszukania :";
        cin  >> i;
        StartCounter();
        heap->find(i);
        cout << endl << "Czas: " << GetCounter() << endl;
        system("pause");
        break;
      case 5:
        for(int i=0; i<30; i++){
          heap->add(20+i);
        }
        break;
      case 6:
        break;
      default: cout << "\nWybrales zly numer\n";
        break;
    }
  }
}
/******************************************************************************/
void treeMenu(){
  int choose = 0;
  Tree * tree = new Tree();
  tree = tree->import();
  while(choose != 6){
    system("cls");
    cout << " 1 - Dodaj\n"
         << " 2 - Usun\n"
         << " 3 - Pokaz\n"
         << " 4 - Wyszukaj\n"
         << " 5 - Dodaj 30 liczb\n"
         << " 6 - Wyjdz \n";
    cin >> choose;
    int i = 0, j=0;;
    switch( choose ){
      case 1:
        cout << "Podaj cyfre :";
        cin >> i;
        StartCounter();
        tree = tree->add(i);
        cout << endl << "Czas: " << GetCounter() << endl;
        system("pause");
        break;
      case 2:
        cout << "Podaj wartosc :";
        cin >> j;
        StartCounter();
        tree->remove(j);
        cout << endl << "Czas: " << GetCounter() << endl;
        system("pause");
        break;
      case 3:
        StartCounter();
        tree->show(tree);
        cout << endl << "Czas: " << GetCounter() << endl;
        system("pause");
        break;
      case 4:
        cout << "\nPodaj liczby do wyszukania :";
        cin  >> i;
        StartCounter();
        tree->find(i);
        cout << endl << "Czas: " << GetCounter() << endl;
        system("pause");
        break;
      case 5:
        for(int i=0; i<30; i++){
          tree = tree->add(i+10);
        }
        break;
      case 6:
        break;
      default: cout << "\nWybrales zly numer\n";
        break;
    }
  }
}
/******************************************************************************/
int main (){
  int choose;
  while( choose != 5){
    system("cls");
    cout << "Welcome !\n"
         << " 1 - table\n"
         << " 2 - list\n"
         << " 3 - heap\n"
         << " 4 - RBT\n"
         << " 5 - end \n";
    cin >> choose;
    switch( choose ){
      case 1: tableMenu();
        break;
      case 2: listMenu();
        break;
      case 3: heapMenu();
        break;
      case 4: treeMenu();
        break;
      case 5:
      break;
    }
  }
  return 0;
}
