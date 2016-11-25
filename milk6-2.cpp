/*
  ID: remijoh1
  LANG: C++11
  TASK: milk6
*/
#include<iostream>
#include<fstream>
#include<queue>
#include<cstring>
#include<climits>
#define MAXN 32
#define MAXM 1000
#define INF LLONG_MAX
using namespace std;

int N,M;
long long network[MAXN+1][MAXN+1]={0};
int conn[MAXN+1][MAXM+1]={0},connc[MAXN+1]={0};
long long eindex[MAXM+1][3]={0};

struct EdmondKarp{
  long long cap[MAXN+1][MAXN+1];
  
  EdmondKarp(){
    // cout<<"here"<<endl;
    memset(cap,0,sizeof cap);
    for(int i=1;i<=N;i++){
      for(int j=1;j<=N;j++){
	if(network[i][j]>0){
	  cap[i][j] = network[i][j];
	}
      }
    }
  }
  
  bool bfs(int pre[]){
    int visited[MAXN+1] = {0};
    queue<int> q;
    q.push(1);
    visited[1] = 1;
  
    while(!q.empty()){
      int cur = q.front();
      q.pop();
      if(cur == N){
	return true;
      }
      else{
	for(int i=0;i<connc[cur];i++){//!!!!!!
	  int nn = conn[cur][i];
	  if(visited[nn]==0 && cap[cur][nn]>0){
	    q.push(nn);
	    pre[nn] = cur;
	    visited[nn] = 1;
	  }
	}
      }
    }
    return false;
  }

  long long  maxflow(){
    long long flow = 0;  
    while(true){
      int pre[MAXN+1]={0};
    
      if(bfs(pre)==false){
	break;
      }
    
      long long cur = N, augflow = INF;
      // cout<<"path ";
      while(cur>1){
	
	if(cap[pre[cur]][cur]<augflow){
	  augflow = cap[pre[cur]][cur];
	  // cout<<pre[cur]<<' '<<cur<<' '<<cap[pre[cur]][cur]<<endl;
	}
	cur = pre[cur];
      }
      // cout<<"augflow "<<augflow<<endl;
      flow += augflow;
      cur = N;
      while(true){
	if(cur==1)
	  break;
	else{
	  cap[pre[cur]][cur] -= augflow;
	  cap[cur][pre[cur]] += augflow;
	  cur = pre[cur];
	}
      }
    }
    return flow;
  }
};
  

int main(){
  ifstream fin("milk6.in");
  ofstream fout("milk6.out");
  fin>>N>>M;

  int count = 0;
  for(int i=0;i<M;i++){
    int from,to,cost;
    fin>>from>>to>>cost;
    network[from][to] += (cost*(M+1)+1);
    conn[from][connc[from]++] = to;
    conn[to][connc[to]++] = from;
    eindex[i][0] = from;
    eindex[i][1] = to;
    eindex[i][2] = cost;
  }
  
  EdmondKarp all;
  long long maxflow = all.maxflow();
  // cout<<maxflow<<endl;
  fout<<maxflow/((long)M+1)<<' '<<maxflow%((long)M+1)<<endl;
  
  for(int i=0;i<M;i++){
    int tmpf=eindex[i][0],tmpt=eindex[i][1];
    long long tmpcost = eindex[i][2]*(M+1)+1;
    // cout<<tmpf<<' '<<tmpt<<' '<<all.cap[tmpf][tmpt]<<' '<<tmpcost<<endl;
    if(network[tmpf][tmpt]>0 && all.cap[tmpf][tmpt]==0){
      network[tmpf][tmpt] -= tmpcost;
      EdmondKarp tmpE;
      long long tmpflow = tmpE.maxflow();
      //cout<<i<<" tmpflow "<<tmpflow<<" tmpcost "<<tmpcost<<" maxflow "<<maxflow<<endl;
      // cout<<tmpflow<<' '<<tmpcost<<endl;
      if(tmpflow+tmpcost==maxflow){
	//cout<<i+1<<endl;
	fout<<i+1<<endl;
	maxflow = tmpflow;
      }
      else{
	network[tmpf][tmpt] += tmpcost;
      }
    }
  }
  return 0;
}
