/*
ID: remijoh1
LANG: C++
TASK: agrinet
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int N,dist[100][100];

struct Edge{
  int from;
  int to;
  int dist;
};

int elements[100];
int findSet(int num){
  return elements[num];
}
void unionSet(int a,int b){
  int aset = findSet(a);
  int bset = findSet(b);
  for(int i=0;i<N;i++){
    if(findSet(i)==bset)
      elements[i] = aset;
  }
  return;
}

bool cmp(Edge a,Edge b){
  return a.dist<b.dist;
}
  
int main(){
  ifstream fin("agrinet.in");
  ofstream fout("agrinet.out");
  
  fin>>N;

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      fin>>dist[i][j];
    }
  }

  Edge edges[10000];
  int count = 0;
  for(int i=0;i<N;i++){
    for(int j=i+1;j<N;j++){
      edges[count].from = i;
      edges[count].to = j;
      edges[count].dist = dist[i][j];
      count++;
    }
  }
  sort(edges,edges+count,cmp);

  for(int i=0;i<N;i++){
    elements[i] = i;
  }
  int sum = 0;
  for(int i=0;i<count;i++){
    if(findSet(edges[i].from)!=findSet(edges[i].to)){
      sum += edges[i].dist;
      unionSet(edges[i].from,edges[i].to);
    }
  }
  fout<<sum<<endl;
  return 0;
}
  

  
