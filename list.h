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
  void deleteNumber(int);
  void deleteFirst();
  void deleteLast();
  void add(int, int);
  List * addFirst(int);
  void search(int);
  void show();
  void import();
};
