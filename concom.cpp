/*
  ID: remijoh1
  LANG: C++
  TASK: concom
*/
/*
  Be careful to the problem!
 */
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int main(void){
  ifstream fin("concom.in");
  ofstream fout("concom.out");
  
  int n,info[101][101]={0},ctrl[101][101]={0},comp[101],compc=0;
  fin>>n;
  for(int i=0;i<n;i++){
    int from,to,perc;
    fin>>from>>to>>perc;
    info[from][to] = perc;

    bool tag = false;
    for(int j=0;j<compc;j++){
      if(comp[j]==from){
        tag = true;
        break;
      }
    }
    if(tag == false){
      comp[compc++]=from;
    }
    tag = false;
    for(int j=0;j<compc;j++){
      if(comp[j]==to){
        tag = true;
        break;
      }
    }
    if(tag == false){
      comp[compc++]=to;
    }
    ctrl[from][from] = 1;
    ctrl[to][to] = 1;
    if(perc>50){
      ctrl[from][to] = 1;
    }
  }
  
  sort(comp,comp+compc);
  bool tag = true;
  while(tag==true){
    tag = false;
    for(int i=0;i<compc;i++){
      for(int j=0;j<compc;j++){
        if(j==i || ctrl[comp[i]][comp[j]]==1)
          continue;
        int sum = 0;
        for(int k=0;k<compc;k++){
          if(ctrl[comp[i]][comp[k]]==1){
            // cout<<comp[i]<<' '<<comp[j]<<' '<<comp[k]<<endl;
            // cout<<info[comp[k]][comp[j]]<<endl;
            sum += info[comp[k]][comp[j]];
          }
        }
        // cout<<sum<<endl;
        if(sum>50){
          ctrl[comp[i]][comp[j]] = 1;
          tag = true;
        }
      }
    }
  }
  for(int i=0;i<compc;i++){
    for(int j=0;j<compc;j++){
      if(i!=j && ctrl[comp[i]][comp[j]]==1)
        fout<<comp[i]<<' '<<comp[j]<<endl;
    }
  }
  return 0;
}
