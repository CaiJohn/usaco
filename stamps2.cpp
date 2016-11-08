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

int main(){
  ifstream fin("stamps.in");
  ofstream fout("stamps.out");

  fin>>K>>N;
  for(int i=0;i<=N;i++){
    fin>>stamps[i];
  }

  bool state[2][51][201]={false};

  for(int m=1;m<MAXV;m++){
    for(int k=1;k<K;k++){
      for(int n=N-1;n>=0;n--){
	bool b = state[m-stamps[k]][n][k-1];
	for(int i=0;i<k;k++){
	  if(b==true)
	    break;
	  b = b||state[
	}

}


  

  
