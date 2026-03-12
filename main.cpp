/*
Aparajita Baidya 3.12.2026
Time to Shunt the yard (or something)
to do:
Binary tree
output functions
*/

#include <iostream>
#include <cstring>
#include "Node.h"
#include <string>
#include <vector>

//func defs.
void mkVect(string expression, vector<string>*);
void getYarded(vector<string>*, Node*& stackH, Node*& queueF, Node*& queueB);//gonna shunt the yard as the kids say 
void biTree(Node*& queueF, Node*& treeH);//make the binary expression tree 
Node* pop(Node*& stackH);//stack
void push(Node*& newN, Node*& stackH);
Node* peek(Node* stackH);
void enqueue(Node*& newN, Node*& queueB);//queue...add to rear
Node* dequeue(Node*& queueF);//remove from front
void postfix(Node* treeH);
void prefix(Node* treeH);
void infix(Node* treeH);

void test(); 
void printStack(Node* head);
void printQueue(Node* head);

using namespace std;

int main(){
  //Set up some sillies.
  string expression;//unser entered expression
  char* notation = new char[3];//desired notation;
  Node* stackH = nullptr;//head of stack LL --> opperators
  Node* queueF = nullptr;//front of queue LL//first in first out-add to back, take from front
  Node* queueB = nullptr;//back of queue LL --> queue is output
  Node* treeH = nullptr;//for the tree stack. a stack of trees.
  vector<string>* exp = new vector<string>();//gonna make a vector to pass into Shunting yard function

  //lets get to it, then
  cout<<"please enter your expression (infix notation)"<<endl;
  getline(cin, expression);
  cin.clear();
  cout<<"oookay, "<<expression<<endl;
  mkVect(expression, exp);//make it a vector
  for(vector<string>::iterator it = exp->begin(); it != exp->end(); ++it){
    cout<<(*it)<<endl;
  }

  //TEST
  //test();
  
  //do shunting yard stuff --> stack and queue --> postfix --> delete em pointer
  getYarded(exp, stackH, queueF, queueB);
  cout<<"Postfix: "<<endl;//cout postfix
  printQueue(queueF);
  cout<<"putting into expression tree"<<endl;
  //put into binary expression tree
  biTree(queueF, treeH);
  cout<<"done with setting up expression tree"<<endl;
  
  //ask user how they'd like their expression
  cout<<"How would you like your expression? Rare, medium, or well done?"<<endl;
  cout<<"[po] postfix, [pr] prefix, [in] infix, [al/any other value] all of them"<<endl;
  cin>>notation;
  cin.ignore(10,'\n');
  cin.clear();

  //output accordingly
  if(strcmp(notation, "pr")==0){
    cout<<"prefix:"<<endl;
    prefix(treeH);
    cout<<endl;
  }
  else if(strcmp(notation, "po")==0){
    cout<<"postfix:"<<endl;
    postfix(treeH);
    cout<<endl;
  }
  else if(strcmp(notation, "in")==0){
    cout<<"infix:"<<endl;
    infix(treeH);
    cout<<endl;
  }
  else{
    cout<<"prefix:"<<endl;
    prefix(treeH);
    cout<<endl;
    cout<<"postfix:"<<endl;
    postfix(treeH);
    cout<<endl;
    cout<<"infix:"<<endl;
    infix(treeH);
    cout<<endl;
  }
  cout<<"BYE"<<endl;
  return 0;
}

void printStack(Node* head){
  while(head != nullptr){
    cout<<head->getD()<<endl;
    head = head -> getN();
  }
  cout<<"done"<<endl;
}
void printQueue(Node* head){
  while(head != nullptr){
    cout<<head->getD()<<endl;
    head = head -> getN();
  }
  cout<<"done"<<endl;
}

void test(){
  Node* stackH = nullptr;//head of stack LL --> opperators
  Node* queueF = nullptr;//front of queue LL//first in first out-add to back, take from front
  Node* queueB = nullptr;//back of queue LL --> queue is output
  Node* tempN = nullptr;
  for(int i = 0; i < 5; i++){//push
    tempN = new Node;
    tempN -> setD("a");
    if(stackH == nullptr){
      stackH = tempN;
    }
    else{
      push(tempN, stackH);
    }
  }
  printStack(stackH);
  for(int i = 0; i<5; i++){//pop
    tempN = pop(stackH);
    delete tempN;
  }
  printStack(stackH);
  for(int i = 0; i < 5; i ++){//enqueue
    tempN = new Node;
    tempN -> setD("b");
    if(queueF == nullptr){
      queueF = tempN;
      queueB = tempN;
    }
    else{
      enqueue(tempN, queueB);
    }
  }
  printQueue(queueF);
  for(int i = 0; i < 5; i ++){//dequeue
    tempN = dequeue(queueF);
    delete tempN;
  }
  printQueue(queueF);
}

