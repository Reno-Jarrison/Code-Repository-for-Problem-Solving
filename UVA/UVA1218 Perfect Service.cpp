#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
vector<int>e[maxn];
int dp[maxn][3];
void link(int u,int v)
{	e[u].push_back(v),e[v].push_back(u); }
void dfs(int u,int f)
{
	dp[u][0]=maxn,dp[u][1]=1,dp[u][2]=0;
	for(int v:e[u]) if(v!=f)
	{
		dfs(v,u);
		dp[u][0]=min(dp[u][0],dp[v][1]-dp[v][0]);
		dp[u][1]+=min(dp[v][2],dp[v][1]);
		dp[u][2]+=dp[v][0];
	}
	dp[u][0]+=dp[u][2];
}
int main()
{
	int n,u,v;
	while(scanf("%d",&n))
	{
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++)
			scanf("%d%d",&u,&v),link(u,v);
		dfs(1,0),printf("%d\n",min(dp[1][0],dp[1][1]));
		scanf("%d",&n);
		if(n==-1) break;
	}
}