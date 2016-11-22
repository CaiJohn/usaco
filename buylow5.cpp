/*
  ID: remijoh1
  LANG: C++11
  TASK: buylow
*/
#include<iostream>
#include<fstream>
#define MAXN 5000
using namespace std;

struct Info{
  int head;
  int count;

}


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
  
    
