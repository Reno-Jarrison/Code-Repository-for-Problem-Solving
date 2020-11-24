#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
struct edge
{
	int to; ll w;
	edge(int to,ll w):to(to),w(w){}
};
vector<edge>e[maxn];
int dep[maxn],fat[maxn][20],lg2[maxn]={-1};
int dfn[maxn],xid[maxn],idx;
ll dis[maxn],ans,w;
set<int>st;
set<int>::iterator it;
void link(int u,int v,ll w)
{	e[u].push_back(edge(v,w)),e[v].push_back(edge(u,w)); }
void getlg2(int n)
{	for(int i=1;i<=n;i++) lg2[i]=lg2[i>>1]+1; }
void dfs(int u,int f)
{
	dep[u]=dep[f]+1,fat[u][0]=f;
	dfn[u]=++idx,xid[idx]=u;
	for(int i=1;(1<<i)<=dep[u];i++)
		fat[u][i]=fat[fat[u][i-1]][i-1];
	for(edge x:e[u]) if(x.to!=f) 
		dis[x.to]=dis[u]+x.w,dfs(x.to,u);
}
int getlca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y])
		x=fat[x][lg2[dep[x]-dep[y]]];
	if(x==y) return x;
	for(int i=lg2[dep[x]];~i;i--)
		if(fat[x][i]!=fat[y][i])
			x=fat[x][i],y=fat[y][i];
	return fat[x][0];
}
ll getdis(int x,int y)
{	return dis[x]+dis[y]-dis[getlca(x,y)]*2; }
int getpre(int u)
{
	it=st.find(dfn[u]);
	if(it==st.begin())
		it=st.end();
	return xid[*(--it)];
}
int getsuc(int u)
{
	it=++st.find(dfn[u]);
	if(it==st.end())
		it=st.begin();
	return xid[*it];
}
int main()
{
	int n,m,u,v;
	char o[3];
	scanf("%d",&n);
	getlg2(maxn-5);
	for(int i=1;i<n;i++)
		scanf("%d%d%lld",&u,&v,&w),link(u,v,w);
	dfs(1,0);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%s",o);
		if(o[0]=='+')
		{
			scanf("%d",&u);
			if(st.count(dfn[u])) continue;
			st.insert(dfn[u]);
			int l=getpre(u),r=getsuc(u);
			ans+=getdis(l,u)+getdis(r,u)-getdis(l,r);
		}
		if(o[0]=='-')
		{
			scanf("%d",&u);
			if(!st.count(dfn[u])) continue;
			int l=getpre(u),r=getsuc(u);
			ans-=getdis(l,u)+getdis(r,u)-getdis(l,r);
			st.erase(dfn[u]);
		}
		if(o[0]=='?') printf("%lld\n",ans/2);
	}
}