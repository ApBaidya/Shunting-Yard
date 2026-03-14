/*
Aparajita Baidya 3.7.2026
*/
#include "Node.h"

Node::Node(){
  right = nullptr;
  left = nullptr;
  next = nullptr;
}
Node::~Node(){
  next = nullptr;
  left = nullptr;
  right = nullptr;
}

void Node::setR(Node* r){
  right = r;
}
void Node::setL(Node* l){
  left = l;
}
void Node::setN(Node* n){
  next = n;
}
void Node::setD(string d){
  data = d;
}

Node* Node::getR(){
  return right;
}
Node* Node::getL(){
  return left;
}
Node* Node::getN(){
  return next;
}
string Node::getD(){
  return data;
}


