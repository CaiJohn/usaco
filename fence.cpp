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
  // cout<<"del "<<v<<endl;
  if(head==NULL){
    // cout<<"here"<<endl;
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

  // for(int i=0;i<501;i++){
  //   if(edgetable[i]!=NULL){
  //     edge* cur = edgetable[i];
  //     cout<<"v"<<i<<endl;
  //     while(cur!=NULL){
  //       cout<<cur->id<<' ';
  //       cur = cur->next;
  //     }
  //     cout<<endl;
  //   }
  // }

  int degree[501]={0};
  bool tag = true;
  for(int i=0;i<501;i++){
    if(edgetable[i]!=NULL){
      edge* cur = edgetable[i];
      while(cur!=NULL){
        cur = cur->next;
        degree[i]++;
      }
      if((degree[i]&1)==1 && tag==true){
        start = i;
        tag = false;
      }
    }
  }
  //cout<<start<<endl;
  
  int pos = start;
  for(int i=0;i<F;i++){
    //cout<<"!!!"<<i<<endl;
    fout<<pos<<endl;
    edge* cur = edgetable[pos];
    while(true){
      if(cur==NULL){
        cout<<"error!"<<endl;
        return 0;
      }
      else{
        if(degree[cur->id]>=2){          
          break;
        }
        else{
          cout<<i<<' '<<cur->id<<endl;
          if(i==F-1){
            break;
          }
          else{
            cur = cur->next;
          }
          
        } 
      }      
    }
    int next = cur->id;
    degree[pos]--;
    degree[next]--;
    edgetable[pos] = del(edgetable[pos],next);
    edgetable[next] = del(edgetable[next],pos);
    
    // for(int i=0;i<501;i++){
    //   if(edgetable[i]!=NULL){
    //     edge* cur = edgetable[i];
    //     cout<<"v"<<i<<endl;
    //     while(cur!=NULL){
    //       cout<<cur->id<<' ';
    //       cur = cur->next;
    //     }
    //     cout<<endl;
    //   }
    // }
    pos = next;
  }
  fout<<pos<<endl;
  return 0;
}
