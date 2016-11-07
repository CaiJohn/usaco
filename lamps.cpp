/*
  ID: remijoh1
  LANG: C++
  TASK: lamps
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#define MAXN 100
using namespace std;

int N,C;
int on[MAXN+1],off[MAXN+1];

bool cmp(int a[][MAXN+1], int b[][MAXN+1]){
  for(int i=1;i<=N;i++){
    if(a[N-i+1]>b[N-i+1])
      return true;
  }
  return false;
}

void press(int typ, int state[]){
  switch(typ){
  case 1:
    for(int i=1;i<=N;i++){
      state[i] = 1-state[i];
    }
    break;
  case 2:
    for(int i=1;i<=N;i+=2){
      state[i] = 1-state[i];
    }
    break;
  case 3:
    for(int i=2;i<=N;i+=2){
      state[i] = 1-state[i];
    }
    break;
  case 4:
    for(int i=1;i<=N;i+=3){
      state[i] = 1-state[i];
    }
    break;
  }
  return;
}

int state_to_int(int state[]){
  cout<<"state to int"<<endl;
  for(int i=1;i<=N;i++)
    cout<<state[i];
  cout<<endl;
  int sum = 0;
  for(int i=1;i<=N;i++){
    if(state[N-i+1]==1){
      sum += (1<<(i-1));
    }
  }
  cout<<"state_to_int: "<<sum<<endl;
  return sum;
}

string int_to_state(int num){
  cout<<num<<endl;
  string result;
  for(int i=0;i<N;i++){
    if((num&(1<<i))==0){
      result.insert(result.begin(),'0');
    }
    else{
      result.insert(result.begin(),'1');
    }
  }
  cout<<result<<endl;
  return result;
}

void solve(int cur,int num,int state[],int last,int ans[][101], int &ansl){
  //cout<<"solve"<<endl;
  // for(int i=1;i<=N;i++){
  //   cout<<off[i];
  // }
  // cout<<endl;
  // for(int i=1;i<=N;i++){
  //   cout<<state[i];
  // }
  // cout<<endl;

  if(cur==num){
    for(int i=1;i<=N;i++){
      if(on[i]==1 && state[i]==0)
	return;
    }
    for(int i=1;i<=N;i++){
      if(off[i]==1 && state[i]==1)
	return;
    }
    for(int i=1;i<=N;i++){
      ans[ansl][i] = state[i];
    }
    ansl++;
    //ans[ansl++] = state_to_int(state);
    // cout<<"answer "<<ans[ansl-1]<<endl;
    return;
  }
  else{
    for(int i=last+1;i<=4;i++){
      int tmp[MAXN] = {0};
      for(int m=0;m<=N;m++){
	tmp[m] = state[m];
      }
      press(i,tmp);
      solve(cur+1,num,tmp,i,ans,ansl);
    }
  }
  return;
}


int main(){
  ifstream fin("lamps.in");
  ofstream fout("lamps.out");


  fin>>N>>C;
  // cout<<'N'<<N<<'C'<<C<<endl;
  while(true){
    int tmp;
    fin>>tmp;
    if(tmp==-1)
      break;
    on[tmp] = 1;
  }
  while(true){
    int tmp;
    fin>>tmp;
    // cout<<tmp;
    if(tmp==-1)
      break;
    off[tmp] = 1;
  }

  int state[MAXN+1];
  for(int i=0;i<=MAXN;i++)
    state[i] = 1;

  int ans[10000][101],ansl=0;

  if(C<=4){
    for(int i=0;i<=C;i++){
      solve(0,i,state,0,ans,ansl);
    }
  }
  else{
    if((C&1)==1){
      solve(0,0,state,0,ans,ansl);
      solve(0,1,state,0,ans,ansl);
      solve(0,3,state,0,ans,ansl);
    }
    else{
      solve(0,0,state,0,ans,ansl);
      solve(0,2,state,0,ans,ansl);
      solve(0,4,state,0,ans,ansl);
    }
  }
  if(ansl==0){
    fout<<"IMPOSSIBLE"<<endl;
  }
  else{
    sort(ans[0],ans[ansl],cmp);
    int last = -1;
    for(int i=0;i<ansl;i++){
      //      last = ans[i];
      for(int j=1;j<=N;j++){
	fout<<ans[i][j];
      }
      fout<<endl;
    }
  }
  return 0;
}




/*
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<int> ivector;

void press(int typ, int state[]){

  switch(typ){
  case 1:
    for(int i=1;i<=N;i++){
      state[i] = 1-state[i];
    }
    break;
  case 2:
    for(int i=1;i<=N;i+=2){
      state[i] = 1-state[i];
    }
    break;
  case 3:
    for(int i=2;i<=N;i+=2){
      state[i] = 1-state[i];
    }
    break;
  case 4:
    for(int i=1;i<=N;i+=3){
      state[i] = 1-state[i];
    }
    break;
  }
  // cout<<"press"<<typ<<endl;
  // for(int i=1;i<=N;i++){
  //   cout<<i<<' '<<state[i]<<endl;
  // }
  // cout<<endl;
  return;
}

int state_to_int(int state[]){
  int sum = 0;
  for(int i=1;i<=N;i++){
    if(state[i]==1){
      sum += (1<<(i-1));
    }
  }
  // cout<<"state_to_int: "<<sum<<endl;
  return sum;
}

string int_to_state(int num){
  string result;
  for(int i=0;i<N;i++){
    if((num&(1<<i))==0){
      result.insert(result.begin(),'0');
    }
    else{
      result.insert(result.begin(),'1');
    }
  }
  return result;
}

void solve(int cur,int num,int state[],int last,int ans[]){
  // cout<<"search"<<num<<last<<endl;
  // for(int i=1;i<=N;i++){
  //   cout<<state[i];
  // }
  // cout<<endl;
  // for(int i=1;i<=N;i++){
  //   cout<<off[i];
  // }
  // cout<<endl;
    
  if(cur==num){
    for(int i=1;i<=N;i++){
      if(on[i]==1 && state[i]==0)
	return;
    }
    for(int i=1;i<=N;i++){
      if(off[i]==1 && state[i]==1)
	return;
    }
    ans->push_back(state_to_int(state));
  }
  else{
    for(int i=last+1;i<=4;i++){
      int tmp[1000 = state;
      press(i,tmp);
      solve(cur+1,num,tmp,i,ans);
    }
  }
  return;
}
    
int main(void){
  ifstream fin("lamps.in");
  ofstream fout("lamps.out");


  fin>>N>>C;
  cout<<'N'<<N<<'C'<<C<<endl;
  while(true){
    int tmp;
    fin>>tmp;
    if(tmp==-1)
      break;
    on[tmp] = 1;
  }
  while(true){
    int tmp;
    fin>>tmp;
    cout<<tmp;
    if(tmp==-1)
      break;
    off[tmp] = 1;
  }

  ivector state(N+1,1);
  ivector *ans = new ivector();
  if((C&1)==1){
    solve(0,0,state,0,ans);
    solve(0,1,state,0,ans);
    solve(0,3,state,0,ans);
  }
  else{
    solve(0,0,state,0,ans);
    solve(0,2,state,0,ans);
    solve(0,4,state,0,ans);
  }
  // for(ivector::iterator it=ans->begin();it!=ans->end();it++){
  //   cout<<*it<<endl;
  // }

  cout<<"off"<<endl;
  for(int i=1;i<=N;i++){
    cout<<off[i];
  }
  cout<<endl;
  sort(ans->begin(),ans->end());
  int last = -1;
  for(ivector::iterator it=ans->begin();it!=ans->end();it++){
    if(*it==last)
      continue;
    last = *it;
    //cout<<*it<<endl;
    fout<<int_to_state(*it)<<endl;
  }
  return 0;
}
*/
