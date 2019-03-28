#include "table.h"
#include <iostream>
using namespace std;

Table::Table(int size){
  this->size = size;
  a = new int[size];
  for(int i=0; i<size; i++){
    a[i] = i;
  }
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
/****************************************************************************/
void Table::show(){
  for(int i=0; i<size; i++){
    cout << a[i] << endl;
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
void Table::deleteRandom(int index){
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
