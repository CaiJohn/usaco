/*
  ID: remijoh1
  LANG: C++
  TASK: maze1
*/

#include<iostream>
#include<fstream>
#include<string>
#define MAXH 100
#define MAXN 38
#define MAXNUM 3800
#define MAXV 99999
using namespace std;

int W,H;
int num;
int graph[MAXNUM][4];
void solve(int p,int output[]){

  int s[num];
  for(int i=0;i<num;i++)
    s[i] = 0;

  output[p] = 0;
  while(true){
    int minV=999999,minP=-1;
    for(int i=0;i<num;i++){
      if(s[i]==0 && output[i]<minV){
        minV = output[i];
        minP = i;
      }
    }
    if(minP==-1)
      break;
    for(int i=0;i<4;i++){
      if(graph[minP][i]==1){
        if(i==0){
          output[minP-W] = output[minP-W]>minV+1?minV+1:output[minP-W];
        }
        if(i==1){
          output[minP+1] = output[minP+1]>minV+1?minV+1:output[minP+1];
        }
        if(i==2){
          output[minP+W] = output[minP+W]>minV+1?minV+1:output[minP+W];
        }
        if(i==3){
          output[minP-1] = output[minP-1]>minV+1?minV+1:output[minP-1];
        }
      }
    }
    s[minP] = 1;
  }
  return;  
}


int main(void){
  ifstream fin("maze1.in");
  ofstream fout("maze1.out");

  fin>>W>>H;
  num = W*H;
  
  string maze[2*H+1];
  getline(fin,maze[0]);
  for(int h=0;h<=H*2;h++){
    getline(fin,maze[h]);
    //cout<<maze[h]<<endl;
  }
  
  
  int e[2],ecount=0,count=0;
  for(int h=0;h<H;h++){
    for(int w=0;w<W;w++){
      // cout<<h<<' '<<w<<endl;
      // cout<<h*W+w<<endl;
      //count++;
      int cur = h*W+w;
      if(maze[h*2][w*2+1]==' '){        
        if(h>0){
          graph[cur][0] = 1;
        }
        else{
          e[ecount] = cur;
          ecount++;
        }
      }
      if(maze[h*2+1][w*2+2]==' '){
        if(w<W-1){
          graph[cur][1] = 1;
        }
        else{
          e[ecount] = cur;
          ecount++;
        }
      }
      if(maze[h*2+2][w*2+1]==' '){
        if(h<H-1){
          graph[cur][2] = 1;
        }
        else{
          e[ecount] = cur;
          ecount++;
        }
      }
      if(maze[h*2+1][w*2]==' '){
        if(w>0){
          graph[cur][3] = 1;
        }
        else{
          e[ecount] = cur;
          ecount++;
        }
      }
    }
  }
  // for(int i=0;i<num;i++){
  //   cout<<i<<' ';
  //   for(int j=0;j<4;j++){
  //     cout<<graph[i][j];
  //   }
  //   cout<<endl;
  // }
  // cout<<ecount<<endl;
  int output1[num],output2[num];
  for(int i=0;i<num;i++)
    output1[i] = MAXV;
  solve(e[0],output1);
  for(int i=0;i<num;i++)
    output2[i] = MAXV;
  solve(e[1],output2);

  int output3[num] = {0};
  for(int i=0;i<num;i++){
    output3[i] = output1[i]>output2[i]?output2[i]:output1[i];
  }
  int result = 0;
  for(int i=0;i<num;i++){
    if(result<output3[i])
      result = output3[i];
  }
  fout<<result+1<<endl;
  return 0;
}
