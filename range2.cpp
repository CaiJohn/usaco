/*
  ID: remijoh1
  LANG: C++11
  TASK: range
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int main(){
  ifstream fin("range.in");
  ofstream fout("range.out");

  int map[250][250]={0},N,result[251]={0},start[250][250]={0};
  fin>>N;
  for(int i=0;i<N;i++){
    string tmp;
    fin>>tmp;
    for(int j=0;j<N;j++){
      map[i][j] = tmp[j]-'0';
      start[i][j]=1;
    }
  }
  
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      bool tag = true;
      int s;
      cout<<"here "<<i<<' '<<j<<' '<<start[i][j]<<endl;
      
      for(s=start[i][j];i+s-1<N && j+s-1<N;s++){
        for(int m=0;m<s&&tag==true;m++){
          // cout<<"check:"<<m+i<<' '<<j+s-1<<' '<<map[m+1][j+s-1]<<endl;
          if(map[m+i][j+s-1]==0){
            tag = false;
            break;
          }
        }          
        for(int m=0;m<s&&tag==true;m++){
          // cout<<"check:"<<i+s-1<<' '<<m+j<<' '<<map[i+s-1][m+j]<<endl;
          if(map[i+s-1][m+j]==0){
            tag = false;
            break;                           
          }
        }
        if(tag==false)
          break;
      }
      cout<<"here s: "<<s<<endl;;
      int maxs = s-1;
      if(maxs>=start[i][j]){
        cout<<"maxs: "<<maxs<<" i: "<<i<<" j: "<<j<<endl;
        cout<<"start[i][j]: "<<start[i][j]<<endl;
        for(int m=start[i][j];m<=maxs;m++){
          result[m] += (maxs-m+1)*(maxs-m+1);
          //result[m]--;
          cout<<"result: "<<m<<' '<<result[m]<<endl;
        }
        for(int m=i;m<i+maxs;m++){
          for(int n=j;n<j+maxs;n++){
            start[m][n] = min(maxs-m+i,maxs-n+j)+1;
            // cout<<m<<' '<<n<<' '<<start[m][n]<<endl;
          }
        }
      }
    }
  }
  for(int i=2;i<=N;i++){
    if(result[i]>0)
      fout<<i<<' '<<result[i]<<endl;
  }
 
  return 0;
}
