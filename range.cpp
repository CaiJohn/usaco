/*
  ID: remijoh1
  LANG: C++11
  TASK: range
*/
#include<iostream>
#include<fstream>
using namespace std;

int main(){
  ifstream fin("range.in");
  ofstream fout("range.out");

  int map[250][250]={0},N,result[251]={0};
  fin>>N;
  for(int i=0;i<N;i++){
    string tmp;
    fin>>tmp;
    for(int j=0;j<N;j++){
      map[i][j] = tmp[j]-'0';
    }
  }
  
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(map[i][j]==0)
        continue;
      else{
        bool tag = true;
        for(int s=2;s<=N && tag==true && i+s-1<N && j+s-1<N;s++){
          for(int m=0;m<s-1&&tag==true;m++){
            if(map[m+i][j+s-1]==0){
              tag = false;
            }
          }
          for(int m=0;m<s&&tag==true;m++){
            if(map[i+s-1][m+j]==0){
              tag = false;
            }
          }
          if(tag==true)
            result[s]++;
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
