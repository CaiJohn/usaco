/*
ID: remijoh1
LANG: C++
TASK: holstein
*/
#include<iostream>
#include<fstream>
using namespace std;

int V,G;
int target[25],vita[15][25];
ifstream fin("holstein.in");
ofstream fout("holstein.out");

bool solve(int cur,int num,int ans[]){
  if(cur==num){
    int tmp[25]={0};
    // if(num==2){
    //   for(int i=0;i<cur;i++){
    // 	cout<<' '<<ans[i];
    //   }
    //   cout<<endl;
    // }

    for(int i=0;i<num;i++){
      for(int j=0;j<V;j++){
	tmp[j] += vita[ans[i]][j];
      }
    }
    for(int i=0;i<V;i++){
      if(tmp[i]<target[i])
	return false;
    }
    fout<<cur;
    for(int i=0;i<cur;i++){
      fout<<' '<<ans[i]+1;
    }
    fout<<endl;
    return true;
  }
  else{
    if(cur == 0){
      for(int i=0;i<G;i++){
	ans[cur] = i;
	if(solve(cur+1,num,ans))
	  return true;
      }
    }
    else{
      for(int i=ans[cur-1]+1;i<G;i++){
	ans[cur] = i;
	if(solve(cur+1,num,ans))
	  return true;
      }
    }
    return false;
  }
}
      

int main(void){
  fin>>V;
  for(int i=0;i<V;i++){
    fin>>target[i];
  }
  fin>>G;
  for(int i=0;i<G;i++){
    for(int j=0;j<V;j++){
      fin>>vita[i][j];
    }
  }
  int ans[15];
  for(int i=1;i<=G;i++){
    if(solve(0,i,ans))
      return 0;
  }
  return 0;
}

  
    
