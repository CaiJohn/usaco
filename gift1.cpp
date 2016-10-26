/*
ID: remijoh1
LANG: C++
TASK: gift1
*/
#include<iostream>
#include<fstream>
#include<map>

int main(){
  std::ifstream fin("gift1.in");
  std::ofstream fout("gift1.out");
  std::map<std::string,int> mymap;
  std::string nameorder[11];
  int NP;
  fin>>NP;

  std::string name;
  for(int i=0;i<NP;i++){
    fin>>name;
    mymap[name] = 0;
    nameorder[i] = name;
  }
  
  for(int i=0;i<NP;i++){
    fin>>name;
    int moneyout, outnum,item;
    fin>>moneyout>>outnum;
    if(outnum>0){
      item = moneyout/outnum; //Divide!!!
      mymap[name] -= (moneyout- (moneyout%outnum));
    }
    

    for(int j=0;j<outnum;j++){
      std::string receiver;
      fin>>receiver;
      mymap[receiver] += item;
    }
  }

  for(int i=0;i<NP;i++){
    std::map<std::string,int>::iterator it = mymap.find(nameorder[i]);
    fout<<it->first<<' '<<it->second<<std::endl;
  }
  return 0;
}
