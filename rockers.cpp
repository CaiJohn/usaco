/*
  ID: remijoh1
  LANG: C++11
  TASK: rockers
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#define MAXN 20
#define MAXM 20
#define MAXT 20
using namespace std;

int main(){
  ifstream fin("rockers.in");
  ofstream fout("rockers.out");
  int N,T,M,len[MAXN+1]={0};
  fin>>N>>T>>M;
  for(int i=0;i<N;i++){
    fin>>len[i];
  }

  int state[MAXN+1][MAXM+1][MAXT+1]={0};

  for(int m=M-1;m>=0;m--){
    for(int n=N-1;n>=0;n--){
      for(int t=0;t<=T;t++){
	int op1,op2;
	if(t-len[n]>=0){
	  op1 = state[n+1][m][t-len[n]]+1;
	}
	else{
	  op1 = state[n][m+1][T];
	}
	op2 = state[n+1][m][t];
	state[n][m][t] = max(op1,op2);
	//cout<<n<<' '<<m<<' '<<t<<' '<<state[n][m][t]<<endl;
      }
    }
  }
  fout<<state[0][0][T]<<endl;
  return 0;
}
  
