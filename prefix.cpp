/*
  ID: remijoh1
  LANG: C++
  TASK: prefix
*/

#include<iostream>
#include<fstream>
#include<string>
#include<utility>
#define QSIZE 1
#define MAXLEN 200001
using namespace std;

typedef pair<int,int> ipair;



string s[200],c;
int scount = 0;
int info[MAXLEN];
///////////////////
ipair queue[QSIZE];
int qhead=0,qtail=0;

bool push(ipair i){
  if(qtail+1==qhead)
    return false;
  else{
    queue[qtail] = i;
    if(qtail == QSIZE-1)
      qtail = 0;
    else
      qtail++;
    return true;
  }
}

ipair pop(){
  ipair result = queue[qhead];
  if(qhead == QSIZE-1)
    qhead = 0;
  else
    qhead++;
  return result;
}

bool empty(){
  return qhead == qtail;
}
  

//////////////////


// int match(int from, int to){
//   //cout<<from<<' '<<to<<endl;
//   if(from>=to){
//     return 0;
//   }
//   else{
//     if(info[from]!=-1){
//       cout<<info[from]<<endl;
//       return info[from];
//     }
    
//     int maxLen = 0;
//     for(int i=0;i<scount;i++){
//       if(s[i].length()<=from+c.length()){
//         if(c.substr(from,s[i].length())==s[i]){
//           //cout<<c.substr(from,s[i].length())<<endl;
          
//           int tmp = match(from+s[i].length(),to);
//           if(tmp+s[i].length()>maxLen){
//             maxLen = tmp+s[i].length();
//           }
//         }
//       }
//     }
//     //cout<<maxLen<<endl;
    
//     return maxLen;
//   }
// }

int main(void){
  ifstream fin("prefix.in");
  ofstream fout("prefix.out");

  
  string tmp;
  bool tag = false;
  while(true){
    fin>>tmp;
    if(tmp=="."){
      while(true){
        fin>>tmp;// Why the reading is wired??
        if(fin.eof())
          break;
        //cout<<tmp<<endl;
        c += tmp;
      }
      break;
    }
    s[scount++] = tmp;
  }
  // for(int i=0;i<MAXLEN;i++)
  //   info[i] = -1;
  //cout<<c.length()<<endl;
  info[c.length()]=0;
  int N = c.length();
  for(int i=N-1;i>=0;i--){
    int maxL = 0;
    for(int j=0;j<scount;j++){
      int sjlen = s[j].length();
      if(i+sjlen>N)
        continue;
      if(c.substr(i,sjlen)==s[j]){
        if(maxL<sjlen+info[i+sjlen]){
          maxL = sjlen+info[i+sjlen];
        }
      }
    }
    //cout<<i<<endl;
    info[i] = maxL;
  }
  fout<<info[0]<<endl;
  return 0;
}

  //fout<<match(0,c.length())<<endl;
  // ipair init;
  // init.first = 0;
  // init.second = 0;
  // push(init);
  // int maxLen = 0;
  // int count = 0;
  // while(!empty()){
  //   ipair cur = pop();
  //   if(maxLen<cur.second)
  //     maxLen = cur.second;
    
  //   for(int i=0;i<scount;i++){
  //     if(cur.first+s[i].length()<=c.length()){
  //       if(c.substr(cur.first,s[i].length())==s[i]){
  //         ipair tmpi;
  //         tmpi.first = cur.first+s[i].length();
  //         tmpi.second = cur.second + s[i].length();
  //         if(!push(tmpi)){
  //           cout<<count<<endl;
  //           cout<<"error!"<<endl;
  //           return 0;
  //         }
  //         count++;
  //       }
  //     }
  //   }
  // }
  // cout<<count<<endl;
  // fout<<maxLen<<endl;
  // return 0;
// }
