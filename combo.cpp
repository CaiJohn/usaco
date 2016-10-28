/*
ID: remijoh1
LANG: C++11
TASK: combo
*/

#include<iostream>
#include<fstream>

using namespace std;

struct Result{
  Result(){
    output = new int [10];
    len = 0;
  }
  int *output;
  int len;
};

bool exists(Result r, int t){  
  for(int i=0;i<r.len;i++){
    if(r.output[i]==t){
      return true;
    }
  }
  return false;
}

void push(Result *r, int k){
  
  if(exists(*r,k)){
    return;
  }
  else{
    r->output[r->len]=k;
    r->len++;
  }
}

int dec(int num, int n, int k){
  
  if(k==0){
    return num;
  }
  else{
    if(num==1){
      return dec(n,n,k-1);
    }
    else{
      return dec(num-1,n,k-1);
    }
  }
}

int inc(int num, int n, int k){
  if(k==0){
    return num;
  }
  else{
    if(num==n){
      return inc(1,n,k-1);
    }
    else{
      return inc(num+1,n,k-1);
    }
  }
}

Result* gen(int mid, int n){
  Result *r = new Result;
  
  push(r,dec(mid,n,2));
  
  push(r,dec(mid,n,1));
  push(r,mid);
  
  push(r,inc(mid,n,1));
  push(r,inc(mid,n,2));
  
  return r;
}

int main(){
  ifstream fin("combo.in");
  ofstream fout("combo.out");

  int N, c[6];
  fin>>N;
  fin>>c[0]>>c[1]>>c[2]>>c[3]>>c[4]>>c[5];
  

  Result *output1,*output2;
  
  int dup = 1,count=0,sum1=1,sum2=1;
  for(int k=0;k<3;k++){
    count=0;
    output1 = gen(c[k],N);
    sum1 *= output1->len;
    // cout<<output1->len<<endl;
    output2 = gen(c[3+k],N);
    sum2 *= output2->len;
    
    for(int i=0;i<(output2->len);i++){
      
      if(exists(*output1,output2->output[i]))
        count++;
    }
    dup *= count;
    delete output1;
    delete output2;
  }


  fout<<sum1+sum2-dup<<endl;
  return 0;
}
  
