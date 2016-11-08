/*
  ID: remijoh1
  LANG: C++11
  TASK: stamps
*/
#include<iostream>
#include<fstream>
#define MAXV 2000001
using namespace std;
int K,N;
int stamps[51],stat[MAXV]={0};

void search(int left,int cur,int ans[]){
  if(left==0 || cur==N+1){
    // for(int i=0;i<cur;i++)
    //   cout<<ans[i]<<' ';
    //    cout<<endl;
    int sum = 0;
    for(int i=0;i<cur;i++){
      sum += stamps[i]*ans[i];
    }
    //cout<<sum<<endl;
    stat[sum] = 1;
    return;
  }
  else{
    for(int i=0;i<=left;i++){
      ans[cur] = i;
      search(left-i,cur+1,ans);
    }
    return;
  }
}

int main(){
  ifstream fin("stamps.in");
  ofstream fout("stamps.out");

  fin>>K>>N;
  for(int i=1;i<=N;i++){
    fin>>stamps[i];
  }
  stamps[0] = 0;
  int ans[51]={0};
  search(K,0,ans);
  int sum = 0;
  for(int i=1;i<MAXV;i++){
    if(stat[i]==0)
      break;
    sum += stat[i];
  }
  fout<<sum<<endl;
  return 0;
}


  

  
