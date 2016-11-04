/*
ID: remijoh1
LANG: C++
TASK: castle
*/

#include<iostream>
#include<fstream>
using namespace std;

void search1(int r,int c,int tag[][51],const int info[][51], const int num){
  int wall = info[r][c];
  tag[r][c] = num;
  if((wall&1)==0){
    if(tag[r][c-1]==0)
      search1(r,c-1,tag,info,num);
  }
  if((wall&2)==0){
    if(tag[r-1][c]==0)
      search1(r-1,c,tag,info,num);
  }
  if((wall&4)==0){
    if(tag[r][c+1]==0)
      search1(r,c+1,tag,info,num);
  }
  if((wall&8)==0){
    if(tag[r+1][c]==0)
      search1(r+1,c,tag,info,num);
  }
  return ;
}

int main(void){
  ifstream fin("castle.in");
  ofstream fout("castle.out");

  int M,N,info[51][51];
  fin>>M>>N;
  for(int i=0;i<N;i++){
    for(int j=0;j<M;j++){
      fin>>info[i][j];
    }
  }

  int tag[51][51] = {0};
  int count = 0;
  for(int r=0;r<N;r++){
    for(int c=0;c<M;c++){
      if(tag[r][c]==0){
	count++;
	search1(r,c,tag,info,count);	
      }
    }
  }
  

  int sizes[2700] = {0};
  for(int r=0;r<N;r++){
    for(int c=0;c<M;c++){
      sizes[tag[r][c]]++;
    }
  }

  int maxSize = 0;
  for(int i=1;i<=count;i++){
    if(maxSize<sizes[i])
      maxSize = sizes[i];
  }


  int maxNewSize = 0;
  int newr=-1,newc=-1,d;
  for(int c=0;c<M;c++){
    for(int r=N-1;r>=0;r--){
      //cout<<r<<' '<<c<<endl;
      if(r>0){
	if(tag[r][c]!=tag[r-1][c]){
	  if(maxNewSize<sizes[tag[r][c]]+sizes[tag[r-1][c]]){
	    maxNewSize = sizes[tag[r][c]]+sizes[tag[r-1][c]];
	    newr = r+1;
	    newc = c+1;
	    d = 0;//N
	  }
	}
      }
      if(c<M-1){
	if(tag[r][c]!=tag[r][c+1]){
	  if(maxNewSize<sizes[tag[r][c]]+sizes[tag[r][c+1]]){
	    maxNewSize = sizes[tag[r][c]]+sizes[tag[r][c+1]];
	    newr = r+1;
	    newc = c+1;
	    d = 1;//E
	    
	  }
	}
      }
    }
  }

  fout<<count<<endl;
  fout<<maxSize<<endl;
  fout<<maxNewSize<<endl;

  char direction = d==1?'E':'N';
  fout<<newr<<' '<<newc<<' '<<direction<<endl;
  return 0;
}  
