/*
ID: remijoh1
LANG: C++11
TASK: charrec
*/
#include<iostream>
#include<fstream>
#define MAXN 1200
#define MAXC 120
using namespace std;

int digits[27][20] = {0};
int input[MAXN] = {0};
int matchOne[27][MAXN][20] = {0};

int change(int from, int to){
  int c = from^to;
  int sum = 0;
  for(int i=0;i<20;i++){
    sum += (c & 1);
    c = c>>1;
  }
  return sum;
}

void calc(int pos){
  for(int i=0;i<27;i++){
    for(int j=0;j<20;j++){
      matchOne[i][pos][j] = change(digits[i][j],input[pos+j]);
    }
  }
  return;
}

int match(int pos, int num){
  int minC = MAXC,tmpc;
  int sum;
  if(num==20){    
    for(int i=0;i<27;i++){
      sum = 0;
      for(int j=0;j<20 && sum<minC ;j++){
	sum += matchOne[i][pos][j];
      }
      if(minC>sum)
	minC = sum;
    }
  }
  else{
    if(num==19){
      calc(pos-1);
      for(int i=0;i<27;i++){
	for(int m=0;m<19;m++){// the missing line
	  for(int j=0;j<m && sum<minC ;j++){
	    sum += matchOne[i][pos][j];
	  }
	  for(int j=m+1;j<19 && sum<minC ;j++){
	    sum += matchOne[i][pos-1][j+1];
	  }
	  if(minC>sum)
	    minC = sum;
	}
      }
    }
    else{
      for(int i=0;i<27;i++){
	for(int m=0;m<21;m++){
	  for(int j=0;j<m && sum<minC ;j++){
	    sum += matchOne[i][pos][j];
	  }
	  int d1 = matchOne[i][pos][m];
	  int d2 = matchOne[i][pos][m+1];
	  sum += min(d1,d2);
	  for(int j=m+2;j<21 && sum<minC ;j++){
	    sum += matchOne[i][pos+1][j-1];
	  }
	  if(minC>sum)
	    minC = sum;
	}
      }
    }
  }
  return minC;
}

int main(){
  ifstream fin("charrec.in");
  ofstream fout("charrec.out");

  int state[MANX+1];
  for(int s=End-19;s>=0;s--){
    int minC = MAXC,tmpc=0;
    if(s+19<End && state[s+19]>=0){
      mr = match(s,19);
      if(tmpc + state[s+19]<minC){
	minC = tmpc + state[s+19];
	minS = mr.s + matchS[s+19];
      }
      
    }
    if(s+20<End && state[s+20]>=0){
      tmpc = match(s,20);
      if(tmpc + state[s+20]<minC){
	minC = tmpc + state[s+20];
	minS = mr.s + matchS[s+20];
      }
    }
    if(s+21<End && state[s+21]>=0){
      tmpc = match(s,21);
      if(tmpc + state[s+21]<minC){
	minC = tmpc + state[s+21];
	minS = mr.s + matchS[s+21];
      }
    }
    state[s] = minC;
    matchS[s] = minS;
  }
  fout<<matchS[0]<<endl;
  return 0;
}
