#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
ll dist[128],p;
int path[128];
bool vis[128];
vector<int>e[128];
struct node
{
	int id; ll w;
	node(int id,ll w):id(id),w(w){}
};
bool operator <(const node& x,const node& y)
{	return x.w>y.w; }
ll getd(ll x)
{	return x+(ll)ceil(x/19.0); }
ll dijkstra(int beg,int end,ll p)
{
	memset(dist,0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	priority_queue<node>q;
	dist[beg]=p,q.push(node(beg,p));
	while(!q.empty())
	{
		int u=q.top().id; q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=0;i<(int)e[u].size();i++)
		{
			int v=e[u][i];
			if(vis[v]) continue;
			ll nowd=(u>='a'?dist[u]+1:getd(dist[u]));
			if(dist[v]>nowd)
				path[v]=u,dist[v]=nowd,q.push(node(v,dist[v]));
			if(dist[v]==nowd) path[v]=min(path[v],u);
		}
	}
	return dist[end];
}
int main()
{ 
	int n,cases=0,u,v,s,t;
	char c[2][3];
	while(scanf("%d",&n)&&n!=-1)
	{
		for(int i='A';i<='z';i++) e[i].clear();
		for(int i=1;i<=n;i++)
		{
			scanf("%s%s",c[0],c[1]);
			u=(int)c[0][0],v=(int)c[1][0];
			e[u].push_back(v),e[v].push_back(u); 
		}
		scanf("%lld%s%s",&p,c[0],c[1]);
		s=(int)c[1][0],t=(int)c[0][0];
		printf("Case %d:\n",++cases);
		printf("%lld\n",dijkstra(s,t,p));
		while(t!=s) printf("%c-",t),t=path[t];
		printf("%c\n",s);
	}
} 