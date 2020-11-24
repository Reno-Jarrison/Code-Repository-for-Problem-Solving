#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
const ll mod=1e9+7;
int f[maxn][21];
int find(int x,int p)
{	return f[x][p]==x?x:f[x][p]=find(f[x][p],p); }
void merge(int x,int y,int p)
{
	int fx=find(x,p),fy=find(y,p);
	if(fx!=fy) f[fx][p]=fy;
}
int main()
{
	int n,m,l1,r1,l2,r2,fst=1;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=20;j++) f[i][j]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		for(int j=20;~j;j--)
			if(l1+(1<<j)-1<=r1)
				merge(l1,l2,j),l1+=1<<j,l2+=1<<j;
	}
	for(int i=20;i;i--)
		for(int j=1;j+(1<<i)-1<=n;j++)
		{
			int fx=find(j,i),len=1<<(i-1);
			merge(j,fx,i-1);
			merge(j+len,fx+len,i-1);
		}
	ll ans=1;
	for(int i=1;i<=n;i++)
		if(find(i,0)==i)
			ans=ans*(fst?9:10)%mod,fst=0;
	printf("%lld",ans);
}