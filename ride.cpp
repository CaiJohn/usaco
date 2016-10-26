/*
ID: remijoh1
LANG: C++
TASK: ride
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
  ifstream fin("ride.in");
  ofstream fout("ride.out");

  string comet, group;
  
  fin>>comet>>group;
  string::iterator it;

  it = comet.begin();
  int scomet = 1;
  for(it=comet.begin();it!=comet.end();it++)
    scomet *= *it - 'A'+1;
 
  it = group.begin();
  int sgroup = 1;
  for(it=group.begin();it!=group.end();it++)
    sgroup *= *it - 'A'+ 1;
    

  if((scomet%47) == (sgroup%47)){
    fout<<"GO"<<endl;
  }
  else{
    fout<<"STAY"<<endl;
  }

  return 0;
}

  
  
