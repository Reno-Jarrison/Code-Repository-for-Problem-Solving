#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=105,mod=1e9+7;
char s[maxn];
ll dp[maxn][maxn][maxn],pow2[maxn];
int main()
{
	int n,x;
	scanf("%d%d%s",&n,&x,s+1);
	for(int i=1;i<=n;i++)
		dp[s[i]-'0'][i][i]=1;
	pow2[0]=pow2[1]=2;
	for(int i=2;i<=x;i++)
		pow2[i]=pow2[i-1]*pow2[i-2]%mod;
	for(int i=2;i<=x;i++)
		for(int j=1;j<=n;j++)
			for(int l=1,r=l+j-1;r<=n;l++,r++)
			{
				dp[i][l][r]+=dp[i-1][l][r]*(r==n?pow2[i-2]:1)%mod;
				dp[i][l][r]+=dp[i-2][l][r]*(l==1?pow2[i-1]:1)%mod;
				for(int k=l;k<r;k++)
					dp[i][l][r]+=dp[i-1][l][k]*dp[i-2][k+1][r]%mod;
				dp[i][l][r]%=mod;
			}
	printf("%lld\n",dp[x][1][n]);
}