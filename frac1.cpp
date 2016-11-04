/*
  ID: remijoh1
  LANG: C++
  TASK: frac1
*/

#include<iostream>
#include<fstream>
#include<utility>
using namespace std;

typedef pair<int,int> ipair;

bool gt(ipair a,ipair b){
  return a.first*b.second > b.first*a.second;
}

bool exists(ipair *h, int size, ipair t){
  for(int i=0;i<size;i++){
    if(h[i].first==t.first && h[i].second == t.second)
      return true;
  }
  return false;
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

int push_heap(pair<int,int> *h,int len,pair<int,int> t){
  cout<<"push "<<t.first<<' '<<t.second<<endl;
  h[len] = t;
  int cur = len;
  while(cur>0){
    int pindex = (cur-1)/2;
    if(gt(h[pindex],h[cur])){
      ipair tmp = h[pindex];
      h[pindex] = h[cur];
      h[cur] = tmp;
      cur = pindex;
    }
    else{
      break;
    }
  }
  return len+1;
}

pair<int, int>* pop_heap(pair<int,int> *h, int len){
  if(len>0){
    pair<int,int> *result = new pair<int,int>();
    result->first = h[0].first;
    result->second = h[0].second;

    h[0] = h[len-1];

    int cur = 0;
    while(true){
      int c1 = cur*2+1,c2 = cur*2+2;
      if(c1>=len-1){
	break;
      }
      else{
	if(c2>=len-1){
	  if(gt(h[cur],h[c1])){
	      pair<int,int> tmp = h[cur];
	      h[cur] = h[c1];
	      h[c1] = tmp;
	      break;
	  }
	  break;
	}
	else{
	  if(gt(h[c1],h[cur])&&gt(h[c2],h[cur])){
	    break;
	  }
	  else{
	    if(gt(h[c1],h[c2])){
	      pair<int,int> tmp = h[cur];
	      h[cur] = h[c2];
	      h[c2] = tmp;
	      cur = c2;
	    }
	    else{
	      pair<int,int> tmp = h[cur];
	      h[cur] = h[c1];
	      h[c1] = tmp;
	      cur = c1;
	    }
	  }
	}
      }
    }
    return result;
  }    
  
  else{
    cerr<<"pop an empty heap!!";

  }
}
   
int main(void){
  ifstream fin("frac1.in");
  ofstream fout("frac1.out");

  int N;
  fin>>N;

  int numer=1,domi=N;
  int lnumer = 0,ldomi = 1;
  
  fout<<0<<'/'<<1<<endl;

  ipair history[10000];
  int count = 0;
  ipair heap[10000];
  int size = 0;
  heap[0].first = 1;
  heap[0].second = N;
  size++;
  while(size>0){

    ipair *tmp = pop_heap(heap,size);
    size--;
    

    
    fout<<tmp->first<<'/'<<tmp->second<<endl;
    cout<<tmp->first<<'/'<<tmp->second<<endl;
    lnumer = tmp->first;
    ldomi = tmp->second;
    if(lnumer+1 <=ldomi){
      tmp = norm(lnumer+1,ldomi);
      if(!exists(history,count,*tmp)){
	history[count++] = *tmp;
	size = push_heap(heap,size,*tmp);
      }
    }
    if(lnumer<=ldomi-1 && ldomi>1){
      tmp = norm(lnumer,ldomi-1);
      if(!exists(history,count,*tmp)){
	history[count++] = *tmp;
	size = push_heap(heap,size,*tmp);
      }
    }
    if(ldomi+1<=N){
      tmp = norm(lnumer+1,ldomi+1);
      if(!exists(history,count,*tmp)){
	history[count++] = *tmp;
	size = push_heap(heap,size,*tmp);
      }
    }
  }
}    
