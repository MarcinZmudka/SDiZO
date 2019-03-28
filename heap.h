using namespace std;
/*#ifndef STRUCT_H
#define STRUCT_H*/
class Heap  {
  int * table;
  int size;
public:
//elo
  Heap();
  void show();
  void add(int);
  void erase(int);
  void sort(int);
  void find(int);
};

//#endif
