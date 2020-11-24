#include<bits/stdc++.h>
using namespace std;
const int maxn=3e3+5;
double dp[maxn][55][55];
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(dp,0,sizeof(dp));
		dp[0][0][0]=1.0;
		for(int i=0;i<n*m;i++)
			for(int j=0;j<=n;j++)
				for(int k=0;k<=m;k++)
				{
					int tot=n*m-i;
					if(j<n||k<m)
						dp[i+1][j][k]+=dp[i][j][k]*(j*k-i)/tot;
					dp[i+1][j+1][k]+=dp[i][j][k]*k*(n-j)/tot;
					dp[i+1][j][k+1]+=dp[i][j][k]*j*(m-k)/tot;
					dp[i+1][j+1][k+1]+=dp[i][j][k]*(n-j)*(m-k)/tot;
				}
		double e=0;
		for(int i=1;i<=n*m;i++)
			e+=dp[i][n][m]*i;
		printf("%.8lf\n",e);
	}
}