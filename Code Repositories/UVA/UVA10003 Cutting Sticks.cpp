#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int dp[maxn][maxn],s[maxn];
int main()
{
	int L,n;
	while(scanf("%d",&L)&&L)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&s[i]);
		s[++n]=L;
		for(int i=2;i<=n;i++)
			for(int l=1,r=l+i-1;r<=n;l++,r++)
			{
				dp[l][r]=0x3f3f3f3f;
				for(int k=l;k<r;k++)
					dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
				dp[l][r]+=s[r]-s[l-1];
			}
		printf("The minimum cutting is %d.\n",dp[1][n]);
	}
}