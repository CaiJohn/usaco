/*
  ID: remijoh1
  LANG: C++11
  TASK: msquare
*/
#include<iostream>
#include<fstream>
using namespace std;

struct node{
  int state[8];
  string sequece;
};

node queue[50000];
int head=0,tail=0;

void push(int state[], string seq){
  for(int i=0;i<8;i++)
    queue[tail].state[i] = state[];
  queue[tail].sequece = seq;
  tail++;
}

node pop(){
  return queue[head++];
}

void transform(int state[],int typ){
  if(typ==0){
    for(int i=0;i<4;i++){
      int tmp = state[i];
      state[i] = state[7-i];
      state[7-i] = tmp;
    }
  }
  else{
    if(typ==1){
      int tmp1 = state[3],tmp2 = state[4];
      for(int i=3;i>0;i--){
	state[i] = state[i-1];
	state[7-i] = state[7-i+1];
      }
      state[0] = state[3];
      state[7] = state[4];
    }
    else{
      int tmp = state[1];
      state[1] = state[6];
      state[6] = state[5];
      state[5] = state[2];
      state[2] = tmp;
    }
    return;
}

int main(){
  ifstream fin("msquare.in");
  ofstream fout("msquare.out");

  int target[8];
  for(int i=0;i<8;i++)
    fin>>target[i];

  string cur="";
  push(target,cur);
  while(head<tail){
    node tmp = pop();
    
    bool tag = true;
    for(int i=0;i<8;i++){
      if(tmp.state[i]!=target[i]){
	tag = false;
	break;
      }
    }

    if(tag==true){
      fout<<tmp.sequece.length()<<endl;
      fout<<tmp.sequece<<endl;//!!!
      return 0;
    }
    else{
      
    }
  }
