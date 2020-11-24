#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=305,mod=1e9+7;
ll dp[maxn][maxn],chain[maxn],cycle[maxn],c[maxn][maxn];
void init(int n)
{
	chain[1]=chain[2]=1,chain[3]=3;
	cycle[1]=cycle[2]=cycle[3]=1;
	for(int i=4;i<=n;i++)
	{
		chain[i]=chain[i-1]*i%mod;
		cycle[i]=cycle[i-1]*(i-1)%mod;
	}
	c[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
}
void update(ll& cur,ll val)
{	cur=(cur+val)%mod; }
ll solve(int n,int m,int lim)
{
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for(int i=0;i<n;i++)
		for(int j=1;j<=lim&&i+j<=n;j++)
			for(int k=0;k+j-1<=m;k++)
			{
				ll val=c[n-i-1][j-1]*dp[i][k]%mod;
				if(k+j-1<=m)
					update(dp[i+j][k+j-1],val*chain[j]%mod);
				if(j>1&&k+j<=m)
					update(dp[i+j][k+j],val*cycle[j]%mod);
			}
	return dp[n][m];
}
int main()
{
	init(300);
	int n,m,l;
	scanf("%d%d%d",&n,&m,&l);
	printf("%lld\n",(solve(n,m,l)-solve(n,m,l-1)+mod)%mod);
}