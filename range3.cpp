/*
  ID: remijoh1
  LANG: C++11
  TASK: range
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int min3(int a,int b,int c){
  return min(min(a,b),c);
}

int main(){
  ifstream fin("range.in");
  ofstream fout("range.out");

  int map[250][250]={0},N;
  fin>>N;
  for(int i=0;i<N;i++){
    string tmp;
    fin>>tmp;
    for(int j=0;j<N;j++){
      map[i][j] = tmp[j]-'0';
    }
  }


  int state[251][251]={0},result[251]={0};
  for(int i=N-1;i>=0;i--){
    for(int j=N-1;j>=0;j--){
      if(map[i][j]==1){
        state[i][j] = min3(state[i+1][j],state[i][j+1],state[i+1][j+1])+1;
        for(int k=1;k<=state[i][j];k++){
          result[k]++;
        }
      }
    }
  }
  for(int i=2;i<=N;i++){
    if(result[i]>0)
      fout<<i<<' '<<result[i]<<endl;
  }
  
  return 0;
}
