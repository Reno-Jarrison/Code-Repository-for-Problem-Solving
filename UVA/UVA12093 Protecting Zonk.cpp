#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
vector<int>e[maxn];
int dp[maxn][4],a,b;
void link(int u,int v)
{	e[u].push_back(v),e[v].push_back(u); }
void dfs(int u,int f)
{
	dp[u][0]=dp[u][3]=0,dp[u][1]=a,dp[u][2]=b;
	int sum=0,tmp=0x7fffffff;
	for(int v:e[u]) if(v!=f)
	{
		dfs(v,u);
		int mnv=min({dp[v][0],dp[v][1],dp[v][2]});
		dp[u][0]+=dp[v][1];
		dp[u][1]+=mnv;
		dp[u][2]+=min(mnv,dp[v][3]);
		dp[u][3]+=mnv;
		sum+=mnv,tmp=min(tmp,dp[v][2]-mnv);
	}
	dp[u][1]=min(dp[u][1],sum+tmp);
}
int main()
{
	int n,u,v;
	while(scanf("%d%d%d",&n,&a,&b)&&n)
	{
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++)
			scanf("%d%d",&u,&v),link(u,v);
		dfs(1,0),printf("%d\n",min({dp[1][0],dp[1][1],dp[1][2]}));
	}
}