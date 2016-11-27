/*
  ID: remijoh1
  LANG: C++11
  TASK: fc
*/
#include<iostream>
#include<fstream>
#include<cmath>
#include<iomanip>
#include<algorithm>
#define MAXN 10000
#define MAXX 1000000
using namespace std;
typedef pair<double, double> Pd;
int N;
Pd pos[MAXN], start;

double crossproduct(Pd a, Pd b){
  return a.first*b.second-a.second*b.first;
}

bool cmp(Pd a, Pd b){
  Pd v1,v2;
  v1.first = a.first-start.first;
  v1.second = a.second-start.second;
  v2.first = b.first-start.first;
  v2.second = b.second-start.second;
  return crossproduct(v1,v2)>0;
}

bool turnright(Pd a, Pd b, Pd c){
  Pd v1,v2;
  v1.first = b.first-a.first;
  v1.second = b.second-a.second;
  v2.first = c.first-a.first;
  v2.second = c.second-a.second;
  return crossproduct(v1,v2)<=0;
}


int main(){
  ifstream fin("fc.in");
  ofstream fout("fc.out");
  fin>>N;
  for(int i=0;i<N;i++){
    fin>>pos[i].first>>pos[i].second;
  }


  if(N==0){
    fout<<"0.00"<<endl;
    return 0;
  }
    
  double miny=MAXX,minx=MAXX;
  int spos = -1;
  for(int i=0;i<N;i++){
    if(miny>=pos[i].second){
      if(minx>pos[i].first){
        minx = pos[i].first;
        miny = pos[i].second;
        spos = i;
      }
    }
  }
  start.first = minx;
  start.second = miny;
  pos[spos].first = pos[0].first;
  pos[spos].second = pos[0].second;
  pos[0].first = minx;
  pos[0].second = miny;
  
  sort(pos+1,pos+N,cmp);
  
  Pd pstack[MAXN+1];
  int sp = 0;
  for(int i=0;i<N;i++){
    // cout<<i<<endl;
    if(sp<3){
      pstack[sp].first = pos[i].first;
      pstack[sp].second = pos[i].second;
      sp++;
    }
    else{
      while(true){
        if(sp>=2 && turnright(pstack[sp-2],pstack[sp-1],pos[i])){
          sp--;
        }
        else{
          break;
        }
      }
      pstack[sp].first = pos[i].first;
      pstack[sp].second = pos[i].second;
      sp++;
    }
  }
  pstack[sp].first = pos[0].first;
  pstack[sp].second = pos[0].second;
  sp++;

  double len = 0;
  for(int i=1;i<sp;i++){
    // cout<<pstack[i-1].first<<' '<<pstack[i-1].second<<endl;
    len += sqrt((pstack[i].first-pstack[i-1].first)*(pstack[i].first-pstack[i-1].first)+(pstack[i].second-pstack[i-1].second)*(pstack[i].second-pstack[i-1].second));
  }
  fout<<fixed<<setprecision(2)<<len<<endl;
  return 0;
}
  

  
  
