#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn=105,inf=0x3f3f3f3f;
struct edge
{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
};
vector<edge>e;
vector<int>g[maxn];
int ecnt,dis[maxn],cur[maxn],cnt[maxn][maxn];
bool vis[maxn];
void link(int u,int v,int w)
{
	e.push_back(edge(u,v,w));
	e.push_back(edge(v,u,0));
	g[u].push_back(ecnt++);
	g[v].push_back(ecnt++);
}
bool bfs(int s,int t)
{
	memset(dis,inf,sizeof(dis));
	memset(vis,0,sizeof(vis));
	queue<int>q;
	q.push(s),vis[s]=true,dis[s]=0;
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<(int)g[u].size();i++)
		{
			int id=g[u][i],v=e[id].v;
			if(!vis[v]&&e[id].w)
				q.push(v),vis[v]=true,dis[v]=dis[u]+1;
		}
	}
	return vis[t];
}
int dfs(int u,int t,int flow)
{
	if(u==t||!flow) return flow;
	int ans=0,tmp;
	for(int& i=cur[u];i<(int)g[u].size();i++)
	{
		int id=g[u][i],v=e[id].v,w=e[id].w;
		if(dis[v]==dis[u]+1&&(tmp=dfs(v,t,min(flow,w))))
		{
			e[id].w-=tmp,e[id^1].w+=tmp;
			flow-=tmp,ans+=tmp;
			if(!flow) break;
		}
	}
	return ans;
}
int dinic(int s,int t)
{
	int ans=0;
	while(bfs(s,t))
		memset(cur,0,sizeof(cur)),ans+=dfs(s,t,inf);
	return ans;
}
void init(int n,int m)
{
	ecnt=0,e.clear();
	for(int i=0;i<=n+m;i++) g[i].clear();
	memset(cnt,0,sizeof(cnt));
}
int main()
{
	int T,n,m,k,x,ks=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		init(n,m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&k);
			for(int j=1;j<=k;j++)
				scanf("%d",&x),cnt[i][x]++;
		}
		int s=0,t=m+n;
		for(int i=1;i<=m;i++)
		{
			link(s,i,cnt[0][i]),link(i,t,1);
			for(int j=1;j<n;j++)
				cnt[j][i]?link(m+j,i,cnt[j][i]-1):link(i,m+j,1);
		}
		printf("Case #%d: %d\n",++ks,dinic(s,t));
	}
}