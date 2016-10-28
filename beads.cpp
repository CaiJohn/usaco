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

  for(int next_head = 0; next_head<length; next_head++){
    int curpos = next_head;
    char curcolor = 'w';
    bool tag = false;
    int new_result = 0;

    while(true){
      if(curpos==length+next_head){
	result = new_result;
	break;
      }
      else{
	if(beads[curpos%length]==curcolor){
	  new_result ++;
	  curpos ++;
	}
	else{
	  if(beads[curpos%length]=='w'){
	    new_result ++;
	    curpos ++;
	  }
	  else{
	    if(curcolor=='w'){
	      curcolor = beads[curpos%length];
	      new_result ++;
	      curpos++;
	    }
	    else{
	      if(tag ==false){
		tag = true;
		curcolor = beads[curpos%length];
		new_result++;
		curpos ++;
	      }
	      else{
		tag = false;
		if(new_result>result){
		  result = new_result;
		}
		break;
	      }
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

  fout<<search(beads,length)<<endl;


  return 0;
}
	
      
      
  
  

