#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
const int maxn=205;
const double eps=1e-7,inf=1e12;
struct edge
{
	int u,v,w; double c;
	edge(int u,int v,int w,double c):
		u(u),v(v),w(w),c(c){}
};
vector<edge>e;
vector<int>g[maxn],eto[maxn];
int ecnt,pre[maxn],mnf[maxn];
double dis[maxn];
bool inq[maxn];
int px[maxn],py[maxn],ind[maxn],otd[maxn];
void link(int u,int v,int w,double c)
{
	e.push_back(edge(u,v,w,c));
	e.push_back(edge(v,u,0,-c));
	g[u].push_back(ecnt++);
	g[v].push_back(ecnt++);
}
void init(int n)
{
	ecnt=0,e.clear();
	memset(ind,0,sizeof(ind));
	memset(otd,0,sizeof(otd));
	for(int i=0;i<=n;i++) 
		g[i].clear(),eto[i].clear();
}
bool spfa(int s,int t)
{
	memset(mnf,0x3f,sizeof(mnf));
	memset(inq,0,sizeof(inq));
	for(int i=0;i<=t;i++) dis[i]=inf;
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
	return fabs(dis[t]-inf)>eps;
}
double mcmf(int s,int t)
{
	double cost=0;
	while(spfa(s,t))
	{
		cost+=dis[t]*mnf[t];
		for(int i=t;i!=s;i=e[pre[i]].u)
			e[pre[i]].w-=mnf[t],e[pre[i]^1].w+=mnf[t];
	}
	return cost;
}
double getdis(int a,int b)
{	return sqrt(pow(px[a]-px[b],2)+pow(py[a]-py[b],2)); }
int main()
{
	int n,wx,wy,to,ks=0;
	while(scanf("%d",&n)&&n)
	{
		int s=0,t=n+1; double ans=0;
		init(n+1);
		scanf("%d%d",&wx,&wy);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&px[i],&py[i]);
			while(scanf("%d",&to)&&to)
				eto[i].push_back(to);
		}
		for(int u=1;u<=n;u++)
			for(int i=0;i<(int)eto[u].size();i++)
			{
				int v=eto[u][i];
				double c=wy-getdis(u,v)*wx;
				if(c>0) link(u,v,1,c); 
				else link(v,u,1,-c),ans+=c,ind[v]++,otd[u]++;
			}
		for(int i=1;i<=n;i++)
		{
			if(ind[i]>otd[i]) link(s,i,ind[i]-otd[i],0);
			if(ind[i]<otd[i]) link(i,t,otd[i]-ind[i],0);
		}
		ans=-ans-mcmf(s,t);
		if(fabs(ans)<eps) ans=0.0;
		printf("Case %d: %.2lf\n",++ks,ans);
	}
}