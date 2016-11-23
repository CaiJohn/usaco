/*
ID: remijoh1
LANG: C++11
TASK: lgame
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

struct Tree{
  char c;
  bool done;
  Tree* next;
  Tree* child;
};

struct Record{
  int type;
  string one;
  string two;
};

void printTree(Tree* root){
  cout<<root->c;
  if(root->done == true)
    cout<<"*";
  cout<<"(";
  Tree* child = root->child;
  while(child!=NULL){
    printTree(child);
    child = child->next;
  }
  cout<<")";
  return;
}


void insert(Tree* root,string s){
  // cout<<"insert "<<s<<endl;
  if(s.length()==0){
    root->done = true;
    return;
  }
  
  Tree* child = root->child;
  bool tag = false;
  while(true){
    if(child==NULL)
      break;
    else{
      if(child->c == s[0]){
	tag = true;
	insert(child,s.substr(1,s.length()-1));
	break;
      }
      else{
        child = child->next;
      }
    }
  }
  if(tag == false){
    Tree* ntree = new Tree();
    ntree->c = s[0];
    ntree->done = false;
    ntree->child = NULL;
    insert(ntree,s.substr(1,s.length()-1));

    if(root->child == NULL){
      root->child = ntree;
    }
    else{
      Tree* tmp = (root->child)->next;
      (root->child)->next = ntree;
      ntree->next = tmp;
    }
  }
  return;
}

int match(Tree* root, string s, int cur, int result[], int count){
  if(root->done == true){
    result[count++] = cur;// cur is length
  }
  if(s.length()==0){
    return count;
  }
  else{
    Tree* child = root->child;
    while(true){
      if(child == NULL)
	break;
      else{
	if(child->c == s[0]){
	  return match(child,s.substr(1,s.length()-1),cur+1,result,count);
	}
	child = child->next;
      }
    }
  }
  return count;
}

string cantor(int num, string word, int fac[]){
  int len = word.length();
  int visited[10] = {0};
  string result;
  for(int i=0;i<len;i++){
    int count = num/fac[len-i-1], pos=1;
    // cout<<"count "<<count<<" num "<<num<<" fac "<<fac[len-i-1];
    while(true){
      while(true){
        if(visited[pos]==1)
          pos++;
        else
          break;
      }
      if(count==0)
	break;
      count--;
      pos++;
    
    }
    // cout<<" pos "<<pos<<endl;
    //cout<<pos;
    visited[pos] = 1;
    result.insert(result.end(),1,word[pos-1]);
    num %= fac[len-i-1];
  }
  
  return result;
}

bool cmp(Record a, Record b){
  if(a.one<b.one){
    return true;
  }
  else{
    if(a.one==b.one){
      if(a.type==1 && b.type==2){
	return true;
      }
      else{
	if(a.type==2 && b.type==1){
	  return false;
	}
	else{
	  return a.two<b.two;
	}
      }
    }
    else{
      return false;
    }
  }
}

int calc(string s){
  int table[26] = {2,5,4,4,1,6,5,5,1,7,6,3,5,2,3,5,7,2,1,2,4,6,6,7,5,7};
  int len = s.length(),score = 0;
  for(int i=0;i<len;i++){
    score += table[s[i]-'a'];
  }
  return score;
}
int main(){

  // Tree test;
  // insert(&test,"test");
  // printTree(&test);
  // insert(&test,"te");
  // printTree(&test);
  // insert(&test,"apple");
  // insert(&test,"testing");
  // printTree(&test);
  // insert(&test,"terrific");
  // insert(&test,"apply");
  // printTree(&test);
  // cout<<endl;

  // int testresult[10],tcount = 0;;
  // tcount = match(&test,"apply",0,testresult,0);
  // tcount = match(&test,"test",0,testresult,0);
  // tcount = match(&test,"testingy",0,testresult,0);
  // for(int i=0;i<tcount;i++){
  //   cout<<testresult[i]<<' ';
  // }
  // cout<<endl;
  // int factest[8] = {1,1,2,6,24,120,720,5040};
  // for(int i=0;i<120;i++){
  //   cout<<cantor(i,"12345",factest)<<endl;
  // }

  
  // return 0;


  
  ifstream fin("lgame.in");
  ofstream fout("lgame.out");
  string word,letters;
  fin>>letters;
  
  ifstream fdict("lgame.dict");
  
  Tree dict;
  
  while(true){
    fdict>>word;
    if(word==".")
      break;
    else{
      insert(&dict,word);
    }
  }
  //printTree(&dict);
  // int testresult[10],tcount = 0;;
  // tcount = match(&dict,"abackt",0,testresult,0);
  // for(int i=0;i<tcount;i++){
  //   cout<<testresult[i]<<' ';
  // }
  // cout<<endl;
  
  
  int maxScore = 0,rcount = 0;
  Record r[100000];
  int fac[8] = {1,1,2,6,24,120,720,5040},maxPerm = fac[letters.length()];
  
  for(int i=0;i<maxPerm;i++){
    string s = cantor(i,letters,fac);
    int result[10],score;
    int count = match(&dict,s,0,result,0);
    //cout<<"s: "<<s<<endl;
    for(int i=0;i<count;i++){
      string subs1 = s.substr(0,result[i]),subs2 = s.substr(result[i]);
      // cout<<subs1<<' '<<subs2<<endl;
      int tmpr[10];
      int tmpc = match(&dict,subs2,0,tmpr,0);
      if(tmpc == 0){
	score = calc(subs1);
	if(score>maxScore){
	  maxScore = score;
	  r[0].type = 1;
	  r[0].one = subs1;
          r[0].two = "";
	  rcount = 1;
	}
	else{
	  if(score == maxScore){
	    r[rcount].type = 1;
	    r[rcount].one = subs1;
            r[rcount].two = "";
	    rcount++;
	  }
	}
        // cout<<s<<' '<<subs1<<endl;
      }
      else{
        string subs3 = subs2.substr(0,tmpr[tmpc-1]);
	score = calc(subs1+subs3);
	if(score>maxScore){
	  maxScore = score;
	  r[0].type = 2;
          if(subs1>subs3){
            r[0].one = subs3;
            r[0].two = subs1;
          }
          else{
            r[0].one = subs1;
            r[0].two = subs3;
          }
	  rcount= 1;
	}
	else{
	  if(score == maxScore){
	    r[rcount].type = 2;
            if(subs1>subs3){
              r[rcount].one = subs3;
              r[rcount].two = subs1;
            }
            else{
              r[rcount].one = subs1;
              r[rcount].two = subs3;
            }
	    rcount++;
	  }
	}
        // cout<<s<<' '<<subs1<<' '<<subs3<<endl;
      }
    }
  }
  sort(r,r+rcount,cmp);
  fout<<maxScore<<endl;

  string lastone,lasttwo;
  int lasttype = -1;
  for(int i=0;i<rcount;i++){
    //cout<<r[i].type<<' '<<r[i].one<<' '<<r[i].two<<endl;
    if(lasttype==r[i].type && lastone==r[i].one && lasttwo==r[i].two)
      continue;
    lasttype = r[i].type;
    lastone = r[i].one;
    lasttwo = r[i].two;
    if(r[i].type==1){
      fout<<r[i].one;
    }
    else{
      fout<<r[i].one<<' '<<r[i].two;
    }
    fout<<endl;
  }
  return 0;
}
