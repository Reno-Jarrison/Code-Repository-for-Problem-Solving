#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=3e5+5,inf=0x3f3f3f3f;
struct edge
{
	int to,w;
	edge(int to,int w):to(to),w(w){}
};
struct node
{
	int u,v,lca,dis;
	node(int u=0,int v=0,int lca=0,int dis=0):
		u(u),v(v),lca(lca),dis(dis){}
}q[maxn];
vector<edge>e[maxn];
int lg2[maxn]={-1},fat[maxn][25],dep[maxn],dist[maxn];
int d[maxn],dfn[maxn],idx,maxd,mind=inf;
void getlg2()
{	for(int i=1;i<=maxn-5;i++) lg2[i]=lg2[i>>1]+1; }
void dfs(int u,int f)
{
	dep[u]=dep[f]+1,fat[u][0]=f,dfn[++idx]=u;
	for(int i=1;(1<<i)<=dep[u];i++)
		fat[u][i]=fat[fat[u][i-1]][i-1];
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i].to,w=e[u][i].w;
		if(v==f) continue;
		dist[v]=dist[u]+w,dfs(v,u);
	}
}
int getlca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y])
		x=fat[x][lg2[dep[x]-dep[y]]];
	if(x==y) return x;
	for(int i=lg2[dep[x]];i>=0;i--)
		if(fat[x][i]!=fat[y][i])
			x=fat[x][i],y=fat[y][i];
	return fat[x][0];
}
bool check(int t,int n,int m)
{
	int cnt=0;
	memset(d,0,sizeof(d));
	for(int i=1;i<=m;i++)
		if(q[i].dis>t)
			d[q[i].u]++,d[q[i].v]++,d[q[i].lca]-=2,cnt++;
	for(int i=n;i;i--)
	{
		int x=dfn[i],f=fat[x][0]; d[f]+=d[x];
		if(dist[x]-dist[f]+t>=maxd&&d[x]==cnt) return true;
	}
	return false;
}
int main()
{
	int n,m,u,v,w;
	getlg2();
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back(edge(v,w));
		e[v].push_back(edge(u,w));
		mind=max(mind,w);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		int lca=getlca(u,v),dis=dist[u]+dist[v]-dist[lca]*2;
		q[i]=node(u,v,lca,dis),maxd=max(maxd,dis);
	}
	int l=maxd-mind,r=maxd,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid,n,m)) r=mid-1;
		else l=mid+1;
	}
	printf("%d",l);
}