/*
  ID: remijoh1
  LANG: C++
  TASK: transform
*/
#include<iostream>
#include<fstream>
using namespace std;
struct pos{
  int r;
  int c;
};

pos transform(pos input, int len, int typ){
  pos tmp;
  switch(typ){
  case 1:
    tmp.r = input.c;
    tmp.c = len-input.r-1;
    return tmp;
  case 2:
    tmp.r = len-input.r-1;
    tmp.c = len-input.c-1;
    return tmp;
  case 3:
    tmp.r = len-input.c-1;
    tmp.c = input.r;
    return tmp;
  case 4:
    tmp.r = input.r;
    tmp.c = len-input.c-1;
    return tmp;
  default:
    return input;
  }
}

int check(char img1[][11], char img2[][11], int N){
  bool tag = false;
  int answer = -1;
  pos p,t;
  for(int typ=1; typ<=8; typ++){ // 5=5,6=5,7=5,8=6,9=7
    tag = false;
    for(int r=0;r<N;r++){
      p.r = r;
      for(int c=0;c<N;c++){
        p.c = c;

        if(typ==5||typ==6||typ==7){
          t = transform(transform(p,N,4),N,typ-4);
        }
        else{
          t = transform(p,N,typ);
        }
        if(img1[p.r][p.c]!=img2[t.r][t.c]){
          
          tag = true;
          break;
        }
      }
      if(tag==true)
        break;
    }
    if(tag==false){
      answer = typ;
      break;
    }
  }
  if(answer == -1)
    return 7;
  else
    {
      if(answer==6||answer==7){
        return 5;
      }
      else{
        if(answer==8)
          return 6;
        else // 1 2 3 4 5
          return answer;
      }
    }
}
      
int main(){

  ifstream fin("transform.in");
  ofstream fout("transform.out");
  
  char img1[11][11],img2[11][11];
  int N;

  fin>>N;
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      fin>>img1[i][j];
    }
  }
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      fin>>img2[i][j];
      
    }
  }
  
  fout<<check(img1,img2,N)<<endl;
  return 0;
}
