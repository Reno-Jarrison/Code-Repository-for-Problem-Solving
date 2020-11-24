#include<iostream>
#include<algorithm>
using namespace std;
int p[1005],dp[1005][1005],m,n;
int main()
{
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		scanf("%d",&m);
		if(m<5) printf("%d\n",m);
		else
		{
			sort(p+1,p+n+1);
			for(int i=1;i<n;i++)
				for(int j=0;j<=m;j++)
				{
					dp[i][j]=dp[i-1][j];
					if(j-p[i]>=5)
						dp[i][j]=max(dp[i][j],dp[i-1][j-p[i]]+p[i]);
				}
			cout<<m-dp[n-1][m]-p[n]<<endl;
		}
	}
}