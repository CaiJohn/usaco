/*
ID: remijoh1
LANG: C++11
TASK: race3
*/
#include<iostream>
#include<fstream>
#include<queue>
#define MAXV 50
using namespace std;
int N=0, edges[MAXV+1][MAXV+1]={0};

void reach(int s,int disn,int visited[]){
  // cout<<"reach "<<s<<' '<<disn<<endl;
  queue<int> q;
  q.push(s);
  visited[s] = 1;
  while(!q.empty()){
    int cur = q.front();
    // cout<<cur<<endl;
    q.pop();
    for(int i=0;i<=N;i++){
      if(i!=disn && visited[i]==0 && edges[cur][i]==1){
	visited[i] = 1;
	q.push(i);
      }
    }
  }
  return;
}

int main(){
  ifstream fin("race3.in");
  ofstream fout("race3.out");

  int tmp;
  while(true){
    while(true){
      fin>>tmp;
      if(tmp<0)
	break;
      else{
	edges[N][tmp] = 1;
      }
    }
    if(tmp==-1)
      break;
    N++;    
  }
  // cout<<N<<endl;

  int ans1[MAXV+1], count1=0;
  for(int i=1;i<N-1;i++){
    int visited[MAXV+1] = {0};
    reach(0,i,visited);
    if(visited[N-1]==0){
      // cout<<"ans1 "<<i<<endl;
      ans1[count1++] = i;
    }
  }
  
  int ans2[MAXV+1],count2 = 0;
  for(int i=0;i<count1;i++){
    int visited[MAXV] = {0};
    reach(ans1[i],-1,visited);
    bool tag = (visited[0]==0) && (visited[N-1]==1);
    for(int m=0;m<N && tag;m++){
      for(int n=0;n<N && tag;n++){
	if(m!=ans1[i] && n!=ans1[i] && visited[m]!=visited[n] && edges[m][n]+edges[n][m]>=1){
	  //cout<<i<<' '<<m<<' '<<n<<endl;
	  tag = false;
	}
      }
    }
    if(tag==true){
      ans2[count2++] = ans1[i];
    }
  }

  fout<<count1;
  for(int i=0;i<count1;i++){
    fout<<' '<<ans1[i];
  }
  fout<<endl;
  fout<<count2;
  for(int i=0;i<count2;i++){
    fout<<' '<<ans2[i];
  }
  fout<<endl;
  return 0;
}
      
  
