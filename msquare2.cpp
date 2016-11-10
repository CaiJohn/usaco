/*
  ID: remijoh1
  LANG: C++11
  TASK: msquare
*/
#include<iostream>
#include<fstream>
#define HEAPSIZE 45000
#define HASHV 5717
using namespace std;

struct node{
  int state[8];
  string sequece;
};

node queue[HEAPSIZE];
int head=0,tail=0;

void push(int state[], string seq){
  for(int i=0;i<8;i++)
    queue[tail].state[i] = state[i];
  queue[tail].sequece = seq;
  tail++;
}

node pop(){
  return queue[head++];
}

struct hnode{
  int value;
  hnode* next;
};

hnode* hashtbl[HASHV];// Initialize?

void insert(int state[]){
  int sum = 0;
  for(int i=0;i<8;i++){
    sum = sum*10+state[i];
  }
  //cout<<"insert "<<sum<<endl;
  hnode* newh = new hnode();
  newh->value = sum;
  newh->next = NULL;
  
  int id = sum%HASHV;
  if(hashtbl[id]==NULL){
    hashtbl[id] = newh;
  }
  else{
    hnode* cur=hashtbl[id];
    while(cur->next!=NULL){
      cur = cur->next;
    }
    cur->next = newh;
  }
  return;
}

bool find(int state[]){
  int sum = 0;
  for(int i=0;i<8;i++){
    sum = sum*10+state[i];
  }

  hnode* cur = hashtbl[sum%HASHV];
  while(cur!=NULL){
    if(cur->value == sum)
      return true;
    cur = cur->next;
  }
  return false;
}

void transform(int state[],int typ, int output[]){
  if(typ==0){
    for(int i=0;i<8;i++){
      output[i] = state[7-i];
    }
  }
  else{
    if(typ==1){
      output[0] = state[3];
      output[1] = state[0];
      output[2] = state[1];
      output[3] = state[2];
      output[4] = state[5];
      output[5] = state[6];
      output[6] = state[7];
      output[7] = state[4];
    }
    else{
      output[0] = state[0];
      output[1] = state[6];
      output[2] = state[1];
      output[3] = state[3];
      output[4] = state[4];
      output[5] = state[2];
      output[6] = state[5];
      output[7] = state[7];
    }
  }
  // cout<<typ<<endl;
  // for(int i=0;i<8;i++){
  //   cout<<state[i];
  // }
  // cout<<endl;
  // for(int i=0;i<8;i++){
  //   cout<<output[i];
  // }
  // cout<<endl;
  return;
}

void checkanswer(string seq, int state[]){
  int l = seq.length();
  int tmp[2][8];
  for(int i=0;i<8;i++)
    tmp[0][i] = state[i];
  int cur = 0;
  for(int i=0;i<l;i++){
    transform(tmp[cur],seq[i]-'0',tmp[1-cur]);
    cout<<(char)(seq[i]-'0'+'A')<<endl;
    for(int j=0;j<8;j++){
      cout<<tmp[1-cur][j];      
    }
    cur = 1-cur;
    cout<<endl;
  }
  return;
}

int main(){
  ifstream fin("msquare.in");
  ofstream fout("msquare.out");

  int target[8];
  for(int i=0;i<8;i++)
    fin>>target[i];
  for(int i=0;i<HASHV;i++)
    hashtbl[i] = NULL;
  
  string cur="";
  int init[8] = {1,2,3,4,5,6,7,8};
  push(init,cur);
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
      //checkanswer(tmp.sequece,init);
      int l = tmp.sequece.length();
      for(int i=0;i<l;i++){
        if(i>0 && i%60==0)
          fout<<endl;
        fout<<(char)(tmp.sequece[i]-'0'+'A');
      }
      fout<<endl;
      return 0;
    }
    else{
      for(int i=0;i<3;i++){
        int nstate[8];
        transform(tmp.state,i,nstate);        
        if(!find(nstate)){
          string nseq = tmp.sequece;
          nseq.insert(nseq.end(),i+'0');
          insert(nstate);
          push(nstate,nseq);
        }
      }
    }
  }
  return 0;
}
