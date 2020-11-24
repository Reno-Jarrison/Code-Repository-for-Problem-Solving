#include<cstdio>
#define ll long long
using namespace std;
ll dp[25][25][25];
int main()
{
	int t,n,l,r;
	dp[1][1][1]=1;
	for(int i=2;i<=20;i++)
		for(int j=1;j<=i;j++)
			for(int k=1;k<=i;k++)
				dp[i][j][k]=dp[i-1][j-1][k]+dp[i-1][j][k-1]+(i>2?dp[i-1][j][k]*(i-2):0);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&l,&r);
		printf("%lld\n",dp[n][l][r]);
	}
}