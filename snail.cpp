/*
  ID: remijoh1
  LANG: C++11
  TASK: snail
*/
#include<iostream>
#include<fstream>
using namespace std;

int search(int curr,int curc,int direct,int step){
  if(curr>=N || curr<0 || curc>=N || curr<0 || map[curr][curc]==true || visited[curr][curc]==true){
    return step;
  }
  
  visited[curr][curc] = true;
  int nextr, nextc;
  switch(direct){
  case 0:
    nextr = curr-1;
    nextc = curc;
    break;
  case 1:
    nextr = curr;
    nextc = curc+1;
    break;
  case 2:
    nextr = curr+1;
    nextc = curc;
    break;
  case 3:
    nextr = curr;
    nextc = curc-1;
    break;
  }
  if(nextr>=N || nextr<0 || nextc>=N || nextr<0 || map[nextr][nextc]==true){
    int maxstep1 = search(cur,curc,(direct+1)%4,step);
    int maxstep2 = search(cur,curc,(direct+3)%4,step);
    return max(maxstep1,maxstep2);
  }
  else{
    int maxstep = search(nextr,nextc,direct,step+1);
    visited[curr][curc] = false;
    return maxstep;
  }
}

int main(){
  ifstream fin("snail.in");
  ofstream fout("snail.out");
  int N,B;
  bool map[MAXN][MAXN] = {false};
  fin>>N>>B;
  
  for(int i=0;i<B;i++){
    string tmp;
    fin>>tmp;
    int c = tmp[0]-'A',r = tmp[1]-'0'-1;
    map[r][c] = true;
  }

  
