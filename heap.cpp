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
  cout << endl;
  int num = 0;
  int size1 = size;
  while(size1 >= pow(2, num)){
    num++;
  }
  for(int i=1; i<num+1; i++){
    int number =  (2*num+1)/(i+1);
    for(int j=0; j<2*num+1; j++){
      if(j == number){
        cout << table[1];
      }
      else{
        cout << " ";
      }
    }
  }
/*  2^1
  .....
  2^8*2+1*/
}
/******************************************************************************/
void Heap::erase(int number){
  size--;
  int index = 0;
  while(table[index] != number){
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
      cout << endl << key << "znajduje się w kopcu" << endl;
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
