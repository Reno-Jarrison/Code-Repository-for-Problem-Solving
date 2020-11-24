#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int dp[maxn][3],col[maxn];
vector<int>e[maxn];
void link(int u,int v)
{	e[u].push_back(v),e[v].push_back(u); }
void dfs(int u,int f)
{
	if(e[u].size()==1) dp[u][col[u]]=0;
	else memset(dp[u],0,sizeof(dp[u]));
	for(int i=0;i<e[u].size();i++) if(e[u][i]!=f)
	{
		int v=e[u][i];
		dfs(v,u);
		dp[u][0]+=min(dp[v][0]-1,dp[v][1]);
		dp[u][1]+=min(dp[v][0],dp[v][1]-1);
		dp[u][2]+=min(dp[v][0],dp[v][1]);
	}
	dp[u][0]++,dp[u][1]++;
}
int main()
{
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&col[i]);
	for(int i=1;i<n;i++)
		scanf("%d%d",&u,&v),link(u,v);
	memset(dp,0x3f,sizeof(dp));
	dfs(1,0);
	printf("%d",dp[1][col[1]]);
}