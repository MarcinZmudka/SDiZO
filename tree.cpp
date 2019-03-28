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

    while(adder != S){ //jeśli ma czerwonego ojca a sam jest //czerwony adder->up->color == 'r' && adder->color == 'r'
    cout << "1";
      if(adder->up == adder->up->up->left){
        temp = adder->up->up->right; // bierzemy stryja
        if(
        temp->color =='r' &&
        adder->color == 'r' &&
        adder->up->color == 'r'){ // spradzamy jego kolor, AD.A
          adder->up->color='b'; // zmieniamy kolor ojcowi
          temp->color='b'; // stryjowi
          if(adder->up->up->up != S){
            //adder->up->up->color='r';
            adder = adder -> up -> up;
            adder->color = 'r';
            //temp = adder->up->up->right; // naprawiamy drzewo do góry!
            continue;
          }
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
        if(
        temp->color=='b' &&
        adder->up->color =='r' &&
        adder->color=='r' &&
        adder == adder->up->left){
          rotationR(adder->up->up);
          adder->up->color = 'b';
          adder->up->right -> color = 'r';
        }
      }
      // analogia dla odbicia
      //
      if(adder->up == adder->up->up->right){
        temp = adder->up->up->left; // bierzemy stryja
        if(
        temp->color=='r' &&
        adder->color == 'r' &&
        adder->up->color == 'r'){ // spradzamy jego kolor, AD.A
          adder->up->color='b'; // zmieniamy kolor ojcowi
          temp->color='b'; // stryjowi
          if(adder-> up -> up -> up != S){
            adder=adder->up->up;
            adder->color='r'; //dziadkowi
            //temp = adder->up->up->left; // naprawiamy drzewo do góry!
            continue;
          }
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
        if(
        temp->color=='b' &&
        adder->up->color =='r' &&
        adder->color=='r' &&
        adder == adder->up->right){
          rotationL(adder->up->up);
          adder->up->color = 'b';
          adder->up->left->color='r';
        }
      }
      adder = adder->up;
      continue;
    }
  }
  //show(this);
  //getch();
  //system("cls");
}
/******************************************************************************/
void Tree::rotationR(Tree * tree){
  Tree * b = tree->left;
  cout << "R";
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
  cout << "L";
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
