/*
ID: remijoh1
LANG: C++
TASK: beads
*/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int search(string beads,int length){
  int result = 0;
  int new_result = 0;
  
  int next_head = -1;
  int curpos = 0;
  char curcolor = 'w';
  bool tag = false;

  while(curpos<length+length){
    if(beads[curpos]==curcolor){
      new_result ++;
      curpos ++;
    }
    else{
      if(beads[curpos]=='w'){
	next_head = curpos;
	new_result ++;
	curpos++;
      }
      else{
	if(curcolor=='w'){
	  curcolor = beads[curpos];
	  new_result ++;
	  curpos++;
	}
	else{
	  if(tag ==false){
	    tag = true;
	    curcolor = beads[curpos];
	    new_result++;
	    curpos ++;
	  }
	  else{
	    tag = false;
	    if(new_result>result){
	      result = new_result;
	    }
	    new_result = 0;
	    if(next_head>=0){
	      curpos = next_head;
	      curcolor = 'w';
	      next_head = -1;
	    }
	    else{
	      curpos++;
	    }
	  }
	}
      }
    }
  }
  return result;
}

int main(){
  ifstream fin("beads.in");
  ofstream fout("beads.out");
  int length;
  string beads;
  fin>>length;
  fin>>beads;

  int sum = 0;
  for(int i=0;i<length;i++){
    int tmp = search(beads,length);
    cout<<tmp<<endl;
    if(tmp>sum)
      sum = tmp;
    string head = beads.substr(0,1);
    string tail = beads.substr(1,length-1);
    beads = head+tail;
    cout<<beads<<endl;
  }

  fout<<sum<<endl;
  return 0;
}
	
      
      
  
  

