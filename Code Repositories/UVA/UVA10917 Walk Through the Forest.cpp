#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int maxn=1e3+5,inf=0x3f3f3f3f;
struct edge
{
	int to,w;
	edge(int to,int w):to(to),w(w){}
};
struct node
{
	int id,w;
	node(int id,int w):id(id),w(w){}
};
vector<edge>e[maxn];
int dist[maxn],dp[maxn];
bool vis[maxn];
bool operator <(const node& x,const node& y)
{	return x.w>y.w; }
void dijkstra(int beg)
{
	memset(dist,inf,sizeof(dist));
	memset(vis,0,sizeof(vis));
	priority_queue<node>q;
	dist[beg]=0,q.push(node(beg,0));
	while(!q.empty())
	{
		int u=q.top().id; q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=0;i<(int)e[u].size();i++)
		{
			int v=e[u][i].to,w=e[u][i].w;
			if(vis[v]) continue;
			if(dist[v]>dist[u]+w)
				dist[v]=dist[u]+w,q.push(node(v,dist[v]));
		}
	}
}
int dfs(int u,int end)
{
	if(u==end) return 1;
	if(dp[u]==-1)
	{
		dp[u]=0;
		for(int i=0;i<(int)e[u].size();i++)
		{
			int v=e[u][i].to;
			if(dist[u]>dist[v]) dp[u]+=dfs(v,end);
		}
	}
	return dp[u];
}
int main()
{
	int n,m,u,v,w;
	while(scanf("%d%d",&n,&m)==2&&n)
	{
		for(int i=1;i<=n;i++) e[i].clear();
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			e[u].push_back(edge(v,w));
			e[v].push_back(edge(u,w));
		}
		dijkstra(2);
		printf("%d\n",dfs(1,2));
	}
}
