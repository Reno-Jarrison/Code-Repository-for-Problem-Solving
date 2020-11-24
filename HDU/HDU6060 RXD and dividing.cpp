#include<cstdio>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=1e6+5;
struct edge
{
	int to,w;
	edge(int to,int w):to(to),w(w){}
};
vector<edge>e[maxn];
void link(int u,int v,int w)
{	e[u].push_back(edge(v,w)),e[v].push_back(edge(u,w)); }
ll ans;
int siz[maxn];
void dfs(int u,int f,int k)
{
	siz[u]=1;
	for(edge x:e[u])
	{
		int v=x.to,w=x.w;
		if(v==f) continue;
		dfs(v,u,k),siz[u]+=siz[v];
		ans+=1LL*w*min(siz[v],k);
	}
}
int main()
{
	int n,k,u,v,w;
	while(~scanf("%d%d",&n,&k))
	{
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++)
			scanf("%d%d%d",&u,&v,&w),link(u,v,w);
		ans=0,dfs(1,0,k);
		printf("%lld\n",ans);
	}
}