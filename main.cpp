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

//func defs.
void getYarded(string expression, Node* stackH, Node* queueF, Node* queueB);//gonna shunt the yard as the kids say 
Node* biTree();//make the binary expression tree 
string pop();//stack
void push();
string peek();
string enqueue();//queue...add to rear
string dequeue();//remove from front
string postfix();
string prefix();
string infix();

using namespace std;

int main(){
  //Set up some sillies.
  string expression;//unser entered expression
  string postFix;//contains expression after t h e s h u n t i n g
  string result;//output expression
  char* notation = new char[3];//desired notation;
  Node* stackH = new Node;//head of stack LL
  Node* queueF = new Node;//front of queue LL//first in first out-add to back, take from front
  Node* queueB = new Node;//back of queue LL 
  Node* treeH = new Node;//for the tree stack. a stack of trees.

  //lets get to it, then
  cout<<"please enter your expression (infix notation)"<<endl;
  cin>>expression;
  cin.clear();
  cout<<"oookay, "<<expression<<endl;
  //do shunting yard stuff --> stack and queue --> postfix --> delete em pointers
  postFix = getYarded(expression, stackH, queueF, queueB);
  cout<<"Postfix: "<<postFix<<endl;
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

void getYarded(string expression, Node* stackH, Node* queueF, Node* queueB){

}
Node* biTree(){
  Node* head = new Node;
  return head;
}
string pop(){
  string top;
  return top;
}
void push(){
}
string peek(){
  string top;
  return top;
}
/*string enqueue(){
}
string dequeue(){
}
string postfix(){
}
string prefix(){
}
string infix(){
}*/
