/*
ID: remijoh1
LANG: C++11
TASK: crypt1
*/

#include<iostream>
#include<fstream>
using namespace std;
bool check(int num, const int digits[], const int dsize){
  int d;
  do{
    d = num%10;
    
    bool tag = false;
    for(int i=0;i<dsize;i++){
      if(digits[i]==d){
	tag = true;
	break;
      }
    }

    if(tag == false)
      return false;
    num /= 10;
  }while(num>0);

  return true;
}
    
	   
int main(){
  ifstream fin("crypt1.in");
  ofstream fout("crypt1.out");

  int N;
  int digits[11];
  fin>>N;
  for(int i=0;i<N;i++){
    fin>>digits[i];
  }

  int count = 0;
  for(int u0=0;u0<N;u0++){
    for(int u1=0;u1<N;u1++){
      for(int u2=0;u2<N;u2++){
	int up;
	up = digits[u0] + digits[u1]*10 + digits[u2]*100;
	if(up<100)
	  continue;
	
	for(int d0=0;d0<N;d0++){
	  for(int d1=0;d1<N;d1++){
	    int down;
	    down = digits[d0] + digits[d1]*10;
	    if(down<10)
	      continue;

	    int p1 = up*digits[d0];
	    int p2 = up*digits[d1];
	    if(p1<1000 && p2<1000 && check(p1,digits,N) && check(p2,digits,N)){
	      int r = up*down;
	      if(r<10000 && check(r,digits,N)){
		//		cout<<up<<' '<<down<<' '<<r<<endl;
		count++;
	      }
	    }
	  }
	}
      }
    }
  }
  fout<<count<<endl;
  return 0;
}
		
	    

	    
    
  
  
