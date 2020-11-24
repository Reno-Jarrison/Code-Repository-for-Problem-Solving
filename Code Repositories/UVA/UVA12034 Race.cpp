#include<cstdio>
using namespace std;
const int maxn=1e3,mod=10056;
int dp[maxn+5],c[maxn+5][maxn+5];
void getc()
{
	for(int i=1;i<=maxn;i++)
	{
		c[0][i]=c[i][i]=1;
		for(int j=1;j<i;j++)
			c[j][i]=(c[j-1][i-1]+c[j][i-1])%mod;
	}
}
int main()
{
	int t,n,cases=0;
	getc(),dp[0]=1;
	for(int i=1;i<=maxn;i++)
		for(int j=1;j<=i;j++)
			dp[i]=(dp[i]+c[j][i]*dp[i-j]%mod)%mod;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
		scanf("%d",&n),printf("Case %d: %d\n",++cases,dp[n]);
}