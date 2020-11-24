#include<cstdio>
#include<vector>
#include<stack>
#include<cstring>
using namespace std;
const int maxn=2e4+5;
vector<int>e[maxn],g[maxn];
stack<int>s;
int idx,sid,dfn[maxn],low[maxn],scc[maxn];
int ind[maxn],otd[maxn];
void tarjan(int u)
{
	dfn[u]=low[u]=++idx;
	s.push(u);
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i];
		if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if(!scc[v]) low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		sid++;
		while(true)
		{
			int x=s.top(); s.pop();
			scc[x]=sid;
			if(x==u) break;
		}
	}
}
void shrink(int n)
{
	idx=sid=0;
	memset(dfn,0,sizeof(dfn));
	memset(scc,0,sizeof(scc));
	memset(ind,0,sizeof(ind));
	memset(otd,0,sizeof(otd));
	for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i);
	for(int u=1;u<=n;u++)
		for(int i=0;i<(int)e[u].size();i++)
		{
			int v=e[u][i];
			if(scc[u]!=scc[v])
			{
				g[scc[u]].push_back(scc[v]);
				otd[scc[u]]++,ind[scc[v]]++;
			}
		}
}
int main()
{
	int t,n,m,u,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) e[i].clear(),g[i].clear();
		for(int i=1;i<=m;i++)
			scanf("%d%d",&u,&v),e[u].push_back(v);
		shrink(n);
		int in=0,out=0;
		for(int i=1;i<=sid;i++)
		{
			if(!ind[i]) in++;  
			if(!otd[i]) out++;	
		}
		printf("%d\n",sid==1?0:max(in,out));
	}
}