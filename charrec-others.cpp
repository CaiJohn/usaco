/*
  ID:remijoh1
  LANG:C++11
  TASK:charrec
*/
#include <fstream>
#include <iostream>
#include <cstring>
#define ma 0x7fffffff-10000
#define len 1205
#define ll 40
using namespace std;
ifstream fin_("font.in");
ifstream fin("charrec.in");
ofstream fout("charrec.out");
struct re{
	string st;
	long da;
	re(){da=ma;}
};
struct r{
	long da;
	char ch;
};
string mode[len/20][ll],a[len];
int f[len/20][len][ll]={0},n=0,t=0;
r c[len][ll]={0};re cost[len+ll];
long ok(long l1,long l2,long k){
	long sum=0;
	for(long i=0;i<=19;i++)
		if(a[l1][i]!=mode[k][l2][i])sum++;
	return sum;
}
int main(int argc,char** argv){
	long n1=0;
	fin_ >>n1;fin_.get();
	t=n1/20;
	for(long i=0;i<=len-1;i++)
		c[i][19].da=c[i][20].da=c[i][21].da=ma;
	for(long i=1;i<=t;i++)
		for(long j=1;j<=20;j++)
			getline(fin_,mode[i][j]);
	fin >>n;fin.get();
	for(long i=1;i<=n;i++)
		getline(fin,a[i]);
	for(long k=1;k<=t;k++)
		for(long i=1;i<=n;i++)	
			for(long j=1;j<=20;j++)
				f[k][i][j]=ok(i,j,k);
	for(long i=1;i<=n;i++){
		long l1,l2,l3;l1=l2=l3=0x7fffffff;
		char c1,c2,c3;
		for(long k=1;k<=t;k++){
			if(i+18<=n){
				long pre[25]={0},tail[25]={0};
				for(long j=1;j<=19;j++){
					long yy=21-j;
					pre[j]=pre[j-1]+f[k][i+j-1][j];
					tail[j]=tail[j-1]+f[k][i+19-j][yy];
				}
				long temp=0x7fffffff;
				for(long j=0;j<=19;j++)
					temp=min(temp,pre[j]+tail[19-j]);
				if(temp<l1){l1=temp;c1='a'+k-2;}
			}
			if(i+19<=n){
				long sum=0;
				for(long j=1;j<=20;j++)
					sum+=f[k][i+j-1][j];
				if(sum<l2){l2=sum;c2='a'+k-2;}
			}
			if(i+20<=n){
				long pre[25]={0},tail[25]={0};
				for(long j=1;j<=20;j++){
					long yy=21-j;
					pre[j]=pre[j-1]+f[k][i+j-1][j];
					tail[j]=tail[j-1]+f[k][i+21-j][yy];
				}
				long temp=0x7fffffff;
				for(long j=1;j<=20;j++)
					temp=min(temp,pre[j]+tail[20-j]);
				if(temp<l3){l3=temp;c3='a'+k-2;}
			}
		}
		c[i][19].da=l1;c[i][19].ch=c1;c[i][19+1].da=l2;c[i][19+1].ch=c2;c[i][19+2].da=l3;c[i][19+2].ch=c3;
	}
	for(long i=n-18;i>=1;i--){
		long min=ma;string ss;
		for(long j=19;j<=21;j++)
			if(cost[i+j].da+c[i][j].da<min)
				{min=cost[i+j].da+c[i][j].da;ss=cost[i+j].st+c[i][j].ch;}
		cost[i].da=min;cost[i].st=ss;
	}
	string ans=cost[1].st;
	ans=ans.assign(ans.rbegin(),ans.rend());
	for(size_t i=0;i<ans.length();i++)
		if(ans[i]<'a')cout <<' ';else cout<<ans[i];
	cout <<endl;
	fin.close();fout.close();fin_.close();
	return 0;
}
