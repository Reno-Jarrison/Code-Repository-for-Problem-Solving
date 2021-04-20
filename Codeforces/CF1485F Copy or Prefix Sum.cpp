#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5,mod=1e9+7;
map<ll,int>dp;
int b[maxn];
int main()
{
	int t,n,sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		dp.clear();
		dp[0]=1,sum=1;
		ll base=0;
		for(int i=1;i<=n;i++)
		{
			base-=b[i];
			int update=(sum-dp[b[i]+base]+mod)%mod;
			dp[b[i]+base]=sum,sum=(sum+update)%mod;
		}
		printf("%d\n",sum);
	}
}