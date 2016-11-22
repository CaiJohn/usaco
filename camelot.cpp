/*
  ID: remijoh1
  LANG: C++11
  TASK: camelot
*/
#include<iostream>
#include<fstream>
#include<queue>
#define MAXR 30
#define MAXC 26
#define MAXDIST 99999999
using namespace std;

struct triple{
  int dist;
  int r;
  int c;
};

int R,C;
int bfscount = 0;
int walk(int r, int c,triple output[]){
  int direct[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
  int count = 0;
  for(int i=0;i<8;i++){
    int newr=r+direct[i][0], newc=c+direct[i][1];
    if(newr>=0&&newr<R&&newc>=0&&newc<C){
      output[count].r = newr;
      output[count].c = newc;
      count++;
    }
  }
  return count;
}

void bfs(int r,int c,int output[][MAXC]){
  // cout<<(bfscount++)<<endl;
  for(int m=0;m<R;m++){
    for(int n=0;n<C;n++){
      output[m][n] = MAXDIST;
    }
  }
  // cout<<"bfs "<<r<<' '<<c<<endl;
  bool visited[MAXR][MAXC]={false};
  queue<triple> q;
  triple cur;
  cur.dist = 0;
  cur.r = r;
  cur.c = c;
  visited[r][c] = true;
  q.push(cur);  
  while(!q.empty()){
    cur = q.front();
    q.pop();
    output[cur.r][cur.c] = cur.dist;
    triple w[10];
    int num = walk(cur.r,cur.c,w);
    for(int i=0;i<num;i++){
      if(visited[w[i].r][w[i].c]==false){
        w[i].dist = cur.dist+1;
        visited[w[i].r][w[i].c] = true;
        q.push(w[i]);
      }
    }
  }

  // for(int m=0;m<R;m++){
  //   for(int n=0;n<C;n++){
  //     cout<<output[m][n]<<' ';
  //   }
  //   cout<<endl;
  // }
}

int main(){
  ifstream fin("camelot.in");
  ofstream fout("camelot.out");
 
  fin>>R>>C;

  int king[2], knight[781][2];
  char tmpr;
  int tmpc;
  fin>>tmpr>>tmpc;  
  king[0] = tmpc-1;
  king[1] = tmpr-'A';
  int kcount = 0;
  while(true){
    fin>>tmpr>>tmpc;
    if(fin.eof())
      break;
    //cout<<tmpr<<' '<<tmpc<<endl;
    knight[kcount][0]= tmpc-1;
    knight[kcount][1] = tmpr-'A';
    kcount++;
  }
  
  // for(int i=0;i<kcount;i++){
  //   cout<<knight[i][0]<<' '<<knight[i][1]<<endl;
  // }
  
  bool calc[MAXR][MAXC] = {false}, visited[MAXR][MAXC]={false};
  int minDist = MAXDIST,dist[MAXR][MAXC][MAXR][MAXC]={0},summap[MAXR][MAXC][MAXR*MAXC]={0},sum[MAXR][MAXC]={0};
  int direct[8][2] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
  
  if(kcount==0){
    fout<<0<<endl;
    return 0;
  }

  for(int m=0;m<R;m++){
    for(int n=0;n<C;n++){
      for(int k=0;k<kcount;k++){
        if(calc[knight[k][0]][knight[k][1]]==false){
          bfs(knight[k][0],knight[k][1],dist[knight[k][0]][knight[k][1]]);
          calc[knight[k][0]][knight[k][1]]=true;
        }
        sum[m][n] += dist[knight[k][0]][knight[k][1]][m][n];        
      }
    }
  }
  
  
  for(int k=0;k<kcount;k++){    
    for(int m=0;m<R;m++){
      for(int n=0;n<C;n++){
        summap[m][n][k] = sum[m][n]-dist[knight[k][0]][knight[k][1]][m][n];
      }
    }
  }
  
  
  queue<triple> q;
  triple curking;
  curking.dist = 0;
  curking.r = king[0];
  curking.c = king[1];
  visited[king[0]][king[1]]=true;
  // cout<<"push "<<curking.r<<' '<<curking.c<<' '<<curking.dist<<endl;
  q.push(curking);
  while(!q.empty()){
    curking = q.front();
    // cout<<"pick up king at "<<curking.r<<' '<<curking.c<<' '<<curking.dist<<endl;
    q.pop();
    // if(curking.dist>=5){
    //   fout<<minDist<<endl;
    //   return 0;
    // }
   
    for(int i=0;i<8;i++){
      int newr = curking.r+direct[i][0],newc = curking.c+direct[i][1];
      if(newr>=0 && newr<R && newc>=0 && newc<C && visited[newr][newc] == false){
        visited[newr][newc] = true;
        triple tmp;
        tmp.r = newr;
        tmp.c = newc;
        tmp.dist = curking.dist + 1;
        // cout<<"push "<<tmp.r<<' '<<tmp.c<<' '<<tmp.dist<<endl;
        q.push(tmp);
      }
    }
    
    for(int i=0;i<kcount;i++){
      if(calc[knight[i][0]][knight[i][1]]==false){
        bfs(knight[i][0],knight[i][1],dist[knight[i][0]][knight[i][1]]);
        calc[knight[i][0]][knight[i][1]]=true;
      }
      int cost = curking.dist;
      cost += dist[knight[i][0]][knight[i][1]][curking.r][curking.c];
      // cout<<"cost "<<cost<<endl;
      if(cost>=minDist)
        continue;
      else{
        int minmap[MAXR][MAXC]={0};
        if(calc[curking.r][curking.c]==false){
          bfs(curking.r,curking.c,dist[curking.r][curking.c]);
          calc[curking.r][curking.c]=true;
        }
        for(int m=0;m<R;m++){
          for(int n=0;n<C;n++){
            minmap[m][n] += dist[curking.r][curking.c][m][n] + summap[m][n][i];
          }
        }
        // for(int j=0;j<kcount;j++){
        //   if(j==i){
        //     if(calc[curking.r][curking.c]==false){
        //       bfs(curking.r,curking.c,dist[curking.r][curking.c]);
        //       calc[curking.r][curking.c]=true;
        //     }
        //     for(int m=0;m<R;m++){
        //       for(int n=0;n<C;n++){
        //         minmap[m][n] += dist[curking.r][curking.c][m][n];
        //       }
        //     }
        //   }
        //   else{
        //     if(calc[knight[j][0]][knight[j][1]]==false){
        //       bfs(knight[j][0],knight[j][1],dist[knight[j][0]][knight[j][1]]);
        //       calc[knight[j][0]][knight[j][1]]=true;
        //     }
        //     for(int m=0;m<R;m++){
        //       for(int n=0;n<C;n++){
        //         minmap[m][n] += dist[knight[j][0]][knight[j][1]][m][n];
        //       }
        //     }
        //   }
        // }
        // cout<<"minmap"<<endl;
        for(int m=0;m<R;m++){
          for(int n=0;n<C;n++){
            //cout<<minmap[m][n]<<' ';
            if(minDist>minmap[m][n]+cost)
              minDist = minmap[m][n]+cost;
          }
          //cout<<endl;
        }
        // cout<<minDist<<endl;
      }      
    }
  }
  fout<<minDist<<endl;
  return 0;
}
