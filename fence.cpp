/*
ID: remijoh1
LANG: C++11
TASK: fence
*/
#include<iostream>
#include<fstream>
using namespace std;

struct edge{
  int id;
  edge* next;
};

edge* insert(edge* head,edge* e){
  if(head==NULL){
    return e;
  }
  else{
    if(head->id<e->id){
      head->next = insert(head->next,e);
      return head;
    }
    else{
      e->next = head;
      return e;
    }
  }
}

edge* del(edge* head, int v){
  if(head==NULL){
    return head;
  }
  else{
    if(head->id>v){
      return head;
    }
    else{
      if(head->id==v){
	edge* tmp = head->next;
	delete head;
	return tmp;
      }
      else{
	head->next = del(head->next,v);
	return head;
      }
    }
  }
}

int main(){
  ifstream fin("fence.in");
  ofstream fout("fence.out");
  int F;
  edge* edgetable[501];
  for(int i=0;i<=500;i++)
    edgetable[i] = NULL;
  fin>>F;
  int start = 501;
  for(int i=0;i<F;i++){
    int from,to;
    fin>>from>>to;
    if(from<start || to<start){
      start = from<to?from:to;
    }
    //cout<<from<<' '<<to<<endl;
	
    edge* nedge = new edge();
    nedge->id = to;
    nedge->next = NULL;
    edgetable[from] = insert(edgetable[from],nedge);

    nedge = new edge();
    nedge->id = from;
    nedge->next = NULL;

    edgetable[to] = insert(edgetable[to],nedge);

  }

  for(int i=0;i<501;i++){
    if(edgetable[i]!=NULL){
      edge* cur = edgetable[i];
      cout<<"v"<<i<<endl;
      while(cur!=NULL){
	cout<<cur->id<<' ';
	cur = cur->next;
      }
      cout<<endl;
    }
  }

  
  edge* e = edgetable[start];
  int degree = 0;
  while(e!=NULL){
    degree++;
    e = e->next;
  }
  degree /= 2;
  degree--;
  int pos = start;
  for(int i=0;i<F;i++){
    edge* cur = edgetable[pos];
    while(true){
      if(cur->id!=start)
	break;
      else{
	if(degree==0){
	  if(i==F-1)
	    break;
	  else{
	    cur = cur->next;
	  }
	}
	else{
	  degree--;
	  break;
	}
      }
    }
    cout<<pos<<' '<<cur->id<<endl;
    edgetable[pos] = del(edgetable[pos],cur->id);
    edgetable[cur->id] = del(edgetable[cur->id],pos);
    for(int i=0;i<501;i++){
      if(edgetable[i]!=NULL){
	edge* cur = edgetable[i];
	cout<<"v"<<i<<endl;
	while(cur!=NULL){
	  cout<<cur->id<<' ';
	  cur = cur->next;
	}
	cout<<endl;
      }
    }
    pos = cur->id;
  }
  return 0;
}
