/*
ID: remijoh1
LANG: C++
TASK: milk2
*/

#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
struct mypair{
  int from;
  int to;
};

bool inrange(int from, int to, int p){
  return from<=p && to>=p;
}

bool compare(mypair a, mypair b){
  return a.from<b.from;
}

int main(){
  ifstream fin("milk2.in");
  ofstream fout("milk2.out");

  int N;
  mypair input[5001];
  
  fin>>N;
  for(int i=0;i<N;i++){
    fin>>input[i].from>>input[i].to;
  }

  sort(input,input+N, compare);


  int milk, not_milk = 0;
  milk = input[0].to-input[0].from;
  int new_from = input[0].from, new_to = input[0].to;
  for(int i=1;i<N;i++){
    if(inrange(new_from, new_to, input[i].from)){
      new_to = input[i].to>new_to?input[i].to:new_to;
      if(milk<new_to-new_from){
	milk = new_to-new_from;
      }
    }
    else{
      if(not_milk<input[i].from-new_to){
	not_milk = input[i].from-new_to;
      }
      new_from = input[i].from;
      new_to = input[i].to;
      if(milk<new_to-new_from){
	milk = new_to-new_from;
      }    
    }
  }

  fout<<milk<<' '<<not_milk<<endl;
  return 0;
}


  
