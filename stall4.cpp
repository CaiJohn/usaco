/*
  ID: remijoh1
  LANG: C++11
  TASK: stall4
*/
#include<iostream>
#include<fstream>
#include<queue>
#define MAXN 200
#define MAXM 200
using namespace std;
struct node{
  int id;
  int flow;
};

int cap[MAXN+MAXM+3][MAXN+MAXM+3] = {0},conn[MAXN+MAXM+3][MAXN+MAXM+3]={0},connc[MAXN+MAXM+3]={0};

int findpath(int s,int t,int pre[]){
  int visited[MAXN+MAXM+3]={0};
  queue<node> q;
  node cur;
  cur.id = s;
  cur.flow = 1;
  visited[cur.id] = 1;
  q.push(cur);
  while(!q.empty()){
    cur = q.front();
    q.pop();
    // cout<<cur.id<<endl;
    if(cur.id==t){
      return cur.flow;
    }
    else{
      for(int i=0;i<connc[cur.id];i++){
        int next = conn[cur.id][i];
        if(visited[next]==0 && cap[cur.id][next]>0){
          visited[next] = 1;
          pre[next] = cur.id;
          node nnode;
          nnode.id = next;
          nnode.flow = cur.flow;
          q.push(nnode);
        }
      }
    }
  }
  return 0;
}

int main(){
  ifstream fin("stall4.in");
  ofstream fout("stall4.out");

  int Nc,Ms;
  fin>>Nc>>Ms;
  int source = 0, sink = Nc+Ms+1;

  for(int i=1;i<=Nc;i++){
    cap[source][i] = 1;
    conn[source][connc[source]++] = i;
    int s,id;
    fin>>s;
    for(int j=0;j<s;j++){
      fin>>id;
      cap[i][Nc+id] = 1;
      conn[i][connc[i]++] = Nc+id;
      conn[Nc+id][connc[Nc+id]++] = i;
    }
  }
  for(int i=1;i<=Ms;i++){
    cap[Nc+i][sink] = 1;
    conn[Nc+i][connc[Nc+i]++] = sink;
    conn[sink][connc[sink]++] = Nc+i;
  }
  int maxflow = 0,result;
  while(true){
    int pre[MAXM+MAXN+3] = {0};
    result = findpath(source,sink,pre);
    //cout<<result<<endl;
    if(result==0){
      fout<<maxflow<<endl;
      break;
    }
    else{
      maxflow += result;
      int cur = sink;
      while(cur!=source){
        cap[pre[cur]][cur] -= result;
        cap[cur][pre[cur]] += result;
        cur = pre[cur];
      }
    }
  }
  return 0;
}

  
