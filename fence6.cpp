/*
  ID: remijoh1
  LANG: C++11
  TASK: fence6
*/
#include<iostream>
#include<fstream>
#define MAXV 30000
using namespace std;

int N;
int len[101]={0},conn[101][2][8],connc[101][2],minC=MAXV;

void solve(int cur,int last,int visited[],int goal,int cost,int &min){
  //cout<<"solve "<<cur<<' '<<last<<' '<<min<<endl;
  int node = 0;
  for(int i=0;i<connc[cur][0];i++){
    if(conn[cur][0][i]==last){
      node = 1;
      break;
    }
  }
  
  visited[cur] = 1;
  if(true || len[cur]+cost<min){// ???
    for(int i=0;i<connc[cur][node];i++){
      if(conn[cur][node][i]==goal){
        if(len[cur]+cost<min)
          min = cost+len[cur];
        //break; // Exploit the fact that all segments are straight
      }
      else{
        if(len[conn[cur][node][i]]>0 && visited[conn[cur][node][i]]==0)
          solve(conn[cur][node][i],cur,visited,goal,cost+len[cur],min);
      }
    }
  }
  visited[cur] = 0;
  return;
}

int main(){
  ifstream fin("fence6.in");
  ofstream fout("fence6.out");

  
  fin>>N;
  for(int i=0;i<N;i++){
    int id,l;
    fin>>id>>l;
    fin>>connc[id][0]>>connc[id][1];
    len[id]=l;
    for(int j=0;j<connc[id][0];j++){
      fin>>conn[id][0][j];
    }
    for(int j=0;j<connc[id][1];j++){
      fin>>conn[id][1][j];
    }
    int visited[101] = {0};
    // cout<<"new "<<id<<endl;
    solve(id,id,visited,id,0,minC);
    // cout<<minC<<endl;
  }

  fout<<minC<<endl;
  return 0;
}
