/*
  ID: remijoh1
  LANG: C++11
  TASK: snail
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#define MAXN 160
using namespace std;
int direct[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int N,B;
bool map[MAXN][MAXN] = {false};
bool visited[MAXN+1][MAXN+1] = {false};

int search(int curr,int curc,int d,int step){
  //cout<<curr<<' '<<curc<<' '<<d<<endl;
  visited[curr][curc] = true;
  int nextr = curr + direct[d][0], nextc = curc + direct[d][1];
  if(nextr>=N || nextr<0 || nextc>=N || nextc<0 || map[nextr][nextc]==true){
    int newd1 = (d+1)%4, newd2 = (d+3)%4;
    int nr1 = curr + direct[newd1][0], nc1 = curc + direct[newd1][1],max1 = step;
    if(!(nr1>=N || nr1<0 || nc1>=N || nc1<0 || map[nr1][nc1]==true || visited[nr1][nc1]==true))
      max1 = search(nr1,nc1,newd1,step+1);

    int nr2 = curr + direct[newd2][0],nc2 = curc + direct[newd2][1],max2 = step;
    if(!(nr2>=N || nr2<0 || nc2>=N || nc2<0 || map[nr2][nc2]==true || visited[nr2][nc2]==true))
      max2 = search(nr2,nc2,newd2,step+1);


    // if(max1==step && max2 == step){
    //   for(int i=0;i<N;i++){
    // 	for(int j=0;j<N;j++){
    // 	  if(map[i][j]==true){
    // 	    cout<<" #";
    // 	  }
    // 	  else{
    // 	    if(visited[i][j]==true){
    // 	      if(i==curr && j==curc)
    // 		cout<<" $";
    // 	      else
    // 		cout<<" *";
    // 	    }
    // 	    else{
    // 	      cout<<" .";
    // 	    }
    // 	  }
    // 	}
    // 	cout<<endl;
    //   }
    //   cout<<step<<endl;
    // }
    visited[curr][curc] = false;
    int s = max(max1,max2);
    //cout<<"return "<<s<<endl;
			  
    return s;
  }
  else{
    if(visited[nextr][nextc] == true){
      // for(int i=0;i<N;i++){
      // 	for(int j=0;j<N;j++){
      // 	  if(map[i][j]==true){
      // 	    cout<<" #";
      // 	  }
      // 	  else{
      // 	    if(visited[i][j]==true){
      // 	      if(i==curr && j==curc)
      // 		cout<<" $";
      // 	      else
      // 		cout<<" *";
      // 	    }
      // 	    else{
      // 	      cout<<" .";
      // 	    }
      // 	  }
      // 	}
      // 	cout<<endl;
      // }
      // cout<<step<<endl;
      visited[curr][curc] = false;
      return step;
    }
    else{
      int maxstep = search(nextr,nextc,d,step+1);
      visited[curr][curc] = false;
      //cout<<"return "<<maxstep<<endl;
      return maxstep;
    }
  }
}

int main(){
  ifstream fin("snail.in");
  ofstream fout("snail.out");

  fin>>N>>B;
  
  for(int i=0;i<B;i++){
    string tmp;//!!!!!! It is a string...
    fin>>tmp;
    int c = tmp[0]-'A',r=0;    
    for(int j=1;j<tmp.length();j++){
      r = r*10+tmp[j]-'0';
    }
    r--;
    map[r][c] = true;
  }

  // for(int i=0;i<N;i++){
  //   for(int j=0;j<N;j++){
  //     if(map[i][j]==true){
  // 	cout<<"# ";
  //     }
  //     else{
  // 	cout<<". ";
  //     }      
  //   }
  //   cout<<endl;
  // }

  int max1 = search(0,0,1,1);
  // cout<<"max1 "<<max1<<endl;
  int max2 = search(0,0,2,1);
  // cout<<"max2 "<<max2<<endl;
  fout<<max(max1,max2)<<endl;
  return 0;
}
  
