/*
ID: remijoh1
LANG: C++11
TASK: milk
*/


#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

struct p{
  int price;
  int amount;
};
bool cmp(p a, p b){
  return a.price<b.price;
}

int main(){
  ifstream fin("milk.in");
  ofstream fout("milk.out");

  int need, num;
  p farmer[5001];
  fin>>need>>num;

  for(int i=0;i<num;i++){
    fin>>farmer[i].price>>farmer[i].amount;
  }
  sort(farmer,farmer+num,cmp);

  int money = 0;
  int buy;
  for(int i=0;i<num;i++){
    buy = need>farmer[i].amount?farmer[i].amount:need;
    money += buy * farmer[i].price;
    need -= buy;
    if(need<=0)
      break;
  }

  fout<<money<<endl;
  return 0;
}
  
   