void mkVect(string expression, vector<string>* exp){
  string temp = "";
  for(int i = 0; i < expression.length(); i++){
    if(expression[i]==' '){//moving onto next value due to " "
      exp->push_back(temp);
      temp = "";
    }
    else{
      temp += expression[i];
    }
  }
  //now, there'll be something after the last space
  exp->push_back(temp);
  return;
}

void getYarded(vector<string>* exp, Node*& stackH, Node*& queueF, Node*& queueB){
  Node* newN = nullptr;
  for(vector<string>::iterator it = exp->begin(); it != exp->end(); ++it){
    //if "("
    if((*it) == ")"){
      newN = stackH;
      //pop and enqueue until you reach "("
      while(newN->getD() != "("){
	newN = pop(stackH);
	enqueue(newN, queueB);
	newN = stackH;
      }
      //then get rid of the "("...pop
      newN = pop(stackH);
      delete newN;
      newN = nullptr;
    }
    //else if number
    else if(isdigit((*it)[0])){
      //first in queue
      newN = new Node;
      newN->setD((*it));
      if(queueF == nullptr){
	queueF = newN;
	queueB = newN;
      }
      else{
	enqueue(newN, queueB);
      }
    }
    //else if operator
    else{
      newN = new Node;
      newN->setD((*it));
      //first in stack
      if(stackH==nullptr){
	stackH = newN;
      }
      else{
	push(newN, stackH);
      }
    }
  }//end the iterating.
  //when finished, queue everything left in stack
  while(stackH != nullptr){
    newN = pop(stackH);
    enqueue(newN, queueB);
  }
  printStack(stackH);//give me nothing, please
  printQueue(queueF);
  return;
}

void biTree(Node*& queueF, Node*& treeH){
  //so, go through the queue, pop and add to temp stack
  Node* right = nullptr;
  Node* left = nullptr;;
  Node* newN = nullptr;
  while(queueF != nullptr){//go through queue
    newN = dequeue(queueF);
    if(isdigit(newN->getD()[0]) == false){//operator --> make tiny tree
      //pop right then left --> make left and right to node
      right = pop(treeH);
      left = pop(treeH);
      newN -> setR(right);
      newN -> setL(left);
      //push
      push(newN, treeH);
    }
    else{//number
      push(newN, treeH);//push into temp stack
    }
  }
  return;
}

Node* pop(Node*& stackH){
  Node* top = nullptr;
  top = stackH;//set 'top' to head
  Node* temp = nullptr;
  temp = stackH->getN();
  stackH = temp;
  top->setN(nullptr);
  return top;
}

void push(Node*& newN, Node*& stackH){//newN becomes the head(top) of the stack
  newN->setN(stackH);
  stackH = newN;
  return; 
}

Node* peek(Node* stackH){//why do I even need this???? I'm literally sending the head pointer....ONLY TO RETURN THE HEAD??? JUST USE THE HEAD PO-this would probably make more sense if I was using classes.
  return stackH;
}

void enqueue(Node*& newN, Node*& queueB){//add to end
  Node* temp = nullptr;
  temp = queueB;
  temp->setN(newN);
  queueB = newN;
  return;
}
Node* dequeue(Node*& queueF){//take out from front
  Node* temp = nullptr;
  Node* front = nullptr;
  temp = queueF->getN();
  front = queueF;
  queueF->setN(nullptr);
  queueF = temp;
  return front;
}

void postfix(Node* current){
  //go to rightmost
  //recurse right
  if(current->getL() == nullptr){
    cout<<current->getD();
    return;//return if right doesnt exist 
  }
  if(current->getL() != nullptr){
    postfix(current->getL());
  }
  //recurse left
  if(current->getR() != nullptr){
    postfix(current->getR());
  }
  cout<<current->getD();
}

void prefix(Node* treeH){

}
void infix(Node* treeH){

}
