/*
ID: remijoh1
LANG: C++11
TASK: lgame
*/
#include<iostream>
#include<fstream>
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
}

void insert(Tree* root,string s){
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
      child = child->next;
    }
  }
  if(tag == false){
    Tree* ntree = new Tree();
    ntree->c = s[0];
    ntree->done = false;
    ntree->child = NULL;
    insert(ntree,s.substr(1,s.length()-1));

    if(root->child == NULL){
      root->child = nchild;
    }
    else{
      Node* tmp = (root->child)->next;
      (root->child)->next = nchild;
      nchild->next = tmp;
    }
  }
  return;
}

int match(Tree* root, string s, int cur, int result[], int count){
  if(root->done == true){
    result[count++] = cur;
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

string cantor(int num, int word,int fac[]){
  int len = word.length();
  int visited[10] = {0};
  string result;
  for(int i=0;i<len;i++){
    int count = num/fac[i],pos=1;
    while(true){
      if(count==0)
	break;
      if(visited[pos]==1){
	pos++;
      }
      else{
	count--;
	pos++;
      }
    }
    result.insert(result.end(),1,word[pos]);
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

int main(){
  ifstream fin("lgame.in");
  ofstream fout("lgame.out");

  ifstream fdict("lgame.dict");
  string word;
  Tree dict;
  while(true){
    fdict>>word;
    if(word==".")
      break;
    else{
      insert(&dict,word);
    }
  }

  int maxScore = 0,rcount = 0;
  Record r[10000];
  for(int i=0;i<maxPerm;i++){
    string s = cantor(i,word);
    int result[10];
    int count = match(&dict,s,0,result,0);
    for(int i=0;i<count;i++){
      int tmpr[10];
      int tmpc = match(&dict,word.substr(result[i]),0,tmpr,0);
      if(tmpc == 0){
	score = calc(word.substr(0,result[i]+1));
	if(score>maxScore){
	  maxScore = score;
	  r[0].type = 1;
	  r[0].one = word.substr(0,result[i]+1);
	  rcount = 1;
	}
	else{
	  if(score == maxScore){
	    r[rcount].type = 1;
	    r[rcount].one = word.substr(0,result[i]+1);
	    rcount++;
	  }
	}
      }
      else{
	score = calc(word.substr(0,result[i]+tmpr[tmpc-1]+1));
	if(score>maxScore){
	  maxScore = score;
	  r[0].type = 2;
	  r[0].one = word.substr(0.result[i]+1);
	  r[0].two = word.substr(result[i],tmpr[tmpc-1]);
	  // Normalize the pair...
	  rcoutn = 1;
	}
	else{
	  if(score == maxScore){
	    r[rcount].type = 2;
	    r[rcount].one = word.substr(0,result[i]+1);
	    r[0].two = word.substr(result[i],tmpr[tmpc-1]);
	    rcount++;
	  }
	}
      }
    }
  }
  sort(r,r+rcount,cmp);
  fout<<maxScore<<endl;
  for(int i=0;i<rcount;i++){
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
	
