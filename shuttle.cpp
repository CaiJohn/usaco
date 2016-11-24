/*
  ID: remijoh1
  LANG: C++11
  TASK: shuttle
*/
#include<iostream>
#include<fstream>
using namespace std;

bool move(int board[],int pos,int size,int &type){
  if(board[pos]==0){
    if(pos==size-1){
      return false;
    }
    else{
      if(board[pos+1]==2 && (type==0 || type==2)){
	board[pos+1] = 0;
	board[pos] = 2;
	type++;
	return true;
      }
      else{
	if(pos<size-2 && board[pos+1]==1 && board[pos+2]==2 && (type==0 || type==1 || type==2)){
	  board[pos+2] = 0;
	  board[pos] = 2;
	  type = 2;
	  return true;
	}
	else{
	  return false;
	}
      }
    }
  }
  else{
    if(board[pos] == 1 ){
      if(pos==0){
	return false;
      }
      else{
	if(board[pos-1]==2 && (type==0 || type==2)){
	  board[pos-1] = 1;
	  board[pos] = 2;
	  type++;
	  return true;
	}
	else{
	  if(pos>1 && board[pos-1]==0 && board[pos-2]==2 && (type==0 || type==1 || type==2)){
	    board[pos-2] = 1;
	    board[pos] = 2;
	    type = 2;
	    return true;
	  }
	  else{
	    return false;
	  }
	}
      }
    }
    else{
      cout<<"error!"<<endl;
      return false;
    }
  }
}

int main(){
  ifstream fin("shuttle.in");
  ofstream fout("shuttle.out");

  int N;
  fin>>N;
  int board[25],len = N*2+1;
  for(int i=0;i<N;i++){
    board[i] = 0;
    board[2*N-i] = 1;
  }
  board[N] = 2;

  int state = 0,tag = true,pcount = 0;;
  while(tag){
    tag = false;
    if(state==0){
      int cur = len-1;
      int type = 0;
      while(true){
	if(cur<0)
	  break;
	if(board[cur]==0){
	  if(move(board,cur,len,type)==true){

	    tag = true;
	    if(pcount>0 && pcount%20==0)
	      fout<<endl;
	    else
	      if(pcount>0)
		fout<<' ';
	    fout<<cur+1;
	    pcount++;
	    
	    // cout<<cur+1<<endl;
	    // for(int i=0;i<len;i++){
	    //   if(board[i] == 2)
	    // 	cout<<' ';
	    //   else
	    // 	cout<<board[i];
	    // }
	    // cout<<endl;
	  }
	}
	cur--;
      }
      state = 1;
    }
    else{
      int cur = 0;
      int type = 0;
      while(true){
	if(cur>len-1)
	  break;
	if(board[cur]==1){
	  if(move(board,cur,len,type)==true){
	    
	    tag = true;
	    if(pcount>0 && pcount%20==0)
	      fout<<endl;
	    else
	      if(pcount>0)
		fout<<' ';
	    fout<<cur+1;
	    pcount++;
	    
	    // cout<<cur+1<<endl;
	    // for(int i=0;i<len;i++){
	    //   if(board[i] == 2)
	    // 	cout<<' ';
	    //   else
	    // 	cout<<board[i];
	    // }
	    // cout<<endl;
	  }
	}
	cur++;
      }
      state = 0;      
    }
  }
  fout<<endl;
  return 0;
}


