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
int sky[MAXH][MAXW]={0};

int direct[8][2] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
pii clusters[26][8][MAXS];
int clusterid = 0;
int clustercount = 2;
int count2id[510]={0};

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
  int refh = output[0].first,refw = output[0].second;
  for(int i=0;i<ocount;i++){
    output[i].first -= refh;
    output[i].second -= refw;
  }
  return;
}

bool checkOne(pii output[], int ocount, int id){
  if(scount[id]==ocount){    
    for(int i=0;i<8;i++){
      bool tag = true;
      for(int j=0;j<ocount && tag;j++){
        if(clusters[id][i][j].first!=output[j].first || clusters[id][i][j].second!=output[j].second){
          // cout<<"diff "<<i<<' '<<j<<endl;
          tag = false;
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
  // cout<<"check cluster: "<<clustercount-1<<endl;
  // for(int i=0;i<ocount;i++)
  //   cout<<output[i].first<<' '<<output[i].second<<endl;
  
  
  int len = clusterid;
  for(int i=0;i<len;i++){
    if(checkOne(output,ocount,i)){
      // cout<<"get! "<<i<<endl;
      return i;
    }
  }
  return -1;
}

pii transform(pii a, int typ){
  pii npos;
  switch(typ){
  case 0:
    npos.first = -a.first;
    npos.second = a.second;
    return npos;
  case 1:
    npos.first = a.first;
    npos.second = -a.second;
    return npos;
  case 2:
    npos.first = -a.first;
    npos.second = -a.second;    
    return npos;
  case 3:
    npos.first = a.second;
    npos.second = a.first;    
    return npos;
  case 4:
    return transform(transform(a,3),0);
  case 5:
    return transform(transform(a,3),1);
  case 6:
    return transform(transform(a,3),2);
  }
}

void transformAll(pii orig[], int count, pii output[],int typ){
  for(int i=0;i<count;i++){
    output[i] = transform(orig[i],typ);
  }
  norm(output,count);
  return;
}

void addCluster(pii output[], int ocount){
  for(int i=0;i<ocount;i++){
    clusters[clusterid][0][i] = output[i];
  }
  //cout<<"addcluster"<<endl;
  for(int i=0;i<7;i++){
    transformAll(output,ocount,clusters[clusterid][i+1],i);
    // cout<<"trans "<<i<<endl;
    // for(int j=0;j<ocount;j++){
    //   cout<<clusters[clusterid][i+1][j].first<<' '<<clusters[clusterid][i+1][j].second<<endl;
    // }    
  }
  scount[clusterid] = ocount;
  clusterid++;
  return;
}

char solve(int h,int w){
  pii output[MAXS];
  int ocount=0;
  queue<pii> q;
  pii cur(h,w);  
  q.push(cur);
  sky[cur.first][cur.second] = clustercount;
  while(!q.empty()){
    cur=q.front();
    q.pop();
    output[ocount++] = cur;
    
    for(int i=0;i<8;i++){
      int nh = cur.first+direct[i][0], nw = cur.second+direct[i][1];
      if(nh>=0 && nh<H && nw>=0 && nw<W &&  sky[nh][nw]==1){
        sky[nh][nw] = clustercount;        
        pii npos(nh,nw);
        q.push(npos);
      }
    }
  }
  
  norm(output,ocount);
  int id = check(output,ocount);
  // cout<<"here "<<id<<' '<<clustercount<<endl;
  if(id>=0){    
    count2id[clustercount++] = id;
    return id;
  }
  else{
    addCluster(output,ocount);
    count2id[clustercount++] = clusterid-1;
    return clusterid-1;
  }
}


int main(){
  ifstream fin("starry.in");
  ofstream fout("starry.out");
   
  fin>>W>>H;
  
  for(int i=0;i<H;i++){
    string tmp;
    fin>>tmp;
    for(int j=0;j<W;j++){
      sky[i][j] = tmp[j]-'0';
    }
  }

  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(sky[i][j]==1){
        solve(i,j);
      }
    }
  }
  // for(int i=0;i<clustercount;i++)
  //   cout<<i<<' '<<count2id[i]<<endl;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      //cout<<sky[i][j];
      if(sky[i][j]==0)
        fout<<char(sky[i][j]+'0');
      else
        fout<<char(count2id[sky[i][j]]+'a');
    }
    //cout<<endl;
    fout<<endl;
  }
  return 0;
}
