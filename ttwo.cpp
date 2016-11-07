/*
  ID: remijoh1
  LANG: C++
  TASK: ttwo
*/
#include<iostream>
#include<fstream>
using namespace std;

int main(void){
  ifstream fin("ttwo.in");
  ofstream fout("ttwo.out");

  int board[11][11] = {0};
  char tmp;
  int Fr,Fc,Cr,Cc;
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      fin>>tmp;
      if(tmp=='.')
        board[i][j] = 0;
      else{
        if(tmp=='*')
          board[i][j] = 1;
        else{
          if(tmp=='F'){
            Fr = i;
            Fc = j;
            board[i][j] = 0;
          }
          else{
            if(tmp=='C'){
              Cr = i;
              Cc = j;
              board[i][j] = 0;
            }
            else{
              cout<<"error!"<<endl;
              return 0;
            }
          }
        }
      }
    }
    //fin>>tmp;// line break
  }

  // for(int i=0;i<10;i++){
  //   for(int j=0;j<10;j++){
  //     cout<<board[i][j];
  //   }
  //   cout<<endl;
  // }
  int visited[4][10][10][4][10][10] = {0};
  visited[0][Fr][Fc][0][Cr][Cc] = 1;
  int df = 0,dc = 0;
  int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
  int curFr = Fr,curFc = Fc, curCr = Cr, curCc = Cc;
  int count = 0;
  do{
    //cout<<curFr<<' '<<curFc<<' '<<curCr<<' '<<curCc<<endl;
    visited[df][curFr][curFc][dc][curCr][curCc]=1;
    int nFr = curFr+d[df][0],nFc= curFc+d[df][1];
    if(nFr>=0 && nFr<10 && nFc>=0 && nFc<10){
      if(board[nFr][nFc]!=1){
        curFr = nFr;
        curFc = nFc;
      }
      else{
        df = (df+1)%4;
      }
    }
    else{
      df = (df+1)%4;
    }

    int nCr = curCr+d[dc][0],nCc= curCc+d[dc][1];
    if(nCr>=0 && nCr<10 && nCc>=0 && nCc<10){
      if(board[nCr][nCc]!=1){
        curCr = nCr;
        curCc = nCc;
      }
      else{
        dc = (dc+1)%4;
      }
    }
    else{
      dc = (dc+1)%4;
    }
    count++;
    if(curFr==curCr && curFc==curCc){
      break;
    }
    if(visited[df][curFr][curFc][dc][curCr][curCc]==1){
      count = 0;
      break;
    }
  }while(true);
  fout<<count<<endl;
  return 0;
}

    
      




  
  
  
            
      
      
