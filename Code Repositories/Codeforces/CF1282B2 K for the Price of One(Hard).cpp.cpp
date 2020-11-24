#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
ll a[maxn],dp[maxn],p;
int main()
{
	int t,n,k,ans;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld%d",&n,&p,&k);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		sort(a+1,a+n+1),ans=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			dp[i]=dp[i-1]+a[i];
			if(i>=k) dp[i]=min(dp[i],dp[i-k]+a[i]);
			if(dp[i]<=p) ans=i;
		}
		printf("%d\n",ans);
	}
}