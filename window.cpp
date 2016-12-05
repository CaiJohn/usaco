/*
  ID: remijoh1
  LANG: C++11
  TASK: window
*/
#include<iostream>
#include<cstdio>
#include<fstream>
#define MAXW 62
using namespace std;

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

int main(){
  FILE* fin;
  ofstream fout("window.out");
  fin = fopen("window.in");

  char windows[MAXW];
  int pos[MAXW][4],wcount = 0;
  while(true){
    char op,id;
    int x1,y1,x2,y2;
    if(fscanf(fin,"%c",&op)){
      if(op=="w"){
        fscanf(fin,"(%c,%d,%d,%d,%d)\n",&id,&x1,&x2,&x3,&x4);
        windows[wcount++] = id;
        pos[id2int(id)][0] = x1;
        pos[id2int(id)][1] = y1;
        pos[id2int(id)][2] = x2;
        pos[id2int(id)][3] = y2;
      }
      else{
        fscanf(fin,"(%c)\n",&id);
        if(op=='t'){
          int tpos = -1;
          for(int i=0;i<wcount;i++){
            if(windows[i]=='id'){
              tpos = i;
              break;
            }
          }
          for(int i=tpos;i>0;i--){
            char tmp = windows[i];
            windows[i] = windows[i-1];
            windows[i-1] = tmp;
          }
        }
        else{
          if(op=='b'){
            int tpos = -1;
            for(int i=0;i<wcount;i++){
              if(windows[i]=='id'){
                tpos = i;
                break;
              }
            }
            for(int i=tpos;i<wcount-1;i++){
              char tmp = windows[i];
              windows[i] = windows[i+1];
              windows[i+1] = tmp;
            } 
          }
          else{
            if(op=='d'){
              int tpos = -1;
              for(int i=0;i<wcount;i++){
                if(windows[i]=='id'){
                  tpos = i;
                  break;
                }
              }
              for(int i=tpos;i<wcount-1;i--){                
                windows[i] = windows[i+1];
              }
              wcount--;
            }
            else{
              //s
              
              
            }
          }
        }
      }
    }
  }
