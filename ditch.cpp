/*
  ID: remijoh1
  LANG: C++11
  TASK: ditch
*/
#include<iostream>
#include<fstream>
#define MAXM 200
#define MAXN 200
#define MAXV 2000000000
using namespace std;

int Nd, Mi;
int cap[MAXM+1][MAXM+1] = {0};
int findpath(int cur,int t,int visited[],int pre[],int maxf,int tag){
  if(tag==1)
    // cout<<"findpath "<<cur<<' '<<pre[cur]<<endl;
  visited[cur] = 1;
  if(cur==t){
    return maxf;
  }
  else{
    for(int i=1;i<=Mi;i++){// Be careful!
      if(visited[i]==0 && cap[cur][i]>0){
        pre[i] = cur;
        int result = findpath(i,t,visited,pre,min(maxf,cap[cur][i]),tag);
        if(result>0)
          return result;
      }
    }
    
  }
  visited[cur] = 0;
  return 0;
}

int main(){
  ifstream fin("ditch.in");
  ofstream fout("ditch.out");

  
  fin>>Nd>>Mi;

  for(int i=0;i<Nd;i++){
    int from,to,c;
    fin>>from>>to>>c;
    cap[from][to] = c;
    
  }

  int maxflow = 0,tag = 0;
  while(true){
    int visited[MAXM+1] = {0},pre[MAXM+1]={0};
    int result = findpath(1,Mi,visited,pre,MAXV,tag);
    //cout<<result<<endl;
    if(result>0){
      int cur = Mi;
      while(true){
        if(cur==1)
          break;
        else{
          cap[pre[cur]][cur] -= result;
          cap[cur][pre[cur]] += result;
          cur = pre[cur];
        }
      }
      maxflow += result;
      //cout<<maxflow<<endl;
      // if(maxflow==973122){
      //   tag = 1;
      //   for(int i=1;i<=Mi;i++){
      //     for(int j=1;j<=Mi;j++){
      //       //cout<<cap[i][j]<<' ';
      //     }
      //     cout<<endl;
      //   }
      // }
    }
    else{
      fout<<maxflow<<endl;
      break;
    }
  }
  return 0;
}
