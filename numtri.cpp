/*
  ID: remijoh1
  LANG: C++11
  TASK: numtri
*/

#include<iostream>
#include<fstream>
using namespace std;

int main(void){

  ifstream fin("numtri.in");
  ofstream fout("numtri.out");

  int R,tri[500501];
  fin>>R;

  int start = 0,result[1001];
  for(int r=1;r<=R;r++){
    for(int i=0;i<r;i++){
      fin>>tri[start+i];
      if(r==R){
	result[i] = tri[start+i];
      }
    }
    start += r;
  }

  start = R*(R-1)/2;
  for(int i=R-1;i>=1;i--){
    start -= i;
    //    cout<<"R"<<i<<endl;
    //    cout<<"start"<<start<<endl;
    for(int j=0;j<i;j++){
      result[j] = result[j]>result[j+1]? result[j]+tri[start+j]:result[j+1]+tri[start+j];
      
      //      cout<<result[j]<<'('<<tri[start+j]<<')';
    }
    //    cout<<endl;

  }

  fout<<result[0]<<endl;

  return 0;
}
  

    
  
