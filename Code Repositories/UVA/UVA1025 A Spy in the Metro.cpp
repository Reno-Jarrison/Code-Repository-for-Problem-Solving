#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=2e3+5,inf=0x3f3f3f3f;
int t0[55],dp[maxn][55];
bool vis[maxn][55][2];
int main()
{
	int n,t,m,d,cases=0;
	while(scanf("%d",&n)&&n)
	{
		scanf("%d",&t);
		memset(vis,0,sizeof(vis));
		memset(t0,inf,sizeof(t0));
		for(int i=1;i<n;i++)
			scanf("%d",&t0[i]);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)	
		{
			scanf("%d",&d);
			for(int j=1;j<=n;j++)
				vis[d][j][1]=true,d+=t0[j];
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&d);
			for(int j=n;j;j--)
				vis[d][j][0]=true,d+=t0[j-1];
		}
		memset(dp[t],inf,sizeof(dp[t]));
		dp[t][n]=0;
		for(int i=t-1;i>=0;i--)
			for(int j=1;j<=n;j++)
			{
				dp[i][j]=dp[i+1][j]+1;
				if(vis[i][j][1]&&j<n&&i+t0[j]<=t)
					dp[i][j]=min(dp[i][j],dp[i+t0[j]][j+1]);
				if(vis[i][j][0]&&j>1&&i+t0[j-1]<=t)
					dp[i][j]=min(dp[i][j],dp[i+t0[j-1]][j-1]);
			}
		printf("Case Number %d: ",++cases);
		if(dp[0][1]>=t) printf("impossible\n");
		else printf("%d\n",dp[0][1]);
	}
}