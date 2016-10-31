/*
  ID: remijoh1
  LANG: C++11
  TASK: ariprog
*/
#include<iostream>
#include<fstream>

using namespace std;

int check(int num, int m){
  for(int i=0;i<=m;i++){
    int i2 = i*i;
    if(i2>num)
      return -1;
    for(int j=0;j<=m;j++){
      int j2 = j*j;
      if(i2+j2==num)
        return 1;
      if(i2+j2>num)
        break;
      // if(i2>num || j2>num){
      //   cout<<i2<<endl;
      //   return false;
    }
  }
  
  return -1;
}

void gen(int m, int info[]){
  for(int i=0;i<=m;i++){
    for(int j=0;j<=m;j++){
      info[i*i+j*j] = 1;
    }
  }
}

int main(void){
  ifstream fin("ariprog.in");
  ofstream fout("ariprog.out");

  int N,M;

  fin>>N>>M;
  int checked[200000] = {0};
  int maxD = M*M*2;
  int tag = false;

  gen(M,checked);
  
  for(int diff = 1;diff<=maxD;diff++){
    for(int start = 0;start<=maxD;start++){
      int l;
      for(l = 0;l<N;l++){
        int target = start+diff*l;
        // if(target>maxD)
        //   break;
        // if(checked[target]==0)
        //   checked[target] = check(target,M);
        if(checked[target]==0){
          break;
        }
      }
      if(l==N){
        fout<<start<<' '<<diff<<endl;
        tag = true;
      }
    }
  }
  if(tag == false)
    fout<<"NONE"<<endl;
  return 0;
}
   
