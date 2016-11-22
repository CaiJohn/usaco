/*
  ID: remijoh1
  LANG: C++11
  TASK: buylow
*/
#include<iostream>
#include<fstream>
using namespace std;
typedef struct Tree Tree;
typedef struct Node Node;

struct Tree{
  int v;
  Node* child;
};

struct Node{
  Tree* t;
  Node* next;
};
int countn = 0;

// If root is not a pointer, can I perform the insertion?
bool insert(Tree* root,Tree* newn){
  // cout<<"insert "<<root->v<<' '<<v<<endl;
  if(root->v == newn->v)
    return true;
  if(root->v > newn->v)
    return false;  
  // root-> v < v
  Node* child = root->child;
  bool tag = false;
  while(true){
    if(child==NULL)
      break;
    else{
      tag = insert(child->t,newn) || tag;
      child = child->next;
    }
  }
  if(tag == false){
    // countn++;
    // cout<<countn<<endl;
    Node* nn = new Node();
    nn->t = newn;
    nn->next = NULL;
    if(root->child==NULL){
      root->child = nn;
    }
    else{
      // cout<<"add to child"<<endl;
      Node* tmp = root->child;
      root->child = nn;
      nn->next = tmp;
    }
  }
  return true;
}

void traverse(Tree* root, int cur, int &maxL, int &num){
  // cout<<"traverse "<<cur<<' '<<maxL<<endl;
  if(root->child==NULL){
    if(cur>maxL){
      // cout<<"here"<<endl;
      maxL = cur;
      num = 1;
    }
    else{
      if(cur==maxL){
        num ++;
      }
    }
    return;
  }
  else{
    Node* child = root->child;
    while(true){
      if(child==NULL)
        break;
      else{
        traverse(child->t,cur+1,maxL,num);
        child = child->next;
      }
    }
    return;
  }
  
}

void printTree(Tree* root){
  cout<<root->v;
  Node* child = root->child;
  while(child!=NULL){
    cout<<"(";
    printTree(child->t);
    cout<<")";
    child = child->next;
  }
  return;
}

int main(){
  ifstream fin("buylow.in");
  ofstream fout("buylow.out");

  int N,seq[5000];
  fin>>N;
  for(int i=0;i<N;i++)
    fin>>seq[i];

  Tree* root = new Tree();
  root->v = 0;
  root->child = NULL;

  for(int i=N-1;i>=0;i--){
    cout<<i<<' '<<seq[i]<<endl;
    Tree* nt = new Tree();
    nt->v = seq[i];
    nt->child = NULL;
    insert(root,nt);
  }
  // printTree(root);
  // cout<<endl;
  int maxL=0,num=0;
  traverse(root,0,maxL,num);
  fout<<maxL<<' '<<num<<endl;
  return 0;
}
  
    
