/*
  ID: remijoh1
  LANG: C++11
  TASK: starry
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<queue>
#define MAXS 160
#define MAXH 100
#define MAXW 100
using namespace std;
typedef pair<int,int> pii;
int H,W;
char sky[MAXH][MAXW]={0};

int direct[8][2];
pii clusters[26][8][MAXS];
int clusterid = 0;
int scount[26]={0};

bool cmp(pii a,pii b){
  if(a.first==b.first){
    return a.second<b.second;
  }
  else{
    return a.first<b.first;
  }
}

void norm(pii output[],int ocount){
  sort(output,output+ocount,cmp);
  for(int i=0;i<ocount;i++){
    output[i].first -= output[0].first;
    output[i].second -= output[0].second;
  }
  return;
}

bool checkOne(pii output[], int ocount, int id){
  if(scount[id]==ocount){    
    for(int i=0;i<8;i++){
      bool tag = true;
      for(int j=0;j<ocount && tag;j++){
        if(clusters[id][i][j].first!=output[j].first || clusters[id][i][j].second!=output[j].second){
          tag =false;
        }
      }
      if(tag==true)
        return true;
    }
    return false;
  }
  else{
    return false;
  }
}

int check(pii output[],int ocount){
  int len = clusterid;
  for(int i=0;i<len;i++){
    if(checkOne(output,ocount,i)){
      return i;
    }
  }
  return -1;
}

pii transform(pii a, int typ, int refh, int refw){
  pii npos;
  switch(typ){
  case 0:
    npos.first = -a.first+refh;
    npos.second = a.second;
    return npos;
  case 1:
    npos.first = a.first;
    npos.second = -a.second+refw;
    return npos;
  case 2:
    npos.first = -a.first+refh;
    npos.second = -a.second+refw;    
    return npos;
  case 3:
    npos.first = a.second;
    npos.second = a.first;    
    return npos;
  case 4:
    return transform(transform(a,3,refh,refw),0,refh,refw);
  case 5:
    return transform(transform(a,3,refh,refw),1,refh,refw);
  case 6:
    return transform(transform(a,3,refh,refw),2,refh,refw);
  }
}

void transformAll(pii orig[], int count, pii output[],int typ,int refh, int refw){
  for(int i=0;i<count;i++){
    output[i] = transform(orig[i],typ,refh,refw);
  }
  sort(output,output+count,cmp);
  return;
}

void addCluster(pii output[], int ocount){
  int refh = 0, refw = 0;
  for(int i=0;i<ocount;i++){
    clusters[clusterid][0][i] = output[i];
    if(refh<output[i].first)
      refh = output[i].first;
    if(refw<output[i].second)
      refw = output[i].second;
  }
  for(int i=0;i<7;i++){
    transformAll(output,ocount,clusters[clusterid][i+1],i,refh,refw);
  }
  clusterid++;
  return;
}

char solve(int h,int w){
  int visited[MAXH][MAXW] = {0};
  pii output[MAXS];
  int ocount=0;
  queue<pii> q;
  pii cur(h,w);  
  q.push(cur);
  visited[h][w] = 1;
  while(!q.empty()){
    cur=q.front();
    q.pop();
    output[ocount++] = cur;
    
    for(int i=0;i<8;i++){
      int nh = cur.first+direct[i][0], nw = cur.second+direct[i][1];
      if(nh>=0 && nh<H && nw>=0 && nw<W && visited[nh][nw]==0 && sky[nh][nw]=='1'){
        visited[nh][nw] = 1;
        pii npos(nh,nw);
        q.push(npos);
      }
    }
  }
  norm(output,ocount);
  int id = check(output,ocount);
  if(id>0){
    return id;
  }
  else{
    addCluster(output,ocount);
    return clusterid;
  }
}

void mark(int h, int w, char cid){
  int visited[MAXH][MAXW] = {0};
  
  queue<pii> q;
  pii cur(h,w);  
  q.push(cur);
  visited[h][w] = 1;
  while(!q.empty()){
    cur=q.front();
    q.pop();
    
    
    for(int i=0;i<8;i++){
      int nh = cur.first+direct[i][0], nw = cur.second+direct[i][1];
      if(visited[nh][nw]==0 && sky[nh][nw]=='1'){
        visited[nh][nw] = 1;
        sky[nh][nw] = cid;
        pii npos(nh,nw);
        q.push(npos);
      }
    }
  }
  return;
}

int main(){
  ifstream fin("starry.in");
  ofstream fout("starry.out");
  
  
  fin>>W>>H;
  
  for(int i=0;i<H;i++){
    string tmp;
    fin>>tmp;
    for(int j=0;j<W;j++){
      sky[i][j] = tmp[j];
    }
  }

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(sky[i][j]=='1'){
        char cid = solve(i,j);
        mark(i,j,cid+'a');
      }
    }
  }
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      fout<<sky[i][j];
    }
    fout<<endl;
  }
  return 0;
}
  
