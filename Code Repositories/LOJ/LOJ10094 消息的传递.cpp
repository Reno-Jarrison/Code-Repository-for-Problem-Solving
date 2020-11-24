#include<cstdio>
#include<vector>
#include<stack>
using namespace std;
const int maxn=1e3+5;
int idx,sid,dfn[maxn],low[maxn],scc[maxn];
int e[maxn][maxn],ind[maxn];
stack<int>s;
void tarjan(int u,int n)
{
	dfn[u]=low[u]=++idx,s.push(u);
	for(int v=1;v<=n;v++)
	{
		if(!e[u][v]) continue;
		if(!dfn[v]) tarjan(v,n),low[u]=min(low[u],low[v]);
		else if(!scc[v]) low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		sid++;
		while(true)
		{
			int x=s.top(); s.pop();
			scc[x]=sid;
			if(u==x) break;
		}
	}
}
void shrink(int n)
{
	for(int i=1;i<=n;i++)
		if(!dfn[i]) tarjan(i,n);
	for(int u=1;u<=n;u++)
		for(int v=1;v<=n;v++)
			if(e[u][v]&&scc[u]!=scc[v]) ind[scc[v]]=true;
}
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&e[i][j]);
	shrink(n);
	for(int i=1;i<=sid;i++)
		ans+=!ind[i];
	printf("%d",ans);
}