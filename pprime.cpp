/*
  ID: remijoh1
  LANG: C++11
  TASK: pprime
*/
#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

int a,b;
ifstream fin("pprime.in");
ofstream fout("pprime.out");


int mult(int base, int time){
  return base*pow(10,time);
}

bool checkPrime(int num){
  if(num>2){
    int end = sqrt(num)+1;
    for(int i=2;i<=end;i++){
      if(num%i==0)
	return false;
    }
    return true;
  }
  else{
    return false;
  } 
}

void genPal(int result,int cur,int l){

  int start = cur==0?1:0;
  if((l&1)==0){
    if(cur<=l/2-1){
      for(int i=start;i<=9;i++){
	genPal(result+mult(i,cur)+mult(i,l-1-cur),cur+1,l);
      }
    }
    else{
      //cout<<result<<endl;
      if(result>=a && result<=b){
	if(checkPrime(result)){
	  fout<<result<<endl;
	}
      }
      return;
    }
  }
  else{
    if(cur<l/2){
      for(int i=start;i<=9;i++){
	genPal(result+mult(i,cur)+mult(i,l-1-cur),cur+1,l);
      }
    }
    else{
      for(int i=start;i<=9;i++){
	int tmp = result + mult(i,cur);
	//cout<<tmp<<endl;
	
	if(tmp>=a && tmp<=b){
	  if(checkPrime(tmp)){
	    fout<<tmp<<endl;
	  }
	}
      }
      return;
    }
  }
}

int getd(int num){
  int d = 0;
  while(num>0){
    num /= 10;
    d++;
  }
  return d;
}

void search(){
  int mind = getd(a),maxd=getd(b);

  for(int i=mind;i<=maxd;i++){
    genPal(0,0,i);
  }
  return;
}
    

int main(void){

  fin>>a>>b;
  search();
  return 0;
}
  
