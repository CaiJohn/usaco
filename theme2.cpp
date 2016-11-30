/*
  ID: remijoh1
  LANG: C++11
  TASK: theme
*/
#include<iostream>
#include<fstream>
#define MAXN 5000
using namespace std;

struct SuffixArray{
  short sa[MAXN];
  short height[MAXN];
  
  bool cmp(int a, int b){
    if(a>len || b>len){
      return a<b;
    }
    else{
      if(seq[a]==seq[b])
        return cmp(a+1,b+1);
      else
        return seq[a]<seq[b];
    }
  }
  
  int LCP(int a, int b){
    if(a>=len || b>=len){
      return 0;
    }
    else{
      if(seq[a]==seq[b]){
        return 1+LCP(a+1,b+1);
      }
      else{
        return 0;
      }
    }
  }
  
  SuffixArray(short melody[],short len){
    for(int i=0;i<len;i++){
      sa[i] = i;
    }
    sort(sa,sa+len,cmp);
    for(int i=0;i<len-1;i++){
      height[i] = LCP(sa[i],sa[i+1]);
    }
  }
  
  bool query(int k){
    
  }
  
  
  
};

int main(){
  ifstream fin("theme.in");
  ofstream fout("theme.out");
  short melody[MAXN],N;
  fin>>N;
  for(int i=0;i<N;i++){
    fin>>melody[i];
  }
  
}
