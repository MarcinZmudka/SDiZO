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
// erase nie naprawia poddrzewa
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
void Tree::remove(int del) {
    Tree *W, *Y, *Z;
    Tree * deleter = this;
    while(deleter->data != del){ // znajdujemy węzeł, który zamierzamy usunąć
      if(deleter->data < del && deleter->right != S){
        deleter = deleter->right;
      }
      if(deleter->data > del && deleter->left != S){
        deleter = deleter->left;
      }
    }
    if ((deleter->left == S) || (deleter->right == S)){
      Y = deleter;
    }
    else{
      Y = findNext(deleter);
    }

    if (Y->left != S){
      Z = Y->left;
    }
    else{
      Z = Y->right;
    }
    Z->up = Y->up;
    if (Y == Y->up->left){
      Y->up->left = Z;
    }
    else{
      Y->up->right = Z;
    }

    if (Y != deleter){
      deleter->data = Y->data;
    }
    if (Y->color == 'b')   // Naprawa struktury drzewa czerwono-czarnego
        while ((Z != S) && (Z->color == 'b'))
            if (Z == Z->up->left) {
                W = Z->up->right;

                //Przypadek 1
                if (W->color == 'r') {
                    W->color = 'b';
                    Z->up->color = 'r';
                    rotationL(Z->up);
                    W = Z->up->right;
                }

                //Przypadek 2
                if ((W->left->color == 'b') && (W->right->color == 'b')) {
                    W->color = 'r';
                    Z = Z->up;
                    continue;
                }

                //Przypadek 3
                if (W->right->color == 'b') {
                    W->left->color = 'b';
                    W->color = 'r';
                    rotationR(W);
                    W = Z->up->right;
                }

                //Przypadek 4
                W->color = Z->up->color;
                Z->up->color = 'b';
                W->right->color = 'b';
                rotationL(Z->up);

                //Zakończenie pętli
                Z = S;

                //Przypadki lustrzane
            } else {
                W = Z->up->left;

                //Lustrzany przypadek 1
                if (W->color == 'r') {
                    W->color = 'b';
                    Z->up->color = 'r';
                    rotationL(Z->up);
                    W = Z->up->left;
                }

                //Lustrzany przypadek 2
                if ((W->left->color == 'b') && (W->right->color == 'b')) {
                    W->color = 'r';
                    Z = Z->up;
                    continue;
                }

                //Lustrzany przypadek 3
                if (W->left->color == 'b') {
                    W->right->color = 'b';
                    W->color = 'r';
                    rotationL(W);
                    W = Z->up->left;
                }

                //Lustrzany przypadek 4
                W->color = Z->up->color;
                Z->up->color = 'b';
                W->left->color = 'b';
                rotationR(Z->up);

                //Zakończenie pętli
                Z = S;
            }
    Z->color = 'b';
    delete Y;
}
