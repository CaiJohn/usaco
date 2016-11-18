/*
  ID: remijoh1
  LANG: C++11
  TASK: fracdec
*/

#include<iostream>
#include<fstream>
using namespace std;

int main(){
  ifstream fin("fracdec.in");
  ofstream fout("fracdec.out");
  int N,D;
  fin>>N>>D;

  int dec = N/D;
  int r = N%D,visited[100000]={0};
  string result;
  int count = 0;
  while(true){
    if(visited[r]!=0){
      result.insert(visited[r]-1,"(");
      result.insert(result.end(),')');
      break;
    }
    if(r==0){
      break;
    }
    //cout<<"r "<<r<<endl;
    int num = r*10/D;
    //cout<<"num "<<num<<endl;
    result.insert(result.end(),num+'0');
    visited[r] = ++count; 
    r = (r*10)%D;
  }
  if(result.length() == 0)
    result = "0";
  result = to_string(dec)+"."+result;
  
  
  int len = result.length();
  for(int i=0;i<len;i++){
    if(i>0 && i%76==0)
      fout<<endl;
    fout<<result[i];
    if(i==len-1)
      fout<<endl;
    
  }
  
  return 0;
}
    
