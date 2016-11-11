/*
  ID: remijoh1
  LANG: C++11
  TASK: shopping
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int main(){
  ifstream fin("shopping.in");
  ofstream fout("shopping.out");

  int s,encode[1000]={0},ccount=1,so[100][6]={0};
  
  fin>>s;
  //cout<<s<<endl;
  for(int i=0;i<s;i++){
    int n;
    fin>>n;
    for(int j=0;j<n;j++){
      int code,num;
      fin>>code>>num;
      if(encode[code]==0){
        encode[code] = ccount;
        ccount++;
      }
      so[i][encode[code]]=num;
    }
    fin>>so[i][0];
  }
  
  int b,target[6]={0},price[6]={0};
  fin>>b;
  for(int i=0;i<b;i++){
    int code,num,p;
    fin>>code>>num>>p;
    if(encode[code]==0){
      encode[code] = ccount;
      ccount++;
    }
    target[encode[code]]=num;
    price[encode[code]] = p;
  }
  // for(int i=1;i<=5;i++)
  //   cout<<target[i]<<' '<<price[i]<<endl;
  // cout<<so[0][0]<<' '<<so[0][1]<<endl;
  // cout<<so[1][0]<<' '<<so[1][1]<<' '<<so[1][2]<<endl;
    
  //        a  b  c  d  e
  int state[6][6][6][6][6][100]={0};
  for(int a=0;a<=target[1];a++){
    for(int b=0;b<=target[2];b++){
      for(int c=0;c<=target[3];c++){
        for(int d=0;d<=target[4];d++){
          for(int e=0;e<=target[5];e++){
            for(int k=s;k>=0;k--){
              if(k==s){
                state[a][b][c][d][e][k]=a*price[1]+b*price[2]+c*price[3]+d*price[4]+e*price[5];
              }
              else{
                if(a>=so[k][1]&&b>=so[k][2]&&c>=so[k][3]&&d>=so[k][4]&&e>=so[k][5]){
                  state[a][b][c][d][e][k] = min(state[a-so[k][1]][b-so[k][2]][c-so[k][3]][d-so[k][4]][e-so[k][5]][k]+so[k][0],state[a][b][c][d][e][k+1]);
                  //cout<<state[a-so[k][1]][b-so[k][2]][c-so[k][3]][d-so[k][4]][e-so[k][5]][k]+so[k][0]<<' '<<state[a][b][c][d][e][k+1]<<endl;
                  
                }
                else{
                  state[a][b][c][d][e][k] = state[a][b][c][d][e][k+1];
                }
                
              }
              //cout<<"a: "<<a<<" b: "<<b<<" c: "<<c<<" d: "<<d<<" e: "<<e<<" k: "<<k<<' '<<state[a][b][c][d][e][k]<<endl;
              
            }
          }
        }
      }
    }
  }
  fout<<state[target[1]][target[2]][target[3]][target[4]][target[5]][0]<<endl;

  return 0;
}
  
    
