/*
  ID: remijoh1
  LANG: C++
  TASK: subset
*/

#include<iostream>
#include<fstream>
using namespace std;

int main(void){
  ifstream fin("subset.in");
  ofstream fout("subset.out");
  unsigned N, sum[40][781]={0};
  
  fin>>N;
  int maxS = (1+N)*N/2;
  sum[0][0] = 1;
  if((maxS&1)==1){
    fout<<0<<endl;
  }
  else{  
    for(int i=1;i<=N;i++){
      for(int j=0;j<=maxS;j++){
        sum[i][j] = sum[i-1][j];
      }
      for(int j=0;j<=maxS;j++){
        if(sum[i-1][j]!=0){
          sum[i][j+i]+=sum[i-1][j];
        }
      }
      // for(int j=0;j<=maxS;j++){
      //   cout<<i<<' '<<j<<' '<<sum[i][j]<<endl;
      // }
    }
    //cout<<(maxS)<<endl;
    
    fout<<(sum[N][maxS>>1]>>1)<<endl;
  }
  return 0;
}
  
