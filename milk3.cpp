/*
  ID: remijoh1
  LANG: C++11
  TASK: milk3
*/
#include<iostream>
#include<fstream>

using namespace std;

struct triple{
  int a;
  int b;
  int c;
};

int A,B,C;

triple pour(int a,int b,int c,int type){
  // cout<<a<<' '<<b<<' '<<c<<" type: "<<type<<endl;
  int empty,more;
  triple result;
  result.a = a;
  result.b = b;
  result.c = c;
  switch(type){
  case 1:
    empty = B-b;
    more = a;
    if(empty>0 && more>0){
      if(empty>more){
	result.a = 0;
	result.b = b+more;
      }
      else{
	result.a = more-empty;
	result.b = B;
      }
    }
    return result;
  case 2:
    empty = C-c;
    more = a;
    if(empty>0 && more>0){
      if(empty>more){
	result.a = 0;
	result.c = c+more;
      }
      else{
	result.a = more-empty;
	result.c = C;
      }
    }
    return result;
  case 3:
    empty = A-a;
    more = b;
    if(empty>0 && more>0){
      if(empty>more){
	result.b = 0;
	result.a = a+more;
      }
      else{
	result.b = more-empty;
	result.a = A;
      }
    }
    return result;
  case 4:
    empty = C-c;
    more = b;
    if(empty>0 && more>0){
      if(empty>more){
	result.b = 0;
	result.c = c+more;
      }
      else{
	result.b = more-empty;
	result.c = C;
      }
    }
    return result;
  case 5:
    empty = A-a;
    more = c;
    if(empty>0 && more>0){
      if(empty>more){
	result.c = 0;
	result.a = a+more;
      }
      else{
	result.c = more-empty;
	result.a = A;
      }
    }
    return result;
  case 6:
    empty = B-b;
    more = c;
    if(empty>0 && more>0){
      if(empty>more){
	result.c = 0;
	result.b = b+more;
      }
      else{
	result.c = more-empty;
	result.b = B;
      }
    }
    return result;
  default:
    result.a=-1;
    result.b=-1;
    result.c=-1;
    return result;
  }
}

void search(int state[][21][21],int a,int b,int c){
  for(int i=1;i<=6;i++){
    triple tmp =  pour(a,b,c,i);
    // cout<<a<<' '<<b<<' '<<c<<endl;
    // cout<<tmp.a<<' '<<tmp.b<<' '<<tmp.c<<endl;
    if(state[tmp.a][tmp.b][tmp.c]==0){
      state[tmp.a][tmp.b][tmp.c] = 1;
      search(state,tmp.a,tmp.b,tmp.c);
    }
  }
  return;
}


int main(void){
  ifstream fin("milk3.in");
  ofstream fout("milk3.out");
  fin>>A>>B>>C;

  int state[21][21][21] = {0};
  search(state,0,0,C);

  int result[21] = {0};
  int len = 0;
  for(int b=0;b<=B;b++){
    for(int c=0;c<=C;c++){
      if(state[0][b][c]==1)
	result[c] = 1;
    }
  }
  // cout<<"here"<<endl;

  for(int i=0;i<=C;i++){
    if(result[i]==1){
      fout<<i;
      if(i==C){
	fout<<endl;
      }
      else{
	fout<<' ';
      }
    }
  }
  return 0;
}
  

