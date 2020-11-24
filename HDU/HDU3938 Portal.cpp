#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5,maxm=5e4+5;
int f[maxn],w[maxn],ans[maxn];
struct edge
{	int u,v,w; }e[maxm];
struct query
{	int id,x; }p[maxn];
bool operator <(const edge& a,const edge& b)
{	return a.w<b.w; }
bool operator <(const query& a,const query& b)
{	return a.x<b.x; }
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
int main()
{
	int n,m,q;
	while(~scanf("%d%d%d",&n,&m,&q))
	{
		for(int i=1;i<=n;i++)
			f[i]=i,w[i]=1;
		for(int i=1;i<=m;i++)
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		for(int i=1;i<=q;i++)
			scanf("%d",&p[i].x),p[i].id=i;
		sort(e+1,e+m+1);
		sort(p+1,p+q+1);
		int cur=0,pt=1;
		for(int i=1;i<=m;i++)
		{
			while(pt<=q&&p[pt].x<e[i].w) ans[p[pt++].id]=cur;
			int fu=find(e[i].u),fv=find(e[i].v);
			if(fu==fv) continue;
			f[fu]=fv,cur+=w[fu]*w[fv],w[fv]+=w[fu];
		}
		while(pt<=q) ans[p[pt++].id]=cur;
		for(int i=1;i<=q;i++)
			printf("%d\n",ans[i]);
	}
}