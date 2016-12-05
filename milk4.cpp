/*
  ID: remijoh1
  LANG: C++11
  TASK: milk4
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#define MAXP 100
#define MAXQ 20000
using namespace std;

ifstream fin("milk4.in");
ofstream fout("milk4.out");

bool check(int P,int K,int pails[]){
  // cout<<"check "<<P<<' '<<K<<endl;
  // for(int i=0;i<P;i++){
  //   cout<<pails[i]<<' ';
  // }
  // cout<<endl;
  bool state[MAXQ+1][2] = {false};
  int cur = 1;
  for(int p=P-1;p>=0;p--){
    for(int k=1;k<=K;k++){
      bool s1 = state[k][(cur+1)%2];
      bool s2;
      if(k-pails[p]==0){        
        s2 = true;
      }
      else{
        if(k-pails[p]<0)
          s2 = false;
        else{
          s2 = state[k-pails[p]][cur];
        }
      }
      state[k][cur] = s1||s2;
      // cout<<"state "<<k<<' '<<p<<' '<<state[k][cur]<<endl;
    }
    cur = (cur+1)%2;
  }
  return state[K][(cur+1)%2];
}

void init(int maxl, int output[],int l){
  for(int i=0;i<maxl;i++){
    output[i] = 1;
  }
  for(int i=maxl;i<l;i++){
    output[i] = 0;
  }
  return;
}

bool next(int output[],int l){
  for(int i=l-1;i>=1;i--){
    if(output[i]==0 && output[i-1]==1){
      output[i] = 1;
      output[i-1] = 0;
      return true;
    }
  }
  return false;
}


bool solve(int cur,int last,int goal,int comb[],const int pails[],const int P,const int Q){
  if(cur==goal){
    int tmppails[MAXP],tcount = 0;
    for(int j=0;j<P;j++){
      if(comb[j]==1){
        tmppails[tcount++] = pails[j];
      }
    }
    if(check(goal,Q,tmppails)){
      fout<<goal;
      for(int j=0;j<goal;j++){
        fout<<' '<<tmppails[j];
      }
      fout<<endl;
      return true;
    }
    else{
      return false;
    }
  }
  else{
    int maxP = P-(goal-cur);
    // cout<<maxP<<endl;
    for(int i = last+1;i<=maxP;i++){
      comb[i] = 1;
      int r = solve(cur+1,i,goal,comb,pails,P,Q);
      comb[i] = 0;
      if(r)
        return r;
    }
    return false;
  }
}
  
int main(){
  
  int Q,P,pails[MAXP];
  fin>>Q>>P;
  for(int i=0;i<P;i++){
    fin>>pails[i];
  }
  sort(pails,pails+P);

  for(int maxl=1;maxl<=P;maxl++){
    int comb[MAXP+1]={0};    
    if(solve(0,-1,maxl,comb,pails,P,Q))
      return 0;
  }
  return 0;
}
