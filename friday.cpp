/*
ID: remijoh1
LANG: C++
TASK: friday
*/
/*

为什么会出现count忘了加的情况？？？？？？

 */
#include<iostream>
#include<fstream>
using namespace std;

int main(){
  ifstream fin("friday.in");
  ofstream fout("friday.out");

  int year_num;
  fin >> year_num;

  int count = 2;
  int result[7] = {0};
  for(int year_count = 0;year_count<year_num;year_count++){
    int year = year_count + 1900;

    for(int month=1;month<=12;month++){
      int day_num;
      if(month==9||month==4||month==6||month==11){
	day_num = 30;
      }
      else{
	if(month==2){
	  if((year%4==0 && year%100!=0)||(year%400==0)){
	    day_num = 29;
	  }
	  else{
	    day_num = 28;
	  }
	}
	else{
	  day_num = 31;
	}
      }
      for(int day_count = 1;day_count<=day_num;day_count++){
	if(count>=7){
	  count = count % 7;
	}
	if(day_count==13){
	  result[count] ++;
	}
	count++;
      }
    }
  }
  for(int i=0;i<7;i++){
    fout<<result[i];
    if(i==6){
      fout<<endl;
    }
    else{
      fout<<' ';
    }
  }
  return 0;
  
}
