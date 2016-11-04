/*
ID: remijoh1
LANG: C++
TASK: hamming
*/

#include<iostream>
#include<fstream>
using namespace std;

int setSize, bitNum, dist;
int maxNum;

bool check(int a, int b){
  

bool solve(int cur,int ans[]){
  if(cur==setSize){
    
  }
  else{
    if(cur==0){
      for(int i=0;i<=maxNum;i++){
	if(checkAll(ans,cur,i)){
	  ans[cur] = i;
	  if(solve(cur+1,ans)){
	    return true;
	  }
	}
      }
    }
    else{
      for(int i=ans[cur-1]+1;i<=maxNum;i++){
	if(checkAll(ans,cur,i)){
	  ans[cur] = i;
	  if(solve(cur+1,ans)){
	    return true;
	  }
	}
      }
    }
    return false;
  }
}

int main(void){
  ifstream fin("hamming.in");
  ofstream fout("hamming.out");


  fin>>setSize>>bitNum>>dist;
