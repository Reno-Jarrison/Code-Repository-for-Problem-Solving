#include<bits/stdc++.h>
using namespace std;
const int maxn=205,inf=0x3f3f3f3f;
int a[maxn],dp[maxn][maxn];
int gcd(int a,int b)
{	return !b?a:gcd(b,a%b); }
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),a[i+n]=a[i];
		memset(dp,inf,sizeof(dp));
		for(int i=1;i<=2*n;i++) 
			dp[i][i]=dp[i][i+1]=0;
		for(int i=3;i<=n;i++)
			for(int l=1,r=l+i-1;r<=2*n;l++,r++)
			{
				int cost=gcd(a[l],a[r]);
				for(int k=l+1;k<=r-1;k++)
					dp[l][r]=min(dp[l][r],dp[l][k]+dp[k][r]+cost);
			}
		int ans=inf;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=min(ans,dp[i][j]+dp[j][i+n]+gcd(a[i],a[j]));
		printf("%d\n",ans);
	}
}