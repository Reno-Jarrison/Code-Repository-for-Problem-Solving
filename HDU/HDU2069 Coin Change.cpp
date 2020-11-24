#include<cstdio>
#define ll long long
using namespace std;
const int maxn=255;
ll dp[maxn][105],ans[maxn];
int coin[6]={0,1,5,10,25,50};
int main()
{
	int n;
	dp[0][0]=ans[0]=1;
	for(int i=1;i<=5;i++)
		for(int k=1;k<=100;k++)
			for(int j=coin[i];j<=250;j++)
				dp[j][k]+=dp[j-coin[i]][k-1];
	for(int i=1;i<=250;i++)
		for(int j=1;j<=100;j++)
			ans[i]+=dp[i][j];
	while(~scanf("%d",&n))
		printf("%lld\n",ans[n]);
}