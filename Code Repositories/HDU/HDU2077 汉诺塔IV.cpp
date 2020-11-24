#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[25];
void solve(int n)
{
	for(int i=1;i<=n;i++)
		dp[i]=dp[i-1]*3+2;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	solve(20);
	while(t--)
	{
		scanf("%d",&n);
		printf("%lld\n",dp[n-1]+2);
	}
}