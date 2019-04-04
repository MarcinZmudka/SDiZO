#ifndef STRUCT_H
#define STRUCT_H
using namespace std;

class List {
  int value;
  List * next;
  List * prev;
public:
  List();
  List(int);
  List * getNext();
  void setNext(List * next);
  List * getPrev();
  void setPrev(List * prev);
  void setValue(int);
  int getValue();
  void remove(int);
  void addRandom(int, int);
  void addFirst(int);
  void addLast(int);
  void search(int);
  void show();
  void import();
};
#endif
