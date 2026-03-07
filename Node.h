/*
Aparajita Baidya 3.6.2026  
Binary tree node
Will also act as the linked list node (hence the next)
*/
#ifndef NODE
#define NODE

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

class Node{
 private:
  Node* right;
  Node* left;
  Node* next;//next specifically for LL
  string data;
 public:
  Node();//constructor
  ~Node();//death. 
  void setR(Node* r);//sets
  void setL(Node* l);
  void setN(Node* n);
  void setD(string d);
  Node* getR();//gets
  Node* getL();
  Node* getN();
  string getD();//uhhh do I need to do something like string*???
};

#endif //NODE
