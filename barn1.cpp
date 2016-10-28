/*
ID: remijoh1
LANG: C++11
TASK: barn1
*/

#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int main(){
  ifstream fin("barn1.in");
  ofstream fout("barn1.out");

  int M,S,C;
  fin>>M>>S>>C;
  int stall[201];
  int tmp1,tmp2;

  for(int i=0;i<C;i++){
    fin>>stall[i];
  }
  sort(stall,stall+C);

  int info[201];
  for(int i=0;i<C-1;i++){
    info[i] = stall[i+1]-stall[i]-1;
  }
  sort(info,info+C-1);

  int length = C;
  int index = 0;
  while(C>M){
    length += info[index++];
    C--;
  }

  fout<<length<<endl;
  return 0;
}

  
  
