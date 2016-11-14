/*
  ID: remijoh1
  LANG: C++11
  TASK: game1
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int main(){
  ifstream fin("game1.in");
  ofstream fout("game1.out");

  int N,board[100],state[100][100][2]={0};
  fin>>N;
  for(int i=0;i<N;i++){
    fin>>board[i];
    state[i][i][0] = board[i];
    state[i][i][1] = 0;
  }
  
  for(int i=1;i<N;i++){
    for(int s=0;s<N-i;s++){
      int l=board[s]+state[s+1][s+i][1],r=board[s+i]+state[s][s+i-1][1];
      state[s][s+i][0] = max(l,r);
      state[s][s+i][1] = l>r?state[s+1][s+i][0]:state[s][s+i-1][0];
      //cout<<i<<' '<<s<<' '<<state[s][s+i][0]<<' '<<state[s][s+i][1]<<endl;
    }
  }
  fout<<state[0][N-1][0]<<' '<<state[0][N-1][1]<<endl;
  return 0;
}
  
