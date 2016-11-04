/*
  ID: remijoh1
  LANG: C++
  TASK: frac1
*/

#include<iostream>
#include<fstream>
#include<utility>
#include<algorithm>
using namespace std;

typedef pair<int,int> ipair;

bool cmp(ipair a,ipair b){
  return a.first*b.second < b.first*a.second;
}


ipair* norm(int n,int d){
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
   
int main(void){
  ifstream fin("frac1.in");
  ofstream fout("frac1.out");

  int N,count=0;
  ipair l[100000];
  fin>>N;

  for(int i=1;i<=N;i++){
    for(int j=i+1;j<=N;j++){
      ipair *tmp = norm(i,j);
      l[count++] = *tmp;
      delete tmp;
    }
  }
  
  sort(l,l+count,cmp);

  int ln=0,ld=1;
  fout<<ln<<'/'<<ld<<endl;
  for(int i=0;i<count;i++){
    if(l[i].first!=ln || l[i].second!=ld){
      ln = l[i].first;
      ld = l[i].second;
      fout<<ln<<'/'<<ld<<endl;
    }
  }
  fout<<1<<'/'<<1<<endl;
  return 0;
}
