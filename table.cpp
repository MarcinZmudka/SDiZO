#include "table.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<cstdlib>
#include <string>
using namespace std;

Table::Table(){
  a = NULL;
  size = 0;
  import();
}
/****************************************************************************/
void Table::addFirst(int number){
  size++;
  int * b = new int [size];
  b[0] = number;
  for(int i=1; i < size; i++){
    b[i]=a[i-1];
  }
  delete[] a;
  a = b;
}
/****************************************************************************/
void Table::addLast(int number){
  size++;
  int * b = new int [size];
  for(int i=0; i<size-1; i++){
    b[i] = a[i];
  }
  b[size-1] = number;
  delete[] a;
  a = b;
}
/****************************************************************************/
void Table::addRandom(int number, int index){
  if(index > size){
    cout << "Za duzy indeks\n";
  }
  else{
    size++;
    int *b = new int [size];
    for(int i =0; i<index; i++){
      b[i]=a[i];
    }
    b[index] = number;
    for(int i = index+1; i<size;i++){
      b[i] = a[i-1];
    }
    delete[] a;
    a = b;
  }
}
/****************************************************************************/
void Table::show(){
  cout << endl;
  for(int i=0; i<size; i++){
    cout << a[i]<< " ";
  }
  cout << endl;
}
/****************************************************************************/
void Table::deleteFirst(){
  size--;
  int *b = new int [size];
  for(int i =0; i<size; i++){
    b[i]=a[i+1];
  }
  delete[] a;
  a = b;
}
/****************************************************************************/
void Table::deleteLast(){
  size--;
  int *b = new int [size];
  for(int i =0; i< size; i++){
    b[i] = a[i];
  }
  delete[] a;
  a = b;
}
/****************************************************************************/
void Table::deleteNumber(int index){
  if(size < index){
    cout << "Wybrales liczbe spoza indeksu\n";
  }
  else{
    size--;
    int *b= new int [size];
    for(int i=0; i<index; i++){
      b[i] = a[i];
    }
    for(int i=index; i<size+1; i++){
      b[i] = a[i+1];
    }
    delete[] a;
    a = b;
  }
}
/****************************************************************************/
void Table::import(){
  string line;
  fstream file;
  file.open("value.txt", ios::in);
  if(file.good() == true){
      while(!file.eof())
      {
          getline(file, line);
          addLast(atoi(line.c_str()));
      }
      file.close();
  }
}
/****************************************************************************/
void Table::find(int find){
  int i = 0;
  while(i < size){
    if(a[i] == find){
      cout << find << " znajduje sie w tablicy\n";
      break;
    }
    i++;
  }
  i++;
  if(i == size){
    cout << find << " nie znajduje sie w tablicy\n";
  }
}
