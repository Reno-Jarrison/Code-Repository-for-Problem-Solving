#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=1e3+5,inf=0x3f3f3f3f;
vector<int>e[maxn];
int dp[maxn][5];
void dfs(int u,int f)
{
	dp[u][1]=dp[u][2]=0,dp[u][4]=1;
	dp[u][0]=dp[u][3]=inf;
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i];
		if(v==f) continue;
		dfs(v,u);
		dp[u][1]+=dp[v][0];
		dp[u][2]+=dp[v][1];
		dp[u][4]+=dp[v][2];
	}
	if(!e[u].size()) dp[u][0]=dp[u][3]=1;
	else for(int i=0;i<(int)e[u].size();i++)
	{
		int v1=e[u][i],tmp1=dp[v1][3],tmp2=dp[v1][4];
		if(v1==f) continue;
		for(int j=0;j<(int)e[u].size();j++)
		{
			int v2=e[u][j];
			if(v2==f||v1==v2) continue;
			tmp1+=dp[v2][0];
			tmp2+=dp[v2][1];
		}
		dp[u][0]=min(dp[u][0],tmp1);
		dp[u][3]=min(dp[u][3],tmp2);
	}
	dp[u][3]=min(dp[u][3],dp[u][4]),dp[u][0]=min(dp[u][0],dp[u][3]);
	dp[u][1]=min(dp[u][1],dp[u][0]),dp[u][2]=min(dp[u][2],dp[u][1]);
}
int main()
{
	int n,to;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&to);
		e[i].push_back(to);
		e[to].push_back(i);
	}
	dfs(1,0);
	printf("%d",dp[1][0]);
}