#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
const int maxn=105;
vector<int>e[maxn];
stack<int>stk;
int idx,sid,dfn[maxn],low[maxn],scc[maxn];
int ind[maxn],otd[maxn];
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
			scc[x]=sid;
			if(x==u) break;
		}
	}
}
void tarjan(int n)
{
	for(int i=1;i<=n;i++)
		if(!dfn[i]) dfs(i);
	for(int u=1;u<=n;u++)
		for(int i=0;i<(int)e[u].size();i++)
		{
			int v=e[u][i];
			if(scc[u]==scc[v]) continue;
			otd[scc[u]]++,ind[scc[v]]++;
		}
}
int main()
{
	int n,x,in=0,out=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		while(scanf("%d",&x)&&x)
			e[i].push_back(x);
	tarjan(n);
	for(int i=1;i<=sid;i++)
	{
		if(!otd[i]) out++;
		if(!ind[i]) in++;
	}
	int ans1=in,ans2=sid==1?0:max(in,out);
	printf("%d\n%d\n",ans1,ans2);
}