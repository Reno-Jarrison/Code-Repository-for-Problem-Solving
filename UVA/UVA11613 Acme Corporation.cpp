#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define ll long long
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
void init(int n)
{
	ecnt=0,e.clear();
	for(int i=0;i<=2*n+1;i++) g[i].clear();
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
		int u=q.front();
		q.pop(),inq[u]=false;
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
	return dis[t]<=0;
}
ll mcmf(int s,int t)
{
	ll flow=0,cost=0;
	while(spfa(s,t))
	{
		flow+=mnf[t],cost+=1LL*mnf[t]*dis[t];
		for(int i=t;i!=s;i=e[pre[i]].u)
			e[pre[i]].w-=mnf[t],e[pre[i]^1].w+=mnf[t];
	}
	return cost;
}
int main()
{
	int T,k,c,m,n,p,s,r,ks=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&k,&c);
		init(k);
		for(int i=1;i<=k;i++)
		{
			scanf("%d%d%d%d%d",&m,&n,&p,&s,&r);
			link(0,i,n,m);
			link(k+i,2*k+1,s,-p);
			for(int j=0;j<=min(r,k-i);j++)
				link(i,k+i+j,inf,c*j);
		}
		printf("Case %d: %lld\n",++ks,-mcmf(0,2*k+1));
	}
}