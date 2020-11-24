#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int id[maxn],p[maxn*400],pt[805],ans[805][maxn];
void solve(int k)
{
	if(k==0)
	{	id[1]=2,id[2]=1; return; }
	solve(k-1);
	int cnt=0,siz=1<<k,tot=siz*2,ok=0;
	for(int i=1;i<=siz;i++,cnt++)
	{
		if(cnt>1) cnt=0,ok^=1;
		id[i]=id[i]*2-ok;
	}
	ok=cnt=0;
	for(int i=1;i<=siz;i++,cnt++)
	{
		if(cnt>1) cnt=0,ok^=1;
		id[tot-i+1]=id[i]+(ok?1:-1);
	}
}
int main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		int siz=1<<(k+1),tot=siz*n;
		for(int i=1;i<=tot;i++)
			scanf("%d",&p[i]);
		solve(k);
		for(int i=1;i<=siz/2;i++)
			swap(id[i],id[siz-i+1]);
		int cnt=0;
		memset(pt,0,sizeof(pt));
		for(int i=1;i<=siz/4;i++)
		{		
			for(int j=n;j;j--)
			{
				ans[j][id[++pt[j]]]=p[++cnt];
				ans[j][id[++pt[j]]]=p[++cnt];
			}
			for(int j=1;j<=n;j++)
			{
				ans[j][id[++pt[j]]]=p[++cnt];
				ans[j][id[++pt[j]]]=p[++cnt];
			}
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=siz;j++)
				printf("%d%c",ans[i][j],i==n&&j==siz?'\n':' ');
	}
}
