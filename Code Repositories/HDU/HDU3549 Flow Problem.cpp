#include<bits/stdc++.h>
using namespace std;
const int maxn=20,inf=0x3f3f3f3f;
struct edge
{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
};
vector<edge>e;
vector<int>g[maxn];
int etot,dis[maxn],cur[maxn],vis[maxn];
void link(int u,int v,int w)
{
	e.push_back(edge(u,v,w));
	e.push_back(edge(v,u,0));
	g[u].push_back(etot++);
	g[v].push_back(etot++);
}
bool bfs(int s,int t)
{
	memset(dis,inf,sizeof(dis));
	memset(vis,0,sizeof(vis));
	queue<int>que;
	que.push(s),vis[s]=1,dis[s]=0;
	while(!que.empty())
	{
		int u=que.front(); que.pop();
		for(int i=0;i<(int)g[u].size();i++)
		{
			int id=g[u][i],v=e[id].v,w=e[id].w;
			if(!vis[v]&&w)
				que.push(v),vis[v]=1,dis[v]=dis[u]+1;
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
int main()
{
	int t,n,m,u,v,w,ks=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		e.clear(),etot=0;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=m;i++)
			scanf("%d%d%d",&u,&v,&w),link(u,v,w);
		printf("Case %d: %d\n",++ks,dinic(1,n));
	}
}