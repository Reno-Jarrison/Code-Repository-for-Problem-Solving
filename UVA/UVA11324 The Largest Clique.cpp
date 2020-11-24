#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
const int maxn=1e3+5;
vector<int>e[maxn],g[maxn];
stack<int>s;
int idx,sid,dfn[maxn],low[maxn],scc[maxn];
int ind[maxn],dp[maxn],sw[maxn];
void dfs(int u)
{
	dfn[u]=low[u]=++idx,s.push(u);
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i];
		if(!dfn[v]) dfs(v),low[u]=min(low[u],low[v]);
		else if(!scc[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		sid++;
		while(true)
		{
			int x=s.top(); s.pop();
			scc[x]=sid,sw[sid]++;
			if(x==u) break;
		}
	}
}
void shrink(int n)
{
	idx=sid=0;
	memset(dfn,0,sizeof(dfn));
	memset(scc,0,sizeof(scc));
	memset(sw,0,sizeof(sw));
	for(int i=1;i<=n;i++)
		if(!dfn[i]) dfs(i);
	memset(ind,0,sizeof(ind));
	for(int u=1;u<=n;u++)
		for(int i=0;i<(int)e[u].size();i++)
		{
			int v=e[u][i];
			if(scc[u]!=scc[v])
				g[scc[u]].push_back(scc[v]),ind[scc[v]]++;
		}
}
int main()
{
	int t,n,m,u,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			e[i].clear(),g[i].clear();
		for(int i=1;i<=m;i++)
			scanf("%d%d",&u,&v),e[u].push_back(v);
		shrink(n),memset(dp,0,sizeof(dp));
		queue<int>q;
		for(int i=1;i<=sid;i++)
			if(!ind[i]) q.push(i),dp[i]=sw[i];
		while(!q.empty())
		{
			int u=q.front(); q.pop();
			for(int i=0;i<(int)g[u].size();i++)
			{
				int v=g[u][i];
				dp[v]=max(dp[v],dp[u]+sw[v]);
				if(--ind[v]==0) q.push(v);
			}
		}
		int ans=0;
		for(int i=1;i<=sid;i++)
			ans=max(ans,dp[i]);
		printf("%d\n",ans);
	}
}