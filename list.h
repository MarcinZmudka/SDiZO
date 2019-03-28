#ifndef STRUCT_H
#define STRUCT_H
#include "struct.h"
using namespace std;

class List {
  int value;
  List * next;
  List * prev;
public:
  List(int);
  List * getNext();
  void setNext(List * next);
  List * getPrev();
  void setPrev(List * prev);
  void setValue(int);
  int getValue();
  void delete(int);
  void addRandom(int, int);
  void addFirst(int);
  void addLast(int);
  void search(int);
  void show();
};
#endif
