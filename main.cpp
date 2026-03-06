/*
Aparajita Baidya 3.4.2026
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
#include "BiTreeNode.h"
#include <string>

//func defs.
char pop();//stack
char push();
char peek();
char enqueue();//queue...add to rear
char dequeue();//remove from front
string postfix();
string prefix();
string infix();


using namespace std;

int main(){
  //Set up some sillies.
  string expression;//unser entered expression
  string postFix;//contains expression after t h e s h u n t i n g
  string result;//output expression
  char* notation[3];//desired notation;
  BiTreeNode* stackH = new BiTreeNode;//head of stack LL
  BiTreeNode* queueF = new BiTreeNode;//head of queue LL
  BiTreeNode* treeH = new BiTreeNode;//for the tree stack. a stack of trees.

  //lets get to it, then
  cout<<"please enter your expression (infix notation)"<<endl;
  cin>>expression;
  cin.clear();
  //do shunting yard stuff --> stack and queue --> postfix --> delete em pointers
  //put into binary expression tree
  //ask user how they'd like their expression
  cout<<"How would you like your expression? Rare, medium, or well done?"<<endl;
  cout<<"[po] postfix, [pr] prefix, [in] infix, [al/any other value] all of them"<<endl;
  cin>>notation;
  cin.ignore(10,'\n');
  cin.clear();
  //output accordingly
  if(strcmp(notation, "pr")==0){
    result = prefix();
    cout<<result<<endl;
  }
  else if(strcmp(notation, "po")==0){
    result = postfix();
    cout<<result<<endl;
  }
  else if(strcmp(notation, "in")==0){
    result = infix();
    cout<<result<<endl;
  }
  else{
    result = prefix();
    cout<<"prefix:"<<result<<endl;
    result = postfix();
    cout<<"postfix:"<<result<<endl;
    result = infix();
    cout<<"infix:"<<result<<endl;
  }
  cout<<"BYE"<<endl;
  return 0;
}
