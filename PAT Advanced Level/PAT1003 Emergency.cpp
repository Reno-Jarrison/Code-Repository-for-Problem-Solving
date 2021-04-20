#include<bits/stdc++.h>
using namespace std;
const int maxn=505,inf=0x3f3f3f3f;
int dis[maxn],cnt[maxn],siz[maxn],num[maxn],vis[maxn];
struct edge
{
	int to,w;
	edge(int to,int w):to(to),w(w){}
};
vector<edge>e[maxn];
void link(int u,int v,int w)
{	e[u].emplace_back(v,w),e[v].emplace_back(u,w); }
void dijstra(int src)
{
	memset(dis,inf,sizeof(dis));
	priority_queue<pair<int,int>>hp;
	dis[src]=0,cnt[src]=1,num[src]=siz[src],vis[src]=1;
	hp.push(make_pair(0,src));
	while(!hp.empty())
	{
		int u=hp.top().second; hp.pop();
		vis[u]=true;
		for(auto x:e[u])
		{
			int v=x.to,w=x.w,cur=dis[u]+w;
			if(vis[v]) continue;
			if(cur<dis[v])
			{
				dis[v]=cur,cnt[v]=cnt[u],num[v]=num[u]+siz[v];
				hp.push(make_pair(-dis[v],v));
			}
			else if(cur==dis[v])
				cnt[v]+=cnt[u],num[v]=max(num[v],num[u]+siz[v]);
		}
	}
}
int main()
{
	int n,m,c1,c2,u,v,w;
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	for(int i=0;i<n;i++)
		scanf("%d",&siz[i]);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&u,&v,&w),link(u,v,w);
	dijstra(c1);
	printf("%d %d\n",cnt[c2],num[c2]);
}