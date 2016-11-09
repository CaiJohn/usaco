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

int check(int M,int N,int K){
  
  if(M>=700000)
    return 0;
  int msize = 700000,nsize = 51,ksize = 201;
  // bool state[200][51][201]={false};

  bool ***state = new bool** [M];
  for(int i=0;i<M;i++){
    state[i] = new bool* [N];
    for(int j=0;j<N;j++){
      state[i][j] = new bool [2]();
    }
  }

  //bool state[700000][51][2]={false};
  
  // for(int n=0;n<=N;n++){
  //   for(int k=0;k<=K;k++){
  //     state[0][n][k] = true;
  //   }
  // }
  for(int n=0;n<=N;n++){
    for(int k=0;k<2;k++){
      state[0][n][k] = true;
    }
  }
  // for(int k=1;k<=K;k++){
  //   for(int m=1;m<=M;m++){
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
  // return state[M][0][K];
  int cur = 0;
  for(int k=1;k<=K;k++){
    cur = 1 - cur;
    for(int m=1;m<=M;m++){
      //cout<<m<<endl;
      for(int n=N-1;n>=0;n--){
        bool m1,k1;
        if(m-stamps[n]<0)
          m1 = false;
        else
          m1 = state[m-stamps[n]][n][(cur+1)%2];        
        state[m][n][cur] = (m1 || state[m][n+1][cur] || state[m][n][(cur+1)%2]);
        // if(m==M && state[m][n][cur]==true)
        //   return true;
        //cout<<m<<' '<<n<<' '<<k<<' '<<cur<<' '<<state[m][n][cur]<<endl;
      }
      
      //cout<<"end of n"<<endl;
      
    }
    //cout<<"end of k, and m is "<<m<<endl;
    
  }
  int count = 0;
  for(int i=1;i<=M;i++){
    if(state[i][0][cur]==false)
      break;
    count++;
  }
  //return state[M][0][cur];
  return count;
}
int main(){
  ifstream fin("stamps.in");
  ofstream fout("stamps.out");

  fin>>K>>N;
  for(int i=0;i<=N;i++){
    fin>>stamps[i];
  }

  int count = 1;
  int reuslt = -1;
  // while(check(count*1000,N,K)){
  //   count++;
  // }
  fout<<check(699999,N,K)<<endl;
  //fout<<count<<endl;
  // for(int i=1;i<20;i++){
  //   cout<<i<<' '<<check(i,N,K)<<endl;
  // }
  return 0;
}
  
