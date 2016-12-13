/*
  ID: remijoh1
  LANG: C++11
  TASK: picture
*/
#include<iostream>
#include<fstream>
#include<cstring>
#include<algorithm>
#define MAXN 5000
using namespace std;


struct Edge{
  int from;
  int to;
  int pos;
  int type;
};

bool cmp(Edge a, Edge b){
  if(a.pos<b.pos){
    return true;
  }
  else{
    if(a.pos>b.pos){
      return false;
    }
    else{
      return a.type==0;
    }
  }
}

int main(){
  ifstream fin("picture.in");
  ofstream fout("picture.out");

  int N, pics[MAXN][4]={0};
  Edge xedge[MAXN*2],yedge[MAXN*2];
  int x1,y1,x2,y2;
  fin>>N;
  for(int i=0;i<N;i++){
    fin>>x1>>y1>>x2>>y2;
    x1+=10000;
    y1+=10000;
    x2+=10000;
    y2+=10000;
    
    xedge[2*i].from = xedge[2*i+1].from = x1;
    xedge[2*i].to = xedge[2*i+1].to = x2;
    xedge[2*i].pos = y1;
    xedge[2*i].type = 0;
    xedge[2*i+1].pos = y2;
    xedge[2*i+1].type = 1;

    yedge[2*i].from = yedge[2*i+1].from = y1;
    yedge[2*i].to = yedge[2*i+1].to = y2;
    yedge[2*i].pos = x1;
    yedge[2*i].type = 0;
    yedge[2*i+1].pos = x2;
    yedge[2*i+1].type = 1;
  }

  int count = 0,level[20010]={0},num = 2*N;
  sort(xedge,xedge+N*2,cmp);
  for(int i=0;i<num;i++){
    // cout<<xedge[i].pos-10000<<endl;
    // cout<<"count "<<count<<endl;
    for(int j=xedge[i].from;j<xedge[i].to;j++){// ????? The corner pos will be counted twice...
      if(xedge[i].type==0){
        level[j]++;
        if(level[j]==1){
          count++;
        }
      }
      else{
        level[j]--;
        if(level[j]==0){
          count++;
        }
      }
    }
  }
  memset(level,0,sizeof(level));
  sort(yedge,yedge+N*2,cmp);
  for(int i=0;i<num;i++){
    for(int j=yedge[i].from;j<yedge[i].to;j++){
      if(yedge[i].type==0){
        level[j]++;
        if(level[j]==1){
          count++;
        }
      }
      else{
        level[j]--;
        if(level[j]==0){
          count++;
        }
      }
    }
  }
  fout<<count<<endl;
  return 0;
}
