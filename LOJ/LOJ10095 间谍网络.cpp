#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
const int maxn=3e3+5,inf=0x3f3f3f3f;
vector<int>e[maxn],g[maxn];
stack<int>s;
int idx,sid,dfn[maxn],low[maxn],scc[maxn],ind[maxn];
int flag[maxn],cost[maxn],sw[maxn],tag1[maxn],tag2[maxn],mid[maxn];
void tarjan(int u)
{
	dfn[u]=low[u]=++idx,s.push(u);
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i];
		if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if(!scc[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		int& w=sw[++sid]=inf; 
		mid[sid]=inf;
		while(true)
		{
			int x=s.top(); s.pop();
			scc[x]=sid,mid[sid]=min(mid[sid],x);
			if(flag[x]) tag1[sid]=true,w=min(w,cost[x]);
			if(u==x) break;
		}
	}
}
void shrink(int n)
{
	for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i);
	for(int u=1;u<=n;u++)
		for(int i=0;i<(int)e[u].size();i++)
		{
			int v=e[u][i];
			if(scc[u]!=scc[v]) 
				g[scc[u]].push_back(scc[v]),ind[scc[v]]++;
		}
}
void dfs(int u,int t)
{
	t|=tag1[u],tag2[u]|=t;
	for(int i=0;i<(int)g[u].size();i++) dfs(g[u][i],t);
}
int main()
{
	int n,p,r,u,v;
	scanf("%d%d",&n,&p);
	for(int i=1;i<=p;i++)
		scanf("%d%d",&u,&v),flag[u]=true,cost[u]=v;
	scanf("%d",&r);
	for(int i=1;i<=r;i++)
		scanf("%d%d",&u,&v),e[u].push_back(v);
	shrink(n);
	int ans=0,ok=1,id=n;
	for(int i=1;i<=sid;i++)
		if(!ind[i]) dfs(i,0),tag1[i]?ans+=sw[i]:ok=false;
	for(int i=1;i<=sid;i++)
		if(!tag2[i]) id=min(id,mid[i]);
	puts(ok?"YES":"NO");
	printf("%d",ok?ans:id);
}