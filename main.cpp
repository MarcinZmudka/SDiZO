#include <iostream>
#include <fstream>
#include <stdlib.h>
#include<cstdlib>
#include <string>
//#include "struct.h"
//#include "table.h"
//#include "list.h"
//#include "heap.h"
#include "tree.h"
using namespace std;
/*List * load(){
    string linia;
    fstream plik;
    plik.open("value.txt", ios::in);
    List * abs;
    if(plik.good() == true)
    {
        getline(plik, linia);
        int val = atoi(linia.c_str());
        abs = new List(val);
        while(!plik.eof())
        {
            getline(plik, linia);
            val = atoi(linia.c_str());
            abs->setNext(new List(val));
            abs->getNext()->setPrev(abs);
            abs = abs->getNext();
        }
        plik.close();
    }
    return abs;
}*/
int main (){
  Tree * a = new Tree();
  a->import();
  a->show(a);
  a->remove(12); // usuneło też 13
  a->show(a);
  return 0;
}
