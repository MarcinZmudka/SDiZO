#include "tree.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include<cstdlib>
#include <string>
#include <conio.h>
#include <math.h>
using namespace std;
/******************************************************************************/
Tree::Tree(){
  this->S = new Tree(1);
  this->up = S;
  this->right = S;
  this->left = S;
  this->color='b';
  this->data = -123;
}
/******************************************************************************/
Tree::Tree(int i){ // konstruktor dla Strażnika
  this->up = this;
  this->left = this;
  this->right = this;
  this->color = 'b';
  this->data = NULL;
}
/******************************************************************************/
void Tree::import(){
  string line;
  fstream file;
  file.open("value.txt", ios::in);
  if(file.good() == true)
  {
      while(!file.eof())
      {
          getline(file, line);
          add(atoi(line.c_str()));
      }
      file.close();
  }
}
/******************************************************************************/
void Tree::find(int l){
  Tree * look = this;
  while(look != S && look->key != l){
    if(l > look->key){
      look = look->right;
    }
    else{
      look = look->left;
    }
    if(look-> key == l){
      cout << endl << "Dana wartość występuje w drzewie";
      break;
    }
  }
}
/******************************************************************************/
void Tree::add(int k){
  if(this->left == S && this->right == S && this->data == -123){
    this->data = k;
  }
  else{
    Tree * adder = new Tree();
    adder->key = k;
    adder->left=S;
    adder->right=S;
    adder->color='r';
    adder->data = k;
    Tree * temp = this;
    while(true){
      if(adder->data > temp->data){ // sprawdzamy gdzie powinnien pójść nowy węzeł
        if(temp->right != S){  // do prawego poddrzewa
          temp = temp->right;
        }
        else{ // czy lewego
          temp->right = adder;
          adder->up = temp;
          break;
        }
      }
      if(adder->data < temp->data){ // analogia do poprzedniego
        if(temp->left != S){
          temp = temp->left;
        }
        else{
          temp->left = adder;
          adder->up = temp;
          break;
        }
      }
    }
    while(adder->up != S && adder->up->color == 'r'){ //jeśli ma czerwonego ojca a sam jest //czerwony adder->up->color == 'r' && adder->color == 'r'
      if(adder->up == adder->up->up->left){
        temp = adder->up->up->right; // bierzemy stryja
        if(
        temp->color =='r' &&
        adder->color == 'r' &&
        adder->up->color == 'r'){ // spradzamy jego kolor, AD.A
          adder->up->color='b'; // zmieniamy kolor ojcowi
          temp->color='b'; // stryjowi
          adder = adder -> up -> up;
          adder->color = 'r';
            //temp = adder->up->up->right; // naprawiamy drzewo do góry!
          continue;
          }
        //AD.C
        if(
        temp->color == 'b' &&
        adder == adder->up->right &&
        adder->up->color =='r' &&
        adder->color == 'r'){
          rotationL(adder->up);
        }
        // AD.B
        rotationR(adder->up->up);
        adder->up->color = 'b';
        adder->up->right -> color = 'r';
        break;
      }
      // analogia dla odbicia
      //
      else{
        temp = adder->up->up->left; // bierzemy stryja
        if(
        temp->color=='r' &&
        adder->color == 'r' &&
        adder->up->color == 'r'){ // spradzamy jego kolor, AD.A
          adder->up->color='b'; // zmieniamy kolor ojcowi
          temp->color='b'; // stryjowi
          adder=adder->up->up;
          adder->color='r'; //dziadkowi
          continue;
          }

        //AD.C
        if(
        temp->color == 'b' &&
        adder == adder->up->left &&
        adder->up->color == 'r' &&
        adder->color == 'r'){
          rotationR(adder->up);
        }
        // AD.B
        rotationL(adder->up->up);
        adder->up->color = 'b';
        adder->up->left->color='r';
        break;
      }
    }
  }
  this->color = 'b';
}
/******************************************************************************/
void Tree::rotationR(Tree * tree){
  Tree * b = tree->left;
  tree->left = b->right;
  b->right = tree;
  b->up = tree->up;
  if(tree->up->left == tree){ // dziadkowi przypisujemy nowego wnuka
    tree->up->left = b;
  }
  else {
    tree->up->right = b;
  }
  tree->up = b;
  b = NULL;
  delete b;
}
/******************************************************************************/
void Tree::rotationL(Tree * tree){ // przy rotacji w lewo giną dane
  Tree * b = tree->right;
  tree->right = b->left; //
  b->left = tree;
  b->up = tree->up; // ustawiamy ojca dla poddrzewa
  if(tree == tree->up->right){
    tree->up->right = b; // dziadkowi przypisujemy nowego wnuka
  }
  else{
    tree->up->left = b;
  }
  tree->up = b; // ojcowi przypisujemy syna jako ojca
  b = NULL;
  delete b;
}
/******************************************************************************/
void Tree::show(Tree * post){
  cout << " "<< post->data << post->color << endl;
  cout << post->left->data << post->left->color << " " << post->right->data << post->right->color << endl << endl;
  if(post->left != S){
    show(post->left);
  }
  if(post ->right != S){
    show(post->right);
  }
}
/******************************************************************************/
Tree * Tree::findNext(Tree * tree){
  if(tree->right != S){
    tree = tree->right;
    while(tree->left != S){
      tree = tree->left;
    }
    return tree;
  }
  else{
    while(tree != S){
      if(tree == tree->up->left){
        return tree;
      }
      if(tree == tree->up->right){
        tree = tree->up;
      }
    }
    tree = NULL;
    delete tree;
    return S;
  }
}
/******************************************************************************/
void Tree::erase(int del){ // gdzieś jest błąd usuwa więcej niż jedną wartość
  Tree * deleter = this;
  while(deleter->data != del){ // znajdujemy węzeł, który zamierzamy usunąć
    if(deleter->data < del && deleter->right != S){
      deleter = deleter->right;
    }
    if(deleter->data > del && deleter->left != S){
      deleter = deleter->left;
    }
  }
  if(deleter -> data != del){
    cout << endl << "there is not such in number in this tree" << endl;
  }
  else{
    //sposób gdy usuwany węzeł ma jednego lub zero dzieci
    if(deleter -> left != S && deleter -> right == S){ // jeśli węzel nie ma prawego syna
      cout <<"\n1";
      Tree * son = deleter->left;
      son->up = deleter->up; // nowy ojciec
      if(deleter->up->left == deleter){ // sprawdzamy czy usuwany węzeł jest prawym czy lewym synem
        son->up->left = son; //
      }
      else{
        son->up->right == son;
      }
      delete deleter; // chyba można
    }
    else if(deleter -> right != S && deleter -> left == S){
      cout <<"\n2";
      Tree * son = deleter->right;
      son->up = deleter->up; // nowy ojciec
      if(deleter->up->left == deleter){ // sprawdzamy czy usuwany węzeł jest prawym czy lewym synem
        son->up->left = son; //
      }
      else{
        son->up->right == son;
      }
      delete deleter; // chyba można
    }
    else if(deleter -> right == S && deleter -> left == S){ // jeśli nie ma dzieci
      cout <<"\n3";
      if(deleter->up->left == deleter){ // sprawdzamy czy usuwany węzeł jest prawym czy lewym synem
        deleter->up->left = S; //
      }
      else{
        deleter->up->right == S;
      }
      delete deleter; // chyba można
    }
    // here it gets complicated
    else if(deleter->right == findNext(deleter)){ // jeśli prawy dzieciak jest następnikiem
      cout <<"\n4";
      Tree * next = findNext(deleter);
      next->left = deleter->left;
      next->up = deleter->up;
      if(deleter == deleter->up->left){
        deleter->up->left = next;
      }
      else{
        deleter->up->right = next;
      }
      next = NULL;
      delete next;
      delete deleter;
    }
    else if(deleter->right != findNext(deleter) && deleter->right != S){ // jeśli ma oba dziecka ale prawe nie jest następnikiem
      cout <<"\n5";
      Tree * next = findNext(deleter);
      next->up->left = next->right;
      next->right = deleter->right;
      next->up = deleter->up;
      deleter->up = next;
      next->left = deleter->left;
      next  = NULL;
      delete deleter;
      delete next;
    }
  }
}
