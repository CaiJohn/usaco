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

int to_num(string s){
  int len = s.length();

  int sum = 0;
  for(int i=0;i<len;i++){
    if(s[i]=='1')
      sum += 1<<(len-1-i);
  }
  return sum;
}
string next(int num,int N,int L){
  num = num+1;
  string result = to_binary(num,N);
  int count = 0;
  for(int i=0;i<N;i++){
    if(result[i]=='1')
      L--;
  }
  L++;  
  for(int i= N-1;i>=0;i--){
    if(L>0){
      if(result[i]=='0'){
        result[i] = '1';
        L--;
      }
    }
    else
      break;
  }
  //  cout<<result<<endl;
  return result;
}


int main(){
  ifstream fin("kimbits.in");
  ofstream fout("kimbits.out");

  int N,L,I;
  fin>>N>>L>>I;

  // string input = "000111";
  // for(int i=0;i<10;i++){
  //   input = next(input);
  //   cout<<to_num(input)<<' '<<input<<endl;
  // }

  long cur = (1<<(L+1))-1;
  // cout<<cur<<endl;
  int count = 0;
  while(cur<I){
    // cout<<cur<<' '<<I<<endl;
    cur = to_num(next(cur,N,L));
    I++;
  }
  cout<<to_binary(I-1,N)<<endl;
  

  // int maxV = 0,maxB=N-1;
  // for(int i=0;i<L;i++){
  //   maxV += (1<<(N-1-i));
  // }
  // //cout<<maxV<<endl;
  // int count = 0,num;
  // for(num=0;num<=maxV;num++){
  //   if(calc(num)<=L)
  //     count++;
  //   if(count==I)
  //     break;
  // }
  // fout<<to_binary(num,N)<<endl;
  return 0;
}
