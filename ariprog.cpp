/*
  ID: remijoh1
  LANG: C++11
  TASK: ariprog
*/
// http://www.cnblogs.com/sxprovence/

// What can be the max array size??
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int check(int num, int m){
  for(int i=0;i<=m;i++){
    int i2 = i*i;
    if(i2>num)
      return -1;
    for(int j=0;j<=m;j++){
      int j2 = j*j;
      if(i2+j2==num)
        return 1;
      if(i2+j2>num)
        break;
      // if(i2>num || j2>num){
      //   cout<<i2<<endl;
      //   return false;
    }
  }
  
  return -1;
}

int gen(int m, int info[], int start[]){
  int k=0;
  for(int i=0;i<=m;i++){
    int i2 = i*i;
    for(int j=i;j<=m;j++){
      if(info[i2+j*j]==0){
	info[i2+j*j] = 1;
	start[k++] = i2+j*j;
      }
    }
  }
  return k;
}

int main(void){
  ifstream fin("ariprog.in");
  ofstream fout("ariprog.out");

  int N,M;

  fin>>N>>M;
  int checked[125001] = {0};
  int maxNum = M*M*2;
  int maxDiff = N>1?maxNum/(N-1):maxNum;
  int tag = false;

  int startnum[125001]={0};
  int startlen = gen(M,checked,startnum);
  sort(startnum,startnum+startlen);
  // cout<<checked[3]<<endl;
  // for(int i=0;i<startlen;i++){
  //   cout<<startnum[i]<<endl;
  // }

  //cout<<"here"<<endl;
  // cout<<startlen<<' '<<startnum[startlen-1]<<endl;
  for(int diff = 1;diff<=maxDiff;diff++){
    for(int start = 0;start<startlen;start++){
      //cout<<diff<<' '<<start<<endl;
      int target = startnum[start];
      //int target = start;
      int l;
      for(l = 0;l<N;l++){

        if(target>maxNum)
          break;
        // if(checked[target]==0)
        //   checked[target] = check(target,M);
        if(checked[target]==0){
          break;
        }
	target += diff;
      }
      if(l==N){
	//cout<<"here"<<endl;
        fout<<startnum[start]<<' '<<diff<<endl;
        tag = true;
      }
    }
  }
  if(tag == false)
    fout<<"NONE"<<endl;
  return 0;
}
   
