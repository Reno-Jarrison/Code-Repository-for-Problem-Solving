#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
ll dp[maxn][2];
int w[maxn],to[maxn],vis[maxn];
vector<int>e[maxn];
void link(int u,int v)
{	e[u].push_back(v); }
void dfs(int u,int f)
{
	vis[u]=1;
	dp[u][0]=0,dp[u][1]=w[u];
	for(int v:e[u])
	{
		if(v==f) dp[v][1]=-1e12;
		else
		{
			dfs(v,f);
			dp[u][0]+=max(dp[v][0],dp[v][1]);
			dp[u][1]+=dp[v][0];
		}
	}
}
ll find(int rt)
{
	vis[rt]=1;
	int x=rt;
	while(!vis[to[x]])
		x=to[x],vis[x]=1;
	dfs(x,x);
	ll ans=max(dp[x][0],dp[x][1]);
	vis[x]=1,x=to[x];
	dfs(x,x);
	return max(ans,max(dp[x][0],dp[x][1]));
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&w[i],&to[i]),link(to[i],i);
	ll ans=0;
	for(int i=1;i<=n;i++)
		if(!vis[i]) ans+=find(i);
	printf("%lld\n",ans);
}