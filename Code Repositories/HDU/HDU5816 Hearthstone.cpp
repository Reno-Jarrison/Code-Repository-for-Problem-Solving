#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-x))
using namespace std;
ll gcd(ll a,ll b)
{	return !b?a:gcd(b,a%b); }
int bit[1<<20],x[1<<20],sum[1<<20];
ll fac[25],dp[25][25],C[25][25];
void init()
{
	dp[0][0]=dp[0][1]=C[0][0]=fac[0]=1;
	for(int i=1;i<=20;i++)
	{
		fac[i]=fac[i-1]*i;
		dp[i][0]=1;
		for(int j=1;j<i;j++)
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
		dp[i][i+1]=dp[i][i]=dp[i][i-1];
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
	for(int i=1;i<(1<<20);i++)
		bit[i]=bit[i^lowbit(i)]+1;
}
int main()
{
	init();
	int t,p,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&p,&n,&m);
		for(int i=0;i<m;i++)
			scanf("%d",&x[1<<i]);
		for(int i=1;i<(1<<m);i++)
			sum[i]=sum[i^lowbit(i)]+x[lowbit(i)];
		ll ans=0;
		for(int i=0;i<(1<<m);i++)
			if(sum[i]>=p&&bit[i]-1<=n)
				ans+=C[n][bit[i]-1]*dp[bit[i]-1][bit[i]]*fac[bit[i]-1]
					 *fac[bit[i]]*fac[n+m-2*bit[i]+1];
		if(sum[(1<<m)-1]>=p&&bit[(1<<m)-1]-1<n)
			ans+=dp[n][m]*fac[n]*fac[m];
		ll d=gcd(ans,fac[n+m]);
		printf("%lld/%lld\n",ans/d,fac[n+m]/d);
	}
}