#include<bits/stdc++.h>
using namespace std;
const int maxn=250;
int d[maxn];
double p[maxn],power[maxn][150],dp[maxn][150];
int main()
{
	int t,n,r;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&r);
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%d",&p[i],&d[i]);
			power[i][0]=1.0;
			for(int j=1;j<=r;j++)
				power[i][j]=power[i][j-1]*(1-p[i]);
		}
		dp[0][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=min(i,r);j++)
			{
				dp[i][j]=0;
				if(j>0) dp[i][j]+=dp[i-1][j-1]*(1-power[i][r-j+1]);
				if(j<i) dp[i][j]+=dp[i-1][j]*power[i][r-j];
			}
		double ans=0;
		for(int i=1;i<=n;i++)
		{
			double q=0;
			for(int j=0;j<=min(i-1,r);j++)
				q+=dp[i-1][j]*(1-power[i][r-j]);
			ans+=d[i]*q;
		}
		printf("%.10lf\n",ans);
	}
}