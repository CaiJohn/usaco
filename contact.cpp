/*
  ID: remijoh1
  LANG: C++11
  TASK: contact
*/
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
struct F{
  int freq;
  int pattern;
};
bool cmp(F a, F b){
  if(a.freq>b.freq){
    return true;
  }
  else{
    if(a.freq==b.freq)
      return a.pattern<b.pattern;
    else
      return false;
  }
}
    
int string_to_int(string s){

  int len = s.length();
  int sum = 0;
  for(int i=0;i<len;i++){
    if(s[i]=='1'){
      sum += (1<<(len-1-i));
    }
  }
  //cout<<s<<' '<<sum<<endl;  
  return sum;
}

string int_to_pattern(int num){
  string result ;
  //  cout<<"int to pattern:"<<num<<' ';  
  while(num>0){
    int r = num%2;
    result.insert(result.begin(),r+'0');
    num /= 2;
  }
  //cout<<result<<endl;
  return result.substr(1,result.length()-1);
      
}

int main(){
  ifstream fin("contact.in");
  ofstream fout("contact.out");
  int A,B,N;
  fin>>A>>B>>N;
  string s,tmp;
  getline(fin,tmp);
  while(!fin.eof()){
    getline(fin,tmp);
    s += tmp;    
  }
  //cout<<s<<endl;
  int len = s.length();
  F frequency[10000];
  for(int i=0;i<10000;i++){
    frequency[i].freq = 0;
    frequency[i].pattern = i;
  }

  for(int l=A;l<=B;l++){
    for(int i=0;i<=len-l;i++){
      frequency[string_to_int("1"+s.substr(i,l))].freq++;
    }
  }
  
  //cout<<frequency[11].freq<<endl;
  
  sort(frequency,frequency+10000,cmp);
  // for(int i=0;i<100;i++)
  //   cout<<frequency[i].freq<<endl;

  int cur = 0,pos=0,last=-1;

  if(frequency[0].freq==0)
    return 0;
  // Printing...
  do{
    last = frequency[pos].freq;
    fout<<frequency[pos].freq<<endl;
    int tmp = pos;
    int count = 0;
    while(frequency[pos].freq==last){
      if(count>0 && count<6)
	fout<<' ';
      if(count==6){
	fout<<endl;
	count = 0;
      }
      fout<<int_to_pattern(frequency[pos++].pattern);
      count++;
    }
    fout<<endl;
    cur++;
  }while(cur<N && frequency[pos].freq!=0);

  
  // while(true){
  //   if(cur>N || frequency[pos].freq==0)
  //     break;
  //   if(frequency[pos].freq!=last){
  //     last = frequency[pos].freq;
  //     cout<<frequency[pos].freq<<endl;
  //     cout<<int_to_pattern(frequency[pos].pattern)<<endl;
  //     cur++;
  //   }
  //   else{
  //     cout<<int_to_pattern(frequency[pos].pattern)<<endl;
  //   }
  //   pos ++;
  // }
  
  return 0;
}
