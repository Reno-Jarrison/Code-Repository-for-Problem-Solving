#include<cstdio>
#include<cstring>
#include<cmath> 
using namespace std;
double dp[105][105];
int main()
{
	int t,a,b,n,cases=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d/%d%d",&a,&b,&n);
		double p=(double)a/b,q=0.0;
		memset(dp,0,sizeof(dp));
		dp[0][0]=1.0;
		for(int i=1;i<=n;i++)
			for(int j=0;j*b<=i*a;j++)
			{
				dp[i][j]=dp[i-1][j]*(1-p);
				if(j) dp[i][j]+=dp[i-1][j-1]*p;
			}
		for(int i=0;i*b<=n*a;i++) q+=dp[n][i];
		printf("Case #%d: %d\n",++cases,(int)(1.0/q));
	}
}