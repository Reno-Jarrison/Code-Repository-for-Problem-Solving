#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e4+5;
int dp[maxn][40],cnt[maxn][40];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int e,n1,n2,x,f=0,l=0;
		scanf("%d%d%d",&e,&n1,&n2);
		for(int j=1;j<=n1;j++)
			scanf("%d",&x),f|=1<<((x-e+n)%n);
		for(int j=1;j<=n2;j++)
			scanf("%d",&x),l|=1<<((x-e+n)%n);
		for(int j=0;j<(1<<5);j++)
			if((~j)&f||j&l) cnt[e][j]++;
	}
	int ans=0;
	for(int s=0;s<16;s++)
	{
		memset(dp,-0x3f,sizeof(dp));
		dp[1][s]=cnt[1][s];
		dp[1][s|16]=cnt[1][s|16];
		for(int i=2;i<=n;i++)
			for(int j=0;j<(1<<5);j++)
				dp[i][j]=max(dp[i-1][(j&15)<<1],dp[i-1][(j&15)<<1|1])+cnt[i][j];
		ans=max(ans,max(dp[n][s<<1],dp[n][s<<1|1]));
	}
	printf("%d",ans);
}