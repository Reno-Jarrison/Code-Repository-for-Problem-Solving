#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e3+5;
double p[maxn],dp[maxn],q;
double qpow(double x,int k)
{
	double ans=1.0;
	while(k)
	{
		if(k&1) ans*=x;
		x*=x,k>>=1;
	}
	return ans;
}
int main()
{
	int t,n,m,k,cases=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&k,&m);
		for(int i=0;i<n;i++)
			scanf("%lf",&p[i]);
		dp[0]=0,dp[1]=p[0];
		for(int i=2;i<=m;i++)
		{
			q=1.0,dp[i]=0;
			for(int j=0;j<n;j++)
				dp[i]+=p[j]*q,q*=dp[i-1];
		}
		printf("Case #%d: %.7lf\n",++cases,qpow(dp[m],k));
	}
}