#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e4+5,inf=0x3f3f3f3f;
int pos[maxn],t[maxn],dp[maxn][maxn][2];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&pos[i],&t[i]);
			dp[i][i][0]=dp[i][i][1]=0;
		}
		for(int i=2;i<=n;i++)
			for(int l=1,r=l+i-1;r<=n;l++,r++)
			{
				dp[l][r][0]=min(dp[l+1][r][0]+pos[l+1]-pos[l],dp[l+1][r][1]+pos[r]-pos[l]);
				if(t[l]<=dp[l][r][0]) dp[l][r][0]=inf;
				dp[l][r][1]=min(dp[l][r-1][0]+pos[r]-pos[l],dp[l][r-1][1]+pos[r]-pos[r-1]);
				if(t[r]<=dp[l][r][1]) dp[l][r][1]=inf;
			}
		int ans=min(dp[1][n][0],dp[1][n][1]);
		if(ans==inf) puts("No solution");
		else printf("%d\n",ans);
	}
}