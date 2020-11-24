#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e3+5;
ll a[maxn][maxn],dp[maxn][maxn];
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				scanf("%lld",&a[i][j]),dp[i][j]=0;
			dp[i][m+1]=0;
		}
		for(int i=1;i<=n;i++)
			for(int j=m;j;j--)
				dp[i][j]=max(max(dp[i-1][j],dp[i][j+1]),dp[i-1][j+1]+a[i][j]);
		printf("%lld\n",dp[n][1]);
	}
}