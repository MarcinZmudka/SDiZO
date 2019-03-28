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
  this->color = 's';
  this->data = -6;
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
  if(this->left == S && this->right == S && this->data ==-123){
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
      if(k > temp->data){ // sprawdzamy gdzie powinnien pójść nowy węzeł
        if(temp->right != S){  // do prawego poddrzewa
          temp = temp->right;
        }
        else{ // czy lewego
          temp->right = adder;
          break;
        }
      }
      if(k < temp->key){ // analogia do poprzedniego
        if(temp->left != S)
          temp = temp->left;
        else{
          temp->left = adder;
          break;
        }
      }
    }
    while(adder->up->color == 'r'){ //jeśli ma czerwonego ojca a sam jest czerwony

      if(adder->up == adder->up->up->left){
        temp = adder->up->up->right; // bierzemy stryja
        if(temp->color=='r'){ // spradzamy jego kolor, AD.A
          adder->up->color='b'; // zmeiniamy kolor ojcowi
          temp->color='b'; // stryjowi
          adder=adder->up->up;
          adder->color='r'; //dziadkowi
          temp = adder->up->up->right; // naprawiamy drzewo do góry!
        }
        //AD.C
        if(temp->color == 'b' && adder == adder->up->right){
          adder = adder->up;
          rotationL(adder);
        }
        // AD.B
        if(temp->color=='b'){
          adder->up->color = 'b';
          adder->up->up->color= 'r';
          rotationR(adder->up->up);
        }
      }
      // analogia dla odbicia
      if(adder->up == adder->up->up->right){
        temp = adder->up->up->left; // bierzemy stryja
        if(temp->color=='r'){ // spradzamy jego kolor, AD.A
          adder->up->color='b'; // zmeiniamy kolor ojcowi
          temp->color='b'; // stryjowi
          adder=adder->up->up;
          adder->color='r'; //dziadkowi
          temp = adder->up->up->left; // naprawiamy drzewo do góry!
        }
        //AD.C
        if(temp->color == 'b' && adder == adder->up->left){
          adder = adder->up;
          rotationR(adder);
        }
        // AD.B
        if(temp->color=='b'){
          adder->up->color = 'b';
          adder->up->up->color= 'r';
          rotationL(adder->up->up);
        }
      }
    }
  }

}
/******************************************************************************/
void Tree::rotationR(Tree * tree){
  Tree * a = S;
  if(tree -> left->right =S){ // jeśli syn nic nie ma w prawym poddrzewie
    tree -> left->right = tree;
  }
  else{
    a = tree -> left->right; //jeśli ma to później trafi do lewego poddrzewa
    tree -> left->right = tree;
  }
  tree->left = a;
  tree->left->up= tree->up; // zmiana ojców
  tree->up = tree->right;
  tree->left =S;
}
/******************************************************************************/
void Tree::rotationL(Tree * tree){
  Tree * a = S;
  if(tree -> right->left =S){ // jeśli syn nic nie ma w lewym poddrzewie
    tree ->right->left = tree;
  }
  else{
    a = tree -> right->left; //jeśli ma to później trafi do prawego poddrzewa
    tree -> right->left = tree;
  }
  tree->right = a;
  tree->right->up= tree->up; // zmiana ojców
  tree->up = tree->right;
  tree->right = S;
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
