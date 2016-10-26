/*
  ID: remijoh1
  LANG: C++
  TASK: palsquare
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int transFrom10(int num, int base, int *output){
  int quot=num, pos=0;
  while(quot>0){
    output[pos] = quot%base;
    quot /= base;
    pos++;
  }
  return pos;
}

bool checkPal(int *num, int len){
  int mid = len/2;
  for(int i=0;i<mid;i++){
    if(num[i]!=num[len-i-1]){
      return false;
    }
  }
  return true;
}

// void printNum(int *num, int len, ofstream fout){
  
//   for(int i=0;i<len;i++){
//     fout<<num[len-i-1];
//   }
//   return;
// }

int main(){
  ifstream fin("palsquare.in");
  ofstream fout("palsquare.out");
  int base;
  fin>>base;
  
  for(int i=1;i<=300;i++){
    int num[100]={0};
    int len = transFrom10(i*i,base,num);
    if(checkPal(num,len)){
      int orig[100] = {0};
      int origlen=transFrom10(i,base,orig);
      for(int i=0;i<origlen;i++){
        if(orig[origlen-i-1]>=10){
          fout<<char(orig[origlen-i-1]-10+'A');
        }
        else
          fout<<orig[origlen-i-1];
      }
      fout<<' ';
      for(int i=0;i<len;i++){
        if(num[len-i-1]>=10){
          fout<<char(num[len-i-1]-10+'A');
        }
        else
          fout<<num[len-i-1];
      }
      fout<<endl;
    }
  }
  return 0;
}
    
    
                     
  
