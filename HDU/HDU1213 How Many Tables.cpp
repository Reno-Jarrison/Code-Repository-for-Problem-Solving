#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int f[maxn];
int find(int x)
{	return x==f[x]?x:f[x]=find(f[x]); }
int main()
{
	int t,n,m,u,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) f[i]=i;
		int ans=n;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			int fu=find(u),fv=find(v);
			if(fu==fv) continue;
			f[fu]=fv,ans--;
		}
		printf("%d\n",ans);
	}
}