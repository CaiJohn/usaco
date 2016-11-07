/*
  ID: remijoh1
  LANG: C++11
  TASK: fracdec
*/

#include<iostream>
#include<fstream>
#include<string>
#define MAXV 100000
using namespace std;
typedef pair<string,int> spair;

spair solve(int n,int d,int cur,int visited[]){
  // cout<<n<<' '<<d<<endl;
  
  if(n==0){
    spair result;
    result.first = "0";
    result.second = -1;
    return result;
  }
    
  if(n<d){
    for(int i=0;i<cur;i++){
      if(visited[i]==n){
        spair result;
        result.first = ")";
        result.second = i;
        return result;
      }
    }
    
    int newn = n*10/d;
    int newd = n*10%d;
    string news(1,newn+'0');
    spair result;
    if(newd==0){
      result.first = news;
      result.second = -1;
      return result;
    }

    visited[cur] = n;
    spair tmp = solve(newd,d,cur+1,visited);
    
    
    if(tmp.second == cur){
      result.first = "("+news+tmp.first;
      result.second = -1;
      return result;
    }
    else{
      result.first = news+tmp.first;
      result.second = tmp.second;
      return result;
    }
  }
  else{
    spair result;
    result.first = "";
    result.second = -1;
    return result;
  }
}
  

int main(){
  ifstream fin("fracdec.in");
  ofstream fout("fracdec.out");

  int N,D;
  fin>>N>>D;

  int big = N/D;
  string bigs = to_string(big);
  int visited[MAXV];
  for(int i=0;i<MAXV;i++)
    visited[i] = -1;
  
  visited[0] = N%D;
  int n = N%D,d=D,cur=0;
  string small;
  if(n==0){
    small = "0";
  }
  else{
    int tag = false;
    while(true){
      //cout<<n<<' '<<d<<endl;
      
      if(visited[n]!=-1){
        small.insert(visited[n],"(");
        small += ")";
        break;
      }
      
      visited[n] = cur++;
        
      int newn = (n*10)/d;
      small += to_string(newn);

      
      n = (n*10)%d;
      if(n==0)
        break;
    }
  }

  // spair small = solve(N%D,D,0,visited);
  
  string answer = bigs+"."+small;
  int len = answer.length();

  
  for(int i=0;i<len;i++){
    if(i%76==0 && i!=0)
      fout<<endl;
    fout<<answer[i];
  }
  fout<<endl;
  
  return 0;
}
