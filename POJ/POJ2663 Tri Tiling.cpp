#include<cstdio>
#define ll long long
using namespace std;
const int lim=30;
ll dp[35];
int main()
{
	dp[0]=1,dp[2]=3;
	for(int i=4;i<=lim;i++)
		dp[i]+=dp[i-2]*4-dp[i-4];
	int n;
	while(scanf("%d",&n)&&~n)
		printf("%lld\n",dp[n]);
}