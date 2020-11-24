#include<cstdio>
using namespace std;
int dp[35][2];
int main()
{
	int n;
	dp[0][0]=1,dp[1][0]=2,dp[2][0]=4;
	for(int i=3;i<=30;i++)
	{
		dp[i][1]=1<<(i-3);
		for(int j=2;j<=i-2;j++)
			dp[i][1]+=dp[j-2][0]*(1<<(i-j-2));
		dp[i][0]=(1<<i)-dp[i][1];
	}
	while(~scanf("%d",&n)&&n)
		printf("%d\n",dp[n][1]);
}