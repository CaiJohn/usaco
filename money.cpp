/*
  ID: remijoh1
  LANG: C++
  TASK: money
*/
#include<iostream>
#include<fstream>
using namespace std;

int main(void){
  ifstream fin("money.in");
  ofstream fout("money.out");

  int V,N,coins[25];

  fin>>V>>N;
  for(int i=0;i<V;i++){
    fin>>coins[i];
  }

  long long state[10001][26] = {0};
  for(int i=0;i<V;i++){
    state[0][i] = 1;
  }
  
  for(int m=1;m<=N;m++){
    for(int c=V-1;c>=0;c--){
      if(m-coins[c]>=0)
          state[m][c]+=state[m-coins[c]][c];
      if(c+1<V)
        state[m][c] += state[m][c+1];
      //cout<<m<<' '<<c<<' '<<state[m][c]<<endl;
    }
  }
  fout<<state[N][0]<<endl;

  return 0;
}
