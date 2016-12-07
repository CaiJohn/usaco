/*
  ID: remijoh1
  LANG: C++11
  TASK: schlnet
*/
#include<iostream>
#include<fstream>
#include<cstring>
#define MAXN 100
using namespace std;
int N,edge[MAXN+1][MAXN+1]={0};

struct SCC{
  int s[MAXN+1];
  int sp;
  bool instack[MAXN+1];
  int low[MAXN+1];
  int visited[MAXN+1];
  int index;
  int scc[MAXN+1];
  int ccount;
  SCC(){
    
    index = 0;
    sp = 0;
    ccount = 0;
    memset(instack,false,sizeof(instack));//???
    memset(visited,0,sizeof(visited));
    
  }
  
  void tarjan(int v){
    // cout<<"tarjan "<<v<<' '<<index<<' '<<ccount<<endl;
    low[v] = visited[v] = ++index;
    // cout<<"tarjan "<<v<<' '<<index<<' '<<ccount<<endl;
    s[sp++] = v;
    instack[v] = true;
    // cout<<"here"<<endl;
    for(int i=1;i<=N;i++){
      // cout<<i<<endl;
      if(edge[v][i] == 1){
	if(visited[i]==0){
	  tarjan(i);
	  if(low[v]>low[i]){
	    // cout<<"low[v] = low[i]"<<endl;
	    low[v] = low[i];
	  }
	}
	else{
	  if(instack[i] == true && visited[i]<low[v]){
	    // cout<<"low[v] = visited[i]"<<endl;
	    low[v] = visited[i];
	  }
	}
      }
    }
    // cout<<"out"<<endl;
    if(visited[v] == low[v]){
      while(true){
	int tmp = s[--sp];
	instack[tmp] = false;
	scc[tmp] = ccount;
	if(tmp==v)
	  break;
      }
      ccount++;
    }
  }

  void solve(){
    for(int i=1;i<=N;i++){
      if(visited[i]==0){
        
	tarjan(i);
      }
    }
  }
};

int main(){
  ifstream fin("schlnet.in");
  ofstream fout("schlnet.out");

  fin>>N;
  for(int i=1;i<=N;i++){
    int tmp;
    while(true){
      fin>>tmp;
      if(tmp==0)
        break;
      else{
        edge[i][tmp] = 1;
      }
    }
  }

  SCC newscc;
  newscc.solve();
  // cout<<"print"<<endl;
  int inedge[MAXN+1]={0},outedge[MAXN+1]={0};
  for(int i=1;i<=N;i++){
    for(int j=1;j<=N;j++){
      if(edge[i][j]==1 && newscc.scc[i]!=newscc.scc[j]){
        // cout<<newscc.scc[i]<<' '<<newscc.scc[j]<<endl;
        outedge[newscc.scc[i]] = 1;
        inedge[newscc.scc[j]] = 1;
      }
    }
  }
  
  
  int cinzero = 0,coutzero = 0,cboth = 0;
  for(int i=0;i<newscc.ccount;i++){
    if(inedge[i]==0){
      cinzero ++;
    }
    if(outedge[i]==0){
      coutzero ++;
    }
    if(inedge[i]==0 && outedge[i]==0){
      cboth ++;
    }
  }
  fout<<cinzero<<endl;
  if(cboth==1 && coutzero == 1 && cinzero==1)
    fout<<0<<endl;
  else
    fout<<(cinzero>coutzero?cinzero:coutzero)<<endl;

  return 0;
}

  
