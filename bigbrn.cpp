/*
  ID: remijoh1
  LANG: C++11
  TASK: bigbrn
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#define MAXN 1000
using namespace std;

int main(){
  ifstream fin("bigbrn.in");
  ofstream fout("bigbrn.out");

  int N,T,map[MAXN+1][MAXN+1]={0};
  fin>>N>>T;
  for(int i=0;i<T;i++){
    int r,c;
    fin>>r>>c;
    map[r][c] = 1;
  }

  int state[MAXN+1][MAXN+1] = {0};
  for(int r=N;r>0;r--){
    for(int c=N;c>0;c--){
      if(map[r][c]==1)
        state[r][c] = 0;
      else{
        int s1=0,s2=0,s3=0;
        if(r+1<=N){
          s1 = state[r+1][c];
        }
        if(c+1<=N){
          s2 = state[r][c+1];
        }
        if(r+1<=N && c+1<=N){
          s3 = state[r+1][c+1];
        }
        state[r][c] = min(min(s1,s2),s3)+1;
      }
    }
  }
  int maxsize = 0;
  for(int r=1;r<=N;r++){
    for(int c=1;c<=N;c++){
      if(maxsize<state[r][c])
        maxsize = state[r][c];
    }
  }
  fout<<maxsize<<endl;
  return 0;
}
  
