/*
  ID: remijoh1
  LANG: C++11
  TASK: spin
*/
#include<iostream>
#include<fstream>
using namespace std;

bool solve(int wedges[][5][2],int cur,int ans[]){
  if(cur>=5){
    return true;
  }
  else{
    for(int i=0;i<wnum[cur];i++){
      if(cur==0){
	ans[0] = wedges[cur][i][0];
	ans[1] = wedges[cur][i][0]+wedges[cur][i][1];
	if(solve(wedges,cur+1,ans))
	  return true;
      }
      else{
	int range[2]={0};
	range[0] = wedges[cur][i][0];
	range[1] = wedges[cur][i][0]+wedges[cur][i][1];
	if(range[1]<ans[0]||range[0]>ans[1])
	  continue;
	else{
	  ans[0] = ans[0]>range[0]?ans[0]:range[0];
	  ans[1] = ans[1]<range[1]?ans[1]:range[1];
	  if(solve(wedges,cur+1,ans)){
	    return;
	  }
	}
      }
    }
    return false;
  }
}

int main(){
  ifstream fin("spin.in");
  ofstream fout("spin.out");

  int speed[5] = {0},wnum[5] = {0},wedges[5][5][2]={0};
  
  for(int i=0;i<5;i++){
    fin>>speed[i];
    fin>>wnum[i];
    for(int j=0;j<wnum[i];j++){
      fin>>wedges[i][j][0]>>wedges[i][j][1];
    }
  }
  int pos[5] = {0},ans[2]={0};
  int time = 0;
  while(true){
    if(solve(wedges,0,ans)){
      fout<<time<<endl;
      return 0;
    }      
    for(int i=0;i<5;i++){
      pos[i] = (pos[i]+speed[i])%360;
      for(int j=0;j<wnum[i];j++){
	wedges[i][j][0] = (wedges[i][j][0]+speed[i])%360;
      }
    }
    
  }

  
  
    
}
