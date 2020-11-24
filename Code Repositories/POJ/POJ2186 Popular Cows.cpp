#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
const int maxn=1e4+5;
vector<int>e[maxn],ex[maxn];
stack<int>stk;
int idx,sid,dfn[maxn],low[maxn],scc[maxn];
int siz[maxn],cnt[maxn];
void dfs(int u)
{
	dfn[u]=low[u]=++idx,stk.push(u);
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
			int x=stk.top(); stk.pop();
			scc[x]=sid,siz[sid]++;
			if(x==u) break;
		}
	}
}
void tarjan(int n)
{
	idx=sid=0;
	while(!stk.empty()) stk.pop();
	fill(dfn,dfn+n+1,0);
	fill(scc,scc+n+1,0);
	fill(siz,siz+n+1,0);
	for(int i=1;i<=n;i++)
		if(!dfn[i]) dfs(i);
	for(int i=1;i<=n;i++) 
		ex[i].clear(),cnt[i]=0;
	for(int u=1;u<=n;u++)
	for(int i=0;i<(int)e[u].size();i++)
		if(scc[u]!=scc[e[u][i]])
		{
			ex[scc[u]].push_back(scc[e[u][i]]);
			cnt[scc[u]]++;
		}
}
int main()
{
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&u,&v),e[u].push_back(v);
	tarjan(n);
	int ans=0,tot=0;
	for(int i=1;i<=sid;i++)
		if(!cnt[i]) ans=siz[i],tot++;
	if(tot>1) ans=0;
	printf("%d\n",ans);
}