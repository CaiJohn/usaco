/*
  ID: remijoh1
  LANG: C++
  TASK: runround
*/

#include<iostream>
#include<fstream>
#include<cmath>

#define MAXI 4294967295
using namespace std;

bool check(unsigned long num){

  int len = 0,tmp = num;
  while(tmp>0){
    tmp /= 10;
    len++;
  }

  int cur = 0;
  int touched[20] = {0};
  int digit[10] = {0};
  do{
    if(touched[cur]==1)
      return false;
    
    int d = (num%(pow(10,len-cur)))/(pow(10,len-cur-1));
    if(digit[d]==1)
      return false;

    digit[d] = 1;
    touched[cur] = 1;
    cur = (cur+ d)%len;
  }while(cur!=0);

  for(int i=0;i<len;i++){
    if(touched[i]==0)
       return false;
  }
  return true;

}

int main(void){
  ifstream fin("runround.in");
  ofstream fout("runround.out");

  unsigned long M;

  fin>>M;

  for(unsigned log i=M+1;i<=MAXI;i++){
    if(check(i)){
      fout<<i<<endl;
    }
  }
  return 0;
}

  
