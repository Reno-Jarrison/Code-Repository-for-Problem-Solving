#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int vis[maxn],dp[maxn][maxn];
struct edge { int nxt,val; };
vector<edge>e[maxn];
void dfs(int u,int q)
{
	vis[u]=1;
	int len=e[u].size(),v,w;
	dp[u][0]=0;
	for(int i=0;i<len;i++)
	{
		v=e[u][i].nxt,w=e[u][i].val;
		if(vis[v]) continue;
		dfs(v,q);
		for(int j=q;j;j--)
			for(int k=0;k<j;k++)
				dp[u][j]=max(dp[u][j],dp[u][k]+dp[v][j-k-1]+w);
	}
}
int main()
{
	int n,q,a,b,c;
	cin>>n>>q;
	memset(dp,-0x3f,sizeof(dp));
	for(int i=1;i<n;i++)
	{
		cin>>a>>b>>c;
		e[a].push_back({b,c});
		e[b].push_back({a,c});
	}
	dfs(1,q);
	cout<<dp[1][q];
} 