using namespace std;
#ifndef STRUCT_H
#define STRUCT_H
class Table {
  int * a;
  int size;
public:
  Table(int);
  void addFirst(int);
  void addLast(int number);
  void addRandom(int number, int index);
  void show();
  void deleteFirst();
  void deleteLast();
  void delete(int index);
};
#endif
