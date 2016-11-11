/*
ID: remijoh1
LANG: C++11
TASK: butter
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#define MAXV 800
#define MAXDIST 200000
using namespace std;
struct edge{
  int id;
  int dist;
  edge *next;
};
edge* edgetable[MAXV+1];

void push(int heap[],int &size,int num,int dist[],int hinfo[]){
  heap[size] = num;
  hinfo[num] = size;
  int cur = size;
  while(true){
    if(cur==0)
      break;
    if(dist[heap[(cur-1)/2]]<=dist[heap[cur]])
      break;
    else{
      int tmp = heap[cur];
      heap[cur] = heap[(cur-1)/2];
      heap[(cur-1)/2] = tmp;
      
      hinfo[heap[cur]] = cur;
      hinfo[heap[(cur-1)/2]] = (cur-1)/2;
      cur = (cur-1)/2;
    }
  }
  size++;
  return;
}

int pop(int heap[], int &size,int dist[],int hinfo[]){
  int result = heap[0];
  heap[0] = heap[size-1];
  hinfo[heap[0]] = 0;
  size--;
  int cur = 0;
  while(true){
    if(cur>=size)
      break;
    if(cur*2+1>=size)
      break;
    else{
      if(cur*2+2>=size){
	if(dist[heap[cur]]>dist[heap[cur*2+1]]){
	  int tmp = heap[cur];
	  heap[cur] = heap[cur*2+1];
	  heap[cur*2+1] = tmp;
	  hinfo[heap[cur]] = cur;
	  hinfo[heap[cur*2+1]] = cur*2+1;
	  cur = cur*2+1;
	}
	else{
	  break;
	}
      }
      else{
	if(dist[heap[cur]]<=dist[heap[cur*2+1]]&&dist[heap[cur]]<=dist[heap[cur*2+2]]){
	  break;
	}
	else{
	  int child = dist[heap[cur*2+1]]<dist[heap[cur*2+2]]?cur*2+1:cur*2+2;
	  int tmp = heap[cur];
	  heap[cur] = heap[child];
	  heap[child] = tmp;
	  hinfo[heap[cur]] = cur;
	  hinfo[heap[child]] = child;
	  cur = child;
	}
      }
    }
  }
  return result;  
}

void update(int heap[],int v,int dist[],int hinfo[]){
  //cout<<"inside update: "<<v<<endl;
  int num = hinfo[v];
  //cout<<"hinfo"<<num<<endl;
  while(true){
    if(num==0)
      break;
    if(dist[heap[num]]>=dist[heap[(num-1)/2]])
      break;
    else{
      int tmp = heap[num];
      heap[num] = heap[(num-1)/2];
      heap[(num-1)/2] = tmp;
      hinfo[heap[num]] = num;
      hinfo[heap[(num-1)/2]] = (num-1)/2;
      num = (num-1)/2;
    }
  }
}

void dijkstra(int source,int vnum,int dist[]){
  //cout<<source<<endl;
  for(int i=1;i<=vnum;i++)
    dist[i] = MAXDIST;
  dist[source] = 0;
  int heap[MAXV+1] = {0},hsize = 0,hinfo[MAXV+1];
  
  for(int i=1;i<=vnum;i++){
    push(heap,hsize,i,dist,hinfo);
    // for(int j=0;j<hsize;j++)
    //   cout<<heap[j];
    // cout<<endl;
  }

  
  while(hsize>0){
    int tmpv = pop(heap,hsize,dist,hinfo);
    //cout<<"pop: "<<tmpv<<endl;
    // for(int i=0;i<hsize;i++)
    //   cout<<heap[i];
    // cout<<endl;
    // for(int i=1;i<=vnum;i++)
    //   cout<<hinfo[i];
    // cout<<endl;
    edge* cur = edgetable[tmpv];
    while(cur!=NULL){
      if(dist[cur->id]>dist[tmpv]+cur->dist){
	dist[cur->id] = dist[tmpv]+cur->dist;
	update(heap,cur->id,dist,hinfo);
      }
      //cout<<"update"<<endl;
      // for(int i=0;i<hsize;i++)
      // 	cout<<heap[i];
      // cout<<endl;
      cur = cur -> next;
    }
  }
  return;
}

int main(){
  ifstream fin("butter.in");
  ofstream fout("butter.out");

  int N,P,C,cows[500];
  //cows not necessarily alone...
  fin>>N>>P>>C;
  for(int i=0;i<N;i++)
    fin>>cows[i];

  for(int i=1;i<=P;i++){
    edgetable[i] = NULL;
  }
  for(int i=0;i<C;i++){
    int from,to,dist;
    fin>>from>>to>>dist;
    edge *nedge = new edge();
    nedge->id = to;
    nedge->dist = dist;
    nedge->next = NULL;
    if(edgetable[from] == NULL)
      edgetable[from] = nedge;
    else{
      edge* cur = edgetable[from];
      while(cur->next!=NULL){
	cur = cur->next;
      }
      cur->next = nedge;
    }

    nedge = new edge();
    nedge->id = from;
    nedge->dist = dist;
    nedge->next = NULL;
    if(edgetable[to] == NULL)
      edgetable[to] = nedge;
    else{
      edge* cur = edgetable[to];
      while(cur->next!=NULL){
	cur = cur->next;
      }
      cur->next = nedge;
    }
  }
  
  sort(cows,cows+N);//In case there are more than one cow in the same pasture
  
  int dists[MAXV+1][MAXV+1],last = -1;
  for(int i=0;i<N;i++){
    if(cows[i]==last)
      continue;
    last = cows[i];    
    dijkstra(cows[i],P,dists[cows[i]]);
    // for(int j=1;j<=P;j++)
    //   cout<<dists[cows[i]][j]<<endl;
  }


  // for(int i=1;i<=P;i++){
  //   for(int j=1;j<=P;j++){
  //     cout<<dists[i][j]<<' ';
  //   }
  //   cout<<endl;
  // }
  int min = MAXDIST;
  int pos = 0;
  for(int i=1;i<=P;i++){
    int sum = 0;
    for(int j=0;j<N;j++){
      sum += dists[cows[j]][i];
    }
    if(sum<min){
      min = sum;
      pos = i;
    }
  }
  // cout<<pos<<endl;
  // cout<<min<<endl;
  fout<<min<<endl;
  return 0;
}
