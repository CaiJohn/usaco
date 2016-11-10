#include<fstream>
#include<iostream>
using namespace std;
ofstream fout("msquare-test.out");

void search(int cur,int ans[]){
  if(cur==8){
    for(int i=0;i<8;i++){
      fout<<ans[i];
      if(i==7)
        fout<<endl;
      else
        fout<<' ';
    }
  }
  else{
    for(int i=1;i<=8;i++){
      bool tag = false;
      for(int j=0;j<cur;j++){
        if(ans[j] == i){
          tag = true;
          break;
        }
      }
      if(tag == true)
        continue;
      else{
        ans[cur] = i;
        search(cur+1,ans);
      }
    }
  }
  return;
}
int main(){
  int ans[8]={0};
  search(0,ans);
  return 0;
}
