#include<cstdio>
#include<vector>
using namespace std;
const int maxn=2e5+5,mod=1e4+7;
int w[maxn],fat[maxn],sum[maxn];
int maxm,dp[maxn][2];
vector<int>e[maxn];
void dfs1(int u,int f)
{
	fat[u]=f;
	int tmp1=0,tmp2=0;
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i];
		if(v==f) continue;
		if(w[v]>tmp1) tmp2=tmp1,tmp1=w[v];
		else if(w[v]>tmp2) tmp2=w[v];
		sum[u]+=w[v];
		dfs1(v,u);
	}
	maxm=max(maxm,tmp1*tmp2);
}
void dfs2(int u)
{
	int g=fat[fat[u]],val=w[u]*w[g];
	if(g) maxm=max(maxm,val),(dp[u][1]+=val%mod)%=mod;
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i];
		if(v==fat[u]) continue;
		dfs2(v),sum[u]-=w[v];
		(dp[u][0]+=sum[u]%mod*w[v]%mod)%=mod;
		(dp[u][0]+=dp[v][1])%=mod;
		(dp[u][1]+=dp[v][0])%=mod;
	}
}
int main()
{
	int n,u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	dfs1(1,0),dfs2(1);
	printf("%d ",maxm);
	printf("%d",(dp[1][0]+dp[1][1])%mod*2%mod);
}