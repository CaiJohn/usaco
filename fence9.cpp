/*
  ID: remijoh1
  LANG: C++11
  TASK: fence9
*/
#include<iostream>
#include<fstream>
#include<cmath>
#define MAXV 50000
using namespace std;

// double getY(double x, double x1,double y1,double x2,double y2){
//   return ((y2-y1)*(x-x1)+y1*(x2-x1))/(x2-x1);
// }

double getX(double y,double x1,double y1,double x2,double y2){
  return ((y-y1)*(x2-x1)+x1*(y2-y1))/(y2-y1);
}

int main(){
  ifstream fin("fence9.in");
  ofstream fout("fence9.out");
  double n,m,p;
  int count=0;// Cannot use double here??
  fin>>n>>m>>p;

  double a1=m,a2=n,maxx = max(n,p);
  for(int y=1;y<m;y++){
    double l1,l2;
    l1 = getX(y,n,m,0,0);
    l2 = getX(y,n,m,p,0);
    count += ceil(l2) - floor(l1)-1;
    // if(n==0){
    //   l1 = MAXV;
    // }
    // else{
    //   l1 = getY(x,n,m,0,0);
    // }
    // if(n==p){
    //   l2 = MAXV;
    // }
    // else{
    //   l2 = getY(x,n,m,p,0);
    // }
    // double high,low;
    // if(l2>0){
    //   high = min(l1,l2);
    // }
    // else
    //   high = l1;
    // cout<<count<<endl;
    // count += (int)(l1)-(int)(l2+1)+1;
    // cout<<x<<' '<<l1<<' '<<l2<<endl;
    // double y=1;
    // while(true){
    //   if(p<n){
    // 	if(y<l1 && y>l2){
    // 	  // cout<<"count! "<<x<<' '<<y<<endl;
    // 	  count++;
    // 	  y++;
    // 	}
    // 	else{
    // 	  if(y>=l1){
    // 	    break;
    // 	  }
    // 	  else{
    // 	    y++;
    // 	  }
    // 	}
    //   }
    //   else{
    // 	if(y<l1 && y<l2){
    // 	  // cout<<"count! "<<x<<' '<<y<<endl;
    // 	  count++;
    // 	  y++;
    // 	}
    // 	else{
    // 	  break;
    // 	}
    //   }
    // }
  }
  fout<<count<<endl;
  return 0;
}
