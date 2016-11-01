/*
ID: remijoh1
LANG: C++
TASK: wormhole
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
int sum = 0;

bool cmp(pair<int,int> a, pair<int,int> b){
  return a.first<b.first;
}


bool check_help(vector< pair<int,int> > one,vector<pair<int,int> > zero, int len){

  for(int start = 0;start<len;start++){
    // cout<<"check_help:"<<start<<endl;
    int next=-1;
    int cur = start;

    for(int i=0;i<len;i++){
      for(vector<pair<int,int> >::iterator it=one.begin();it!=one.end();it++){
	if(it->first == cur){
	  next = it->second;
	  break;
	}
      }

      for(vector<pair<int,int> >::iterator it=zero.begin();it!=zero.end();it++){
	if(it->first == next){
	  next = it->second;
	  break;
	}
      }

      if(next==start)
	{
	  return true;
	}
      if(next==-1)
	break;
      cur = next;
      next = -1;
    }
  }
  return false;
}
      
  
//   if(len>15)
//     return false;
//   if(cur==start)
//     return true;
  
//   vector<pair<int,int> > cur;

//   // why vector<pair<int,int> > *cur ; is not working???
//   cur = 
  
//   int newf=-1,newt=-1;
//   for(vector<pair<int,int> >::iterator it=cur.begin();it!=cur.end();it++){
//     // if(it->first == from && it->second == to){
//     //   return true;
//     // }
//     if(it->first == from){
// 	newf = it->second;
//     }
//     // if(it->second == to && visited[it->first] == 0){
//     // 	newt = it->first;
//     // }
//   }
//   if(type==0)
//     return check_help(one,zero,1,newf,to,len+1);
//   else
//     return check_help(one,zero,0,newf,to,len+1);

//   // if(type==1 && newf==5 && newt==1){
//   //   for(vector<pair<int,int> >::iterator it=cur.begin();it!=cur.end();it++){
//   //     cout<<it->first<<' '<<it->second<<endl;
//   //   }
//   // }

//   // cout<<"ch"<<newf<<' '<<newt<<endl;
//   // if(newt==from || newf==to){
//   //   return true;
//   // }
//   // else{
//   //   if(newf==-1 || newt==-1){
//   //     return false;
//   //   }
//   //   else{
//   //     return check_help(one,zero,1-type,newf,newt,visited,len+1);
//   //   }
//   // }
//   // return false;
// }
  
// bool check(vector<pair<int,int> > one,vector<pair<int,int> > two){
//   for(vector<pair<int,int> >::iterator it=one.begin();it!=one.end();it++){
//     int visited[15] = {0};
//     cout<<"check path"<<it->second<<' '<<it->first<<endl;
//     if(check_help(one,two,0,it->second,it->first,0))
//       return true;
//   }
//   return false;
// }

void search(vector<pair<int,int> > one, vector<pair<int,int> > two, int N, int cur, int tag[], int *result){

  if(cur==N){
    sum ++;
    if(check_help(one,two,N)==true){
      (*result) ++;
    }
    else{
      // cout<<"check here"<<endl;
      sort(two.begin(),two.end(),cmp);
      // for(vector<pair<int,int> >::iterator it=two.begin();it!=two.end();it++){
      // 	cout<<it->first<<' '<<it->second<<endl;
      // }
    }
    return;
  }
  else{
    int left;
    for(int i=0;i<N;i++){
      if(tag[i]==0){
	left = i;
	break;
      }
    }
    tag[left] = 1;
    for(int i=left+1;i<N;i++){
      if(tag[i]==0){
	tag[i]=1;
	// cout<<"search"<<' '<<left<<' '<<i<<endl;
	two.push_back(make_pair(left,i));
	two.push_back(make_pair(i,left));
	search(one,two,N,cur+2,tag,result);
	tag[i]=0;
	two.pop_back();
	two.pop_back();
      }
    }
    tag[left] = 0;
    return;
  }
}

int main(){

  ifstream fin("wormhole.in");
  ofstream fout("wormhole.out");

  int pos[12][2],N;
  
  fin>>N;

  for(int i=0;i<N;i++){
    fin>>pos[i][0]>>pos[i][1];
  }

  vector<pair<int, int > > one,zero;
  // Set 1 edge
  for(int i=0;i<N;i++){
    int t = -1;
    for(int j=0;j<N;j++){
      if(j==i)
	continue;
      if(pos[j][1]==pos[i][1]){
	if(pos[j][0]>pos[i][0]){
	  if(t==-1||pos[t][0]>pos[j][0]){
	    t = j;
	  }
	}
      }
    }
    if(t!=-1){
      one.push_back(make_pair(i,t));
    }
  }
  // for(vector<pair<int,int> >::iterator it=one.begin();it!=one.end();it++){
  //   cout<<it->first<<' '<<it->second<<endl;
  // }
  int result = 0,tag[100]={0};
  search(one,zero,N,0,tag,&result);
  // cout<<sum<<endl;
  fout<<result<<endl;
  return 0;
}
