#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=105,inf=0x3f3f3f3f;
int f[maxn];
int find(int x)
{	return x==f[x]?x:f[x]=find(f[x]); }
struct edge
{	int u,v,w; }e[maxn*maxn];
bool operator <(const edge& x,const edge& y)
{	return x.w<y.w; }
int kruskal(int beg,int n,int m)
{
	int cnt=0,pt=beg;
	for(int i=1;i<=n;i++) f[i]=i;
	while(pt<=m&&cnt<n-1)
	{
		int fx=find(e[pt].u),fy=find(e[pt].v); pt++;
		if(fx==fy) continue;
		f[fx]=fy,cnt++;
	}
	return cnt==n-1?e[pt-1].w-e[beg].w:inf;
}
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m)&&n)
	{
		int ans=inf;
		for(int i=1;i<=m;i++)
			scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		sort(e+1,e+m+1); 
		for(int i=1;i<=m;i++) ans=min(ans,kruskal(i,n,m));
		if(ans==inf) ans=-1;
		printf("%d\n",ans);
	}
}