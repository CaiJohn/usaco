/*
  ID: remijoh1
  LANG: C++
  TASK: inflate
*/
#include<iostream>
#include<fstream>
using namespace std;

int main(void){
  ifstream fin("inflate.in");
  ofstream fout("inflate.out");
  int M,N;
  fin>>M>>N;

  int points[10000],minites[10000];
  for(int i=0;i<N;i++){
    fin>>points[i]>>minites[i];
    //cout<<points[i]<<' '<<minites[i]<<endl;
  }

  int state[10001][2]={0},cur=0;

  for(int k=N-1;k>=0;k--){
    cur = (cur+1)%2;
    for(int m=1;m<=M;m++){
      int c1,c2;
      if(k+1>=N){
        c1 = 0;
      }
      else{
        c1 = state[m][(cur+1)%2];
      }
      if(m-minites[k]<0){
        c2 = 0;
      }
      else{
        c2 = state[m-minites[k]][cur]+points[k];
      }
      state[m][cur] = c1>c2?c1:c2;
      //cout<<m<<' '<<cur<<' '<<state[m][cur]<<endl;
    }
  }
  
  fout<<state[M][cur]<<endl;
  return 0;
}



        
