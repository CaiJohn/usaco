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

bool check(int M,int N,int K){
  
  if(M>=200)
    return false;
  //bool state[200][51][201]={false};
  bool state[200][51][2]={false};
  
  // for(int n=0;n<=N;n++){
  //   for(int k=0;k<=K;k++){
  //     state[0][n][k] = true;
  //   }
  // }
  for(int n=0;n<=N;n++){
    for(int k=0;k<=2;k++){
      state[0][n][k] = true;
    }
  }
  
  // for(int m=1;m<=M;m++){
  //   for(int k=1;k<=K;k++){
  //     for(int n=N-1;n>=0;n--){
  //       bool m1;
  //       if(m-stamps[n]<0)
  //         m1 = false;
  //       else
  //         m1 = state[m-stamps[n]][n][k-1];
  //       state[m][n][k] = (m1 || state[m][n+1][k] || state[m][n][k-1]);
        
  //     }
  //   }
  // }
  int cur = 1;
  for(int m=1;m<=M;m++){
    cur = 1;
    cout<<m<<endl;
    for(int k=1;k<=K;k++){
      for(int n=N-1;n>=0;n--){
        bool m1,k1;
        if(m-stamps[n]<0)
          m1 = false;
        else
          m1 = state[m-stamps[n]][n][(cur+1)%2];        
        state[m][n][cur] = (m1 || state[m][n+1][cur] || state[m][n][(cur+1)%2]);
        cout<<m<<' '<<n<<' '<<k<<' '<<cur<<' '<<state[m][n][cur]<<endl;
      }
      //cout<<"end of n"<<endl;
      cur = 1 - cur;
    }
    cout<<"end of k, and m is "<<m<<endl;    
  }
  return state[M][0][cur];
}
int main(){
  ifstream fin("stamps.in");
  ofstream fout("stamps.out");

  fin>>K>>N;
  for(int i=0;i<=N;i++){
    fin>>stamps[i];
  }

  int count = 0;
  while(check(count+1,N,K)){
    count++;
  }
  fout<<count<<endl;
  // for(int i=1;i<20;i++){
  //   cout<<i<<' '<<check(i,N,K)<<endl;
  // }
  return 0;
}
  
