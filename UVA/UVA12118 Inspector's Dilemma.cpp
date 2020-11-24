#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
vector<int>e[maxn];
int idx,deg[maxn],col[maxn],cnt[maxn],siz[maxn];
void link(int u,int v)
{
	e[u].push_back(v);
	e[v].push_back(u);
	deg[u]++,deg[v]++;
}
void dfs(int u,int tag)
{
	col[u]=tag,cnt[tag]+=deg[u]&1,siz[tag]++;
	for(int v:e[u])
		if(!col[v]) dfs(v,tag);
}
int main()
{
	int n,m,t,u,v,ks=0;
	while(scanf("%d%d%d",&n,&m,&t)&&n)
	{
		for(int i=1;i<=n;i++)
			e[i].clear(),deg[i]=col[i]=cnt[i]=siz[i]=0;
		for(int i=1;i<=m;i++)
			scanf("%d%d",&u,&v),link(u,v);
		idx=0;
		for(int i=1;i<=n;i++)
			if(!col[i]) dfs(i,++idx);
		int ans=0;
		for(int i=1;i<=idx;i++)
		{
			if(siz[i]==1) continue;
			ans+=max(0,cnt[i]/2-1)+1;
		}
		ans=max(0,ans-1)+m;
		printf("Case %d: %d\n",++ks,ans*t);
	}
}