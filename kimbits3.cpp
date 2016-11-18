/*
  ID: remijoh1
  LANG: C++11
  TASK: kimbits
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
  ifstream fin("kimbits.in");
  ofstream fout("kimbits.out");
  unsigned int N,L,I;
  fin>>N>>L>>I;

  unsigned int state[32][32];
  for(int n=0;n<=N;n++){
    for(int l=0;l<=L;l++){
      if(n==0 || l==0)
	state[n][l]=1;
    }
  }
  for(int n = 1;n<=N;n++){
    for(int l = 1;l<=L;l++){
      state[n][l] = state[n-1][l]+state[n-1][l-1];
      // cout<<state[n][l]<<endl;
    }
  }
  
  unsigned int curN=N,curL=L,curI=I;
  string result;
  while(true){
    // cout<<curN<<' '<<curL<<' '<<curI<<endl;
    if(curN==0)
      break;
    if(state[curN-1][curL]>=curI){
      // cout<<state[curN-1][L]<<' '<<curI<<endl;
      result.insert(result.end(),'0');
      curN--;
    }
    else{
      result.insert(result.end(),'1');
      curI -= state[curN-1][curL];
      curN--;
      curL--;
    }
  }

  fout<<result<<endl;
  // cout<<result<<endl;
  return 0;
}

