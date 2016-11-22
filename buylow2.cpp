/*
  ID: remijoh1
  LANG: C++11
  TASK: buylow
*/
#include<iostream>
#include<fstream>
#define MAXN 5000
using namespace std;


int main(){
  ifstream fin("buylow.in");
  ofstream fout("buylow.out");

  int N,seq[MAXN];
  fin>>N;
  for(int i=0;i<N;i++)
    fin>>seq[i];
  
  int state[MAXN+1] = {0},count[MAXN+1]= {0};
  for(int i=N-1;i>=0;i--){
    int maxS = 0, num = 1;// When all the numbers are greater, then maxS==0, num=1
    for(int j=i+1;j<N;j++){
      // if(seq[j]==seq[i])
      // 	break;
      if(seq[j]<seq[i]){
	if(state[j]>maxS){
	  maxS = state[j];
	  num = count[j];
	}
	else{
	  if(state[j]==maxS){
	    num += count[j];
	  }
	}
      }
    }
    state[i] = maxS+1;
    for(int j=i+1;j<N;j++){
      if(state[j]==state[i] && seq[j]==seq[i])
	num -= count[j];
    }
    count[i] = num;
  }
  // for(int i=0;i<N;i++){
  //   cout<<state[i]<<' '<<count[i]<<endl;
  // }
  int result=0,snum=0;
  for(int i=0;i<N;i++){
    if(state[i]>result){
      result = state[i];
      snum = count[i];
    }
    else{
      if(state[i]==result){
	snum+=count[i];
      }
    }    
  }
  fout<<result<<' '<<snum<<endl;
  return 0;
}
