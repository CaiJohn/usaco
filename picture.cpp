/*
  ID: remijoh1
  LANG: C++11
  TASK: picture
*/
#include<iostream>
#include<fstream>
#define MAXN 5000
using namespace std;
int N, pics[MAXN][4]={0};
int commonLen = 0;
struct Cover{
  int pos;
  int len;
};



Cover coverLine(int direct, int c, int from, int to, int pid){
  Cover result(-1,0);
  if(direct==0 || direct==2){
    if(c<pid[i][1] || c>pid[i][3] || from>pid[i][2] || to<pid[i][0]){
      return result;
    }
    else{
      int t1 = pid[i][0]>from?pid[i][0]:from, t2 = pid[i][2]<from?pid[i][2]:to;
      int len = t2-t1+1;
      result.pos = t1;
      result.len = len;
      if((direct == 0 && c == 
      
    }
  }
  else{
  }
}



int main(){
  ifstream fin("picture.in");
  ofstream fout("picture.out");

  
  for(int i=0;i<N;i++){
    fin>>pics[i][0]>>pics[i][1]>>pics[i][2]>>pics[i][3];
  }
  
