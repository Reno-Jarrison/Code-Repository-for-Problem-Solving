#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5,maxm=1e5+5;
struct edge
{	int u,v,w; }e[maxm];
bool operator <(const edge& a,const edge& b)
{	return a.w>b.w; }
int f[maxn],tag[maxn];
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)&&n)
	{
		for(int i=0;i<n;i++) f[i]=i,tag[i]=0;
		for(int i=1;i<=m;i++)
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		sort(e+1,e+m+1);
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			int fu=find(e[i].u),fv=find(e[i].v);
			if(fu!=fv&&!(tag[fu]&&tag[fv])) 
				f[fu]=fv,ans+=e[i].w,tag[fv]|=tag[fu];
			else if(fu==fv&&!tag[fu]) ans+=e[i].w,tag[fu]=1;
		}
		printf("%d\n",ans);
	}
}