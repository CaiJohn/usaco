/*
  ID: remijoh1
  LANG: C++11
  TASK: spin
*/
#include<iostream>
#include<fstream>
using namespace std;
int speed[5] = {0},wnum[5] = {0},wedges[5][5][2]={0};
int norm(int from,int to,int output[][2]){
  int ansl;
  if(from>to){
    output[0][0] = from;
    output[0][1] = 359;
    output[1][0] = 0;
    output[1][1] = to;
    ansl = 2;
  }
  else{
    output[0][0] = from;
    output[0][1] = to;
    ansl = 1;
  }
  return ansl;
}

int cover(int a[][2],int b[][2],int anum,int bnum,int output[][2]){
  // a, b are both normalized
  // cout<<"cover"<<endl;
  // for(int i=0;i<anum;i++){
  //   cout<<a[i][0]<<' '<<a[i][1]<<endl;
  // }
  // cout<<"======"<<endl;
  // for(int i=0;i<bnum;i++){
  //   cout<<b[i][0]<<' '<<b[i][1]<<endl;
  // }

  int count = 0;
  for(int i=0;i<anum;i++){
    for(int j=0;j<bnum;j++){
      if(a[i][0]>b[j][1] || a[i][1]<b[j][0])
	continue;
      else{
	output[count][0] = a[i][0]>b[j][0]?a[i][0]:b[j][0];
	output[count][1] = a[i][1]<b[j][1]?a[i][1]:b[j][1];
	count++;
      }
    }
  }
  return count;
}

bool solve(int cur,int ans[][2],int ansl){
  //cout<<cur<<endl;
  if(cur>=5){
    // for(int i=0;i<ansl;i++){
    //   cout<<ans[i][0]<<' '<<ans[i][1]<<endl;
    // }
    return true;
  }
  else{
    for(int i=0;i<wnum[cur];i++){
      if(cur==0){
	int from = wedges[cur][i][0],to = (wedges[cur][i][0]+wedges[cur][i][1])%360;
	int ansl = norm(from,to,ans);
	if(solve(cur+1,ans,ansl))
	  return true;
      }
      else{
	int range[2][2]={0};
	int from = wedges[cur][i][0],to=(wedges[cur][i][0]+wedges[cur][i][1])%360;
	int rlen = norm(from,to,range);
	int output[20][2] = {0};
	int outputl = cover(range,ans,rlen,ansl,output);
	if(outputl>0 && solve(cur+1,output,outputl))
	  return true;
      }
    }   
  }
  return false;
}

int main(){
  ifstream fin("spin.in");
  ofstream fout("spin.out");
  
  for(int i=0;i<5;i++){
    fin>>speed[i];
    fin>>wnum[i];
    for(int j=0;j<wnum[i];j++){
      fin>>wedges[i][j][0]>>wedges[i][j][1];
    }
  }
  int pos[5] = {0},ans[10][2]={0};
  int time = 0;
  while(true){
    if(solve(0,ans,0)){
      fout<<time<<endl;
      break;
    }      
    for(int i=0;i<5;i++){
      pos[i] = (pos[i]+speed[i])%360;
      for(int j=0;j<wnum[i];j++){
	wedges[i][j][0] = (wedges[i][j][0]+speed[i])%360;
      }
    }
    time++;
    // Judge whether the same state has happened
    if(pos[0]==0 && pos[1]==0 && pos[2]==0 && pos[3]==0 && pos[4]==0){
      fout<<"none"<<endl;
      break;
    }
  }
  return 0;
}
