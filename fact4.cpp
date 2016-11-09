/*
  ID: remijoh1
  LANG: C++11
  TASK: fact4
*/
#include<iostream>
#include<fstream>
using namespace std;

// int solve(int num){
//   cout<<num<<endl;
//   if(num<=2 && num>0){
//     return num;
//   }
//   else{
//     int tmp = solve(num-1);
//     int count5 = 0;
//     while(num%5==0){
//       count5++;
//       num /= 5;
//     }
//     for(int i=0; tmp%2 ==0 && i<count5;i++){
//       tmp /= 2;
//       if(tmp==1)
// 	break;
//     }
//     cout<<num<<' '<<tmp<<endl;
//     return (num*tmp)%10;
//   }
// }

int solve(int num, int count5,int result){
  if(num==1 && num>0)
    return result;
  else{
    int tmp = num;
    while(num%5==0){
      count5++;
      num /= 5;
    }
    while(num%2==0&&count5>0){
      num /= 2;
      count5--;
    }
    return solve(tmp-1,count5,(result*num)%10);
  }
}

int main(void){
  ifstream fin("fact4.in");
  ofstream fout("fact4.out");

  int N;
  fin>>N;
  fout<<solve(N,0,1)<<endl;
  return 0;
}
  
