#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn=405,inf=0x3f3f3f3f;
struct edge
{
	int u,v,w,c;
	edge(int u,int v,int w,int c):
		u(u),v(v),w(w),c(c){}
};
int a[maxn],dct[maxn],aw[maxn];
int ecnt,dis[maxn],pre[maxn],mnf[maxn];
bool inq[maxn];
vector<edge>e;
vector<int>g[maxn];
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
	q.push(s),inq[s]=true,dis[s]=0,mnf[s]=inf;
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
int main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
			scanf("%d%d%d",&a[i<<1],&a[i<<1|1],&aw[i]);
		for(int i=0;i<n<<1;i++) dct[i]=a[i];
		sort(dct,dct+(n<<1));
		int uni=unique(dct,dct+(n<<1))-dct;
		for(int i=0;i<n<<1;i++)
			a[i]=lower_bound(dct,dct+uni,a[i])-dct+1;
		ecnt=0,e.clear();
		for(int i=0;i<=uni+1;i++) g[i].clear();
		for(int i=0;i<=uni;i++) link(i,i+1,k,0);
		for(int i=0;i<n;i++)
			link(a[i<<1],a[i<<1|1],1,-aw[i]);
		int flow,cost;
		mcmf(0,uni+1,flow,cost);
		printf("%d\n",-cost);
	}
}
