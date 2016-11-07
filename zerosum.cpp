/*
  ID: remijoh1
  LANG: C++
  TASK: zerosum
*/
#include<iostream>
#include<fstream>
using namespace std;

int ops[10],N;
ifstream fin("zerosum.in");
ofstream fout("zerosum.out");

int calc(){
  int cur = -1;
  int sum = 0;
  int op = 0;
  while(cur<N-1){
    int n=cur+2;  
    while(ops[++cur]==2){
      n = n*10+cur+2;
    }
    // cout<<n<<endl;
    if(op==0)
      sum += n;
    else
      sum -= n;
    // cout<<"sum"<<sum<<endl;
    op = ops[cur];
  }
  return sum;
}
  
//   if(cur==N-1)
//     return N;
//   if(ops[cur]==0)
//     return calc(cur+1,0);
//   if(ops[cur]==1)
//     return sum+cur-calc(cur+1,0);
//   if(ops[cur]==2)
//     return calc(cur+1,(sum+cur+1)*10);
// }

char decode(int num){
  if(num==0)
    return '+';
  if(num==1)
    return '-';
  if(num==2)
    return ' ';
}

void solve(int cur){
  if(cur==N-1){
    // for(int i=0;i<N;i++){
    //   cout<<i+1;
    //   if(i<N-1){
    //     cout<<decode(ops[i]);
    //   }
    // }
    // cout<<endl;
    if(calc()==0){
      for(int i=0;i<N;i++){
        fout<<i+1;
        if(i<N-1){
          fout<<decode(ops[i]);
        }
      }
      fout<<endl;
    }
  }
  else{
    for(int i=0;i<3;i++){
      ops[cur]=(i+2)%3;
      solve(cur+1);
    }
  }
}
  

int main(void){

  fin>>N;
  solve(0);
  return 0;
}
