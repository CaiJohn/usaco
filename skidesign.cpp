/*
  ID: remijoh1
  LANG: C++11
  TASK: skidesign
*/

#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int main(void){
  ifstream fin("skidesign.in");
  ofstream fout("skidesign.out");
  int N,h[1001];

  fin>>N;
  for(int i=0;i<N;i++){
    fin>>h[i];
    
  }

  int mcost = 99999999;
  for(int low = 0;low<=83;low++){
    int high = low+17;
    int cost = 0;
    for(int i=0;i<N;i++){
      if(h[i]<low){
        cost += (low-h[i])*(low-h[i]);
      }
      else{
        if(h[i]>high){
          cost += (h[i]-high)*(h[i]-high);
        }
      }
    }
    mcost = min(mcost,cost);
  }
  fout<<mcost<<endl;
  return 0;
}

  


  
  /*
  sort(h1,h1+N);
  sort(h2,h2+N);
  // for(int i=0;i<N;i++)
  //   cout<<h[i]<<endl;
  
  int count[1001] = {0};
  while(h1[N-1]-h1[0]>17){
    
    int cl=1, cr=1;
    for(int i=0;i<N-1;i++){
      if(h1[i]<h1[i+1])
        break;
      cl++;
    }
    for(int i=N-1;i>=1;i--){
      if(h1[i-1]<h1[i])
        break;
      cr++;
    }

    if(cl<cr){
      
      for(int i=0;i<cl;i++){
        h1[i]++;
      }
      
    }
    else{
      
      for(int i=N-1;i>=N-cr;i--){
        h1[i]--;
      }
    }
    
  }
  int result = 0;
  cout<<"result"<<endl;
  for(int i=0;i<N;i++){
    //    cout<<count[i]<<endl;
    int tmp = h1[i]>h2[i]?(h1[i]-h2[i]):(h2[i]-h1[i]);
    result += tmp*tmp;
  }

  cout<<result<<endl;
  return 0;
}
  */
