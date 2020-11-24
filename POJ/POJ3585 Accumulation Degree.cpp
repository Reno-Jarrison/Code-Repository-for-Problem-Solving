#include<cstdio>
#include<iostream>
#include<vector>
#define ll long long
using namespace std;
const int maxn=2e5+5;
const ll inf=1e12;
struct edge
{
	int to; ll w;
	edge(int to,ll w):to(to),w(w){}
};
vector<edge>e[maxn];
ll dp1[maxn],dp2[maxn],deg[maxn];
void link(int u,int v,ll w)
{	e[u].push_back(edge(v,w)),e[v].push_back(edge(u,w)); }
void dfs1(int u,int f)
{
	dp1[u]=0;
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i].to; ll w=e[u][i].w;
		if(v==f) continue;
		dfs1(v,u);
		if(deg[v]==1) dp1[u]+=w;
		else dp1[u]+=min(dp1[v],w);
	}
}
void dfs2(int u,int f)
{
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i].to; ll w=e[u][i].w;
		if(v==f) continue;
		if(deg[u]==1) dp2[v]=dp1[v]+w;
		else dp2[v]=min(w,dp2[u]-min(w,dp1[v]))+dp1[v];
		dfs2(v,u);
	}
}
int main()
{
	int t,n,u,v; ll w;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) 
			e[i].clear(),deg[i]=0;
		for(int i=1;i<n;i++)
		{
			scanf("%d%d%lld",&u,&v,&w);
			link(u,v,w),deg[u]++,deg[v]++;
		}
		dfs1(1,0),dp2[1]=dp1[1],dfs2(1,0);
		ll ans=0;
		for(int i=1;i<=n;i++)
			ans=max(ans,dp2[i]);
		printf("%lld\n",ans);
	}
}