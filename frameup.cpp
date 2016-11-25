/*
  ID: remijoh1
  LANG: C++11
  TASK: frameup
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#define MAXH 30
#define MAXW 30
using namespace std;
ifstream fin("frameup.in");
ofstream fout("frameup.out");

bool cmp(string a,string b){
  return a<b;
}


void cantor(int num, int output[]){
  int fac[5]={1,1,2,6,24};
  int visited[6] = {0};
  for(int i=0;i<5;i++){
    int n = num/fac[5-i-1];
    num %= fac[5-i-1];
    int cur = 1;
    while(true){
      if(visited[cur]==1){
        cur++;
        continue;
      }
      else{
        if(n==0)
          break;
        cur++;
        n--;
      }
    }

    visited[cur] = 1;
    output[i] = cur-1;
  }
}

void solve(int cur, string result,int remove[],int covered[][26],int exists[],int len,string ans[],int &acount){
  if(cur==len){
    //fout<<result<<endl;
    ans[acount++] = result;
    return;
  }
  else{
    for(int i=0;i<26;i++){
      if(exists[i]==0 || remove[i]==1)
        continue;
      bool tag = true;
      for(int j=0;j<26 && tag;j++){
        if(covered[i][j]==1 && remove[j]==0){
          tag = false;
        }
      }
      if(tag==true){
        result[len-cur-1] = i+'A';
        remove[i] = 1;
        solve(cur+1,result,remove,covered,exists,len,ans,acount);
        remove[i] = 0;
      }
    }
    return;
  }
}


int main(){
  
  
  int H,W;
  fin>>H>>W;

  char pic[MAXH][MAXW] = {0};
  string tmp;
  for(int i=0;i<H;i++){
    fin>>tmp;
    for(int j=0;j<W;j++){
      pic[i][j] = tmp[j];
    }
  }

  int frame[26][4]={0};// 0 min x, 1 min y, 2 max x, 3 max y
  int exists[26] = {0};
  for(int i=0;i<26;i++){
    frame[i][0] = MAXW+1;
    frame[i][1] = MAXH+1;
    frame[i][2] = 0;
    frame[i][3] = 0;
  }
  
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      if(pic[i][j]!='.'){
        exists[pic[i][j]-'A'] = 1;
        if(frame[pic[i][j]-'A'][0]>j){
          frame[pic[i][j]-'A'][0]=j;
        }
        if(frame[pic[i][j]-'A'][1]>i){
          frame[pic[i][j]-'A'][1]=i;
        }
        if(frame[pic[i][j]-'A'][2]<j){
          frame[pic[i][j]-'A'][2]=j;
        }
        if(frame[pic[i][j]-'A'][3]<i){
          frame[pic[i][j]-'A'][3]=i;
        }
      }
    }
  }
  
  
  int covered[26][26]={0};
  for(int i=0;i<26;i++){
    if(exists[i]==0)
      continue;
    for(int w=frame[i][0];w<=frame[i][2];w++){
      if(pic[frame[i][1]][w]!=('A'+i)){
        covered[i][pic[frame[i][1]][w]-'A'] = 1;
      }
      if(pic[frame[i][3]][w]!=('A'+i)){
        covered[i][pic[frame[i][3]][w]-'A'] = 1;
      }
    }
    for(int h=frame[i][1];h<=frame[i][3];h++){
      if(pic[h][frame[i][0]]!=('A'+i)){
        covered[i][pic[h][frame[i][0]]-'A'] = 1;
      }
      if(pic[h][frame[i][2]]!=('A'+i)){
        covered[i][pic[h][frame[i][2]]-'A'] = 1;
      }
    }
  }
  int len = 0;
  for(int i=0;i<26;i++)
    len += exists[i];
  
  string result(len,'x');
  int remove[26]={0};
  string ans[99999];
  int acount = 0;
  solve(0,result,remove,covered,exists,len,ans,acount);
  sort(ans,ans+acount,cmp);
  for(int i=0;i<acount;i++)
    fout<<ans[i]<<endl;
  // for(int i=0;i<120;i++){
  //   int output[5] = {0};
  //   cantor(i,output);
  //   //cout<<i<<endl;
    
  //   bool tag = true;
  //   for(int m=0;m<5&&tag;m++){
  //     int tmpcovered[5]={0};
  //     for(int n=m+1;n<5;n++){
  //       tmpcovered[output[n]] = 1;
  //     }
      
  //     for(int n=0;n<5 && tag;n++){
  //       if(tmpcovered[n]==0 && covered[output[m]][n]==1){
  //         tag = false;
  //       }
  //     }
  //   }
    
  //   if(tag==true){
  //     for(int j=0;j<5;j++){
  //       fout<<char(output[j]+'A');
  //     }
  //     fout<<endl;
  //   }
  // }
  return 0;
}
