/*
ID: remijoh1
LANG: C++11
TASK: butter
*/
#include<iostream>
#include<fstream>
using namespace std;

int main(){
  ifstream fin("butter.in");
  ofstream fout("butter.out");

  int N,P,C,cows[500],edges[801][801]={0};
  //cows not necessarily alone...
  fin>>N>>P>>C;
  for(int i=0;i<N;i++)
    fin>>cows[i];
  for(int i=0;i<C;i++){
    int from,to,dist;
    fin>>from>>to>>dist;
    edge[from][to] = dist;
  }
  for(int i=0;i<N;i++){
    dijstra()
  }
  
