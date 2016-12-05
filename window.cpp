/*
  ID: remijoh1
  LANG: C++11
  TASK: window
*/
#include<iostream>
#include<cstdio>
#include<fstream>
#include<iomanip>
#include<cmath>
#define MAXW 62
using namespace std;

struct Node{
  int x1;
  int y1;
  int x2;
  int y2;
  Node* next;
  
  Node(){
    next = NULL;
  }
  
  Node(int nx1,int ny1,int nx2,int ny2,Node* nnext){
    x1 = nx1;
    y1 = ny1;
    x2 = nx2;
    y2 = ny2;
    next = nnext;
  }
  
};

int id2int(char id){
  if(id>='a' && id<='z'){
    return id-'a';
  }
  if(id>='A' && id<='Z'){
    return id-'A'+26;
  }
  if(id>='0' && id<='9'){
    return id-'0'+52;
  }
  return -1;
}

Node* coverOne(Node* orig, int x1, int y1, int x2, int y2){
  if(orig==NULL){
    return orig;
  }
  else{
    if(x1>=orig->x2 || x2<=orig->x1 || y1>=orig->y2 || y2<=orig->y1){
      return orig;
    }
    else{      
      Node* newn = orig->next;
      int newx1=orig->x1, newx2=orig->x2;
      if(x1>orig->x1){
        newn = new Node(orig->x1,orig->y1,x1,orig->y2,newn);
        newx1 = x1;
      }
      if(x2<orig->x2){
        newn = new Node(x2,orig->y1,orig->x2,orig->y2,newn);
        newx2 = x2;
      }
      if(y1>orig->y1){
        newn = new Node(newx1,orig->y1,newx2,y1,newn);        
      }
      if(y2<orig->y2){
        newn = new Node(newx1,y2,newx2,orig->y2,newn);
      }
      delete orig;
      return newn;
    }
  }
}

Node* cover(Node* orig, int x1, int y1, int x2, int y2){
  if(orig == NULL){
    return NULL;
  }
  else{
    orig->next = cover(orig->next,x1,y1,x2,y2);
    return coverOne(orig,x1,y1,x2,y2);
  }
}

int calc(Node* w){
  if(w==NULL){
    return 0;
  }
  else{
    // cout<<w->x1<<' '<<w->y1<<' '<<w->x2<<' '<<w->y2<<endl;
    return (w->x2-w->x1)*(w->y2-w->y1)+calc(w->next);
  }
}

int main(){
  FILE* fin;
  ofstream fout("window.out");
  fin = fopen("window.in","r");

  char windows[MAXW];
  int pos[MAXW][4]={0},wcount = 0;
  while(true){
    char op,id;
    int x1,y1,x2,y2;
    //cout<<"here"<<endl;
    if(fscanf(fin,"%c",&op)!=EOF){//???
      // cout<<op<<endl;
      if(op=='w'){
        fscanf(fin,"(%c,%d,%d,%d,%d)\n",&id,&x1,&y1,&x2,&y2);
        
        if(pos[id2int(id)][0]!=pos[id2int(id)][2]){// already exists
          int tpos = -1;
          for(int i=0;i<wcount;i++){
            if(windows[i]==id){
              tpos = i;
              break;
            }
          }
          for(int i=tpos;i<wcount-1;i++){                
            windows[i] = windows[i+1];
          }
          wcount--;
        }
       
        windows[wcount++] = id;
        pos[id2int(id)][0] = x1<x2?x1:x2;
        pos[id2int(id)][1] = y1<y2?y1:y2;
        pos[id2int(id)][2] = x2>x1?x2:x1;
        pos[id2int(id)][3] = y2>y1?y2:y1;
        // cout<<"add new window "<<id<<" wcount "<<wcount<<endl;
        // for(int i=0;i<wcount;i++){
        //   cout<<windows[i];
        // }
        // cout<<endl;
      }
      else{
        fscanf(fin,"(%c)\n",&id);
        if(op=='t'){
          int tpos = -1;
          for(int i=0;i<wcount;i++){
            if(windows[i]==id){
              tpos = i;
              break;
            }
          }          
          for(int i=tpos;i<wcount-1;i++){                
            windows[i] = windows[i+1];
          }
          windows[wcount-1] = id;

          // cout<<"t("<<id<<")"<<endl;
          // for(int i=0;i<wcount;i++){
          //   cout<<windows[i];
          // }
          // cout<<endl;
        }
        else{
          if(op=='b'){
            int tpos = -1;
            for(int i=0;i<wcount;i++){
              if(windows[i]==id){
                tpos = i;
                break;
              }
            }
            for(int i=tpos;i>0;i--){
              windows[i] = windows[i-1];
            }
            windows[0] = id;
            // cout<<"b("<<id<<")"<<endl;
            // for(int i=0;i<wcount;i++){
            //   cout<<windows[i];
            // }
            // cout<<endl;
          }
          else{
            if(op=='d'){
              int tpos = -1;
              for(int i=0;i<wcount;i++){
                if(windows[i]==id){
                  tpos = i;
                  break;
                }
              }
              for(int i=tpos;i<wcount-1;i++){                
                windows[i] = windows[i+1];
              }
              wcount--;
              // cout<<"d("<<id<<")"<<endl;
              // for(int i=0;i<wcount;i++){
              //   cout<<windows[i];
              // }
              // cout<<endl;
            }
            else{
              //s
              Node *w = new Node(pos[id2int(id)][0],pos[id2int(id)][1],pos[id2int(id)][2],pos[id2int(id)][3],NULL);
              for(int i=wcount-1;i>=0;i--){
                if(windows[i]==id)
                  break;
                else{
                  w = cover(w,pos[id2int(windows[i])][0],pos[id2int(windows[i])][1],pos[id2int(windows[i])][2],pos[id2int(windows[i])][3]);
                }
              }
              // cout<<"s("<<id<<")"<<endl;
              int newsize = calc(w);
              double ratio = round((newsize/(double)((pos[id2int(id)][2]-pos[id2int(id)][0])*(pos[id2int(id)][3]-pos[id2int(id)][1])))*100000)/1000.0;
              fout<<fixed<<setprecision(3)<<ratio<<endl;//?????
              // cout<<ratio<<endl;
            }
          }
        }
      }
    }
    else
      break;
  }
  return 0;
}
