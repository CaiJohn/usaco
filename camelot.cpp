/*
  ID: remijoh1
  LANG: C++11
  TASK: camelot
*/
#include<iostream>
#include<fstream>
#include<queue>
#include<utility>
using namespace std;

typedef pair<int,int> ipair;
// The dists of a knight from one point to other points
// Actually, can do it on demand

void bfs(ipair cur, int visited[][], int output[][],int (*walk)(ipair)){
  queue<ipair> q;
  q.push(cur);
  output[cur.first][cur.second] = 0;
  while(!q.empty()){
    output
  }
  
}
