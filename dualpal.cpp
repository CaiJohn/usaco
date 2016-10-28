/*
ID: remijoh1
LANG: C++
TASK: dualpal
*/

#include<iostream>
#include<fstream>
using namespace std;
int transFrom10(int num, int base, int output[]){
  int pos = 0;
  while(num>0){
    output[pos++] = num%base;
    num /= base;
  }
  return pos;
}

bool checkPal(int num[], int len){
  int mid = len/2;
  for(int i=0;i<mid;i++){
    if(num[i]!=num[len-i-1])
      return false;
  }
  return true;
}

int main(){
  ifstream fin("dualpal.in");
  ofstream fout("dualpal.out");

  int N,S;
  fin>>N>>S;
  int resCount = 0, i=S+1;
  
  while(resCount<N){ 
    int count = 0;
    //cout<<i<<endl;
    for(int base=2;base<=10;base++){
      int num[100] = {0};
      int len = transFrom10(i,base,num);
      if(checkPal(num,len)){
	//	cout<<"base:"<<base<<endl;
	count++;
	if(count>=2){
	  fout<<i<<endl;
	  resCount++;
	  break;
	}
      }
    }

    i++;
  }
  return 0;
}
