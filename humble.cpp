/*
  ID: remijoh1
  LANG: C++
  TASK: humble
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int main(){
  ifstream fin("humble.in");
  ofstream fout("humble.out");

  int K,N;
  fin>>K>>N;

  long primes[100];
  for(int i=0;i<K;i++){
    fin>>primes[i];
  }

  
  int num[1000000];
  for(int i=0;i<K;i++)
    num[i] = primes[i];
  
  int count = K;
  while(){
    
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<K;j++){
      num[count++] = num[i]*primes[j];
      //cout<<num[count-1]<<endl;
    }
  }
  sort(num,num+count);
  for(int i=0;i<count;i++)
    cout<<num[i]<<endl;
  
  int cur = 0,p=0;
  int last = -1;
  while(true){
    cout<<p<<' '<<cur<<endl;
    if(cur==N)
      break;
    if(num[p] == last){
      p++;
    }
    else{
      last = num[p];
      p++;
      cur++;
    }
  }
  fout<<num[p]<<endl;
  return 0;
}
