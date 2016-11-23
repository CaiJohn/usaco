/*
ID: remijoh1
LANG: C++11
TASK: lgame
*/
#include<iostream>
#include<fstream>
using namespace std;
typedef struct Tree Tree;
typedef struct Node Node;

struct Tree{
  char c;
  bool done;
  Node* child;
};

struct Node{
  Tree* t;
  Node* next;
};

void insert(Tree* root,string s){
  if(s.length()==0){
    root->done = true;
    return;
  }
  
  Node* child = root->child;
  bool tag = false;
  while(true){
    if(child==NULL)
      break;
    else{
      if((child->t)->c == s[0]){
	tag = true;
	insert(child->t,s.substr(1,s.length()-1));
	break;
      }
      child = child->next;
    }
  }
  if(tag == false){
    Tree* ntree = new Tree();
    ntree->c = s[0];
    ntree->done = false;
    ntree->child = NULL;
    insert(ntree,s.substr(1,s.length()-1));
    Node* nchild = new Node();
    nchild->t = ntree;
    nchild->next = NULL;
    if(root->child == NULL){
      root->child = nchild;
    }
    else{
      Node* tmp = (root->child)->next;
      (root->child)->next = nchild;
      nchild->next = tmp;
    }
  }
  return;
}

void match(Tree* root, string s, int &score, string &result){
  if(s.length()==0){
    if(root->done==false){
      score = 0;
      result = "";
    }
    return;
  }
  else{
    Node* child = root->child;
    while(true){
      if(child == NULL)
	break;
      else{
	if((child->t)->c == 
      }
    }
  }
}

int main(){
  ifstream fin("lgame.in");
  ofstream fout("lgame.out");

  ifstream fdict("lgame.dict");
  string word;
  Tree dict;
  while(true){
    fdict>>word;
    if(word==".")
      break;
    else{
      insert(&dict,word);
    }
  }
  
