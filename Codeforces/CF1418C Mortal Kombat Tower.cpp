#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,inf=0x3f3f3f3f;
int a[maxn],dp[maxn][2];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		dp[0][0]=inf,dp[0][1]=0;
		dp[1][0]=a[1],dp[1][1]=inf;
		for(int i=2;i<=n;i++)
		{
			dp[i][0]=min(dp[i-1][1],dp[i-2][1]+a[i-1])+a[i];
			dp[i][1]=min(dp[i-1][0],dp[i-2][0]);
		}
		printf("%d\n",min(dp[n][0],dp[n][1]));
	}
}