/*
ID: remijoh1
LANG: C++
TASK: sort3
*/

#include<iostream>
#include<fstream>
using namespace std;

int main(){
  ifstream fin("sort3.in");
  ofstream fout("sort3.out");

  int N, s[1000];
  fin>>N;
  for(int i=0;i<N;i++){
    fin>>s[i];
  }

  int num[4]={0};
  for(int i=0;i<N;i++){
    num[s[i]]++;
  }

  // for(int i=1;i<=3;i++){
  //   //    cout<<num[i]<<endl;
  // }
  int stat[4][4]={0};
  for(int i=0;i<num[1];i++){
    stat[1][s[i]]++;
  }
  for(int i=num[1];i<num[1]+num[2];i++){
    stat[2][s[i]]++;
  }
  for(int i=num[1]+num[2];i<N;i++){
    stat[3][s[i]]++;
  }

  // for(int i=1;i<=3;i++){
  //   for(int j=1;j<=3;j++){
  //     cout<<stat[i][j]<<endl;
  //   }
  // }
  
  int count = 0;

  if(stat[2][1]>0 && stat[1][2]>0){
    if(stat[1][2]>stat[2][1]){
      count += stat[2][1];
      stat[1][2] -= stat[2][1];
      stat[2][1] = 0;
    }
    else{
      count += stat[1][2];
      stat[2][1] -= stat[1][2];
      stat[1][2] = 0;
    }
  }

  if(stat[1][3]>0 && stat[3][1]>0){
    if(stat[1][3]>stat[3][1]){
      count += stat[3][1];
      stat[1][3] -= stat[3][1];
      stat[3][1] = 0;
    }
    else{
      count += stat[1][3];
      stat[3][1] -= stat[1][3];
      stat[1][3] = 0;
    }
  }

  if(stat[2][3]>0 && stat[3][2]>0){
    if(stat[2][3]>stat[3][2]){
      count += stat[3][2];
      stat[2][3] -= stat[3][2];
      stat[3][2] = 0;
    }
    else{
      count += stat[2][3];
      stat[3][2] -= stat[2][3];
      stat[2][3] = 0;
    }
  }
  // for(int i=1;i<=3;i++){
  //   for(int j=1;j<=3;j++){
  //     cout<<stat[i][j]<<endl;
  //   }
  // }
  //cout<<count<<endl;
  count += stat[1][3]*2;
  count += stat[1][2]*2;

  fout<<count<<endl;
  //  cout<<count<<endl;

  return 0;
}

