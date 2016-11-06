/*
  ID: remijoh1
  LANG: C++
  TASK: cowtour
*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
#define MAXV 999999999
using namespace std;

int main(void){
  ifstream fin("cowtour.in");
  ofstream fout("cowtour.out");

  int N,pos[151][2],edge[151][151];
  fin>>N;

  for(int i=0;i<N;i++){
    fin>>pos[i][0]>>pos[i][1];
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      char tmp;
      fin>>tmp;
      edge[i][j] = tmp-'0';
    }
  }

  long double dist[151][151];
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      if(edge[i][j]==0){
        //if(i!=j)
        dist[i][j] = MAXV;
        // else
        //   dist[i][j] = 0;
      }
      else{        
        dist[i][j] = sqrt((pos[i][0]-pos[j][0])*(pos[i][0]-pos[j][0])+(pos[i][1]-pos[j][1])*(pos[i][1]-pos[j][1]));
      }
    }
  }
  // for(int i=0;i<N;i++){
  //   for(int j=0;j<N;j++){
  //     cout<<i<<' '<<j<<' '<<edge[i][j]<<' '<<dist[i][j]<<endl;
  //   }
  // }
  
  for(int k=1;k<N;k++){
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        if(dist[i][j]>dist[i][k]+dist[k][j] && i!=j)
          dist[i][j] = dist[i][k]+dist[k][j];
      }
    }
  }

  long double maxd[150];
  for(int i=0;i<N;i++){
    maxd[i] = 0;
    for(int j=0;j<N;j++){
      if(dist[i][j]<MAXV && maxd[i]<dist[i][j]){
        maxd[i] = dist[i][j];
      }
    }
  }
      
  // for(int i=0;i<N;i++){
  //   for(int j=0;j<N;j++){
  //     cout<<i<<' '<<j<<' '<<edge[i][j]<<' '<<dist[i][j]<<endl;
  //   }
  // }
  
  long double maxnewp = MAXV,newp=0,p1,p2;
  
  for(int i=0;i<N;i++){
    p1=0;
    for(int k=0;k<N;k++){
      if(dist[i][k]<MAXV && p1<maxd[k]){
        p1 = maxd[k];
      }
    }
    for(int j=i+1;j<N;j++){
      if(dist[i][j]>=MAXV){
        p2=p1;
        for(int k=0;k<N;k++){
          if(dist[j][k]<MAXV && p2<maxd[k]){
            p2 = maxd[k];
          }
        }
        
        newp = maxd[i]+maxd[j]+sqrt((pos[i][0]-pos[j][0])*(pos[i][0]-pos[j][0])+(pos[i][1]-pos[j][1])*(pos[i][1]-pos[j][1]));
        newp = newp>p2?newp:p2;
        // cout<<i<<' '<<j<<' '<<p1<<' ' <<p2<<' '<<newp<<endl;
        if(maxnewp>newp)
          maxnewp = newp;
      }
    }
  }
  
  //printf("%.6f\n",maxnewp);
  fout<<fixed<<setprecision(6)<<maxnewp<<endl;
  return 0;
}
