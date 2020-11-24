#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=1e4+5;
struct edge
{
	int to,w;
	edge(int to,int w):to(to),w(w){}
};
vector<edge>e[maxn];
void link(int u,int v,int w)
{	e[u].push_back(edge(v,w)),e[v].push_back(edge(u,w)); }
int idx,siz[maxn],son[maxn],vis[maxn],vec[maxn],k;
void getroot(int u,int f,int tot,int& rt)
{
	siz[u]=1,son[u]=0;
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i].to;
		if(v==f||vis[v]) continue;
		getroot(v,u,tot,rt);
		siz[u]+=siz[v];
		son[u]=max(son[u],siz[v]);
	}
	son[u]=max(son[u],tot-siz[u]);
	if(son[u]<son[rt]) rt=u;
}
void dfs(int u,int f,int d)
{
	vec[++idx]=d;
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i].to,w=e[u][i].w;
		if(v==f||vis[v]) continue;
		dfs(v,u,d+w);
	}
}
int solve(int u,int d)
{
	idx=0,dfs(u,0,d);
	int l=1,r=idx,ans=0;
	sort(vec+1,vec+idx+1);
	while(l<=r) vec[l]+vec[r]<=k?ans+=r-l,l++:r--;
	return ans;
}
int dnc(int u)
{
	int ans=solve(u,0);
	vis[u]=1;
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i].to,w=e[u][i].w,rt=0;
		if(vis[v]) continue;
		ans-=solve(v,w);
		getroot(v,u,siz[v],rt);
		ans+=dnc(rt);
	}
	return ans;
}
int main()
{
	int n,u,v,w,rt;
	while(scanf("%d%d",&n,&k)&&n)
	{	
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++)
			scanf("%d%d%d",&u,&v,&w),link(u,v,w);
		memset(vis,0,sizeof(vis));
		memset(son,0,sizeof(son));
		rt=0,son[rt]=n;
		getroot(1,0,n,rt);
		printf("%d\n",dnc(rt));
	}
}