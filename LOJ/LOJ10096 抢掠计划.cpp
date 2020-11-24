#include<cstdio>
#include<vector>
#include<stack>
#include<queue>
#define ll long long
using namespace std;
const int maxn=5e5+5;
int idx,sid,dfn[maxn],low[maxn],scc[maxn],tag[maxn];
ll w[maxn],sw[maxn],dis[maxn];
bool inq[maxn];
vector<int>e[maxn],g[maxn];
stack<int>s;
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
		sid++;
		while(true)
		{
			int x=s.top(); s.pop();
			scc[x]=sid,sw[sid]+=w[x];
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
				g[scc[u]].push_back(scc[v]);
		}
}
void spfa(int s)
{
	queue<int>q;
	q.push(s),inq[s]=true,dis[s]=sw[s];
	while(!q.empty())
	{
		int u=q.front();
		q.pop(),inq[u]=false;
		for(int i=0;i<(int)g[u].size();i++)
		{
			int v=g[u][i];
			if(dis[v]<dis[u]+sw[v])
			{
				dis[v]=dis[u]+sw[v];
				if(!inq[v]) q.push(v),inq[v]=true;
			}
		}
	}
}
int main()
{
	int n,m,u,v,s,p;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&u,&v),e[u].push_back(v);
	for(int i=1;i<=n;i++)
		scanf("%lld",&w[i]);
	scanf("%d%d",&s,&p);
	for(int i=1;i<=p;i++)
		scanf("%d",&tag[i]);
	shrink(n),spfa(scc[s]);
	ll ans=0;
	for(int i=1;i<=p;i++)
		ans=max(ans,dis[scc[tag[i]]]);
	printf("%lld",ans);
}