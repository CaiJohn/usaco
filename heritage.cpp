/*
  ID: remijoh1
  LANG: C++11
  TASK: heritage
*/
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

ifstream fin("heritage.in");
ofstream fout("heritage.out");

void postorder(string intree, int ifrom,int ito,string pretree,int pfrom,int pto){
  if(ifrom==ito){
    return;
  }
  else{
    char root = pretree[pfrom];
    int rootpos = -1;
    for(int i=ifrom;i<ito;i++){
      if(intree[i]==root){
	rootpos = i;
	break;
      }
    }
    int lsize = rootpos-ifrom, rsize = ito-rootpos-1;
    postorder(intree,ifrom,rootpos,pretree,pfrom+1,pfrom+lsize+1);
    postorder(intree,rootpos+1,ito,pretree,pfrom+lsize+1,pfrom+lsize+rsize+1);
    fout<<root;
    return;
  }
}

int main(){
  string inorder,preorder;
  fin>>inorder>>preorder;
  postorder(inorder,0,inorder.length(),preorder,0,preorder.length());
  fout<<endl;
  return 0;
}

  
