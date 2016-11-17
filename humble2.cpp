/*
  ID: remijoh1
  LANG: C++11
  TASK: humble
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

long long gen[100001],fac[100001];
int K,N,primes[100];
int heap[100001];
int hsize = 0;

void heapup(int pos){
  if(pos==0)
    return;
  else{
    if(gen[heap[pos]]*primes[fac[heap[pos]]]<gen[heap[(pos-1)/2]]*primes[fac[heap[(pos-1)/2]]]){
      int tmp = heap[pos];
      heap[pos] = heap[(pos-1)/2];
      heap[(pos-1)/2] = tmp;
      heapup((pos-1)/2);
    }
    else
      return;
  }  
}

void push(int v){
  // cout<<"push "<<v<<endl;
  heap[hsize]=v;
  heapup(hsize);
  hsize++;
  // for(int i=0;i<hsize;i++){
  //   cout<<heap[i]<<' ';
  // }
  // cout<<endl;
  return;
}

void heapdown(int pos){
  if(pos*2+1>=hsize)
    return;
  else{
    int next;
    if(pos*2+2>=hsize)
      next = pos*2+1;
    else{
      next = gen[heap[pos*2+1]]*primes[fac[heap[pos*2+1]]]<gen[heap[pos*2+2]]*primes[fac[heap[pos*2+2]]]?pos*2+1:pos*2+2;
    }
    if(gen[heap[pos]]*primes[fac[heap[pos]]]>gen[heap[next]]*primes[fac[heap[next]]]){
      int tmp = heap[pos];
      heap[pos] = heap[next];
      heap[next] = tmp;
      heapdown(next);
    }
    else
      return;
  }
}

int pop(){
  int result = heap[0];
  heap[0] = heap[hsize-1];
  hsize--;
  heapdown(0);
  // for(int i=0;i<hsize;i++){
  //   cout<<heap[i]<<' ';
  // }
  // cout<<endl;
  return result;
}

int main(){
  ifstream fin("humble.in");
  ofstream fout("humble.out");
  
  fin>>K>>N;
  for(int i=0;i<K;i++)
    fin>>primes[i];
  sort(primes,primes+K);
  
  gen[0] = 1;
  fac[0] = 0;
  push(0);
  int last = -1,count = 0;
  
  while(true){
    if(count==N){
      break;
    }
    int cur = pop();
    int num = gen[cur]*primes[fac[cur]];
    // cout<<"cur "<<cur<<" num "<<num<<" last "<<last<<" fac[cur] "<<fac[cur]<<" count "<<count<<endl;
    if(num!=last){
      last = num;
      gen[count+1] = num;
      count++;
    }
    if(fac[cur]==0){
      fac[cur+1] = 0;
      push(cur+1);
    }
    if(fac[cur]<K-1){
      fac[cur]++;
      push(cur);
    }
    
  }
  fout<<gen[count]<<endl;
  return 0;
}
