/*
  ID: remijoh1
  LANG: C++11
  TASK: nuggets
*/
#include<iostream>
#include<fstream>
#define MAXV 2000000000
#define MAXNUM 1000000
using namespace std;

int GCD(int a,int b){
  if(a==b)
    return a;
  else{
    if(a>b)
      return GCD(a-b,b);
    else
      return GCD(b-a,a);
  }
}

int main(){
  ifstream fin("nuggets.in");
  ofstream fout("nuggets.out");

  int N,pack[10];
  fin>>N;
  for(int i=0;i<N;i++)
    fin>>pack[i];

  int cd = pack[0],goal = MAXV;
  for(int i=0;i<N;i++){
    if(goal>pack[i])
      goal = pack[i];
    cd = GCD(cd,pack[i]);
  }
  
  if(cd>1){
    fout<<0<<endl;
    return 0;
  }
  
  int gen[MAXNUM],count=1,pos[10]={0},ccount=0,last=0;
  gen[0] = 0;
  
  while(true){
    int next = MAXV;
    for(int i=0;i<N;i++){
      //cout<<pos[i]<<endl;
      while(true){
        if(gen[pos[i]]+pack[i]<=gen[count-1]){
          pos[i]++;
          continue;
        }
        else{
          if(gen[pos[i]]+pack[i]<next){
            next = gen[pos[i]]+pack[i];
            //cout<<"here"<<endl;
          }
          break;
        }
      }
    }
    // cout<<next<<endl;
    //cout<<count<<endl;
    if(next-1 == gen[count-1]){
      ccount++;
    }
    else{
      ccount = 1;
      last = next-1;
    }
    if(ccount==goal){
      fout<<last<<endl;
      return 0;
    }
    gen[count++] = next;
  }

  return 0;
}
  
