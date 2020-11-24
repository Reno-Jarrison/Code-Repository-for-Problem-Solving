#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn=2e3+5,inf=0x3f3f3f3f;
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
int mcmf(int s,int t)
{
	int flow=0,cost=0;
	while(spfa(s,t))
	{
		flow+=mnf[t],cost+=mnf[t]*dis[t];
		for(int i=t;i!=s;i=e[pre[i]].u)
			e[pre[i]].w-=mnf[t],e[pre[i]^1].w+=mnf[t];
	}
	return cost;
}
void init(int n)
{
	ecnt=0,e.clear();
	for(int i=0;i<=n;i++) g[i].clear();
}
int main()
{
	int n,m,u,v,w;
	while(~scanf("%d%d",&n,&m))
	{
		init(n<<1),link(1,n+1,2,0);
		for(int i=2;i<n;i++) link(i,n+i,1,0);
		for(int i=1;i<=m;i++)
			scanf("%d%d%d",&u,&v,&w),link(n+u,v,1,w);
		printf("%d\n",mcmf(1,n));
	}
}