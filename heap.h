using namespace std;

class Heap  {
  int * table;
  int size;
public:

  Heap();
  void show();
  void add(int);
  void erase(int);
  void sort(int);
  void find(int);
  void import();
};
