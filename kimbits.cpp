/*
  ID: remijoh1
  LANG: C++11
  TASK: kimbits
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int calc(int num){
  int count = 0;
  //cout<<num<<' ';
  while(num>0){
    if((num&1)==1)
      count++;
    num = num>>1;
  }
  //cout<<count<<endl;
  return count;
}


// Be careful, fixed length!!
string to_binary(int num,int digit){
  //cout<<num<<endl;
  string result(digit,'0');
  while(num>0){
    int tmp = num%2;
    result[--digit] = tmp+'0';
    //result.insert(result.begin(),tmp+'0');
    num /= 2;
  }
  return result;
}

int main(){
  ifstream fin("kimbits.in");
  ofstream fout("kimbits.out");

  int N,L,I;
  fin>>N>>L>>I;

  int maxV = 0,maxB=N-1;
  for(int i=0;i<L;i++){
    maxV += (1<<(N-1-i));
  }
  //cout<<maxV<<endl;
  int count = 0,num;
  for(num=0;num<=maxV;num++){
    if(calc(num)<=L)
      count++;
    // else
    //   cout<<num<<endl;
    if(count==I)
      break;
  }
  fout<<to_binary(num,N)<<endl;
  return 0;
}
