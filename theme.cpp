/*
  ID: remijoh1
  LANG: C++11
  TASK: theme
*/
#include<iostream>
#include<fstream>
using namespace std;

struct Pos{
  int p;
  Pos* next;
};

struct Node{
  Node* next;
  Pos* member;
  int len;
  Node(){
    next = NULL;
    member = NULL;      
  }
  int collect(Pos* n, Pos* s,int t){
    int count = 0;
    while(true){
      if(s==NULL){
        break;
      }
      else{
        if(
      }
    }
  }
  void splitOne(Node* setlst, Pos* s){
    if(s==NULL)
      return;
    else{
      Pos* news = s;
      int newn = theme[s.p+len-1]-theme[s.p+len];
      
    }
  }
  
  void split(){
    if(member==NULL){
      return;
    }
    else{
      
    }
  }
  
};
