/*
  ID: remijoh1
  LANG: C++11
  TASK: stamps
*/
#include<iostream>
#include<fstream>
#define MAXM 2000000
#define H 10001
using namespace std;

int main(){
  ifstream fin("stamps.in");
  ofstream fout("stamps.out");
  
  int K,N;
  int stamps[51];

  fin>>K>>N;
  for(int i=0;i<=N;i++){
    fin>>stamps[i];
  }
  
  int maxStep = K+1;
  int state[H][51] = {0};
  
  for(int m=1;m<=MAXM;m++){
    for(int n=N-1;n>=0;n--){
      int m1,m2;
      if(m-stamps[n]>=0){
	if(m-stamps[n]==0)
	  m1 = 0;
	else
	  m1 = state[(m-stamps[n])%H][n];
      }
      else{
	m1 = maxStep;	
      }
      if(n+1>=N){
	m2 = maxStep;
      }
      else{
	m2 = state[m%H][n+1];
      }
      state[m%H][n] = m1+1<m2?m1+1:m2;
    }
    if(state[m%H][0]>K && m>1){
      fout<<m-1<<endl;
      break;
    }
  }
    
  return 0;
}
  
