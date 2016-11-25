/*
  ID: remijoh1
  LANG: C++11
  TASK: milk6
*/
#include<iostream>
#include<fstream>
#include<queue>
#define MAXN 32
#define MAXM 1000
#define INF 2000000
using namespace std;

int N,M;
int cap[MAXN+1][MAXN+1]={0};
int conn[MAXN+1][MAXN+1]={0},connc[MAXN+1]={0};
int eindex[MAXN+1][MAXN+1]={0};

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
      for(int i=0;i<connc[cur];i++){
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

int maxflow(){
  int flow = 0;  
  while(true){
    int pre[MAXN+1];
    
    if(bfs(pre)==false){
      break;
    }
    
    int cur = N,augflow = INF;
    while(cur>1){
      if(cap[pre[cur]][cur]<augflow)
        augflow = cap[pre[cur]][cur];
      cur = pre[cur];
    }
    
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

void reach(int s, int visited[]){
  queue<int> q;
  q.push(s);
  visited[s] = 1;
  while(!q.empty()){
    int cur = q.front();
    q.pop();
    for(int i=0;i<connc[cur];i++){
      int nn = conn[cur][i];
      if(visited[nn]==0 && cap[cur][nn]>0){
	visited[nn] = 1;
	q.push(nn);
      }
    }
  }
  return;
}
  

int main(){
  ifstream fin("milk6.in");
  ofstream fout("milk6.out");
  fin>>N>>M;

  int count = 0;
  for(int i=0;i<M;i++){
    int from,to,cost;
    fin>>from>>to>>cost;
    cap[from][to] = cost;
    conn[from][connc[from]++] = to;
    
    eindex[from][to] = ++count;
  }
  
  int mincost = maxflow();

  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      if(eindex[i][j]>0){
        if(cap[i][j]==0){
          cap[i][j] = 1;
	  cout<<eindex[i][j]<<endl;
        }
        else{
          cap[i][j] = INF;
        }
      }
      else{
        cap[i][j] = 0;
      }
    }
  }
  cout<<maxflow()<<endl;
  int minIndex = MAXM+1,minfrom,minto;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      if(eindex[i][j]>0){
        if(cap[i][j]==0){
          if(eindex[i][j]<minIndex){
            minIndex = eindex[i][j];
            minfrom = i;
            minto = j;
          }
          cap[i][j] = 2;
        }
        else{
          cap[i][j] = INF;
        }
      }
      else{
        cap[i][j] = 0;
      }
    }
  }
  cout<<minfrom<<' '<<minto<<endl;
  cap[minfrom][minto] = 1;

  cout<<maxflow()<<endl;
  int cut[MAXM+1] = {0};
  reach(1,cut);
  int ans[MAXM],acount=0;
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      if(cut[i]==1 && cut[j]==0 && eindex[i][j]>0){
	ans[acount++] = eindex[i][j];
      }
    }
  }
  
  sort(ans,ans+acount);
  fout<<mincost<<' '<<acount<<endl;
  for(int i=0;i<acount;i++)
    fout<<ans[i]<<endl;
  return 0;
}
