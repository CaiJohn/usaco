/*
  ID: remijoh1
  LANG: C++11
  TASK: tour
*/
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#define MAXN 100
using namespace std;
struct City{
  string name;
  int id;
};

bool cmp(City a, City b){
  return a.name<b.name;
}


//??? again, binary search
int getId(string name,int from, int to,City cities[]){
  if(from>to)
    return -1;
  
  int mid = (from+to)/2;
  if(cities[mid].name==name){
    // cout<<"getId "<<name<<' '<<cities[mid].id<<endl;
    return cities[mid].id;
  }
  else{
    if(cities[mid].name<name){
      return getId(name,mid+1,to,cities);
    }
    else{
      return getId(name,from,mid-1,cities);
    }
  }
}

int main(){
  ifstream fin("tour.in");
  ofstream fout("tour.out");

  int N,V,ccount=0,edges[MAXN+1][MAXN+1]={0};
  fin>>N>>V;
  City cities[MAXN+1];
  for(int i=0;i<N;i++){
    fin>>cities[i].name;    
    cities[i].id = i;
  }
  sort(cities,cities+N,cmp);
  for(int i=0;i<V;i++){
    string from,to;
    fin>>from>>to;
    int id1=getId(from,0,N,cities),id2=getId(to,0,N,cities);
    edges[id1][id2] = 1;
    edges[id2][id1] = 1;
  }

  int state[MAXN+1][MAXN+1] = {0};
  state[N-1][N-1] = 1;
  for(int start = N-2;start>=0;start--){
    for(int end = N-1;end>=start;end--){
      int maxC = 0;
      for(int mid = start+1;mid<N;mid++){
        if(edges[start][mid]==1){
          int tmpC=0;
          if(mid<end){
            tmpC = state[mid][end];
          }
          else{
            if(mid>end){
              tmpC = state[end][mid];
            }
            else{
              if(mid==N-1)
                tmpC = 1;
              else
                tmpC = 0;
            }
          }
          if(tmpC>maxC)
            maxC = tmpC;
        }
      }
      if(maxC>0)
        state[start][end] = maxC+1;
      // cout<<start<<' '<<end<<' '<<state[start][end]<<endl;
    }
  }
  if(state[0][0]==0)
    fout<<1<<endl;
  else
    fout<<state[0][0]-1<<endl;
  return 0;
}
  
