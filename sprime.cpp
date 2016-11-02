/*
  ID: remijoh1
  LANG: C++
  TASK: sprime
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;

int prime[4] = {2,3,5,7};

bool checkPrime(int num){
  if(num>2){
    int end = sqrt(num);
    for(int i=2;i<=end+1;i++){
      if(num%i==0)
        return false;
    }
    return true;
  }
  else{
    if(num==2)
      return true;
    else
      return false;
  }
}
  
vector<int>* search(int n){
  if(n==1){
    vector<int> *result = new vector<int>();
    result->push_back(2);
    result->push_back(3);
    result->push_back(5);
    result->push_back(7);
    return result;
  }
  else{
    vector<int>* v = search(n-1);
    
    vector<int>* result = new vector<int>();
    for(vector<int>::iterator it=v->begin();it!=v->end();it++){
      //cout<<*it<<endl;
      for(int i=0;i<=9;i++){
        if(i&1==0)
          continue;
        int tmp = (*it)*10+i;
        if(checkPrime(tmp))
          result->push_back(tmp);
      }
    }
    delete v;
    return result;
  }
}

int main(void){
  ifstream fin("sprime.in");
  ofstream fout("sprime.out");
  int N;

  fin>>N;
  vector<int>* result = search(N);
  for(vector<int>::iterator it=result->begin();it!=result->end();it++){
    fout<<*it<<endl;
  }
  return 0;
}
  
