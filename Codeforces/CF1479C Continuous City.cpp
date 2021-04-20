#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-x))
using namespace std;
const int maxn=500;
int u[maxn],v[maxn],w[maxn];
void link(int a,int b,int c,int id)
{	u[id]=a,v[id]=b,w[id]=c; }
int count(int x)
{
	int cnt=0;
	while(x) x>>=1,cnt++;
	return cnt;
}
int main()
{
	int l,r,lim,x;
	scanf("%d%d",&l,&r);
	puts("YES");
	x=l-1,r-=l-1,lim=r;
	while(lim>lowbit(lim))
		lim-=lowbit(lim);
	int cnt=count(lim),n=cnt+(r>lim)+1,m=0;
	for(int i=2;i<=cnt+1;i++)
	{
		link(1,i,1,++m);
		for(int j=i+1;j<=cnt+1;j++)
			link(i,j,1<<(i-2),++m);
	}
	if(r>lim)
	{
		link(1,n,1,++m);
		int tmp=r-1;
		for(int i=0;i<cnt;i++)
			if(tmp&(1<<i))
				tmp-=1<<i,link(i+2,n,tmp+1,++m);
	}
	if(l>1) link(n,n+1,x,++m),n++;
	printf("%d %d\n",n,m);
	for(int i=1;i<=m;i++)
		printf("%d %d %d\n",u[i],v[i],w[i]);
}