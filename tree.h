using namespace std;
class Tree  {
  Tree * S;
  Tree * up;
  Tree * left;
  Tree * right;
  int data;
  int key;
  char color;
public:

  Tree();
  Tree(int);
  void import();
  void show(Tree * post);
  void add(int);
  void erase(int);
  void sort(int);
  void find(int);
  void rotationR(Tree * tree);
  void rotationL(Tree * tree);
};