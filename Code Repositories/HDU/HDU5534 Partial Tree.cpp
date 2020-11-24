#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2020;
ll w[maxn],dp[maxn],w0;
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&w0);
		for(int i=1;i<n-1;i++)
			scanf("%lld",&w[i]),w[i]-=w0;
		memset(dp,-0x3f,sizeof(dp));
		dp[0]=n*w0;
		for(int i=1;i<n-1;i++)
			for(int j=i;j<=n-2;j++)
				dp[j]=max(dp[j],dp[j-i]+w[i]);
		printf("%lld\n",dp[n-2]);
	}
}