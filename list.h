using namespace std;
 //dorobić usuwanie na pierwszej i ostaniej pozycji
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
  void deleteNumber(int);
  void deleteFirst();
  void deleteLast();
  void addRandom(int, int);
  void addFirst(int);
  void addLast(int);
  void search(int);
  void show();
  void import();
};
