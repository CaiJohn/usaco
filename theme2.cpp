/*
  ID: remijoh1
  LANG: C++11
  TASK: theme
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#define MAXN 5000
using namespace std;

short seq[MAXN+1];
short len;

short sa[MAXN+1];
short height[MAXN+1];

bool cmp(int a, int b){
  if(a>=len || b>=len)
    return a<b;
  
  if(seq[a]==seq[b])
    return cmp(a+1,b+1);
  else
    return seq[a]<seq[b];
}
  
int LCP(int a, int b){// a and b cannot be equal
  if(seq[a]==seq[b]){
    return 1+LCP(a+1,b+1);
  }
  else{
    return 0;
  }
}
  
void init(){
  for(int i=0;i<len;i++){
    sa[i] = i;
  }

  sort(sa,sa+len,cmp);
  // cout<<"here"<<endl;
  for(int i=0;i<len-1;i++){
    height[i] = LCP(sa[i],sa[i+1]);
  }
}

int group(int output[],int k){
  int count = 0;
  output[count++] = 0;
  for(int i=0;i<len-1;i++){
    if(height[i]<k){
      output[count++] = i+1;
    }
  }
  output[count++] = len;
  return count;
}
  
bool query(int k){
  // cout<<"query "<<k<<endl;
  int g[MAXN+1],gcount = 0;
  gcount = group(g,k);

  // cout<<"group"<<endl;
  // for(int i=0;i<gcount;i++){
  //   cout<<g[i]<<' ';
  // }
  // cout<<endl;

  
  for(int i=0;i<gcount-1;i++){
    int start = g[i], end = g[i+1];
    int maxp = 0,minp = MAXN+1;
    for(int j=start;j<end;j++){
      if(sa[j]>maxp)
	maxp = sa[j];
      if(sa[j]<minp)
	minp = sa[j];
    }
    if(minp+k<maxp){
      return true;
    }
  }
  return false;
}

int main(){
  ifstream fin("theme.in");
  ofstream fout("theme.out");
  short melody[MAXN],N;
  fin>>N;
  for(int i=0;i<N;i++){
    fin>>melody[i];
  }
  len = N-1;
  for(int i=0;i<len;i++){
    seq[i] = melody[i+1]-melody[i];
    // cout<<seq[i]<<' ';
  }
  seq[len] = -10000;
  // cout<<endl;
  init();

  // cout<<"sa"<<endl;
  // for(int i=0;i<len;i++){
  //   for(int j=sa[i];j<len;j++){
  //     cout<<seq[j]<<' ';
  //   }
  //   cout<<endl;
  // }
  // cout<<"height"<<endl;
  // for(int i=0;i<len-1;i++){
  //   cout<<height[i]<<' ';
  // }
  // cout<<endl;

  
  int ks = 0,ke = N/2+1,ans = 0;
  while(ks<=ke){
    int cur = (ks+ke)/2;
    // cout<<ks<<' '<<ke<<' '<<cur<<endl;
    if(query(cur)){
      ks = cur+1;
      ans = cur;
    }
    else{
      ke = cur-1;
    }
  }
  if(ans+1<5)
    fout<<0<<endl;
  else
    fout<<ans+1<<endl;
  return 0;
}
