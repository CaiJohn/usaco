/*
  ID: remijoh1
  LANG: C++11
  TASK: buylow
*/
#include<iostream>
#include<fstream>
#include<string>
#define MAXN 5000
#define MAXBIT 200
using namespace std;

struct BigInt{
  int len;
  int num[MAXBIT];
  int s;
};

string printBigInt(BigInt n){
  string result;
  for(int i=n.len-1;i>=0;i--){
    result.insert(result.end(),1,n.num[i]+'0');
  }
  if(n.s==0)
    result.insert(result.begin(),1,'-');
  return result;
}

void assign(BigInt* num1, BigInt num2){//num1=num2
  for(int i=0;i<num2.len;i++){
    num1->num[i] = num2.num[i];
  }
  num1->len = num2.len;
  num1->s = num2.s;
  return;
}

int add(int num1[],int l1,int num2[],int l2){
  int l = l1>l2?l1:l2;
  int e = 0;
  for(int i=0;i<l;i++){
    int sum;
    if(i<l1 && i<l2){
      sum = num1[i]+num2[i]+e;
      e = sum/10;
      sum %= 10;
    }
    else{
      if(i>=l1){
	sum = num2[i]+e;
	e = sum/10;
	sum %= 10;
      }
      else{
	sum = num1[i]+e;
	e = sum/10;
	sum %= 10;
      }
    }
    num1[i] = sum;
  }
  if(e==1){
    num1[l] = 1;
    l++;
  }
  return l;
}

int minus_(int num1[],int l1,int num2[],int l2){ // num1>=num2
  int e = 0,sum;
  for(int i=0;i<l1;i++){
    if(i<l2){
      if(num1[i]-e>=num2[i]){
	sum = num1[i]-e-num2[i];
	e=0;
      }
      else{
	sum = num1[i]-e+10-num2[i];
	e=1;
      }
    }
    else{
      sum = num1[i]-e;
      e=0;
    }
    num1[i] = sum;
  }
  while(true){
    if(l1==1 || num1[l1-1]>0)
      break;
    l1--;
  }
  return l1;
}

bool greater_(int num1[],int l1,int num2[],int l2){// num1>num2
  if(l1>l2){
    return true;
  }
  else{
    if(l1<l2)
      return false;
    else{
      for(int i=l1-1;i>=0;i--){
	if(num1[i]>num2[i]){
	  return true;
	}
	if(num1[i]<num2[i]){
	  return false;
	}
      }
    }
  }
  return false;
}

void plus_(BigInt* num1,BigInt num2){//num1 += num2
  if(num1->s == num2.s){
    int l = add(num1->num,num1->len,num2.num,num2.len);
    num1->len = l;
    return;
  }
  else{
    if(greater_(num1->num,num1->len,num2.num,num2.len)==true){
      int l = minus_(num1->num,num1->len,num2.num,num2.len);
      num1->len = l;
      return;
    }
    else{
      int l = minus_(num2.num,num2.len,num1->num,num1->len);
      for(int i=0;i<l;i++){
	num1->num[i] = num2.num[i];
      }
      num1->len = l;
      num1->s = num2.s;
      return;
    }
  }
}

void sub(BigInt* num1, BigInt num2){
  num2.s = 1-num2.s;
  plus_(num1,num2);
  return;
}

int main(){

  int input1[100] = {1,2,3,4,5,6,7,8,9};
  int input2[100] = {1,2,3,4,5,6,7,8};
  BigInt test1,test2;
  test1.len = 9;
  test1.s = 1;
  test2.len = 8;
  test2.s = 1;

  for(int i=0;i<test1.len;i++){
    test1.num[i] = input1[i];
  }
  for(int i=0;i<test2.len;i++){
    test2.num[i] = input2[i];
  }

  cout<<printBigInt(test1)<<' '<<printBigInt(test2)<<endl;
  plus_(&test1,test2);
  cout<<printBigInt(test1)<<endl;
  sub(&test1,test2);
  cout<<printBigInt(test1)<<endl;
  return 0;
  ifstream fin("buylow.in");
  ofstream fout("buylow.out");

  int N,seq[MAXN];
  fin>>N;
  for(int i=0;i<N;i++)
    fin>>seq[i];
  
  int state[MAXN+1] = {0};
  BigInt count[MAXN+1];
  for(int i=N-1;i>=0;i--){
    int maxS = 0;// When all the numbers are greater, then maxS==0, num=1
    BigInt tmp;
    tmp.num[0] = 1;
    tmp.len = 1;
    tmp.s = 1;
    for(int j=i+1;j<N;j++){
      if(seq[j]<seq[i]){
	if(state[j]>maxS){
	  maxS = state[j];
	  assign(&tmp,count[j]);
	}
	else{
	  if(state[j]==maxS){
	    //num += count[j];
	    plus_(&tmp,count[j]);
	  }
	}
      }
    }
    state[i] = maxS+1;
    for(int j=i+1;j<N;j++){
      if(state[j]==state[i] && seq[j]==seq[i])
	//num -= count[j];
	sub(&tmp,count[j]);
    }
    assign(count+i,tmp);
    //count[i] = num;
  }
  // for(int i=0;i<N;i++){
  //   cout<<state[i]<<' '<<count[i]<<endl;
  // }
  int result=0;
  BigInt snum;
  snum.num[0] = 0;
  snum.s = 1;
  snum.len = 1;
  for(int i=0;i<N;i++){
    if(state[i]>result){
      result = state[i];
      //snum = count[i];
      assign(&snum,count[i]);
    }
    else{
      if(state[i]==result){
	//snum+=count[i];
	
      }
    }    
  }
  fout<<result<<' '<<printBigInt(snum)<<endl;
  return 0;
}
