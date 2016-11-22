/*
ID: remijoh1
LANG: C++11
TASK: butter
*/
#include<iostream>
#include<fstream>
#define MAXN 500
#define MAXP 800
#define MAXV 300000
using namespace std;

int N,P,C,cows[MAXN],edges[MAXP+1][MAXP+1],conn[MAXP+1][MAXP+1],ecount[MAXP+1];

void heapswap(int heap[],int i,int j,int href[]){
  int tmp = heap[i];
  heap[i] = heap[j];
  heap[j] = tmp;

  href[heap[i]] = i;
  href[heap[j]] = j;
  return;
}

void heapup(int heap[],int pos,int dist[],int href[]){
  if(pos==0)
    return;
  else{
    if(dist[heap[pos]]<dist[heap[(pos-1)/2]]){
      heapswap(heap,pos,(pos-1)/2,href);
      heapup(heap,(pos-1)/2,dist,href);
    }
  }
  return;
}

void push(int heap[], int &hsize, int v, int dist[],int href[]){
  heap[hsize] = v;
  href[v] = hsize;
  heapup(heap,hsize,dist,href);
  hsize++;
  return;
}

void heapdown(int heap[], int pos, int hsize,int dist[],int href[]){
  if(pos*2+1>=hsize)
    return;
  else{
    int next;
    if(pos*2+2>=hsize)
      next = pos*2+1;
    else{
      next = dist[heap[pos*2+1]]<dist[heap[pos*2+2]]?pos*2+1:pos*2+2;
    }
    if(dist[heap[pos]]>dist[heap[next]]){
      heapswap(heap,pos,next,href);
      heapdown(heap,next,hsize,dist,href);
    }
  }
  return;
}

int pop(int heap[], int &hsize,int dist[],int href[]){
  int result = heap[0];
  heap[0] = heap[hsize-1];
  hsize--;
  heapdown(heap,0,hsize,dist,href);
  return result;
}

void decreasekey(int heap[],int pos,int dist[],int href[]){
  heapup(heap,pos,dist,href);
}

void dijkstra(int s, int dist[]){

  for(int i=1;i<=P;i++)
    dist[i] = MAXV;
  dist[s] = 0;

  int heap[MAXP],hsize = 0,href[MAXP+1];
  for(int i=1;i<=P;i++){
    push(heap,hsize,i,dist,href);
  }
  for(int i=0;i<P;i++){
    int cur = pop(heap,hsize,dist,href);

    for(int j=0;j<ecount[cur];j++){
      int newv = conn[cur][j];
      if(edges[cur][newv]>0){
	if(dist[cur]+edges[cur][newv]<dist[newv]){

	  dist[newv] = dist[cur]+edges[cur][newv];
	  decreasekey(heap,href[newv],dist,href);
	}
      }
    }
  }
  return;
}

int main(){
  ifstream fin("butter.in");
  ofstream fout("butter.out");

  fin>>N>>P>>C;
  for(int i=0;i<N;i++)
    fin>>cows[i];
  for(int i=0;i<C;i++){
    int from, to, dist;
    fin>>from>>to>>dist;
    edges[from][to] = dist;
    edges[to][from] = dist;
    conn[from][ecount[from]++] = to;
    conn[to][ecount[to]++] = from;
  }
  int dist[MAXP+1][MAXP+1];
  for(int i=0;i<N;i++){
    dijkstra(cows[i],dist[cows[i]]);
  }
  int minD = MAXV;
  for(int i=1;i<=P;i++){
    int sum = 0;
    for(int j=0;j<N;j++){
      sum += dist[cows[j]][i];
    }
    if(minD>sum)
      minD = sum;
  }
  fout<<minD<<endl;
  return 0;
}
