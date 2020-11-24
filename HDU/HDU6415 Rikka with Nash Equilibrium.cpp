#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[85*85][85][85],mod;
void add(ll &a,ll b) { a=(a+b)%mod; }
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%lld",&n,&m,&mod);
		memset(dp,0,sizeof(dp));
		dp[1][1][1]=n*m;
		for(int i=1;i<n*m;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=m;k++)
				{
					ll cur=dp[i][j][k];
					if(!cur) continue;
					if(j*k>i) add(dp[i+1][j][k],cur*(j*k-i));
					if(k<m) add(dp[i+1][j][k+1],cur*(j*(m-k)));
					if(j<n) add(dp[i+1][j+1][k],cur*(k*(n-j)));
				}
		printf("%lld\n",dp[n*m][n][m]);
	}
}