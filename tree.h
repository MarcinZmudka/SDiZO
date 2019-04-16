using namespace std;
class Tree  {
  public:
  Tree * S;
  Tree * up;
  Tree * left;
  Tree * right;
  int data;
  int key;
  char color;
  Tree();
  Tree(int);
  Tree * import();
  void show(Tree * post);
  void show(int,Tree ** table, Tree * post);
  Tree * add(int);
  void remove(int);
  void sort(int);
  void find(int);
  void rotationR(Tree * tree);
  void rotationL(Tree * tree);
  Tree * findNext(Tree * tree);
};
