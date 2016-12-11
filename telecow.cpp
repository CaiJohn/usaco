/*
  ID:remijoh1
  LANG:C++11
  TASK:telecow
*/

/*

???

Some places to pay attention:
1. every time the maxflow is got, the cap[][] matrix will be modified,
so it needs a way to reuse the information;
2. use edge tables in the first time;

*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<queue>
#define MAXM 600
#define MAXN 100
#define MAXNN 205
#define INF 9999999
using namespace std;

int conn[MAXNN+1][MAXNN+1]={0},connc[MAXNN] = {0};
int Ncount = 1;

struct EdmondKarp{
  int cap[MAXNN+1][MAXNN+1];
  int s,t;
  EdmondKarp(int from,int to){
    s = from;
    t = to;
    memset(cap,0,sizeof(cap));
  }

  EdmondKarp(EdmondKarp* e){
    s = e->s;
    t = e->t;
    for(int i=0;i<MAXNN+1;i++){
      for(int j=0;j<MAXNN+1;j++){
        cap[i][j] = e->cap[i][j];
      }
    }
  }

  bool BFS(int path[]){
    // cout<<"BFS"<<endl;
    bool visited[MAXNN+1]={false};    
    queue<int> q;
    q.push(s);
    visited[s] = true;
    while(!q.empty()){
      int cur = q.front();
      // cout<<cur<<endl;
      q.pop();
      if(cur == t){
        return true;
      }
      for(int i=0;i<connc[cur];i++){
        int next = conn[cur][i];
        if(visited[next]==false && cap[cur][next]>0){
          visited[next] = true;
          path[next] = cur;
          q.push(next);
        }
      }
    }
    return false;
  }
  
  int maxFlow(){
    int maxf = 0;
    while(true){
      int path[MAXNN+1] = {0};
      if(BFS(path)){
        maxf++;
        int cur = t;
        while(true){
          if(cur==s)
            break;
          else{
            cap[path[cur]][cur]--;
            cap[cur][path[cur]]++;
            cur = path[cur];
          }
        }
      }
      else{
        return maxf;
      }
    }    
  }
};

int main(){
  ifstream fin("telecow.in");
  ofstream fout("telecow.out");

  int N,M,from,to,convert[MAXN+1][2]={0},edges[MAXNN+1][MAXNN+1]={0};
  fin>>N>>M>>from>>to;
  int tmp1,tmp2;
  EdmondKarp maxf(from,to);
  for(int i=0;i<M;i++){
    fin>>tmp1>>tmp2;
    if(tmp1!=from && tmp1!=to){
      if(convert[tmp1][0]==0){
        while(Ncount==from || Ncount==to){
          Ncount++;
        }
        convert[tmp1][0] = Ncount++;
        while(Ncount==from || Ncount==to){
          Ncount++;
        }
        convert[tmp1][1] = Ncount++;
        conn[convert[tmp1][0]][connc[convert[tmp1][0]]++] = convert[tmp1][1];
        conn[convert[tmp1][1]][connc[convert[tmp1][1]]++] = convert[tmp1][0];
        maxf.cap[convert[tmp1][0]][convert[tmp1][1]] = 1;
      }
      
      if(tmp2==from){
        conn[tmp2][connc[tmp2]++] = convert[tmp1][0];
        conn[convert[tmp1][0]][connc[convert[tmp1][0]]++] = tmp2;
        maxf.cap[tmp2][convert[tmp1][0]] = INF;
        maxf.cap[convert[tmp1][0]][tmp2] = INF;
      }
      if(tmp2==to){
        conn[tmp2][connc[tmp2]++] = convert[tmp1][1];
        conn[convert[tmp1][1]][connc[convert[tmp1][1]]++] = tmp2;
        maxf.cap[tmp2][convert[tmp1][1]] = INF;
        maxf.cap[convert[tmp1][1]][tmp2] = INF;
      }
    }
    if(tmp2!=from && tmp2!=to){
      if(convert[tmp2][0]==0){
        while(Ncount==from || Ncount==to){
          Ncount++;
        }
        convert[tmp2][0] = Ncount++;
        while(Ncount==from || Ncount==to){
          Ncount++;
        }
        convert[tmp2][1] = Ncount++;
        conn[convert[tmp2][0]][connc[convert[tmp2][0]]++] = convert[tmp2][1];
        conn[convert[tmp2][1]][connc[convert[tmp2][1]]++] = convert[tmp2][0];
        maxf.cap[convert[tmp2][0]][convert[tmp2][1]] = 1;
      }
      
      if(tmp1==from){
        conn[tmp1][connc[tmp1]++] = convert[tmp2][0];
        conn[convert[tmp2][0]][connc[convert[tmp2][0]]++] = tmp1;        
        maxf.cap[tmp1][convert[tmp2][0]] = INF;
        maxf.cap[convert[tmp2][0]][tmp1] = INF;
      }
      if(tmp1==to){
        conn[tmp1][connc[tmp1]++] = convert[tmp2][1];
        conn[convert[tmp2][1]][connc[convert[tmp2][1]]++] = tmp1;
        maxf.cap[tmp1][convert[tmp2][1]] = INF;
        maxf.cap[convert[tmp2][1]][tmp1] = INF;
      }
    }
    if(tmp1!=from && tmp1!=to && tmp2!=from && tmp2!=to){
      conn[convert[tmp1][0]][connc[convert[tmp1][0]]++] = convert[tmp2][1];
      conn[convert[tmp1][1]][connc[convert[tmp1][1]]++] = convert[tmp2][0];
      conn[convert[tmp2][0]][connc[convert[tmp2][0]]++] = convert[tmp1][1];
      conn[convert[tmp2][1]][connc[convert[tmp2][1]]++] = convert[tmp1][0];
      
      maxf.cap[convert[tmp1][1]][convert[tmp2][0]] = INF;
      maxf.cap[convert[tmp2][1]][convert[tmp1][0]] = INF;
    }    
  }
  for(int i=1;i<=N;i++){
    // cout<<convert[i][0]<<' '<<convert[i][1]<<endl;
  }
  // cout<<"Ncount "<<Ncount<<endl;
  // for(int i=1;i<Ncount;i++){
  //   cout<<i<<' '<<connc[i]<<endl;
  //   for(int j=0;j<connc[i];j++){
  //     cout<<conn[i][j]<<' '<<maxf.cap[i][conn[i][j]]<<endl;      
  //   }
  // }


  EdmondKarp e1(maxf);
  int maxflow = e1.maxFlow();
  // cout<<"maxflow "<<maxflow<<endl;
  fout<<maxflow<<endl;
  bool tag = false;
  for(int i=1;i<=N && maxflow > 0;i++){
    if(i!=from && i!=to){
      EdmondKarp tmpe(maxf);
      tmpe.cap[convert[i][0]][convert[i][1]] = 0;
      int tmpf = tmpe.maxFlow();
      // cout<<i<<" tmpf "<<tmpf<<endl;
      if(tmpf+1==maxflow){
        if(tag==true)
          fout<<' ';
        maxflow--;
        fout<<i;
        tag = true;
        maxf.cap[convert[i][0]][convert[i][1]] = 0;
      }
      // else{
      //   maxf.cap[convert[i][0]][convert[i][1]] = 1;
      // }
    }
  }
  fout<<endl;
  return 0;
}
