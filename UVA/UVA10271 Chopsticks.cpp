#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5,maxm=1e3+5,inf=0x3f3f3f3f;
int a[maxn],dp[maxn][maxm];
int sqr(int x) { return x*x; }
int main()
{
	int t,k,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&k,&n),k+=8;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1,greater<int>());
		memset(dp,0x3f,sizeof(dp));
		for(int i=0;i<=n;i++) dp[i][0]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=k;j++)
			{
				if(3*j==i) dp[i][j]=dp[i-2][j-1]+sqr(a[i]-a[i-1]);
				if(3*j<i) dp[i][j]=min(dp[i-1][j],dp[i-2][j-1]+sqr(a[i]-a[i-1]));
			}
		printf("%d\n",dp[n][k]);
	}
}