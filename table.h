using namespace std;
// dodać wyszukiwanie
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
  void find(int);
};
