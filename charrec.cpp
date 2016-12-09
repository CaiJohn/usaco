/*
ID: remijoh1
LANG: C++11
TASK: charrec
*/
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#define MAXN 1200
#define MAXC 120
using namespace std;
struct Node{
  int count;
  string s;
  Node(){
    count = 0;
    s = "";
  }
  Node(int minc, string mins){
    count = minc;
    s = mins;
  }
};

int digits[27][20] = {0};
int input[MAXN] = {0};
int matchOne[27][MAXN][20] = {0};

int toInt(string s){
  int sum = 0;
  for(int i=0;i<20;i++){
    if(s[i]=='1'){
      sum += 1<<(19-i);
    }       
  }
  return sum;
}

int change(int from, int to){
  int c = from^to;
  int sum = 0;
  for(int i=0;i<20;i++){
    sum += (c & 1);
    c = c>>1;
  }
  return sum;
}

void calc(int pos){
  for(int i=0;i<27;i++){
    for(int j=0;j<20;j++){
      matchOne[i][pos][j] = change(digits[i][j],input[pos+j]);
      // cout<<"matchOne "<<i<<' '<<pos<<' '<<j<<' '<<matchOne[i][pos][j]<<endl;
    }
  }
  return;
}

Node match(int pos, int num){
  cout<<"match "<<pos<<' '<<num<<endl;
  int minC = MAXC,mins;
  int sum;
  if(num==20){    
    for(int i=0;i<27;i++){
      sum = 0;
      for(int j=0;j<20 && sum<minC ;j++){
	sum += matchOne[i][pos][j];
      }
      if(minC>sum){
	minC = sum;
        mins = i;
      }
    }
  }
  else{
    if(num==19){
      calc(pos-1);
      for(int i=0;i<27;i++){
        cout<<"matching "<<i<<endl;
	for(int m=0;m<20;m++){// the missing line
          // cout<<"missing "<<m<<endl;
          sum = 0;
	  for(int j=0;j<m && sum<minC ;j++){
	    sum += matchOne[i][pos][j];
	  }          
	  for(int j=m+1;j<20 && sum<minC ;j++){
	    sum += matchOne[i][pos-1][j];
	  }
          // cout<<sum<<endl;
	  if(minC>sum){
	    minC = sum;
            mins = i;
          }
	}
      }
    }
    else{
      for(int i=0;i<27;i++){
	for(int m=0;m<20;m++){
          cout<<i<<" duplicate "<<m<<endl;
          sum = 0;
	  for(int j=0;j<m && sum<minC ;j++){
	    sum += matchOne[i][pos][j];
	  }
	  int d1 = matchOne[i][pos][m];
	  int d2 = matchOne[i][pos+1][m];
	  sum += min(d1,d2);
	  for(int j=m+2;j<20 && sum<minC ;j++){
	    sum += matchOne[i][pos+1][j];
	  }
          cout<<sum<<endl;
	  if(minC>sum){
	    minC = sum;
            mins = i;
          }
	}
      }
    }
  }
  cout<<"match end: "<<minC<<' '<<(char)('a'+mins-1)<<' '<<mins<<endl;
  string s;
  if(mins==0)
    s = " ";
  else
    s.insert(s.end(),1,(char)('a'+mins-1));
  Node r(minC,s);
  return r;
}

int main(){
  ifstream fin("charrec.in");
  ifstream ffont("font.in");
  ofstream fout("charrec.out");

  int N,digits[27][20];
  string tmp;
  ffont>>N;
  for(int i=0;i<27;i++){
    for(int j=0;j<20;j++){      
      ffont>>tmp;
      digits[i][j] = toInt(tmp);
    }
  }
  fin>>N;
  for(int i=0;i<N;i++){
    fin>>tmp;
    input[i+1] = toInt(tmp);
  }

  if(N>=19){    
    for(int i=0;i<27;i++){
      for(int j=0;j<19;j++){
        matchOne[i][N-18][j] = change(digits[i][j],input[N-18+j]);
      }
    }
  }
  else{
    fout<<"?"<<endl;
    return 0;
  }
  
  int state[MAXN+1];
  memset(state,-1,sizeof(state));
  state[N+1] = 0;
  string matchS[MAXN+1];
  Node mr;
  matchS[N] = "";
  for(int s=N-19+1;s>0;s--){
    int minC = MAXC+1,tmpc=0;
    string minS;
    if(s+19<=N+1 && state[s+19]>=0){
      mr = match(s,19);
      if(mr.count + state[s+19]<minC){
	minC = mr.count + state[s+19];
	minS = mr.s + matchS[s+19];
      }
    }
    if(s+20<=N+1 && state[s+20]>=0){
      mr = match(s,20);
      if(mr.count + state[s+20]<minC){
	minC = mr.count + state[s+20];
	minS = mr.s + matchS[s+20];
      }
    }
    if(s+21<=N+1 && state[s+21]>=0){
      mr = match(s,21);
      if(mr.count + state[s+21]<minC){
	minC = mr.count + state[s+21];
	minS = mr.s + matchS[s+21];
      }
    }
    if(minC>MAXC){
      state[s] = -1;
    }
    else{
      state[s] = minC;
      matchS[s] = minS;
      // cout<<s<<' '<<state[s]<<' '<<matchS[s]<<endl;
    }
  }
  fout<<matchS[1]<<endl;
  return 0;
}
