/*
ID: remijoh1
LANG: C++11
TASK: namenum
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

void search(int cur, char name[], vector<string> *result,const int num[], const int code[][3],const int len,const string dict[]){
  if(cur == len){
    name[len] = '\0';

    string sname(name);
    int head=0, tail=5000,p;
    do{
      p = (head+tail)/2;

      if(dict[p]==sname){
	(*result).insert((*result).end(),sname);
	return;
      }
      if(dict[p]<sname){
	head = p+1;
      }
      else{
	tail = p;
      }
    }while(head<tail);
    return;
  }
  else{
    for(int i=0;i<3;i++){
      name[cur] = code[num[len-cur-1]][i];
      search(cur+1,name,result,num,code,len,dict);
    }
    return;
  }
}

int main(){

  ifstream fin("namenum.in");
  ifstream fdict("dict.txt");
  ofstream fout("namenum.out");

  string dict[5001];
  for(int i=0;i<5000;i++){
    fdict>>dict[i];
  }

  long long num_int;
  fin>>num_int;

  int len = 0;
  int num[13];
  while(num_int>0){
    num[len++] = num_int%10;
    num_int /= 10;
  }

  char name[13] = "";
  int code[10][3] = {{'Z','Z','Z'},{'Z','Z','Z'},{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'}};
  vector<string> result;
  search(0,name,&result,num,code,len,dict);
  if(result.size()==0){
    fout<<"NONE"<<endl;
  }
  else{
    for(vector<string>::iterator it = result.begin();it!=result.end();it++){
      fout<<*it<<endl;
    }
  }
  return 0;
}
  
