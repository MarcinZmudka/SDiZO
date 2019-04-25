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
  more = this;
  while(more){
    if(more->getValue() == value1){
      if(more->getPrev() == nullptr){
        this->deleteFirst();
        return;
      }
      (more->getPrev())->setNext(more->getNext());
      more->getNext()->setPrev(more->getPrev());
      break;
    }
    more = more->getNext();
  }
}
/****************************************************************************/
void List::add(int previous, int value1){
  List * more;
  List * add = new List(value1);
  more = this;
  bool check = false;
  while(more){
    if( previous == more->getValue()){
      add->setNext(more->getNext());
      add->setPrev(more);
      more->setNext(add);
      add->getNext()->setPrev(add);
      check = true;
    }
    more = more->getNext();
  }
  if(check == false){
    cout << "\n wartosc poprzedzajaca nie zostala odnaleziona\n";
  }
  add = NULL;
  more = NULL;
  delete add;
  delete more;
}
/****************************************************************************/
List * List::addFirst(int value1){
  this->setPrev(new List(value1));
  this->getPrev()->setNext(this);
  return this->getPrev();
}
/****************************************************************************/
void List::search( int value1 ){
  List * more = this;
  while(more->getPrev()){
    more = more->getPrev();
  }
  bool check = false;
  while(more->getNext()){
    if(more->getValue() == value1){
      cout << value1 << " znajduje sie w liscie" << endl;
      check = true;
      break;
    }
    more = more->getNext();
  }
  if(!check){
    cout << value1 << " nie znajduje sie w liscie" << endl;
  }
  more = NULL;
  delete more;
}
  /****************************************************************************/
  void List::show(){
    List * a = this;
    cout << endl;
    while(a->getPrev()){
      a = a->getPrev();
    }
    while(a){
      cout << a->getValue() << " ";
      a = a->getNext();
    }
    a = NULL;
    cout << endl;
    delete a;
  }
  /*****************************************************************************/
  void List::import(){ // dodawanie nie działa, pomyśleć nad rozwiązaniem
    string line;
    fstream file;
    file.open("value.txt", ios::in);
    getline(file, line);
    List * niu = this;
    niu->setValue(atoi(line.c_str()));
    if(file.good() == true)
    {
        while(!file.eof())
        {
            getline(file, line);
            niu = niu->addFirst(atoi(line.c_str()));
        }
        file.close();
    }
  }
/*****************************************************************************/
void List::deleteFirst(){
  List * nexter = this;
  while(nexter->getPrev()){
    nexter = nexter->getPrev();
  }
  while(nexter->getNext() != NULL){
    nexter->setValue(nexter->getNext()->getValue());
    nexter = nexter->getNext();
  }
  nexter->getPrev()->setNext(NULL);
  delete nexter;
}
/*****************************************************************************/
void List::deleteLast(){
  List * nexter = next;
  while(nexter->getPrev()){
    nexter = nexter->getPrev();
  }
  while(nexter->getNext() != NULL){
    nexter = nexter->getNext();
  }
  nexter->getPrev()->setNext(NULL);
  nexter = NULL;
  delete nexter;
}
