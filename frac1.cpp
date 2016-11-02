/*
  ID: remijoh1
  LANG: C++
  TASK: frac1
*/

#include<iostream>
#include<fstream>
#include<utility>
using namespace std;

bool gt(int n1,int d1,int n2,int d2){
  return n1*d2>n2*d1;
}

pair<int,int>* norm(int n,int d){
  int a=n,b=d;
  while(a!=b){
    int tmp = b-a;
    if(tmp>a){
      b = b-a;
    }
    else{
      b=a;
      a=tmp;
    }
  }
  pair<int,int> *result = new pair<int,int>(n/a,d/a);
  return result;
}

void norm_heap(pair<int,int> *h, int cur){
  if(cur==0)
    return;
  else{
    int pindex = (cur-1)/2;
    if(gt(h[pindex],h[cur])){
      pair<int,int> tmp = h[pindex];
      h[pindex] = h[cur];
      h[cur] = tmp;
      norm_heap(h,pindex);
    }
    else{
      return;
    }
  }
}

int push_heap(pair<int,int> *h,int len,pair<int,int> t){
  h[len] = t;
  norm_heap(h,len);
  return len+1;
}

int main(void){
  ifstream fin("frac1.in");
  ofstream fout("frac1.out");

  int N;
  fin>>N;

  int numer=1,domi=N;
  int lhumer = 0,ldomi = 1;
  
  fout<<0<<'/'<<1<<endl;
  while(size>0){
    
    
  while(numer<domi){
    fout<<numer<<'/'<<domi<<endl;

    pair<int,int> *newf;
    if(gt(numer+1,domi,numer,domi-1)){
      newf = norm(numer,domi-1);
    }
    else{
      newf = norm(numer+1,domi);
    }
    numer = newf->first;
    domi = newf->second;
  }
  fout<<1<<'/'<<1<<endl;
  return 0;
}
  
    
