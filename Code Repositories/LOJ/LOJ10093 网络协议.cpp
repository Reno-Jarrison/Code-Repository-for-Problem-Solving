#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
const int maxn=105;
vector<int>e[maxn],g[maxn];
stack<int>s;
int idx,sid,dfn[maxn],low[maxn],scc[maxn];
int ind[maxn],otd[maxn];
void tarjan(int u)
{
	dfn[u]=low[u]=++idx,s.push(u);
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
	for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i);
	for(int u=1;u<=n;u++)
		for(int i=0;i<(int)e[u].size();i++)
		{
			int v=e[u][i];
			if(scc[u]!=scc[v])
			{
				g[scc[u]].push_back(scc[v]);
				ind[scc[v]]++,otd[scc[u]]++;
			}
		}
}
int main()
{
	int n,in=0,out=0;
	scanf("%d,",&n);
	for(int u=1,v;u<=n;u++)
		while(scanf("%d",&v)&&v)
			e[u].push_back(v);
	shrink(n);
	for(int i=1;i<=sid;i++)
		in+=!ind[i],out+=!otd[i];
	printf("%d\n%d",in,sid==1?0:max(in,out));
}