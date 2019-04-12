#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<cstdlib>
#include <string>
#include <windows.h>

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
    if(!QueryPerformanceFrequency(&li))
    cout << "QueryPerformanceFrequency failed!\n";

    PCFreq = double(li.QuadPart)/1000.0;

    QueryPerformanceCounter(&li);
    CounterStart = li.QuadPart;
}
/******************************************************************************/
double GetCounter() // podaje czas w milisekundach
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}
/******************************************************************************/
void tableMenu(){
  int choose;
  Table * table = new Table();
  while(choose != 8){
    system("cls");
    cout << " 1 - Dodaj na poczatek\n"
         << " 2 - Dodaj na koniec\n"
         << " 3 - Dodaj na dowolna pozycje\n"
         << " 4 - Usun pierwszy indeks\n"
         << " 5 - Usun ostatni indeks\n"
         << " 6 - Usun dowolny indeks\n"
         << " 7 - Pokaz \n"
         << " 8 - Wyjdz \n";
    cin >> choose;
    int i = 0, j=0;
    switch( choose ){
      case 1:
        cout << "Podaj cyfre";
        cin >> i;
        table->addFirst(i);
        system("pause");
        break;
      case 2:
        cout << "Podaj cyfre";
        cin >> i;
        table->addLast(i);
        system("pause");
        break;
      case 3:
        cout << "Podaj cyfre :";
        cin >> i;
        cout << "Podaj indeks :";
        cin >> j;
        table->addRandom(i, j);
        system("pause");
        break;
      case 4:
        table->deleteFirst();
        system("pause");
        break;
      case 5:
        table->deleteLast();
        system("pause");
        break;
      case 6:
        cout << "Podaj indeks :";
        cin >> j;
        table->deleteNumber(j);
        system("pause");
        break;
      case 7:
        table->show();
        system("pause");
        break;
      case 8:
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
  while(choose != 7){
    system("cls");
    cout << " 1 - Dodaj wartosc\n"
         << " 2 - Usun pierwszy indeks\n"
         << " 3 - Usun ostatni indeks\n"
         << " 4 - Usun dowolna wartosc\n"
         << " 5 - Pokaz\n"
         << " 6 - Wyszukaj \n"
         << " 7 - Wyjdz \n";
    cin >> choose;
    int i = 0, j=0;;
    switch( choose ){
      case 1:
        cout << "Podaj cyfre :";
        cin >> i;
        cout << "Podaj poprzedzajaca wartosc :";
        cin >> j;
        list->add(j, i);
        system("pause");
        break;
      case 2:
        list = list->getNext();
        list->getPrev()->deleteFirst();
        system("pause");
        break;
      case 3:
        list->deleteLast();
        system("pause");
        break;
      case 4:
        cout << "Podaj wartosc :";
        cin >> j;
        list->deleteNumber(j);
        system("pause");
        break;
      case 5:
        list->show();
        system("pause");
        break;
      case 6:
        cout << "\nPodaj liczby do wyszukania :";
        cin  >> i;
        list->search(i);
        system("pause");
        break;
      case 7:
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
  while(choose != 5){
    system("cls");
    cout << " 1 - Dodaj\n" // ??????????
         << " 2 - Usun\n" // ??????????
         << " 3 - Pokaz \n"
         << " 4 - Wyszukaj \n"
         << " 5 - Wyjdz\n";
    cin >> choose;
    int i = 0, j=0;;
    switch( choose ){
      case 1:
        cout << "Podaj cyfre :";
        cin >> i;
        heap->add(i);
        system("pause");
        break;
      case 2:
        cout << "Podaj wartosc :";
        cin >> j;
        heap->erase(j);
        system("pause");
        break;
      case 3:
        heap->show();
        system("pause");
        break;
      case 4:
        cout << "\nPodaj liczby do wyszukania :";
        cin  >> i;
        heap->find(i);
        system("pause");
        break;
      case 5:
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
  tree->import();
  while(choose != 5){
    system("cls");
    cout << " 1 - Dodaj na poczatek\n"
         << " 2 - Usun pierwszy indeks\n"
         << " 3 - Pokaz \n"
         << " 4 - Wyszukaj \n"
         << " 5 - Wyjdz \n";
    cin >> choose;
    int i = 0, j=0;;
    switch( choose ){
      case 1:
        cout << "Podaj cyfre :";
        cin >> i;
        tree->add(i);
        system("pause");
        break;
      case 2:
        cout << "Podaj wartosc :";
        cin >> j;
        tree->remove(j);
        system("pause");
        break;
      case 3:
        tree->show(tree);
        system("pause");
        break;
      case 4:
        cout << "\nPodaj liczby do wyszukania :";
        cin  >> i;
        tree->find(i);
        system("pause");
        break;
      case 5:
        break;
      default: cout << "\nWybrales zly numer\n";
        break;
    }
  }
}
/******************************************************************************/
int main (){
  fstream file("1000.txt", ios::out);
  /*if(file.good()){
    for(int i=0;i< 5000; i++){
      file << i << endl;
      file.flush();
    }
  }*/
  /*Tree * tree = new Tree();
  tree = tree->import();
  tree->show(tree);*/
  Tree * table = new Tree();
  StartCounter();
  table = table->import();
  file << GetCounter() << endl;
  file.flush();
  StartCounter();
  table = table->add(115268);
  file << GetCounter() << endl;
  file.flush();
  StartCounter();
  table->remove(1);
  file << GetCounter() << endl;
  file.flush();
  StartCounter();
  table->find(14996);
  file << GetCounter() << endl;
  file.flush();
  file.close();
  cout << "elo";
  int choose;
  while( choose != 5){
    //system("cls");
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
