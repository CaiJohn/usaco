/*
  ID: remijoh1
  LANG: C++
  TASK: preface
*/

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

string translate(int num){
  string result;
  if(num<10){
    switch(num){
    case 1: result = "I"; break;
    case 2: result = "II"; break;
    case 3: result = "III"; break;
    case 4: result = "IV"; break;
    case 5: result = "V"; break;
    case 6: result = "VI"; break;
    case 7: result = "VII"; break;
    case 8: result = "VIII"; break;
    case 9: result = "IX"; break;
    }
    return result;
  }
  else{
    if(num>=10 && num<100){
      int nnum = num/10, r = num%10;
      switch(nnum){
      case 1: result = "X"; break;
      case 2: result = "XX"; break;
      case 3: result = "XXX"; break;
      case 4: result = "XL"; break;
      case 5: result = "L"; break;
      case 6: result = "LX"; break;
      case 7: result = "LXX"; break;
      case 8: result = "LXXX"; break;
      case 9: result = "XC"; break;
      }
      return result+translate(r);
    }
    else{
      if(num>=100 && num<1000){
        int nnum = num/100, r = num%100;
        switch(nnum){
        case 1: result = "C"; break;
        case 2: result = "CC"; break;
        case 3: result = "CCC"; break;
        case 4: result = "CD"; break;
        case 5: result = "D"; break;
        case 6: result = "DC"; break;
        case 7: result = "DCC"; break;
        case 8: result = "DCCC"; break;
        case 9: result = "CM"; break;
        }
        return result + translate(r);
      }
      else{
        int nnum = num/1000, r = num%1000;
        switch(nnum){
        case 1: result = "M"; break;
        case 2: result = "MM"; break;
        case 3: result = "MMM"; break;
        }
        return result+translate(r);
      }
    }
  }
}

int encode(char c){
  switch(c){
  case 'I': return 0;
  case 'V': return 1;
  case 'X': return 2;
  case 'L': return 3;
  case 'C': return 4;
  case 'D': return 5;
  case 'M': return 6;
  }
  return -1;
}

char decode(int c){
  switch(c){
  case 0: return 'I';
  case 1: return 'V';
  case 2: return 'X';
  case 3: return 'L';
  case 4: return 'C';
  case 5: return 'D';
  case 6: return 'M';
  }
  return '?';
}

int main(void){
  ifstream fin("preface.in");
  ofstream fout("preface.out");

  int N;
  fin>>N;

  int stat[7] = {0};
  for(int i=1;i<=N;i++){
    string tmp = translate(i);
    //cout<<tmp<<endl;
    for(string::iterator it=tmp.begin();it!=tmp.end();it++){
      //cout<<*it<<endl;
      stat[encode(*it)]++;
    }
  }

  for(int i=0;i<7;i++){
    if(stat[i]>0){
      fout<<decode(i)<<' '<<stat[i]<<endl;
    }
  }

  return 0;
}
    
