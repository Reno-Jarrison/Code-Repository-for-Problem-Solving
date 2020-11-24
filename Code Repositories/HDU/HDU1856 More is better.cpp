#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int f[maxn],g[maxn];
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
int main()
{
	int n,u,v;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n*2;i++)
			f[i]=i,g[i]=1;
		map<int,int>mp;
		int ans=1,idx=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&u,&v);
			if(!mp[u]) mp[u]=++idx;
			if(!mp[v]) mp[v]=++idx;
			int fu=find(mp[u]),fv=find(mp[v]);
			if(fu==fv) continue;
			f[fu]=fv,g[fv]+=g[fu];
			ans=max(ans,g[fv]);
		}
		printf("%d\n",ans);
	}
}