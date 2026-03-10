/*
Aparajita Baidya 3.7.2026
Time to Shunt the yard (or something)
to do:
BiTreeNode class
make a stack LL and queue LL --> do the sy algo -->then Binary Expression Tree
So, put nums into queue and operators into stack
pop
push
peek
enqueue
dequeue
*/

#include <iostream>
#include <cstring>
#include "Node.h"
#include <string>
#include <vector>

//func defs.
void mkVect(string expression, vector<string>*);
void getYarded(vector<string>*, Node*& stackH, Node*& queueF, Node*& queueB);//gonna shunt the yard as the kids say 
Node* biTree();//make the binary expression tree 
Node* pop(Node*& stackH);//stack
void push(Node*& newN, Node*& stackH);
Node* peek(Node* stackH);
void enqueue(Node*& newN, Node*& queueB);//queue...add to rear
Node* dequeue(Node*& queueF);//remove from front
string postfix();
string prefix();
string infix();

using namespace std;

int main(){
  //Set up some sillies.
  string expression;//unser entered expression
  string result;//output expression
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
  //do shunting yard stuff --> stack and queue --> postfix --> delete em pointers
  getYarded(exp, stackH, queueF, queueB);
  cout<<"Postfix: "<<endl;
  //then...uh...go through queue
  Node* temp = nullptr;
  temp = queueF;
  while(temp != nullptr){
    cout<<temp->getD()<<endl;
    temp = temp->getN();
  }
  //put into binary expression tree
  biTree();
  //ask user how they'd like their expression
  cout<<"How would you like your expression? Rare, medium, or well done?"<<endl;
  cout<<"[po] postfix, [pr] prefix, [in] infix, [al/any other value] all of them"<<endl;
  cin>>notation;
  cin.ignore(10,'\n');
  cin.clear();
  //output accordingly
  if(strcmp(notation, "pr")==0){
    //result = prefix();
    cout<<result<<endl;
  }
  else if(strcmp(notation, "po")==0){
    //result = postfix();
    cout<<result<<endl;
  }
  else if(strcmp(notation, "in")==0){
    //result = infix();
    cout<<result<<endl;
  }
  else{
    //result = prefix();
    cout<<"prefix:"<<result<<endl;
    //result = postfix();
    cout<<"postfix:"<<result<<endl;
    //result = infix();
    cout<<"infix:"<<result<<endl;
  }
  cout<<"BYE"<<endl;
  return 0;
}

void mkVect(string expression, vector<string>* exp){
  string temp = "";
  for(int i = 0; i < expression.length(); i++){
    if(expression[i]==' '){//moving onto next value due to " "
      exp->push_back(temp);
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
  string temp = "";
  Node* newN = nullptr; 
  for(vector<string>::iterator it = exp->begin(); it != exp->end(); ++it){
    //if ")"
    if((*it) == ")"){
      while(temp != "("){
	
      }
    }
    //if number --> queue
    else if(isdigit((*it))){
      newN = new Node;
      newN -> setD((*it));
      if(queueF == nullptr){
	queueF = new Node;
	queueB = new Node;
	queueF = newN;
	queueB = newN;
      }
      else{
	enqueue(newN, queueB);
      }
    }
    //if operator --> stack
    else{
      if(stackH == nullptr){
	stackH = new Node;
	stackH = newN;
      }
      else{
	newN = new Node;
	newN->setD((*it));
	push(newN, stackH);
      }
    }
  }
  //put everything left in stack into queue
  return;
}

Node* biTree(){
  Node* head = new Node;
  return head;
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

void push(Node*& newN, Node*& stackH){
  Node* temp = nullptr;
  temp = stackH;
  newN->setN(temp);
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
/*
string postfix(){
}
string prefix(){
}
string infix(){
}*/
