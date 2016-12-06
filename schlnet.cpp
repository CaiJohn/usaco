/*
  ID: remijoh1
  LANG: C++11
  TASK: schlnet
*/
#include<iostream>
#include<fstream>
#define MAXN 100


int tarjan(int low[], int visited[]){
  low[v] = index;
  visited[v] = index;
  index++;
  for(int i=1;i<=N;i++){
    if(visited[i]==0 && edge[v][i]==1){
      tarjan(low,visited);
      if(low[v]>low[i])
        low[v] = low[i];
    }
    else{
      if(instack[i] == 1 && visited[i]<low[v]){
        low[v] = visited[i];
      }
    }
  }
  if(visited[v] == low[v]){
    ccount ++;
    while(true){
      
    }
  }
}

int main(){
  ifstream fin("schlnet.in");
  ofstream fout("schlnet.out");
  int N,edge[MAXN+1][MAXN+1]={0};
  fin>>N;
  for(int i=1;i<=N;i++){
    int tmp;
    while(true){
      fin>>tmp;
      if(tmp==0)
        break;
      else{
        edge[i][tmp] = 1;
      }
    }
  }

  int vertex[MAXN+1]={0};
  int V = tarjan(vertex);

  
  int inedge[MAXN+1]={0},outedge[MAXN+1]={0};
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      if(vertex[i]!=vertex[j]){
        outedge[vertex[i]] = 1;
        inedge[vertex[j]] = 1;
      }
    }
  }

  int cinzero = 0,coutzero = 0;
  for(int i=0;i<V;i++){
    if(inedge[i]==0){
      cinzero ++;
    }
    if(outedge[i]==0){
      coutzero ++;
    }
  }
  fout<<cinzero<<endl;
  fout<<cinzero*coutzero<<endl;
  return 0;
}

  
