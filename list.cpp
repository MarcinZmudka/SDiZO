#include "list.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

List::List(){
  next = NULL;
  prev = NULL;
  import();
}
/****************************************************************************/
List::List(int value){
  this->value = value;
  next = NULL;
  prev = NULL;
}
/****************************************************************************/
List * List::getNext(){
  return next;
}
/****************************************************************************/
void  List::setNext(List * next){
  this->next=next;
}
/****************************************************************************/
List * List::getPrev(){
  return prev;
}
/****************************************************************************/
void  List::setPrev(List * prev){
  this->prev = prev;
}
/****************************************************************************/
void  List::setValue(int value){
  this -> value = value;
}
/****************************************************************************/
int  List::getValue(){
  return value;
}
/****************************************************************************/
void List::deleteNumber(int value1){
  List * more;
  more = this->getNext();
  while(more){
    if(more->getValue() == value1){

      (more->getPrev())->setNext(more->getNext());
      cout << more->getPrev()->getValue() << endl;
      more->getNext()->setPrev(more->getPrev());
      break;
    }
    more = more->getNext();
  }
}
/****************************************************************************/
void List::addRandom(int previous, int value1){
  List * more;
  List * add = new List(value1);
  more = this;
  while(more){
    if( previous == more->getValue()){
      add->setNext(more->getNext());
      add->setPrev(more);
      more->setNext(add);
      add->getNext()->setPrev(add);
    }
    more = more->getNext();
  }
  add = NULL;
  more = NULL;
  delete add;
  delete more;
}
/****************************************************************************/
void List::addFirst(int value1){
  this->setPrev(new List(value1));
  this->getPrev()->setNext(this);
}
/****************************************************************************/
void List::addLast(int value1){
  List * more = this;
  while(more){
    if(!more->getNext()){
      more->setNext(new List(value1));
      more->getNext()->setPrev(more);
      break;
    }
    more = more->getNext();
  }
  more = NULL;
  delete more;
}
/****************************************************************************/
void List::search( int value1 ){
  List * more = this;
  while(more->getNext()){
    if(more->getValue() == value1){
      cout << "jest" << endl;
      break;
    }
    more = more->getNext();
  }
  more = NULL;
  delete more;
}
  /****************************************************************************/
  void List::show(){
    List * a = this;
    while(a->getPrev()){
      a = a->getPrev();
    }
    while(a){
      cout << a->getValue() << endl;
      a = a->getNext();
    }
    a = NULL;
    delete a;
  }
  /*****************************************************************************/
  void List::import(){
    string line;
    fstream file;
    file.open("value.txt", ios::in);
    getline(file, line);
    value = atoi(line.c_str());
    if(file.good() == true)
    {
        while(!file.eof())
        {
            getline(file, line);
            addLast(atoi(line.c_str()));
        }
        file.close();
    }
  }
/*****************************************************************************/
void List::deleteFirst(){

}
/*****************************************************************************/
void List::deleteLast(){

}
