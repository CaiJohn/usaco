/*
  ID: remijoh1
  LANG: C++11
  TASK: comehome
*/
#include<iostream>
#include<fstream>
#define MAXDIST 30000
using namespace std;

int main(){
  ifstream fin("comehome.in");
  ofstream fout("comehome.out");

  int P,edges[52][52]={0},cows[52]={0};

  for(int i=0;i<52;i++){
    for(int j=0;j<52;j++){
      edges[i][j] = MAXDIST;
    }
  }
  fin>>P;

  for(int i=0;i<P;i++){
    char from,to;
    int ifrom,ito,dist;
    fin>>from>>to>>dist;
    if(from>='A' && from<='Z'){
      ifrom = from-'A';
      if(from!='Z')
        cows[ifrom] = 1;
    }
    else{
      ifrom = from-'a'+26;
    }
    if(to>='A' && to<='Z'){
      ito = to -'A';
      if(to!='Z')
        cows[ito] = 1;
    }
    else{
      ito = to-'a'+26;
    }
    // cout<<ifrom<<' '<<ito<<endl;
    if(edges[ifrom][ito]>dist){
      // cout<<dist<<endl;
      edges[ifrom][ito] = dist;
      edges[ito][ifrom] = dist;
    }
  }

  bool visited[52] = {false};
  int dist[52];
  for(int i=0;i<52;i++)
    dist[i] = MAXDIST;
  dist['Z'-'A'] = 0;
  while(true){
    int cur = -1,minDist = MAXDIST;
    for(int i=0;i<52;i++){
      if(visited[i]==false && dist[i]<minDist){
        cur = i;
        minDist = dist[i];
      }
    }
    // cout<<cur<<endl;
    if(cur==-1)
      break;

    visited[cur] = true;
    for(int i=0;i<52;i++){
      if(visited[i]==false && edges[cur][i]+dist[cur]<dist[i]){
        dist[i] = edges[cur][i] + dist[cur];
      }
    }
  }

  int minDist = MAXDIST;
  char pos;
  for(int i=0;i<52;i++){
    if(cows[i]==1){
      if(minDist>dist[i]){
        pos = i+'A';
        minDist = dist[i];
      }
    }
  }
  fout<<pos<<' '<<minDist<<endl;
  return 0;
}
