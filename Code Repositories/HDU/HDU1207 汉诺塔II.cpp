#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const ull inf=1e18;
ull dp[70];
void solve(int n)
{
	dp[1]=1;
	for(int i=2;i<=n;i++)
	{
		dp[i]=inf;
		for(int j=1;j<i;j++)
			dp[i]=min(dp[i],dp[i-j]*2+(1LL<<j)-1);
	}
}
int main()
{
	solve(64);
	int n;
	while(~scanf("%d",&n))
		printf("%llu\n",dp[n]);
}