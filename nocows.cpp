/*
  ID: remijoh1
  LANG: C++
  TASK: nocows
*/
#include<iostream>
#include<fstream>
// #include<cassert>
#define MAXN 200
using namespace std;

int C(int m,int n){// C_m^n
  if(m>=n && n>0){
    n = (m-n)>n?n:m-n;
    unsigned long long num = 1,dom=1;
    for(int i=1;i<=n;i++){
      num = num*(m-i+1);
      dom = dom*i;
    }
    //cout<<'C'<<m<<' '<<n<<' '<<num<<' '<<dom<<endl;
    
    return (num/dom)%9901;
  }
  else{
    cout<<"error"<<endl;
    return -1;
  }
}

int main(void){
  ifstream fin("nocows.in");
  ofstream fout("nocows.out");

  int N,K;
  fin>>N>>K;
  
  
  unsigned long long info[2][MAXN+1][MAXN+1]={0};
  int cur=0;
  // for(int i=0;i<=N;i++){
  //   for(int j=0;j<=N;j++)
  //     cout<<info[0][i][j]<<endl;
  // }
  
  info[0][1][1] = 1;
  for(int l=2;l<=K;l++){
    // cout<<cur<<endl;
    cur = (cur+1)%2;
    for(int i=0;i<=MAXN;i++)
      for(int j=0;j<=MAXN;j++)
        info[cur][i][j] = 0;

    
    for(int n=1;n<=N;n+=2){
      for(int leaf=2;leaf<=n;leaf+=2){
        // cout<<l<<' '<<n<<' '<<leaf<<endl;
         
        for(int pleaf = leaf/2;pleaf<=N;pleaf++){
          
          if(info[1-cur][n-leaf][pleaf]>0){
            //cout<<l<<' '<<n<<' '<<leaf<<endl;
            // cout<<' '<<cur<<' '<<l-1<<' '<<n-leaf<<' '<<pleaf<<' '<<endl;
            // cout<<"here"<<' '<<1-cur<<' '<<n-leaf<<' '<<pleaf<<' '<<info[1-cur][n-leaf][pleaf]<<' '<<C(pleaf,leaf/2)<<endl;
            // cout<<'+'<<"info["<<l-1<<"]["<<n-leaf<<"]["<<pleaf<<"]("<<info[1-cur][n-leaf][pleaf]<<")*C("<<pleaf<<","<<leaf/2<<")("<<C(pleaf,leaf/2)<<")"<<endl;
            info[cur][n][leaf] += ((info[1-cur][n-leaf][pleaf]%9901)*C(pleaf,leaf/2))%9901;
          }
        }
        info[cur][n][leaf] %= 9901;
        
      }
      
    }
  }
  //cout<<cur<<endl;
  //cout<<info[3][7][4];
  unsigned long long sum = 0;
  for(int i=2;i<=N;i+=2){
    sum += info[cur][N][i];
  }
  fout<<(sum%9901)<<endl;
  return 0;
}
      
