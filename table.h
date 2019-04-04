using namespace std;
#ifndef STRUCT_H
#define STRUCT_H
class Table {
  int * a;
  int size;
public:
  Table();
  void addFirst(int);
  void addLast(int number);
  void addRandom(int number, int index);
  void show();
  void deleteFirst();
  void deleteLast();
  void deleteNumber(int index);
  void import();
};
#endif
