#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int>e[maxn];
int dep[maxn],dp[maxn],d;
void link(int u,int v)
{	e[u].push_back(v),e[v].push_back(u); }
void dfs(int u,int f)
{
	dep[u]=dep[f]+1,dp[u]=0;
	for(int v:e[u]) if(v!=f)
	{
		dfs(v,u);
		d=max(d,dp[u]+dp[v]+1);
		dp[u]=max(dp[u],dp[v]+1);
	}
}
int main()
{
	int t,n,a,b,da,db,u,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d%d",&n,&a,&b,&da,&db);
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++)
			scanf("%d%d",&u,&v),link(u,v);
		dep[0]=-1,d=0,dfs(a,0);
		puts(dep[b]<=da||2*da>=d||2*da>=db?"Alice":"Bob");
	}
}