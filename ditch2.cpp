/*
  ID: remijoh1
  LANG: C++11
  TASK: ditch
*/
#include<iostream>
#include<fstream>
#include<queue>
#include<algorithm>
#define MAXM 200
#define MAXN 200
#define MAXV 2000000000
using namespace std;

struct node{
  int id;
  int flow;
};

int Nd, Mi;
int cap[MAXM+1][MAXM+1] = {0};
int conn[MAXM+1][MAXM+1] = {0}, connc[MAXM+1]={0};

int findpath(int s,int t,int visited[],int pre[]){
  queue<node> q;
  node cur;
  cur.id = s;
  cur.flow = MAXV;
  visited[cur.id] = 1;
  q.push(cur);
  // cout<<"findpath "<<endl;
  while(!q.empty()){
    cur = q.front();
    q.pop();
    // cout<<cur.id<<endl;
    if(cur.id==t)
      return cur.flow;    
    for(int i = 0;i<connc[cur.id];i++){
      if(visited[conn[cur.id][i]]==0 && cap[cur.id][conn[cur.id][i]]>0){
        pre[conn[cur.id][i]] = cur.id;
        node next;
        next.id = conn[cur.id][i];
        next.flow = min(cur.flow,cap[cur.id][conn[cur.id][i]]);
        visited[next.id] = 1;
        q.push(next);
      }
    }
  }
  return 0;
}

int main(){
  ifstream fin("ditch.in");
  ofstream fout("ditch.out");

  
  fin>>Nd>>Mi;

  for(int i=0;i<Nd;i++){
    int from,to,c;
    fin>>from>>to>>c;
    cap[from][to] = cap[from][to]==0?c:cap[from][to]+c;
    conn[from][connc[from]++]=to;
    conn[to][connc[to]++] = from;    
  }
  // for(int i=1;i<=Mi;i++){
  //   for(int j=0;j<connc[i];j++){
  //     cout<<conn[i][j]<<' ';
  //   }
  //   cout<<endl;
  // }
  //cout<<connc[50]<<endl;
  int maxflow = 0;
  while(true){
    int visited[MAXM+1] = {0},pre[MAXM+1]={0};
    int result = findpath(1,Mi,visited,pre);
    // cout<<"result "<<result<<endl;
    if(result>0){
      int cur = Mi;
      while(true){
        if(cur==1)
          break;
        else{
          cap[pre[cur]][cur] -= result;
          cap[cur][pre[cur]] += result;
          
          // cout<<cur<<' '<<cap[cur][pre[cur]]<<' '<<cap[pre[cur]][cur]<<endl;
          //   cout<<"error"<<endl;
          cur = pre[cur];
        }
      }
      maxflow += result;
    }
    else{
      // for(int i=1;i<=Mi;i++){
      //   for(int j=1;j<=Mi;j++){
      //     cout<<cap[i][j]<<' ';
      //   }
      //   cout<<endl;
      // }
      fout<<maxflow<<endl;
      break;
    }
  }
  return 0;
}
