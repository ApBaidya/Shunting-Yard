/*
Aparajita Baidya 3.4.2026  
Binary tree node
Will also act as the linked list node (hence the next)
*/
#ifndef NODE
#define NODE

#include <iostream>
#include <cstring>

using namespace std;

class BiTreeNode(){
 private:
  BiTreeNode * right;
  BiTreeNode * left;
  BiTreeNode * next;//next specifically for LL
  char* data;
 public:
  void setR(BiTreeNode* r);
  void setL(BiTreeNode* l);
  void setN(BiTreeNode* n);
  void setD(char* d);
  BiTreeNode* getR();
  BiTreeNode* getL();
  BiTreeNode getN();
  char* getD();
}

#endif NODE
