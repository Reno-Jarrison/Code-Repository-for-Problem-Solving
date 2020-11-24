#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn=205,inf=0x3f3f3f3f;
struct edge
{
	int u,v,w,c;
	edge(int u,int v,int w,int c):
		u(u),v(v),w(w),c(c){}
};
vector<edge>e;
vector<int>g[maxn];
int ecnt,dis[maxn],pre[maxn],mnf[maxn];
bool inq[maxn];
void link(int u,int v,int w,int c)
{
	e.push_back(edge(u,v,w,c));
	e.push_back(edge(v,u,0,-c));
	g[u].push_back(ecnt++);
	g[v].push_back(ecnt++);
}
bool spfa(int s,int t)
{
	memset(dis,inf,sizeof(dis));
	memset(mnf,inf,sizeof(mnf));
	memset(inq,0,sizeof(inq));
	queue<int>q;
	q.push(s),inq[s]=true,dis[s]=0;
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		inq[u]=false;
		for(int i=0;i<(int)g[u].size();i++)
		{
			int id=g[u][i],v=e[id].v;
			if(e[id].w&&dis[v]>dis[u]+e[id].c)
			{
				dis[v]=dis[u]+e[id].c;
				pre[v]=id,mnf[v]=min(mnf[u],e[id].w);
				!inq[v]?q.push(v),inq[v]=true:false;
			}
		}
	}
	return dis[t]<inf;
}
void mcmf(int s,int t,int& flow,int& cost)
{
	flow=cost=0;
	while(spfa(s,t))
	{
		flow+=mnf[t],cost+=mnf[t]*dis[t];
		for(int i=t;i!=s;i=e[pre[i]].u)
			e[pre[i]].w-=mnf[t],e[pre[i]^1].w+=mnf[t];
	}
}
void init(int n)
{
	ecnt=0,e.clear();
	for(int i=0;i<=n+1;i++) g[i].clear();
}
int main()
{
	int n,flow,cost;
	while(~scanf("%d",&n)&&n)
	{
		init(n<<1);
		int s=0,t=2*n+1,v,w;
		for(int u=1;u<=n;u++)
		{
			link(s,u,1,0),link(n+u,t,1,0);
			while(scanf("%d",&v)&&v)
				scanf("%d",&w),link(u,n+v,1,w);
		}
		mcmf(s,t,flow,cost);
		if(flow!=n) puts("N");
		else printf("%d\n",cost);
	}
}