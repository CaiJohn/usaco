/*
  ID: remijoh1
  LANG: C++11
  TASK: ratios
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int main(){
  ifstream fin("ratios.in");
  ofstream fout("ratios.out");

  int goal[3],ratios[3][3];
  fin>>goal[0]>>goal[1]>>goal[2];
  
  for(int i=0;i<3;i++){
    fin>>ratios[i][0]>>ratios[i][1]>>ratios[i][2];
  }

  int sum;
  for(sum=0;sum<=300;sum++){
    for(int i=0;i<=sum;i++){
      for(int j=0;j<=sum-i;j++){
	int k = sum-i-j;
	int newg[3];
	newg[0] = i*ratios[0][0]+j*ratios[1][0]+k*ratios[2][0];
	newg[1] = i*ratios[0][1]+j*ratios[1][1]+k*ratios[2][1];
	newg[2] = i*ratios[0][2]+j*ratios[1][2]+k*ratios[2][2];
	int r;
	if(goal[0]>0 && newg[0]%goal[0]==0){
	  r = newg[0]/goal[0];
	}
	else{
	  if(goal[1]>0 && newg[1]%goal[1]==0){
	    r = newg[1]/goal[1];
	  }
	  else{
	    if(goal[2]>0 && newg[2]%goal[2]==0){
	      r = newg[2]/goal[2];
	    }
	    else{
	      if(goal[0]==0 && goal[1]==0 && goal[2]==0){
		fout<<0<<' '<<0<<' '<<0<<' '<<0<<endl;
		return 0;
	      }
	      else{
		continue;
	      }
	    }
	  }
	}
	if(r>0 && r*goal[0]==newg[0] && r*goal[1]==newg[1] && r*goal[2]==newg[2]){
	  fout<<i<<' '<<j<<' '<<k<<' '<<r<<endl;
	  return 0;
	}
      }
    }
  }
  fout<<"NONE"<<endl;
  return 0;
}
