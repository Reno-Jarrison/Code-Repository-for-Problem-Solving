#include<cstdio>
#include<vector>
using namespace std;
const int maxn=1e5+5;
struct edge
{
	int to,w;
	edge(int to,int w):to(to),w(w){}
};
vector<edge>e[maxn];
int dp[maxn];
void link(int u,int v,int w)
{	e[u].push_back(edge(v,w)),e[v].push_back(edge(u,w)); }
void dfs(int u,int f,int& d)
{
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i].to,w=e[u][i].w;
		if(v==f) continue;
		dfs(v,u,d);
		d=max(d,dp[u]+dp[v]+w);
		dp[u]=max(dp[u],dp[v]+w);
	}
}
int main()
{
	int n,s,ans=0,d=0,u,v,w;
	scanf("%d%d",&n,&s);
	for(int i=1;i<n;i++)
		scanf("%d%d%d",&u,&v,&w),ans+=w,link(u,v,w);
	dfs(1,0,d);
	printf("%d\n",ans*2-d);
}