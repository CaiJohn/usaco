/*
  ID: remijoh1
  LANG: C++11
  TASK: job
*/
#include<iostream>
#include<fstream>
#define MAXV 1000000
using namespace std;

bool cmp(int a,int b){
  return a>b;
}

int main(){
  ifstream fin("job.in");
  ofstream fout("job.out");

  int N,M1,M2,a[30],b[30];
  fin>>N>>M1>>M2;
  for(int i=0;i<M1;i++){
    fin>>a[i];
  }
  for(int i=0;i<M2;i++){
    fin>>b[i];
  }
  int starta[1000]={0},finisha[1000]={0};
  for(int i=0;i<N;i++){
    int minf = MAXV,id=-1;
    for(int j=0;j<M1;j++){
      if(starta[j]+a[j]<minf){
        minf = starta[j]+a[j];
        id = j;
      }
    }
    finisha[i] = minf;
    starta[id] = minf;
    
  }
  
  int startb[1000]={0},finishb[1000]={0};
  for(int i=0;i<N;i++){
    int minf = MAXV,id = -1;
    for(int j=0;j<M2;j++){
      if(startb[j]+b[j]<minf){
        minf = startb[j]+b[j];
        id = j;
      }
    }
    finishb[i] = minf;
    startb[id] = minf;
   
  }
  
  int maxf=0;
  for(int i=0;i<N;i++){
    if(finisha[i]+finishb[N-i-1]>maxf)
      maxf = finisha[i]+finishb[N-i-1];
  }
  fout<<finisha[N-1]<<' '<<maxf<<endl;
  return 0;
}
