/*
  ID: remijoh1
  LANG: C++11
  TASK: humble
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<climits>
#define MAXV LONG_MAX
using namespace std;


unsigned long heap[1000000]={0};
int hsize = 0;

void push(unsigned long num){
  //cout<<"push: "<<num<<endl;
  heap[hsize] = num;
  int cur = hsize;
  while(true){
    if(cur==0)
      break;
    else{
      int pindex = (cur-1)/2;
      if(heap[pindex]<=heap[cur]){
        break;
      }
      else{
        unsigned long tmp = heap[cur];
        heap[cur] = heap[pindex];
        heap[pindex] = tmp;
        cur = pindex;
      }
    }
  }
  hsize++;
  return;
}

unsigned long pop(){
  if(hsize<=0){
    cout<<"error!"<<endl;
    return -1;
  }
  else{
    unsigned long result = heap[0];
    heap[0] = heap[hsize-1];
    hsize --;
    
    int cur = 0;
    while(true){
      if(cur>=hsize)
        break;
      if((cur*2+1)<hsize){
        if(cur*2+2<hsize){
          if(heap[cur]<=heap[cur*2+1] && heap[cur]<=heap[cur*2+2]){
            break;
          }
          else{
            unsigned long tmp;
            if(heap[cur*2+1]<heap[cur*2+2]){
              tmp = heap[cur*2+1];
              heap[cur*2+1] = heap[cur];
              heap[cur] = tmp;
              cur = cur*2+1;
            }
            else{
              tmp = heap[cur*2+2];
              heap[cur*2+2] = heap[cur];
              heap[cur] = tmp;
              cur = cur*2+2;
            }
          }
        }
        else{
          if(heap[cur]<=heap[cur*2+1])
            break;
          else{
            unsigned long tmp = heap[cur*2+1];
            heap[cur*2+1] = heap[cur];
            heap[cur] = tmp;
            cur = cur*2+1;
          }
        }
      }
      else{
        break;
      }

    }
    // if(result>=292500000)
    //   cout<<"pop: "<<result<<endl;
    return result;
  }
}

int main(){
  ifstream fin("humble.in");
  ofstream fout("humble.out");

  int K,N;
  fin>>K>>N;

  int primes[100];
  for(int i=0;i<K;i++){
    fin>>primes[i];
    push(primes[i]);
  }

  unsigned long cur = 0,num=0,last=0;
  int maxsize=0;
  while(cur<N){
    num = pop();
    if(num==last)
      continue;
    else{
      last = num;
      cur++;
      for(int i=0;i<K;i++){
	unsigned long newn = primes[i]*num;
	if(newn<MAXV)
	  push(newn);
      }
    }
    if(maxsize<hsize)
      maxsize = hsize;
    //cout<<num<<' '<<cur<<endl;
  }
  cout<<maxsize<<endl;
  fout<<num<<endl;
  return 0;
}
