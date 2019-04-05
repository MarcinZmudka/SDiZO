#include "heap.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include<cstdlib>
#include <string>
#include <conio.h>
#include <math.h>
using namespace std;
/******************************************************************************/
Heap::Heap(){
    this -> size = 0;
    import();
}
/******************************************************************************/
void Heap::add(int a){
  if(size == 0){
    size = 1;
    table = new int [1];
    table[0] = a;
  }
  else{
    size++;
    int * table2 =  new int[size];
    for(int i =0 ; i< size-1; i++){
      table2[i] = table[i];
    }
    table2[size-1] = a;
    delete[] table;
    table = table2;
    sort(size-1);
  }
}
/******************************************************************************/
void Heap::sort(int index){
  int parent = (index-1)/2;
  if(table[parent] < table[index]){
    int a = table[parent];
    table[parent] = table[index];
    table[index] = a;
    if(parent != 0)
    sort(parent);
  }
}
/******************************************************************************/
void Heap::show(){
  for(int i = 0; i<size; i++){
    cout << table[i] << " ";
  }
  /*cout << endl;
  int num = 0;
  int size1 = size;
  while(size1 > pow(2, num)){
    num++;
  }
  String[] first = new String [num];
  int num1 = num;
  for(int i=0; i< num; i++){
    int num2 = pow(2, num1-1);
    num1--;
    String a = "";
    for(int j=0; j<num2){
      a+= " ";
    }
    first[i] = a;
  }
  String[] mid = new String[num];
  num1 = num;
  for(int i=num1-1; i>-1; i--){
    for(int j =0; j<pow(i, num1); i++){
      mid[i] += " "
    }
    mid[i]+= " ";
    num1--;
  }
  for(int i=0; i<num; i++){

  }*/
}
/******************************************************************************/
void Heap::erase(int number){ //usuwanie z kopca
  size--;
  int index = 0;
  while(table[index] != number){ // szukamy jaki indeks ma usuwana liczba
    index++;
  }
  int * table2 = new int[size];
  for(int i=0; i<index;i++){
    table2[i] = table[i];
  }
  for(int i = index; i<size;i++){
    table2[i] = table[i+1];
  }
  delete[] table;
  table = table2;
  for(int i=size; i>0; i--){
    sort(i);
  }
}
/******************************************************************************/
void Heap::find(int key){
  for(int i = 0; i< size; i++){
    if(table[i] == key){
      cout << endl << key << "znajduje sie w kopcu" << endl;
      break;
    }
  }
}
/******************************************************************************/
void Heap::import(){
  string line;
  fstream file;
  file.open("value.txt", ios::in);
  if(file.good() == true)
  {
      while(!file.eof())
      {
          getline(file, line);
          add(atoi(line.c_str()));
      }
      file.close();
  }
}
