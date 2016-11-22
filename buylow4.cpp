/*
  ID: remijoh1
  LANG: C++11
  TASK: buylow
*/
#include<iostream>
#include<fstream>
#define MAXN 1000
// 5000 is too big
using namespace std;
typedef struct Tree Tree;
typedef struct Node Node;

struct Tree{
  int v;
  int cnum;
  Tree* child[MAXN];
};

// If root is not a pointer, can I perform the insertion?
bool insert(Tree* root,Tree* newn){
  // cout<<"insert "<<root->v<<' '<<v<<endl;
  if(root->v == newn->v)
    return true;
  if(root->v > newn->v)
    return false;  
  // root-> v < v
  bool tag = false;
  for(int i=0;i<root->cnum;i++){
    tag = insert(root->child[i],newn) || tag;
  }
  if(tag == false){
    // countn++;
    // cout<<countn<<endl;
    root->child[root->cnum] = newn;
    root->cnum ++;
  }
  return true;
}

void traverse(Tree* root, int cur, int &maxL, int &num){
  // cout<<"traverse "<<cur<<' '<<maxL<<endl;
  if(root->cnum==0){
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
    for(int i=0;i<root->cnum;i++){
      traverse(root->child[i],cur+1,maxL,num);
    }
    return;
  }
}

// void printTree(Tree* root){
//   cout<<root->v;
//   Node* child = root->child;
//   while(child!=NULL){
//     cout<<"(";
//     printTree(child->t);
//     cout<<")";
//     child = child->next;
//   }
//   return;
// }

int main(){
  ifstream fin("buylow.in");
  ofstream fout("buylow.out");

  int N,seq[MAXN];
  fin>>N;
  for(int i=0;i<N;i++)
    fin>>seq[i];

  Tree* root = new Tree();
  root->v = 0;
  root->cnum = 0;

  Tree nt[MAXN];
  for(int i=N-1;i>=0;i--){
    // cout<<i<<' '<<seq[i]<<endl;
    nt[i].v = seq[i];
    nt[i].cnum = 0;
    insert(root,nt+i);
  }
  // printTree(root);
  // cout<<endl;
  int maxL=0,num=0;
  traverse(root,0,maxL,num);
  fout<<maxL<<' '<<num<<endl;
  return 0;
}
  
    
