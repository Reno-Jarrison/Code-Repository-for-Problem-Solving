#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5,inf=0x3f3f3f3f;
struct edge
{
	int to,w;
	edge(int to,int w):to(to),w(w){}
};
int idx[maxn],dis[maxn],vis[maxn];
vector<edge>e[maxn];
struct node
{
	int x,d;
	node(int x,int d):x(x),d(d){}
};
bool operator <(const node& a,const node& b)
{	return a.d>b.d; }
void link(int u,int v,int w)
{	e[u].push_back(edge(v,w)); }
void dijstra(int s)
{
	priority_queue<node>hp;
	memset(dis,inf,sizeof(dis));
	memset(vis,0,sizeof(vis));
	hp.push(node(s,0)),dis[s]=0;
	while(!hp.empty())
	{
		int u=hp.top().x; hp.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto x:e[u])
		{
			int v=x.to,w=x.w;
			if(vis[v]||dis[u]+w>=dis[v]) continue;
			dis[v]=dis[u]+w;
			hp.push(node(v,dis[v]));
		}
	}
}
int main()
{
	int m,s,t,u,v,w;
	while(~scanf("%d%d%d",&m,&s,&t))
	{
		int n=0;
		memset(idx,0,sizeof(idx));
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			if(!idx[u]) idx[u]=++n;
			if(!idx[v]) idx[v]=++n;
			link(idx[u],idx[v],w);
			link(idx[v],idx[u],w);
		}
		for(int i=1;i<=s;i++)
		{
			scanf("%d",&u);
			if(!idx[u]) idx[u]=++n;
			link(0,idx[u],0);
		}
		dijstra(0);
		int ans=inf;
		for(int i=1;i<=t;i++)
		{
			scanf("%d",&u);
			if(!idx[u]) idx[u]=++n;
			ans=min(ans,dis[idx[u]]);
		}
		printf("%d\n",ans);
		for(int i=0;i<=n;i++) e[i].clear();
	}
}