/*
  ID: remijoh1
  LANG: C++
  TASK: money
*/
#include<iostream>
#include<fstream>
using namespace std;

int main(void){
  ifstream fin("money.in");
  ofstream fout("money.out");

  int V,N,coins[25];

  fin>>V>>N;
  for(int i=0;i<V;i++){
    fin>>coins[i];
  }

  int state[10001][26] = {0};

  for(int m=1;m<=MAXM;m++){
    for(int c=N;c>=0;c--){
      state[m]
