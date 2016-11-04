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
  int N, sum[781]={0};
  
  fin>>N;
  int maxS = (1+N)*N/2;
  sum[0] = 1;
  if((maxS&1)==1){
    fout<<0<<endl;
  }
  else{  
    for(int i=1;i<=N;i++){
      int tag[781] = {0};
      for(int j=0;j<=maxS;j++){
        if(sum[j]!=0 && tag[j]==0){
          tag[j+i]=1;
          sum[j+i] += sum[j];
        }
      }
    }
    for(int i=0;i<=100;i++){
      cout<<sum[i]<<endl;
    }
    fout<<sum[maxS>>2]<<endl;
  }
  return 0;
}
  
